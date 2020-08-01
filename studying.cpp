#include "studying.h"
#include "ui_studying.h"
#include <QObject>
#include <QObjectData>

String keydata[num] = {"chatLuongGiaoTrinh.json","khuVucTuHoc.json","nhaVeSinh.json", "nhaXe.json","phanHoi.json","phongHoc.json","phongThiNghiem.json","taiLieuDayDu.json", "thoiGianDkmh.json","trangWeb.json"};

//declare network config
QNetworkAccessManager m_manager;

string url = "https://thesis-24eab.firebaseio.com/hocTap/";
//url = url + "/phongHoc.json";
//const char *command  = url.c_str();
QNetworkRequest request; // QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));
QNetworkReply* reply;
QNetworkReply* postRequest;
QJsonObject obj;

int hoctap[num];
void func(String keydata, int value);



studying::studying(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studying)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->next,&QPushButton::clicked,this, &studying::next_page);
    connect(ui->next_2,&QPushButton::clicked,this, &studying::next_page2);
    connect(&m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

}
studying::~studying()
{
    delete ui;
}

void studying::next_page(){
    ui->stackedWidget->setCurrentIndex(1);
    audio_ht.i = 2;
    audio_ht.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra1_1,1);
    gr1->addButton(ui->ra1_2,2);
    gr1->addButton(ui->ra1_3,3);
    gr1->addButton(ui->ra1_4,4);
    hoctap[0] = gr1->checkedId();
    func(keydata[0],hoctap[0]);
    qDebug() << hoctap[0];
    qDebug() << gr1->checkedButton();
}

void studying::next_page2(){
    audio_ht.i = 3;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(2);
    QButtonGroup *gr2 = new QButtonGroup(this);
    gr2->addButton(ui->ra2_1,1);
    gr2->addButton(ui->ra2_2,2);
    gr2->addButton(ui->ra2_3,3);
    gr2->addButton(ui->ra2_4,4);
    hoctap[1] = gr2->checkedId();
    func(keydata[1],hoctap[1]);
    qDebug() << hoctap[1];
    qDebug() << gr2->checkedButton();
}



void studying::on_home_clicked()
{
    audio_ht.i = 4;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(3);
    QButtonGroup *gr3 = new QButtonGroup(this);
    gr3->addButton(ui->ra3_1,1);
    gr3->addButton(ui->ra3_2,2);
    gr3->addButton(ui->ra3_3,3);
    gr3->addButton(ui->ra3_4,4);
    hoctap[2] = gr3->checkedId();
    func(keydata[2],hoctap[2]);
    qDebug() << hoctap[2];
    qDebug() << gr3->checkedButton();

//    emit homeClicked();
}

void studying::on_home_2_clicked()
{
    audio_ht.i = 5;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(4);
    QButtonGroup *gr4 = new QButtonGroup(this);
    gr4->addButton(ui->ra3_5,1);
    gr4->addButton(ui->ra3_6,2);
    gr4->addButton(ui->ra3_7,3);
    gr4->addButton(ui->ra3_8,4);
    hoctap[3] = gr4->checkedId();
    func(keydata[3],hoctap[3]);
    qDebug() << hoctap[3];
//    qDebug() << gr3->checkedButton();
}

void studying::on_home_3_clicked()
{
    audio_ht.i = 6;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(5);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra3_9,1);
    gr5->addButton(ui->ra3_10,2);
    gr5->addButton(ui->ra3_11,3);
    gr5->addButton(ui->ra3_12,4);
    hoctap[4] = gr5->checkedId();
    func(keydata[4],hoctap[4]);
    qDebug() << hoctap[4];
}

void studying::on_home_4_clicked()
{
    audio_ht.i = 7;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(6);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra3_13,1);
    gr5->addButton(ui->ra3_14,2);
    gr5->addButton(ui->ra3_15,3);
    gr5->addButton(ui->ra3_16,4);
    hoctap[5] = gr5->checkedId();
    func(keydata[5],hoctap[5]);
    qDebug() << hoctap[5];
}

void studying::on_next_3_clicked()
{   audio_ht.i = 8;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(7);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_5,1);
    gr5->addButton(ui->ra1_6,2);
    gr5->addButton(ui->ra1_7,3);
    gr5->addButton(ui->ra1_8,4);
    hoctap[6] = gr5->checkedId();
    func(keydata[6],hoctap[6]);
    qDebug() << hoctap[6];
}

void studying::on_next_4_clicked()
{
    audio_ht.i = 9;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(8);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_9,1);
    gr5->addButton(ui->ra1_10,2);
    gr5->addButton(ui->ra1_11,3);
    gr5->addButton(ui->ra1_12,4);
    hoctap[7] = gr5->checkedId();
    func(keydata[7],hoctap[7]);
    qDebug() << hoctap[7];
}

void studying::on_next_5_clicked()
{
    audio_ht.i = 10;
    audio_ht.start();
    ui->stackedWidget->setCurrentIndex(9);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_13,1);
    gr5->addButton(ui->ra1_14,2);
    gr5->addButton(ui->ra1_15,3);
    gr5->addButton(ui->ra1_16,4);
    hoctap[8] = gr5->checkedId();
    func(keydata[8],hoctap[8]);
    qDebug() << hoctap[8];
}

void studying::on_next_6_clicked()
{
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_9,1);
    gr5->addButton(ui->ra1_10,2);
    gr5->addButton(ui->ra1_11,3);
    gr5->addButton(ui->ra1_12,4);
    hoctap[9] = gr5->checkedId();
    func(keydata[9],hoctap[9]);
    qDebug() << hoctap[9];
    // make sure to clean up
    //postRequest->deleteLater();
    emit homeClicked();
}


//declare function for network sent to firebase
void func(String keydata, int value){
    qDebug() << "run func connect ok ";
    String field="";
    field = url + keydata;
    const char *command  = field.c_str();
    request = QNetworkRequest(QUrl(command));
    //request = QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));

    // connect to signal  when its done using lambda)
    reply = m_manager.get(request);
    qDebug() << "run data firebase connect ok ";
    // send data
    obj.insert("rate", value);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postRequest = m_manager.post(request, QJsonDocument(obj).toJson());
}

void studying::onResult(QNetworkReply*) {
//    QString ReplyText = reply->readAll();
//    qDebug() << ReplyText;
//    // ask doc to parse it
//    QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
//    // we know first element in file is object, to try to ask for such

//    QString data = doc.toJson();
    qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //qDebug() << "get data" << data;

    QJsonDocument doc_post = QJsonDocument::fromJson(postRequest->readAll());
    QJsonObject objdata = doc_post.object();
    if (objdata.value("status").toString() == "ok") {
        qDebug() << "post finish";
    } else {
      qWarning() << "ERROR" << objdata.value("error").toString();
    }

}








