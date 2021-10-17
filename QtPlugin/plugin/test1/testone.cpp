#include "testone.h"
#include <QPushButton>
#include <QCalendar>
#include <QRadioButton>

QString TestOne::name()
{
    return "testone";
}

QWidget *TestOne::createWidget(QWidget *parent)
{
//    return new WorldTimeClock(parent);
    return new QPushButton("ahah",parent);
//    return new QRadioButton(parent);
}

