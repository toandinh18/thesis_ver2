#ifndef OK_H
#define OK_H

#include <QMainWindow>

class ok : public QMainWindow
{
    Q_OBJECT
public:
    explicit ok(QWidget *parent = 0);
    void test();
signals:
    void signal_test();
public slots:
};

#endif // OK_H
