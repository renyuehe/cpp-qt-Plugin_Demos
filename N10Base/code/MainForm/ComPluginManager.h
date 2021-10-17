#ifndef COMPLUGINMANAGER_H
#define COMPLUGINMANAGER_H

#include <QObject>
#include "ComPluginInterface.h"

//通用插件管理类
class ComPluginManager : public QObject
{
    Q_OBJECT
public:
    ComPluginManager(QObject *parent = nullptr);

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
     * @brief 消息订阅映射<插件， 订阅插件列表>
     */
    QMap<int, QList<ComPluginInterface*> > m_mapSubList;

public:

    /**
     * @brief LoadAndInitAllPlugin 加载所有插件
     */
    void LoadAndInitAllPlugin();

    /**
     * @brief LoadOnePlugin  加载插件
     * @param Path          目标插件路径
     */
    void LoadOnePlugin(QString Path);

public Q_SLOTS:

    /**
     * @brief slotTranslateMsgToPlugin 转发插件消息
     * @param code 编号
     * @param varMsg 消息内容
     */
    void slotTranslateMsgToPlugin(int code, const QVariant& varMsg);
};

#endif // COMPLUGINMANAGER_H
