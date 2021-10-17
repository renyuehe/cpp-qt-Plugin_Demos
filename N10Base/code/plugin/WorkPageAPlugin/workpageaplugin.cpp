#include "workpageaplugin.h"
#include <QPushButton>
#include <QDebug>

WorkPageAPlugin::WorkPageAPlugin(QObject *parent)
    :QObject(parent)
    ,m_pForm(nullptr)
{

}

void WorkPageAPlugin::InitPlugin()
{
    m_pForm = Q_NULLPTR;
    m_pForm = new Form;
}

QString WorkPageAPlugin::PluginName()
{
    return QStringLiteral("WorkPageAPlugin");
}

QWidget *WorkPageAPlugin::getWidget()
{
    return this->m_pForm;
}

void WorkPageAPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if (m_pForm)
    {
        mapWidgets.insert(QStringLiteral("A plugin"), m_pForm);
    }
}

void WorkPageAPlugin::SubPluginMsgCode(QList<int> &listSubCode)
{
    listSubCode << 0 << 1 << 2;
    return;
}

void WorkPageAPlugin::ProcessMsg(int code, const QVariant &varMsg)
{
    qDebug() << QString("ProcessMsg is :") << code;
    qDebug() << QString("varient message is :") << varMsg.toString();
    this->m_pForm->setPlainText(QString::number(code) + ":   " + varMsg.toString());
    return;
}
