#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //老师和学生对象创建
    pTeacher=new Teacher(this);
    pStudent=new Student(this);

//    //建立连接
//    connect(pTeacher,&Teacher::hungry,pStudent,&Student::treat);

    //函数发生重载
    //1.函数指针赋值

//    void (Teacher::*teacher_QString)(QString)=&Teacher::hungry;
//    void (Student::*student_QString)(QString)=&Student::treat;

//    connect(pTeacher,teacher_QString,pStudent,student_QString);

    //断开连接
//    disconnect(pTeacher,teacher_QString,pStudent,student_QString);

    //2.使用static_cast来转换无参函数
    connect(pTeacher,
            static_cast<void (Teacher::*)()>(&Teacher :: hungry),
            pStudent,
            static_cast<void (Student::*)()>(&Student :: treat));



//    //信号可以连接信号
//    QPushButton *btn=new QPushButton("按钮1",this);
//    connect(btn,&QPushButton::clicked,pTeacher,static_cast<void (Teacher::*)()>(&Teacher :: hungry));

    //qt4
    connect(pTeacher,SIGNAL(hungry(QString)),pStudent,SLOT(treat(QString)));

    //下课
    this->classover();



}


Widget::~Widget()
{

}

void Widget::classover()
{
    //触发老师饿了信号
    emit pTeacher->hungry();
    emit pTeacher->hungry("黄焖鸡");
}


/*
 信号和槽的扩展：
     1.一个信号可以连接多个槽

     2.一个槽可以连接多个信号

     3.信号可以连接信号

     4.信号可以断开连接
        disconnect跟connect填法一样

     5.信号和槽的参数关系，必须同时满足以下两点：
        a.信号和槽函数的参数类型必须对应
        b.信号和槽函数的参数个数不需要一致，但是信号函数参数个数》=槽函数参数个数


QT4的信号和槽
    使用两个宏 SIGNAL  SLOT
    connect(信号发送者，SIGNAL(函数原型），信号接收者，SLOT（函数原型））

    好处：没有二义性问题
    坏处：写错了，编译不报错

    推荐QT5


QDebug
*/
