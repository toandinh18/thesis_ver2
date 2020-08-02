#ifndef FIRST_PAGE_H
#define FIRST_PAGE_H

#include <QWidget>
#include "include.h"
#include "welcome_page.h"
#include "final.h"

namespace Ui {
class first_page;
}

class first_page : public QWidget
{
    Q_OBJECT

public:
    explicit first_page(QWidget *parent = 0);
    ~first_page();

signals:
    void signal_back_to_main();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void call_back_first();
    void update_page();

private:
    Ui::first_page *ui;
    welcome_page welcome_page1;
    Final final_page;
    play_audio audio2;
};

#endif // FIRST_PAGE_H
