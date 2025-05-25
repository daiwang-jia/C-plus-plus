#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //lambda表达式
    //[capture](parameters) opt->retType
    //{}

    //调用lambda函数，使用函数指针
//    void(*p)()=
//    []()
//    {
//        qDebug()<<"hello lambda";
//    };
//    p();


    //局部变量捕获

    int a=10;
    int b=20;
    //捕获两种方式：值传递和引用
    //默认是值传递
//    [&a,&b]()
//    {
//        qDebug()<<"hello lambda";
//        qDebug()<<a<<b;
//        a=20;
//        b=30;
//    }();
//    qDebug()<<a<<b;


//    [a,b]()mutable
//    {
//        qDebug()<<"hello lambda";
//        qDebug()<<a<<b;
//        a=40;
//        b=50;
//    }();
//    qDebug()<<a<<b;



    //信号和槽使用lambda
    QPushButton * btn=new QPushButton("按钮1",this);

    //推荐使用[=](){}
    connect(btn,&QPushButton::clicked,[=](){
//        qDebug()<<a<<b;
        this->resize(800,600);
    });
}

Widget::~Widget()
{

}
