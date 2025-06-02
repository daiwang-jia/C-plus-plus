#include "widget.h"
#include <QPushButton>
#include "widget2.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(500,400);
    this->setWindowTitle("窗口1");
    QPushButton *btn=new QPushButton("按钮1",this);

    connect(btn,&QPushButton::clicked,[=]{
        //点击按钮1，显示窗口2
        Widget2 *widget2=new Widget2  ;
        widget2->show();
        //隐藏窗口1
        this->hide();
    });
}

Widget::~Widget()
{

}
