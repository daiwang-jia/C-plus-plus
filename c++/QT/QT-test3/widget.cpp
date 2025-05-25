#include "widget.h"
#include <QPushButton>
#include "mypushbuttn.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //局部变量再函数退出时自动释放
//    QPushButton btn("按钮1",this);
//    btn.show();

    //解决  让按钮的生命周期变长
    //1.static
    //2.类成员变量
    //3. new 一个

    MyPushButtn *btn1=new MyPushButtn(this);
    btn1->setText("按钮1");
    //没有delete

    //验证析构



}

Widget::~Widget()
{

}
