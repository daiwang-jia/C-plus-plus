#include "mainwindow.h"
#include<QMenuBar>
#include <QToolBar>
#include<QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏,获取当前窗口菜单栏，没有的话会自动创建一个
    QMenuBar*mb=this->menuBar();
    //添加菜单
    QMenu *menufile=mb->addMenu("文件");
    QMenu *menuedit=mb->addMenu("编辑");
    //往菜单里面添加菜单项
    QAction *actionnew=menufile->addAction("新建");
    QAction *actionopen=menufile->addAction("打开");
    //添加分隔符
    menufile->addSeparator();
    //添加二级菜单
    QMenu *menurecent=menufile->addMenu("最近打开文件");

    menurecent->addAction("1.txt");
    menurecent->addAction("2.txt");


    //工具栏，可以有多个
    QToolBar*toolbar=this->addToolBar("");
    //工具栏添加工具
    toolbar->addAction("视图");
    toolbar->addAction("外观");
    //初始时放在左侧
    this->addToolBar(Qt::LeftToolBarArea,toolbar);
    //只允许在左边或者右边
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置工具栏不可以浮动
    toolbar->setFloatable(false);
    //设置工具栏不可以拖动
    toolbar->setMovable(false);


    //状态栏
    //获取窗口的状态栏
    QStatusBar *sb=this->statusBar();
    //往状态栏里添加信息
    //添加左侧信息
    QLabel* labelleft=new QLabel("左侧信息",this);
    sb->addWidget(labelleft);
    //添加右侧信息
    QLabel* labelright=new QLabel("右侧信息",this);
    sb->addPermanentWidget(labelright);


    //停靠部件
    QDockWidget*dockwidget=new QDockWidget("停靠部件",this);
    //默认情况下没有核心部件作为参照物，将会占完窗口
    this->addDockWidget(Qt::BottomDockWidgetArea,dockwidget);

    //添加核心部件
    QTextEdit* textedit=new QTextEdit(this);
    this->setCentralWidget(textedit);


}

MainWindow::~MainWindow()
{

}


