#include "mainwindow.h"
#include <QDebug>
#include <QPluginLoader>


#include "ComPluginInterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(700,700);
    initWorkSpace();
}

MainWindow::~MainWindow()
{
}


void MainWindow::initWorkSpace(){
    m_pWorkSpaceWidget = new WorkSpaceWidget;
    setCentralWidget(m_pWorkSpaceWidget);
}


