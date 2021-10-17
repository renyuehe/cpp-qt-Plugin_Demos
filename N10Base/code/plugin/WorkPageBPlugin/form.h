#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void setPlainText(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
