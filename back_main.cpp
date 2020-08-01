#include "back_main.h"
#include <QDebug>

back_main::back_main()
{

}
void back_main::tranmit(){

    emit signal_back();
//    QThread::sleep(10);
    qDebug() << "start comeback";
}
