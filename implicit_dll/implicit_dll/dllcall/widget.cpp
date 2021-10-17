#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

#pragma comment(lib,"dll.lib") //注意：这句不是C++语句，而是编译预处理语句，路径时该文件widget.cpp的路径,而不是最终的可执行程序.exe的路径
extern "C" int _declspec(dllimport) add(int x,int y);
#include <QDebug>
void Widget::on_pushButton_clicked()
{
    qDebug() << add(10,20);
}
