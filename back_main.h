#ifndef BACK_MAIN_H
#define BACK_MAIN_H
#include <QThread>
#include <QObject>

class back_main : public QObject
{
    Q_OBJECT
public:
    back_main();
    void tranmit();

signals:
    void signal_back();

};

#endif // BACK_MAIN_H
