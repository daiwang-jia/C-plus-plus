#include "mypushbutton.h"
#include <QPainter>
#include <QBrush>

Mypushbutton::Mypushbutton(QWidget *parent) : QPushButton(parent)
{

}

void Mypushbutton::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    //判断状态
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    switch(mstat)
    {
    case Normal:
        //填充红色
        brush.setColor(Qt::red);
        break;

    case Entered:
        //填充绿色
        brush.setColor(Qt::green);
        break;

    case Pressed:
        //填充蓝色
        brush.setColor(Qt::blue);
        break;
    }

    //画家设置画刷
    painter.setBrush(brush);

    //画按钮，椭圆
    painter.drawEllipse(0,0,this->width()-1,this->height()-1);

    //画按钮文字
    painter.drawText(0,0,this->width(),this->height(),
                     Qt::AlignHCenter | Qt::AlignVCenter,this->text());



}

void Mypushbutton::enterEvent(QEvent *event)
{
    this->mstat=Entered;
    update();
}

void Mypushbutton::leaveEvent(QEvent *event)
{
    this->mstat=Normal;
    update();
}

void Mypushbutton::mousePressEvent(QMouseEvent *e)
{
    this->mstat=Pressed;
    update();

    //信号依赖事件
    QPushButton::mousePressEvent(e);
}

void Mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    this->mstat=Entered;
    update();

    QPushButton::mouseReleaseEvent(e);
}
