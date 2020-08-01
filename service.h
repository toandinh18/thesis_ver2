#ifndef SERVICE_H
#define SERVICE_H

#include <QWidget>
#include "include.h"
#include "play_audio.h"
#define num_service 9

namespace Ui {
class service;
}

class service : public QWidget
{
    Q_OBJECT

public:
    explicit service(QWidget *parent = 0);
    ~service();

signals:
    void homeClicked1();

private slots:
    void on_next_clicked();

    void on_next_2_clicked();

    void on_home_clicked();

    void on_home_2_clicked();

    void on_home_3_clicked();

    void on_home_4_clicked();

    void on_next_3_clicked();

    void on_next_4_clicked();

    void on_next_5_clicked();

private slots:
    void onResult1(QNetworkReply*);

private:
    Ui::service *ui;
    play_audio audio_dv;
};

#endif // SERVICE_H
