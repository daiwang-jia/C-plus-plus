#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QByteArray>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //写文件
    QFile file("D:\\C++\\C-plus-plus\\c++\\QT\\qfile\\text.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.write("hello");


    file.close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"打开一个txt","D:\\C++\\C-plus-plus\\c++\\QT\\qfile","TXT(*.txt)");

    //对filename做判断，如果没有选择文件，那么就是空串
    if(filename.isEmpty())
    {
        return ;
    }
    //不为空串，选择了某个文件
    this->ui->lineEdit->setText(filename);

    //使用qfile读取文件
    QFile file(filename);
    //打开文件
    file.open(QIODevice::ReadOnly);
    //读取文件内容
    //将所有内容读取出来
    QByteArray array=file.readAll();
    //将QByteArray转化为QString
//    QString content =QString(array);
    //使用gbk编码
    QTextCodec* codec=QTextCodec::codecForName("gbk");
    //将array转化到QString
    QString content=codec->toUnicode(array);

    //输出到edit上
    this->ui->plainTextEdit->setPlainText(content);

    //获取文件信息
    QFileInfo info(filename);
    qDebug()<<info.fileName();
    qDebug()<<info.baseName();
    qDebug()<<"创建时间"<<info.lastModified();
    qDebug()<<"最后修改时间"<<info.created().toString("yyyy--mm-dd");


    //关闭文件
    file.close();
}
