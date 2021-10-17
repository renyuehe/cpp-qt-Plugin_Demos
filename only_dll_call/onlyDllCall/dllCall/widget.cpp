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

////第一种通过 win32 的方法调用， visual studio 里面是可行的，这里不可行，原因待查
//#include <Windows.h>
//#include <QDebug>
//void Widget::on_pushButton_clicked()
//{
//    HINSTANCE hDLL = LoadLibrary("dll.dll");
//    typedef int(*p_add)(int a, int b);
//    p_add addFunction = (p_add)GetProcAddress(hDLL, "add");

//        if(addFunction != NULL)
//        {
//    qDebug() << __LINE__ << "only dll run";
//    qDebug() << addFunction(2, 4);
//        }
//        else
//        {
//            FreeLibrary(hDLL);
//            return;
//        }
//}


//第二种方法 QLibrary方式
#include <QLibrary>
#include <QDebug>
typedef bool ( *SetKeyBoardHook)(HWND); //定义函数指针
void Widget::on_pushButton_clicked()
{

    QLibrary mylib("dll.dll");
    if(mylib.load())
    {
        qDebug() << "dllhook加载成功";
        SetKeyBoardHook open = (SetKeyBoardHook)mylib.resolve("SetKeyBoardHook");
        if(open)
        {
            qDebug() << "SetKeyBoardHook加载成功";
            bool flag = open((HWND)this->winId());
        }
    }
}

//第三种通过 C++方式 调用 dll
//用新程序来做
