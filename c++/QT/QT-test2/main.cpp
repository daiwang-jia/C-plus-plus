#include "widget.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

//    //添加按钮
//    QPushButton btn;
//    btn.setText("按钮1");
//    //显示按钮
//    btn.show();

    //默认情况下没有建立父子关系
    //建立关系
    //1.setParent函数
    QPushButton btn;
    btn.setText("按钮1");
    btn.setParent(&w);

    //2.构造函数传参
    QPushButton btn2("按钮2",&w);
    //移动位置
    btn2.move(100,100);

    btn2.resize(400,400);

    QPushButton btn3("按钮3",&btn2);
    btn3.move(100,100);


    //设置窗口标题
    w.setWindowTitle("hello world");

    w.show();



    return a.exec();
}
