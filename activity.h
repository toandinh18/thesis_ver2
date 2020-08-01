#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QWidget>
#include "include.h"
#include <play_audio.h>
#define num_activity 5

namespace Ui {
class activity;
}

class activity : public QWidget
{
    Q_OBJECT

public:
    explicit activity(QWidget *parent = 0);
    ~activity();

signals:
    void homeClicked2();

private slots:
    void on_next_clicked();
    void on_next_2_clicked();
    void onResult2(QNetworkReply*);
    void on_home_clicked();

    void on_home_2_clicked();

    void on_home_3_clicked();

private:
    Ui::activity *ui;
    play_audio audio_hd;
};

#endif // ACTIVITY_H
