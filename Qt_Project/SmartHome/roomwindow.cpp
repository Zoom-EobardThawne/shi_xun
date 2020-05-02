#include "roomwindow.h"
#include "ui_roomwindow.h"
#include "majorwindow.h"

RoomWindow::RoomWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);
    flag = 1;
}

RoomWindow::~RoomWindow()
{
    delete ui;
}

void RoomWindow::on_pushButton_clicked()
{
    MajorWindow * major = new MajorWindow;
    major->show();
    this->close();
}

void RoomWindow::on_toolButton_clicked()
{
    if(flag)
    {   //设置样式
        ui->toolButton->setStyleSheet("border-image: url(:/image/room/ON.png);");
        ui->widget_2->setStyleSheet("border-image: url(:/image/room/openled_ico.png);");
        flag = 0;
    }
    else
    {
        ui->toolButton->setStyleSheet("border-image: url(:/image/room/OFF.png);");
        ui->widget_2->setStyleSheet("border-image: url(:/image/room/closeled_ico.png);");
        flag= 1;
    }
}

void RoomWindow::on_toolButton_2_clicked()
{

    if(flag)
    {   //设置样式
        ui->toolButton_2->setStyleSheet("border-image: url(:/image/room/ON.png);");
        ui->widget_3->setStyleSheet("border-image: url(:/image/room/openled_ico.png);");
        flag = 0;
    }
    else
    {
        ui->toolButton_2->setStyleSheet("border-image: url(:/image/room/OFF.png);");
        ui->widget_3->setStyleSheet("border-image: url(:/image/room/closeled_ico.png);");
        flag= 1;
    }
}

void RoomWindow::on_toolButton_3_clicked()
{
    if(flag)
    {   //设置样式
        ui->toolButton_3->setStyleSheet("border-image: url(:/image/room/ON.png);");
        ui->widget_4->setStyleSheet("border-image: url(:/image/room/openfan_ico.png);");
        flag = 0;
    }
    else
    {
        ui->toolButton_3->setStyleSheet("border-image: url(:/image/room/OFF.png);");
        ui->widget_4->setStyleSheet("border-image: url(:/image/room/closefan_ico.png);");
        flag= 1;
    }
}

void RoomWindow::on_toolButton_4_clicked()
{
    if(flag)
    {   //设置样式
        ui->toolButton_4->setStyleSheet("border-image: url(:/image/room/ON.png);");
        ui->widget_5->setStyleSheet("border-image: url(:/image/room/opendoor_ico.png);");
        flag = 0;
    }
    else
    {
        ui->toolButton_4->setStyleSheet("border-image: url(:/image/room/OFF.png);");
        ui->widget_5->setStyleSheet("border-image: url(:/my_image/Door.png);");
        flag= 1;
    }
}
