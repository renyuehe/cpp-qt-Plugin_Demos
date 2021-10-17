#ifndef WORKPAGECPLUGIN_H
#define WORKPAGECPLUGIN_H

#include "WorkPageCPlugin_global.h"
#include "ComPluginInterface.h"
#include <QObject>
#include "form.h"

class WORKPAGECPLUGIN_EXPORT WorkPageCPlugin : public QObject, public ComPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ComPluginInterface_IID)
    Q_INTERFACES(ComPluginInterface)
private:
    Form * m_pForm;
public:
    WorkPageCPlugin();


    void InitPlugin() override;
    QString PluginName() override;
    QWidget * getWidget() override;
    void CreateWidget(QMap<QString, QWidget*>& mapWidgets) override;

    /**
     * @brief SubPluginMsgCode 消息发布和订阅编号列表
     * @param listSubCode 订阅编号列表
     */
    void SubPluginMsgCode(QList<int>& listSubCode) override;

    /**
     * @brief ProcessMsg 消息接收---接收来自插件管理器的消息
     * @param code  消息号
     * @param Msg   消息体
     */
    void ProcessMsg(int code, const QVariant& varMsg) override;
};

#endif // WORKPAGECPLUGIN_H
