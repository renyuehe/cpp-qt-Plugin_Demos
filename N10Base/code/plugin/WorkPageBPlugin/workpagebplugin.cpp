#include "workpagebplugin.h"
#include <QDebug>

WorkPageBPlugin::WorkPageBPlugin()
    :m_pForm(nullptr)
{
}

void WorkPageBPlugin::InitPlugin()
{
    m_pForm = Q_NULLPTR;
    m_pForm = new Form;
}

QString WorkPageBPlugin::PluginName()
{
    return QStringLiteral("WorkPageBPlugin");
}

QWidget *WorkPageBPlugin::getWidget()
{
    return m_pForm;
}

void WorkPageBPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if(m_pForm){
        mapWidgets.insert(QStringLiteral("B plugin"), m_pForm);
    }
}

void WorkPageBPlugin::SubPluginMsgCode(QList<int> &listSubCode)
{
    listSubCode << 1 << 2 ;
    return;
}

void WorkPageBPlugin::ProcessMsg(int code, const QVariant &varMsg)
{
    qDebug() << QString("ProcessMsg is :") << code;
    qDebug() << QString("varient message is :") << varMsg.toString();

    this->m_pForm->setPlainText(QString::number(code) + ":   " + varMsg.toString());
    return;
}
