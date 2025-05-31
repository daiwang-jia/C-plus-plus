#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Mypushbutton(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *ev);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
