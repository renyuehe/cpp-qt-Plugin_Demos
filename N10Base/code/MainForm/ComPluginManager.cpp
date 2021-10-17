#include "ComPluginManager.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

#include "ComInstance.h"

ComPluginManager::ComPluginManager(QObject *parent)
    :QObject(parent)
{
    //连接消息传输信号槽
    connect(ComInstance::GetInstance(), SIGNAL(SendMsgToManager(int, const QVariant&)), this, SLOT(slotTranslateMsgToPlugin(int, const QVariant&)));
}

void ComPluginManager::LoadAndInitAllPlugin()
{
    QDir pluginsDir(QApplication::applicationDirPath() + QStringLiteral("/plugin"));

    //遍历插件文件夹，加载插件文件
    Q_FOREACH(QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QString strFilePath = pluginsDir.absoluteFilePath(fileName);
        LoadOnePlugin(strFilePath);
    }
}

#include <QPluginLoader>
//void ComPluginManager::LoadOnePlugin(QString Path)
//{
//    qDebug() << Path << __LINE__ << __FUNCTION__;
//}

void ComPluginManager::LoadOnePlugin(QString Path)
{
    QPluginLoader loader(Path);
    if(loader.load())
    {
        QObject *plugin = loader.instance();
        if (plugin)
        {
            ComPluginInterface* pComPluginInterface = qobject_cast<ComPluginInterface *>(plugin);//都可以

            if (pComPluginInterface)
            {
                //插件初始化
                pComPluginInterface->InitPlugin();

                //插件指针维护
                m_mapPluginInterface.insert(pComPluginInterface->PluginName(), pComPluginInterface);

                //插件对话框维护
                pComPluginInterface->CreateWidget(m_mapPluginWidget);


                //获取插件消息发布和订阅信息
                QList<int> listSub;
                pComPluginInterface->SubPluginMsgCode(listSub);

                //将发布订阅信息放到消息传输队列
                Q_FOREACH(int nCode, listSub)
                {
                    if (m_mapSubList.contains(nCode))
                    {
                        QList<ComPluginInterface*>& listSub = m_mapSubList[nCode];
                        listSub.append(pComPluginInterface);
                    }
                    else
                    {
                        m_mapSubList.insert(nCode, QList<ComPluginInterface*>() << pComPluginInterface);
                    }
                }
            }
        }
        else
        {
            qDebug() << QString("loader %1 library error!!\r\n").arg(Path);
        }
    }
    else
    {
        qDebug() << QString("%1 can not load !\r\n").arg(Path);
    }
}

void ComPluginManager::slotTranslateMsgToPlugin(int code, const QVariant &varMsg)
{
    if(m_mapSubList.contains(code))
    {
        //找到订阅此消息号的插件们
        const QList<ComPluginInterface*>& temp = m_mapSubList.find(code).value();
        Q_FOREACH(ComPluginInterface* it,temp)
        {
            //插件处理该消息
            it->ProcessMsg(code,varMsg);
        }
    }
}


