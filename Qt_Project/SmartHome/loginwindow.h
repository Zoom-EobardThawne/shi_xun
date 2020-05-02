#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include "registerwindow.h"
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:

   void on_loginButton_clicked();

   void on_toolButton_clicked();

private:
    Ui::LoginWindow *ui;
    RegisterWindow *regist;//注册界面

};

#endif // LOGINWINDOW_H
