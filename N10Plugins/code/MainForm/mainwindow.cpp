#include "mainwindow.h"
#include <QDebug>
#include <QPluginLoader>


#include "ComPluginInterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(400,400);
    initWorkSpace();
}

MainWindow::~MainWindow()
{
}


void MainWindow::initWorkSpace(){
    m_pWorkSpaceWidget = new WorkSpaceWidget;
    setCentralWidget(m_pWorkSpaceWidget);
}


