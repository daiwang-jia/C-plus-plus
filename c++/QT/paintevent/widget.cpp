#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>


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

void Widget::paintEvent(QPaintEvent *event)
{
    //这里画画
    QPainter painter(this);

    //画家偏移
    painter.translate(100,30);

    //创建画笔
    QPen pen;
    pen.setColor(QColor(255,0,0));

    //设置笔宽
    pen.setWidth(3);

    //设置画笔风格
    pen.setStyle(Qt::DashLine);


    //画家设置画笔
    painter.setPen(pen);

    //画刷填充
    QBrush brush;
    brush.setColor(Qt::cyan);
    //默认情况下画刷不填充
    brush.setStyle(Qt::Dense4Pattern);

    //画家设置画刷
    painter.setBrush(brush);




    //画一条线
    painter.drawLine(0,0,100,100);

    //画矩形
    painter.drawRect(20,20,50,50);

    //画圆形
    painter.drawEllipse(QPoint(100,100),50,50);

    //文字
    painter.drawText(200,100,"好好学习");
}
