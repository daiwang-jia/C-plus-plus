#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //使用treewidget
    //1.设置标题
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"简介");
    //2.添加根节点
    QTreeWidgetItem * item1= new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * item2= new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * item3= new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);
    //3.添加相应子节点
    item1->addChild(new QTreeWidgetItem(QStringList()<<"刚背猪"<<"简介"));


}

Widget::~Widget()
{
    delete ui;
}
