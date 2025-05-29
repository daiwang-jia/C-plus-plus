#include "mylabel.h"
#include <QMouseEvent>

mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
    //默认情况下窗口不会跟踪鼠标，只有按下才会开始跟踪
    //下面会开始就跟踪
    this->setMouseTracking(true);

    //事件过滤器的使用
    //1.窗口调用installEventFilter来安装一个事件过滤器
    //2.参数是一个事件过滤器对象QObject，该对象的类要重写eventFilter的函数
    //事件过滤的时候，事件会先到达事件过滤器的eventFilter函数
    //返回值：true表示拦截，false表示不拦截继续到达窗口

    this->installEventFilter(this);

}

void mylabel::mousePressEvent(QMouseEvent *ev)
{
    //输出鼠标事件信息
    //获取坐标
    int x=ev->x();
    int y=ev->y();

    //获取鼠标按键
    Qt::MouseButton btn=ev->button();
    QString strbutton="";
    if(btn==Qt::LeftButton)
    {
        strbutton="LeftButton";
    }
    if(btn==Qt::RightButton)
    {
        strbutton="RightButton";
    }
    if(btn==Qt::MidButton)
    {
        strbutton="MidButton";
    }

    //label是可以显示html
    QString str=QString("<h1><center>press[%1  %2][%3]</center></h1>").
            arg(x).arg(y).arg(strbutton);

    this->setText(str);


}

void mylabel::mouseMoveEvent(QMouseEvent *ev)
{

    //输出鼠标事件信息
    //获取坐标
    int x=ev->x();
    int y=ev->y();

    //获取鼠标按键
    Qt::MouseButtons btns=ev->buttons();
    QString strbutton="";
    if(btns & Qt::LeftButton)
    {
        strbutton+="LeftButton;";
    }
    if(btns &Qt::RightButton)
    {
        strbutton+="RightButton;";
    }
    if(btns &Qt::MidButton)
    {
        strbutton+="MidButton";
    }

    //label是可以显示html
    QString str=QString("<h1><center>move[%1  %2][%3]</center></h1>").
            arg(x).arg(y).arg(strbutton);

    this->setText(str);

}


//事件先会到底窗口的event函数，可以拦截
bool mylabel::event(QEvent *e)
{
    //返回值：true表示该事件得到处理，如果是false，没被处理，事件会继续传到父窗口
    //QEvent就是所有Event类的父类
    //判断event类型
    if(e->type()==QEvent::MouseMove)
    {
        //注释会拦截移动
        this->mouseMoveEvent(static_cast<QMouseEvent *>(e));
        return true;
    }

    return QLabel::event(e);
}

bool mylabel::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseMove)
    {
        //返回true表示拦截该事件
        return true;
    }
    return false;
}

