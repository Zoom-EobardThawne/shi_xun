#ifndef MAJORWINDOW_H
#define MAJORWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QLCDNumber>
#include <QTime>
#include "airhttp.h"
#include "camerawindow.h"
#include "playmedia.h"
#include "roomwindow.h"

namespace Ui {
class MajorWindow;
}

class MajorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MajorWindow(QWidget *parent = 0);
    ~MajorWindow();
    void displayMajorwindow();
private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_lineEdit_returnPressed();

    void timerUpdate(void);//时间日期显示槽函数
    void displayTemperature(const QString &temperature);//显示温度信息槽函数
    void displayWind(const QString &wind);//显示风力信息槽函数
    void displayType(const QString &type);//显示天气类型信息槽函数
    void on_pushButton_7_clicked();

private:
    Ui::MajorWindow *ui;
    PlayMedia *play;//多媒体窗口
    QTimer *timer;//定时器
    Airhttp *airHttp;//天气接口对象
    CameraWindow *cameraWindow;//摄像头界面
    RoomWindow *room;

};

#endif // MAJORWINDOW_H
