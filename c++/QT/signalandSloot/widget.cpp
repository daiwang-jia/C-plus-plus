#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn=new QPushButton(this);
    btn->setText("按钮1");

    //槽和信号本质都是函数
    //槽：信号的处理动作
    //connect(信号发送者，信号，信号接受者，槽）都是指针

    //保留&
    connect(btn,&QPushButton::released,this,&Widget::showMaximized);
}

Widget::~Widget()
{

}
