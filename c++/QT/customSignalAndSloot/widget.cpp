#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //老师和学生对象创建
    pTeacher=new Teacher(this);
    pStudent=new Student(this);

    //建立连接
    connect(pTeacher,&Teacher::hungry,pStudent,&Student::treat);

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
}
