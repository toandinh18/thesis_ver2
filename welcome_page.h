#ifndef WELCOME_PAGE_H
#define WELCOME_PAGE_H

#include <QWidget>
#include "include.h"
#include "studying.h"
#include "activity.h"
#include "service.h"
#include "final.h"
#include "play_audio.h"

namespace Ui {
class welcome_page;
}

class welcome_page : public QWidget
{
    Q_OBJECT

public:
    explicit welcome_page(QWidget *parent = 0);
    ~welcome_page();

signals:
    void signal_call_final();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void moveHome();

    void on_pushButton_4_clicked();


private:
    Ui::welcome_page *ui;
    studying study_page;
    service service_page;
    activity activity_page;
    play_audio play_first;
};

#endif // WELCOME_PAGE_H
