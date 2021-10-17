#include "dll.h"
#include <QDebug>

Dll::Dll()
{
}

void Dll::run()
{
    qDebug() << __LINE__ << "run";
}
