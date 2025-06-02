#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>

class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //按钮的三种状态
    enum Mypushbuttonsat
    {
        Normal,
        Entered,
        Pressed
    };

    explicit Mypushbutton(QWidget *parent = nullptr);

private:
    Mypushbuttonsat mstat;

protected:
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent * event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
