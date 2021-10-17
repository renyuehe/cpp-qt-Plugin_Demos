#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadPlugin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPlugin()
{

    QPluginLoader pluginLoader(QString("D:\\Desktop\\QtPlugin\\plugin\\plugins\\test1.dll"));
    QObject *plugin = pluginLoader.instance();


    auto centerInterface = qobject_cast<TestOneInterface*>(plugin);


    auto centerWidget = centerInterface->createWidget(this);
    this->setCentralWidget(centerWidget);

    return;
}


