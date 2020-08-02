#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include.h"
#include "first_page.h"
#include "play_audio.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void open_camera();

private slots:
    void pressed_button();
    void back();

public:
    Ui::MainWindow *ui;
    first_page page1;
    play_audio audio;
};

#endif // MAINWINDOW_H
