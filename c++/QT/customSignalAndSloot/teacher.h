#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:
    //自定义信号
    void hungry();
    void hungry(QString what);

public slots:
};

#endif // TEACHER_H
