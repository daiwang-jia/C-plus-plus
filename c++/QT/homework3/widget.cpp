#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_pushButton_clicked()
{

}

void Widget::on_pushButton_pressed()
{
    //鼠标按下，label改变
    this->ui->label->setText("鼠标按下");
}

void Widget::on_pushButton_released()
{
    this->ui->label->setText("鼠标松开");
}
