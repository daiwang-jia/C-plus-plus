#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn=new QPushButton(this);
    btn->setText("按钮1");

    //关闭 this->close（）;
    //建立四者关系 按钮 被点击 窗口 关闭

    connect(btn,&QPushButton::clicked,this,&Widget::close);

}

Widget::~Widget()
{

}
