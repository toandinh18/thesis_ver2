#include "welcome_page.h"
#include "ui_welcome_page.h"

welcome_page::welcome_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome_page)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1,&study_page);
    ui->stackedWidget->insertWidget(2,&activity_page);
    ui->stackedWidget->insertWidget(3,&service_page);
    //ui->stackedWidget->insertWidget(4,&finish);
    connect(&study_page, SIGNAL(homeClicked()),this,SLOT(moveHome()));
    connect(&service_page, SIGNAL(homeClicked1()),this,SLOT(moveHome()));
    connect(&activity_page, SIGNAL(homeClicked2()),this,SLOT(moveHome()));
}

welcome_page::~welcome_page()
{
    delete ui;
}



void welcome_page::on_pushButton_clicked()
{
    play_first.i = 1;
    play_first.start();
    ui->stackedWidget->setCurrentIndex(1);
}

void welcome_page::on_pushButton_2_clicked()
{
    play_first.i = 30;
    play_first.start();
    ui->stackedWidget->setCurrentIndex(2);
}

void welcome_page::on_pushButton_3_clicked()
{
    play_first.i = 20;
    play_first.start();
    ui->stackedWidget->setCurrentIndex(3);
}

void welcome_page::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void welcome_page::on_pushButton_4_clicked()
{

    emit signal_call_final();
    //ui->stackedWidget->setCurrentIndex(4);
    qDebug() << "emit call_final";
}
