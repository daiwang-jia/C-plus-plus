#include "student.h"
#include <Qdebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"Student treat teacher";
}
