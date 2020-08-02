#include "activity.h"
#include "ui_activity.h"
#include <QObject>

String keydata2[num_activity] = {"boIch.json","capNhatCtxh.json","damBaoNhuCauCtxh.json","toChucPt.json","toChucThuongXuyen.json"};
QNetworkAccessManager m_manager2;
string url2 = "https://thesis-24eab.firebaseio.com/hoatDong/";

QNetworkRequest request2; // QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));
QNetworkReply* reply2;
QNetworkReply* postRequest2;
QJsonObject obj2;

int hd[num_activity];
void func2(String keydata, int value);

activity::activity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::activity)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(&m_manager2, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult2(QNetworkReply*)));
}

activity::~activity()
{
    delete ui;
}

void activity::on_next_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    audio_hd.i = 31;
    audio_hd.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra1_1,1);
    gr1->addButton(ui->ra1_2,2);
    gr1->addButton(ui->ra1_3,3);
    gr1->addButton(ui->ra1_4,4);
    hd[0] = gr1->checkedId();
    func2(keydata2[0],hd[0]);
    qDebug() << hd[0];
}

void activity::on_next_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    audio_hd.i = 32;
    audio_hd.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra2_1,1);
    gr1->addButton(ui->ra2_2,2);
    gr1->addButton(ui->ra2_3,3);
    gr1->addButton(ui->ra2_4,4);
    hd[1] = gr1->checkedId();
    func2(keydata2[1],hd[1]);
    qDebug() << hd[1];
}

void activity::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    audio_hd.i = 33;
    audio_hd.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra3_1,1);
    gr1->addButton(ui->ra3_2,2);
    gr1->addButton(ui->ra3_3,3);
    gr1->addButton(ui->ra3_4,4);
    hd[2] = gr1->checkedId();
    func2(keydata2[2],hd[2]);
    qDebug() << hd[2];
}

void activity::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    audio_hd.i = 34;
    audio_hd.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra3_5,1);
    gr1->addButton(ui->ra3_6,2);
    gr1->addButton(ui->ra3_7,3);
    gr1->addButton(ui->ra3_8,4);
    hd[3] = gr1->checkedId();
    func2(keydata2[3],hd[3]);
    qDebug() << hd[3];
}

void activity::on_home_3_clicked()
{
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra3_9,1);
    gr1->addButton(ui->ra3_10,2);
    gr1->addButton(ui->ra3_11,3);
    gr1->addButton(ui->ra3_12,4);
    hd[4] = gr1->checkedId();
    func2(keydata2[4],hd[4]);
    qDebug() << hd[4];
    ui->stackedWidget->setCurrentIndex(0);
    emit homeClicked2();
}


void func2(String keydata, int value){
    qDebug() << "run func connect ok ";
    String field="";
    field = url2 + keydata;
    const char *command  = field.c_str();
    request2 = QNetworkRequest(QUrl(command));
    //request = QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));

    // connect to signal  when its done using lambda)
    reply2 = m_manager2.get(request2);
    qDebug() << "run data firebase connect ok ";
    // send data
    obj2.insert("rate", value);
    request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postRequest2 = m_manager2.post(request2, QJsonDocument(obj2).toJson());
}

void activity::onResult2(QNetworkReply*) {
//    QString ReplyText = reply->readAll();
//    qDebug() << ReplyText;
//    // ask doc to parse it
//    QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
//    // we know first element in file is object, to try to ask for such

//    QString data = doc.toJson();
    qDebug() << reply2->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //qDebug() << "get data" << data;

    QJsonDocument doc_post = QJsonDocument::fromJson(postRequest2->readAll());
    QJsonObject objdata = doc_post.object();
    if (objdata.value("status").toString() == "ok") {
        qDebug() << "post finish";
    } else {
      qWarning() << "ERROR" << objdata.value("error").toString();
    }
    // make sure to clean up
    //postRequest->deleteLater();
}






