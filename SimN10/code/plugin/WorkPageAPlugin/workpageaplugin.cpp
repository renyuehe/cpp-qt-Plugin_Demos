#include "workpageaplugin.h"
#include <QPushButton>

WorkPageAPlugin::WorkPageAPlugin(QObject *parent)
    :QObject(parent)
    ,p_pushbutton(nullptr)
{

}

void WorkPageAPlugin::InitPlugin()
{
    p_pushbutton = Q_NULLPTR;
    p_pushbutton = new QPushButton(QStringLiteral("pushbutton plugin"));
}

QWidget *WorkPageAPlugin::getWidget()
{
    return this->p_pushbutton;
}
