#include "final.h"
#include "ui_final.h"

Final::Final(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Final)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

Final::~Final()
{
    delete ui;
}
