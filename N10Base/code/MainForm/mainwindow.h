#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WorkSpaceWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    WorkSpaceWidget * m_pWorkSpaceWidget;
    void initWorkSpace();
};
#endif // MAINWINDOW_H
