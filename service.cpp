#include "service.h"
#include "ui_service.h"
#include <QObject>

String keydata1[num_service] = {"dichVuCanteen.json","dichVuInBangDiem.json","dichVuNuocUong.json","quyTrinhSach.json","suTienNghi.json","thaiDoNhanVien.json","thaiDoNhanVienCanteen.json","thaiDoPhucVu.json","tratTu.json"};
QNetworkAccessManager m_manager1;
string url1 = "https://thesis-24eab.firebaseio.com/dichVu/";

QNetworkRequest request1; // QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));
QNetworkReply* reply1;
QNetworkReply* postRequest1;
QJsonObject obj1;

int dichvu[num_service];
void func1(String keydata, int value);

service::service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::service)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(&m_manager1, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult1(QNetworkReply*)));
}

service::~service()
{
    delete ui;
}

void service::on_next_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    audio_dv.i = 21;
    audio_dv.start();
    QButtonGroup *gr1 = new QButtonGroup(this);
    gr1->addButton(ui->ra1_1,1);
    gr1->addButton(ui->ra1_2,2);
    gr1->addButton(ui->ra1_3,3);
    gr1->addButton(ui->ra1_4,4);
    dichvu[0] = gr1->checkedId();
    func1(keydata1[0],dichvu[0]);
    qDebug() << dichvu[0];
    qDebug() << gr1->checkedButton();
}


void service::on_next_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    audio_dv.i = 22;
    audio_dv.start();
    QButtonGroup *gr2 = new QButtonGroup(this);
    gr2->addButton(ui->ra2_1,1);
    gr2->addButton(ui->ra2_2,2);
    gr2->addButton(ui->ra2_3,3);
    gr2->addButton(ui->ra2_4,4);
    dichvu[1] = gr2->checkedId();
    func1(keydata1[1],dichvu[1]);
    qDebug() << dichvu[1];
    qDebug() << gr2->checkedButton();
}

void service::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    audio_dv.i = 23;
    audio_dv.start();
    QButtonGroup *gr3 = new QButtonGroup(this);
    gr3->addButton(ui->ra3_1,1);
    gr3->addButton(ui->ra3_2,2);
    gr3->addButton(ui->ra3_3,3);
    gr3->addButton(ui->ra3_4,4);
    dichvu[2] = gr3->checkedId();
    func1(keydata1[2],dichvu[2]);
    qDebug() << dichvu[2];
}

void service::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    audio_dv.i = 24;
    audio_dv.start();
    QButtonGroup *gr4 = new QButtonGroup(this);
    gr4->addButton(ui->ra3_5,1);
    gr4->addButton(ui->ra3_6,2);
    gr4->addButton(ui->ra3_7,3);
    gr4->addButton(ui->ra3_8,4);
    dichvu[3] = gr4->checkedId();
    func1(keydata1[3],dichvu[3]);
    qDebug() << dichvu[3];
}

void service::on_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    audio_dv.i = 25;
    audio_dv.start();
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra3_9,1);
    gr5->addButton(ui->ra3_10,2);
    gr5->addButton(ui->ra3_11,3);
    gr5->addButton(ui->ra3_12,4);
    dichvu[4] = gr5->checkedId();
    func1(keydata1[4],dichvu[4]);
    qDebug() << dichvu[4];
}

void service::on_home_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    audio_dv.i = 26;
    audio_dv.start();
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra3_13,1);
    gr5->addButton(ui->ra3_14,2);
    gr5->addButton(ui->ra3_15,3);
    gr5->addButton(ui->ra3_16,4);
    dichvu[5] = gr5->checkedId();
    func1(keydata1[5],dichvu[5]);
    qDebug() << dichvu[5];
}

void service::on_next_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    audio_dv.i = 27;
    audio_dv.start();
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_5,1);
    gr5->addButton(ui->ra1_6,2);
    gr5->addButton(ui->ra1_7,3);
    gr5->addButton(ui->ra1_8,4);
    dichvu[6] = gr5->checkedId();
    func1(keydata1[6],dichvu[6]);
    qDebug() << dichvu[6];
}

void service::on_next_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    audio_dv.i = 28;
    audio_dv.start();
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_9,1);
    gr5->addButton(ui->ra1_10,2);
    gr5->addButton(ui->ra1_11,3);
    gr5->addButton(ui->ra1_12,4);
    dichvu[7] = gr5->checkedId();
    func1(keydata1[7],dichvu[7]);
    qDebug() << dichvu[7];
}

void service::on_next_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    QButtonGroup *gr5 = new QButtonGroup(this);
    gr5->addButton(ui->ra1_13,1);
    gr5->addButton(ui->ra1_14,2);
    gr5->addButton(ui->ra1_15,3);
    gr5->addButton(ui->ra1_16,4);
    dichvu[8] = gr5->checkedId();
    func1(keydata1[8],dichvu[8]);
    qDebug() << dichvu[8];
    //postRequest1->deleteLater();
    emit homeClicked1();
}


void func1(String keydata, int value){
    qDebug() << "run func connect ok ";
    String field="";
    field = url1 + keydata;
    const char *command  = field.c_str();
    request1 = QNetworkRequest(QUrl(command));
    //request = QNetworkRequest(QUrl("https://thesis-24eab.firebaseio.com/hocTap/nhaVeSinh.json"));

    // connect to signal  when its done using lambda)
    reply1 = m_manager1.get(request1);
    qDebug() << "run data firebase connect ok ";
    // send data
    obj1.insert("rate", value);
    request1.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postRequest1 = m_manager1.post(request1, QJsonDocument(obj1).toJson());
}

void service::onResult1(QNetworkReply*) {
//    QString ReplyText = reply->readAll();
//    qDebug() << ReplyText;
//    // ask doc to parse it
//    QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
//    // we know first element in file is object, to try to ask for such

//    QString data = doc.toJson();
    qDebug() << reply1->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //qDebug() << "get data" << data;

    QJsonDocument doc_post = QJsonDocument::fromJson(postRequest1->readAll());
    QJsonObject objdata = doc_post.object();
    if (objdata.value("status").toString() == "ok") {
        qDebug() << "post finish";
    } else {
      qWarning() << "ERROR" << objdata.value("error").toString();
    }
    // make sure to clean up
    //postRequest->deleteLater();
}
