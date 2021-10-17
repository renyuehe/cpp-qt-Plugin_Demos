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

#include "dll.h"
void Widget::on_pushButton_clicked()
{
    Dll * p_dll = new Dll();
    p_dll->run();

    delete p_dll;
}
