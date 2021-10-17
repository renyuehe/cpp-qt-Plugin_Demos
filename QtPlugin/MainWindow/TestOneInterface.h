#ifndef TESTONEINTERFACE_H
#define TESTONEINTERFACE_H

#include <QObject>
#include <QString>

class TestOneInterface
{
public:
    virtual ~TestOneInterface() = default;
    virtual QString name() = 0;
    virtual QWidget *createWidget(QWidget *parent) = 0;
};

QT_BEGIN_NAMESPACE

#define TestOneInterface_iid "org.qt-project.Qt.Examples.TestOneInterface"
Q_DECLARE_INTERFACE(TestOneInterface, TestOneInterface_iid)

QT_END_NAMESPACE

#endif // TESTONEINTERFACE_H
