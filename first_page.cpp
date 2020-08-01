#include "first_page.h"
#include "ui_first_page.h"


first_page::first_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::first_page)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,&welcome_page1);
    ui->stackedWidget->insertWidget(2,&final_page);
}

first_page::~first_page()
{
    delete ui;
}

void first_page::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void first_page::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


