#include "mainwindow.h"
#include <QDebug>
#include <QPluginLoader>


#include "ComPluginInterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadPlugin();
}

MainWindow::~MainWindow()
{
}

void MainWindow::loadPlugin()
{
    QPluginLoader pluginLoader(QString("D:\\Desktop\\SimPlugin\\SimN10\\code\\plugin\\WorkPageAPlugin\\debug\\WorkPageAPlugin.dll"));
    QObject *plugin = pluginLoader.instance();


    auto centerInterface = qobject_cast<ComPluginInterface*>(plugin);


    centerInterface->InitPlugin();
    this->setCentralWidget(centerInterface->getWidget());

    return;
}
