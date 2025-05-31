#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget:: paintEvent(QPaintEvent* event)
{
    //painter绘制已经存在的图片
    QPainter painter(this);
    QPixmap pixmap("://Nitro/Nitro_Wallpaper_02_3840x2400.jpg");
    painter.drawPixmap(mPox,0,pixmap);
}

void Widget::on_pushButton_clicked()
{
    //每点击一次就向右移动10像素
    mPox+=100;

    //手动触发绘图事件
    //1. repaint
    //2. update

//    this->repaint();  会马上触发
    this->update();   //会优化
}
