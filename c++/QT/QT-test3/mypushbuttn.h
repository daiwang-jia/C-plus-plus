#ifndef MYPUSHBUTTN_H
#define MYPUSHBUTTN_H

#include <QWidget>
#include <QPushButton>

class MyPushButtn : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButtn(QWidget *parent = 0);
    ~MyPushButtn();
signals:

public slots:
};

#endif // MYPUSHBUTTN_H
