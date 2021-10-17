#include "dll.h"
#include <QDebug>

Dll::Dll()
{
}

void Dll::run()
{
    qDebug() << "run";
}


void run()
{
    qDebug() << "run function";
}
