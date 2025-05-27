#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionModal,&QAction::triggered,[=](){
        //创建一个模块对话框
        QDialog dlg(this);
        dlg.exec();
        qDebug()<<"hello dialog";
    }
    );


    connect(ui->actionNonmodal,&QAction::triggered,[=](){
        //创建一个非模块对话框
        //因为show是非堵塞，所以很快释放，改用new
        QDialog *dlg=new QDialog(this);
        //释放问题，只有父对象释放时子对象才会释放
        //通过设置窗口的属性
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();
        qDebug()<<"hello nodialog";
    }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCriticial_triggered()
{
    QMessageBox ::critical(this,"错误","critical");
}


void MainWindow::on_actionWarning_triggered()
{
    QMessageBox::warning (this,"警告","warning");
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(this,"信息","info");
}

void MainWindow::on_actionQuestion_triggered()
{
    if(QMessageBox::Ok==QMessageBox::question(this,"问你个问题","你有对象吗",
                          QMessageBox::Ok | QMessageBox::Cancel))
    {
        qDebug()<<"点击了OK";
    }
    else
    {
        qDebug()<<"点击了cancel";
    }
}

void MainWindow::on_actionQFileDialog_triggered()
{
   //打开一个文件对话框
    QString filename=QFileDialog::getOpenFileName(this,"打开一个文件","C:\\Users\\a1956\\Pictures\\Nitro"
                                 ,"PNG (*.png);; JPG(*.jpg);;all(*.*)");

    qDebug()<<filename;

}
