#include "mypushbutton.h"
#include <QDebug>

Mypushbutton::Mypushbutton(QWidget *parent) : QPushButton(parent)
{

}

void Mypushbutton::paintEvent(QPaintEvent *ev)
{
    static int num=1;
    qDebug()<<num++;
    //QPushButton::paintEvent(ev);
}
