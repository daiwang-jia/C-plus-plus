#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置行数、列数
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);

    //2.设置标题
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"英雄"<<"性别"<<"年龄");

    //3.添加数据
    QStringList heronames=QStringList()<<"亚瑟"<<"妲己"<<"安其拉"<<"赵云"<<"孙悟空";
    QStringList herogender=QStringList()<<"男"<<"女"<<"女"<<"男"<<"男";
    for(int row=0;row<5;++row)
    {
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(heronames[row]));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(herogender[row]));

    }

}

Widget::~Widget()
{
    delete ui;
}
