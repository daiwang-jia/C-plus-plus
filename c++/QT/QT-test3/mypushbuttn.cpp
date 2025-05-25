#include "mypushbuttn.h"
#include <QDebug>

MyPushButtn::MyPushButtn(QWidget *parent) : QPushButton(parent)
{

}

MyPushButtn::~MyPushButtn()
{
    qDebug()<<"MyPushButton Destroyed";

}
