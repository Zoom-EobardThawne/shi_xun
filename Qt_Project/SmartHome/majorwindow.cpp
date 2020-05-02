#include "majorwindow.h"
#include "ui_majorwindow.h"



MajorWindow::MajorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MajorWindow)
{
    ui->setupUi(this);
    //新建一个天气的信息对象
    airHttp =new Airhttp;
    //显示天气信息的信号与槽连接
    connect(airHttp,SIGNAL(readyTemp(QString)),this,SLOT(displayTemperature(QString)));
    connect(airHttp,SIGNAL(readyWind(QString)),this,SLOT(displayWind(QString)));
    connect(airHttp,SIGNAL(readyAirType(QString)),this,SLOT(displayType(QString)));
    //airHttp->requestAirData("%E6%AD%A6%E6%B1%89");

    //用定时器定时的发送信号
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

    //视频监控
    cameraWindow = new CameraWindow;
    //多媒体界面
    play =new PlayMedia;
    //房间窗口
    room = new RoomWindow;
}

MajorWindow::~MajorWindow()
{
    delete ui;
    delete airHttp;
    delete timer;
    delete cameraWindow;
    delete play;
    delete room;
    timer->stop();
}

void MajorWindow::displayMajorwindow()
{
    this->show();
    airHttp->requestAirData("%E6%AD%A6%E6%B1%89");
}
// 点击设备管理按钮跳转到roomwindow窗口
void MajorWindow::on_pushButton_9_clicked()
{
    room->show();
    this->close();
}
//日期和时间显示
void MajorWindow::timerUpdate(void)
{   //在LCDnumber_4显示时间
    QTime time = QTime::currentTime();
    QString t_str = time.toString("hh:mm:ss");
    ui->lcdNumber_4->display(t_str);
    //在label_12显示日期
    QDateTime date = QDateTime::currentDateTime();
    QString d_str = date.toString("yyyy-MM-dd\n     dddd");
    ui->label_12->setText(d_str);
}
//点击多媒体播放音乐
void MajorWindow::on_pushButton_8_clicked()
{
    play->show();
    this->close();
}
//输入城市名称
void MajorWindow::on_lineEdit_returnPressed()
{
    QString city = ui->lineEdit->text();
    airHttp->requestAirData(city.toUtf8().toPercentEncoding());
}
//显示温度
void MajorWindow::displayTemperature(const QString &temperature)
{
    ui->TempLabel->setText(temperature);
}
//显示风力风向
void MajorWindow::displayWind(const QString &wind)
{
    ui->WindLabel->setText(wind);
}
//显示天气类型
void MajorWindow::displayType(const QString &type)
{
    ui->TypeLabel->setText(type);
}

//显示视频界面
void MajorWindow::on_pushButton_7_clicked()
{
    cameraWindow->show();
}
