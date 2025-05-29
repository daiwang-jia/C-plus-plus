#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建定时器
    //startTimer(1000);
    mtimerid(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int num=1;
    //qDebug()<<num++;
    this->ui->lcdNumber->display(num++);
}

void Widget::on_pushButton_start_clicked()
{
    //定时器1，1秒响一次
    this->mtimerid=startTimer(1000);
}

void Widget::on_pushButton_stop_clicked()
{
    //停止计时器
    killTimer(this->mtimerid);
    this->mtimerid=0;
}
