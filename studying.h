#ifndef STUDYING_H
#define STUDYING_H

#include <QWidget>
#include "include.h"
#include <play_audio.h>
#define num 10

namespace Ui {
class studying;
}

class studying : public QWidget
{
    Q_OBJECT

public:
    explicit studying(QWidget *parent = 0);
    ~studying();

signals:
    void homeClicked();
    void send_data();

public slots:
    void next_page();
    void next_page2();

    void on_home_clicked();



private slots:
    void on_home_2_clicked();

    void on_home_3_clicked();

    void on_home_4_clicked();

    void on_next_3_clicked();

    void on_next_4_clicked();

    void on_next_5_clicked();

    void on_next_6_clicked();
    void onResult(QNetworkReply*);

private:
    Ui::studying *ui;
    play_audio audio_ht;
};

#endif // STUDYING_H
