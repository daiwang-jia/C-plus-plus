#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = 0);

signals:

public slots:

protected:
    //重写鼠标案件处理函数
    void mousePressEvent(QMouseEvent *ev);

    //重写鼠标移动处理函数
    void mouseMoveEvent(QMouseEvent *ev);

    //重写event分发函数
    bool event(QEvent *e);


    //重写eventFilter
    bool eventFilter(QObject *watched, QEvent *event);

};

#endif // MYLABEL_H
