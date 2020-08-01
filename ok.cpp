#include "ok.h"
#include <QDebug>
ok::ok(QWidget *parent) : QMainWindow(parent)
{

}

void ok::test(){
    emit signal_test();
    qDebug() << " load emit";
}
