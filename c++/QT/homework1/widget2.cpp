#include "widget2.h"
#include <QPushButton>
#include <widget.h>

Widget2::Widget2(QWidget *parent) : QWidget(parent)
{
    this->resize(500,400);

    QPushButton * btn2=new QPushButton("按钮2",this);

    connect(btn2,&QPushButton::clicked,[=]{
        Widget * widget1=new Widget;
        widget1->show();

        this->hide();
    });
}
