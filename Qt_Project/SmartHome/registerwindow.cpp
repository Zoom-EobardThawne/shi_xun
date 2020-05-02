#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "userdatabase.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
//注册按钮
void RegisterWindow::on_registerushButton_clicked()
{
    QString username = ui->usernamelineEdit->text();
    QString password = ui->passwordlineEdit->text();
    QString phone    = ui->telephonelineEdit->text();
    
 
    UserDataBase *userDb = UserDataBase::getUserDataBase();
    
    if(userDb->queryUsername(username)){
       QMessageBox::information(NULL,"注册","注册失败用户名已存在",QMessageBox::Ok);
        return ;
    }
    if(userDb->queryTelephone(phone)){
       QMessageBox::information(NULL,"注册","注册失败电话已存在",QMessageBox::Ok);
        return ;
    }
    
    bool ok = userDb->addRegisterUser(username,password,phone);
    if(!ok){
         QMessageBox::information(NULL,"注册","注册失败",QMessageBox::Ok);
    }else{
         QMessageBox::information(NULL,"注册","注册成功",QMessageBox::Ok);
         }

}
