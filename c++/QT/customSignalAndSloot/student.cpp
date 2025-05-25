#include "student.h"
#include <Qdebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"Student treat teacher";
}

void Student::treat(QString what)
{
    //QDebug默认将String转义输出
    //解决方法：
    //1.将Qstring转为 char*
//    qDebug()<<"Student treat teacher with"<<what.toUtf8().data();

     //2.使用qDebug().noquote()
    qDebug().noquote()<<"Student treat teacher with"<<what;
}

