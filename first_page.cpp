#include "first_page.h"
#include "ui_first_page.h"


first_page::first_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::first_page)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,&welcome_page1);
    ui->stackedWidget->insertWidget(2,&final_page);
    connect(&welcome_page1, SIGNAL(signal_call_final()),this, SLOT(call_back_first()));
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

void first_page::call_back_first()
{
    ui->stackedWidget->setCurrentIndex(0);
    emit signal_back_to_main();
    qDebug() << "emit call back to main";
}
