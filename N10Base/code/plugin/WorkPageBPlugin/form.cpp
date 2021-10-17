#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setPlainText(QString str)
{
    ui->subscribeTextEdit->append(str);
}

#include "ComInstance.h"
void Form::on_pushButton_clicked()
{
    SEND_MSG(1, ui->publishTextEdit->toPlainText());
}

