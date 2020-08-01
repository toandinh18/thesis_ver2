#ifndef FINAL_H
#define FINAL_H

#include <QWidget>
#include "include.h"
namespace Ui {
class Final;
}

class Final : public QWidget
{
    Q_OBJECT

public:
    explicit Final(QWidget *parent = 0);
    ~Final();

private:
    Ui::Final *ui;
};

#endif // FINAL_H
