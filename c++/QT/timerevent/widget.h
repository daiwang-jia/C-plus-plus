#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

protected:
    void timerEvent(QTimerEvent *event);


public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();



private:
    Ui::Widget *ui;

    //定时器ID
    int mtimerid;
};

#endif // WIDGET_H
