#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


//    //PixMap作为绘图设备
//    QPixmap pix(300,300);
//    //默认黑色填充
//    QPainter painter(&pix);
//    pix.fill(Qt::white);
//    painter.setPen(QColor(255,0,0));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    pix.save("D:\\C++\\C-plus-plus\\c++\\QT\\PaintDevices\\pix.png");


//    //QImage作为绘图设备
//    QImage img(300,300,QImage::Format_RGB32);
//    //默认黑色填充
//    QPainter painter(&img);
//    img.fill(Qt::white);
//    painter.setPen(QColor(255,0,0));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    img.save("D:\\C++\\C-plus-plus\\c++\\QT\\PaintDevices\\img.png");

//    //QPicture作为绘图设备
//    QPicture pic;
//    QPainter painter;
//    //开始录制painter绘图步骤
//    painter.begin(&pic);
//    painter.drawEllipse(QPoint(150,150),100,100);
//    painter.end();
//    pic.save("D:\\C++\\C-plus-plus\\c++\\QT\\PaintDevices\\pic.png");




}

void Widget::paintEvent(QPaintEvent *event)
{
//    //先显示一张图片
//    QImage img;
//    img.load("://Nitro/Nitro_Wallpaper_01_3840x2400.jpg");
//    //修改像素
//    for(int x=50;x<100;++x)
//    {
//        for(int y=50;y<100;++y)
//        {
//             img.setPixelColor(x,y,QColor(0,255,0));
//        }
//    }

//    QPainter painter(this);
//    painter.drawImage(0,0,img);



    //重现QPicture的画画步骤
    QPainter  painter(this);
    QPicture pic;
    pic.load("D:\\C++\\C-plus-plus\\c++\\QT\\PaintDevices\\pic.png");
    painter.drawPicture(0,0,pic);

}


Widget::~Widget()
{
    delete ui;
}
//QPixmap  对显示做优化
//Qimage   提供像素级别的访问操作
//Qpicture  作为录像机，记录painter画画的步骤，日后重现
