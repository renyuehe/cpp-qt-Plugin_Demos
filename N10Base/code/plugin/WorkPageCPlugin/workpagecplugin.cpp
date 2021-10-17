#include "workpagecplugin.h"
#include <QDebug>
WorkPageCPlugin::WorkPageCPlugin()
    :m_pForm(nullptr)
{
}

void WorkPageCPlugin::InitPlugin()
{
    m_pForm = Q_NULLPTR;
    m_pForm = new Form;
}

QString WorkPageCPlugin::PluginName()
{
    return QStringLiteral("WorkPageCPlugin");
}

QWidget *WorkPageCPlugin::getWidget()
{
    return m_pForm;
}

void WorkPageCPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if (m_pForm)
    {
        mapWidgets.insert(QStringLiteral("C plugin"), m_pForm);
    }
}

void WorkPageCPlugin::SubPluginMsgCode(QList<int> &listSubCode)
{
    listSubCode << 2;
    return;
}

void WorkPageCPlugin::ProcessMsg(int code, const QVariant &varMsg)
{
    qDebug() << QString("ProcessMsg is :") << code;
    qDebug() << QString("varient message is :") << varMsg.toString();

    this->m_pForm->setPlainText(QString::number(code) + ":   " + varMsg.toString());
    return;
}
