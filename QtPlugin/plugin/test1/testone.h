#ifndef TESTONE_H
#define TESTONE_H

#include <QObject>
#include "TestOneInterface.h"

class TestOne : public QObject, TestOneInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.TestOneInterface" FILE "test1.json")
    Q_INTERFACES(TestOneInterface)

      //不要json文件也可以
//    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.TestOneInterface")
//    Q_INTERFACES(TestOneInterface)
public:
    QString name() override;
    QWidget *createWidget(QWidget *parent) override;
};

#endif // TESTONE_H
