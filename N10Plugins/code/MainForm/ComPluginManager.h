#ifndef COMPLUGINMANAGER_H
#define COMPLUGINMANAGER_H

#include <QObject>
#include "ComPluginInterface.h"

//通用插件管理类
class ComPluginManager : public QObject
{
    Q_OBJECT
public:
    ComPluginManager();

public:
    /**
     * @brief 插件名称和插件对象映射<插件名称，插件对象>
     */
    QMap<QString, ComPluginInterface*> m_mapPluginInterface;

    /**
     * @brief 插件名称和插件对象映射<插件名称，插件对象>
     */
    QMap<QString, QWidget*> m_mapPluginWidget;

    /**
     * @brief LoadAndInitAllPlugin 加载所有插件
     */
    void LoadAndInitAllPlugin();

Q_SIGNALS:

    /**
     * @brief signalChangeTabPage 窗口切换信号
     * @param code 消息编号
     * @param varMsg 消息
     */
    void signalChangeTabPage(int code, const QVariant& varMsg);

private:

    /**
     * @brief LoadOnePlugin  加载插件
     * @param Path          目标插件路径
     */
    void LoadOnePlugin(QString Path);
};

#endif // COMPLUGINMANAGER_H
