#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //关联UI文件到程序
    ui->setupUi(this);

    //往状态栏添加信息
    this->statusBar()->addWidget(new QLabel("左侧信息",this));
    this->statusBar()->addPermanentWidget(new QLabel("右侧信息",this));


    //使用图片资源
    //1.使用绝对路径
//    ui->actionnew->setIcon(QIcon("C:\\Users\\a1956\\Pictures\\Screenshots\\2025-05-26 150125.png"));
    //2.使用资源文件
    //使用资源路径
    //冒号：前缀/+目录文件名
    ui->actionnew->setIcon(QIcon(":/Nitro/Nitro_Wallpaper_02_3840x2400.jpg"));





}

MainWindow::~MainWindow()
{
    delete ui;
}
