#ifndef COMPLUGININTERFACE_H
#define COMPLUGININTERFACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QJsonObject>
#include <QVariant>
#include <QVector>

class ComPluginInterface /*: public QObject*/
{
public:
    virtual ~ComPluginInterface(){}

    /**
     * @brief InitPlugin 插件初始化
     */
    virtual void InitPlugin() = 0;

    virtual QWidget * getWidget() = 0;
};

QT_BEGIN_NAMESPACE

#define ComPluginInterface_IID "org.qt-project.Qt.ComPluginInterface/1.0"

//此宏用于把标识符与类名接口关联起来。这个标识符是唯一的
Q_DECLARE_INTERFACE(ComPluginInterface, ComPluginInterface_IID)

QT_END_NAMESPACE

#endif // COMPLUGININTERFACE_H
