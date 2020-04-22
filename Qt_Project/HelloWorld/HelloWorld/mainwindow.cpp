#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);              //设置好界面之后进行操作
    ui->pushButton->setText("Hello World");
    //连接信号与槽
    connect(this,SIGNAL (mySignal_1()),this,SLOT(mySlot_1()));
    connect(this,SIGNAL (mySignal_2()),this,SLOT(mySlot_2()));
    //手动连接
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(mySlot_1()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(mySlot_2()));
    //发送信号
   // emit mySignal_1();
   //emit mySignal_2();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//槽函数的实现
void MainWindow::mySlot_1()
{
    qDebug() <<"call mySlot_1()";
}

void MainWindow::mySlot_2()
{
    qDebug() <<"call mySlot_2()";
}
//自动连接
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked()";
}
