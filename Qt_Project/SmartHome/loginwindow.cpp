#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "majorwindow.h"
#include "registerwindow.h"
#include "userdatabase.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    regist = new RegisterWindow;//注册窗口

}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete regist;
}

//点击登录
void LoginWindow::on_loginButton_clicked()
{
    UserDataBase *userDb = UserDataBase::getUserDataBase();

    //用户名或密码为空
    if(ui->lineEdit->text().trimmed()==(NULL)||
       ui->lineEdit_2->text().trimmed()==(NULL))
    {
       QMessageBox::warning(NULL,"Warning","user name or password NULL!");
    }
    //密码正确
    else if( userDb->Checkusernamepassword(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {//if判断是否用户名和密码同时可被查询到
        QMessageBox* box = new  QMessageBox;
        QTimer::singleShot(2000, box, SLOT(close()));
        //消息框三秒关闭
        box->setWindowTitle("Information");
        box->setIcon(QMessageBox::Information);
        box->setText("Login Successful!");
        box->show();
        //进入主界面
        MajorWindow * major = new MajorWindow;
        major->displayMajorwindow();
        this->close();
    }
    //密码错误
    else
    {
        QMessageBox::warning(NULL,"Warning","user name or password ERROR!");
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setFocus();
    }
}

//注册按钮
void LoginWindow::on_toolButton_clicked()
{
   regist->show();
}


