#include "userdatabase.h"
#include "QSqlDatabase"
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

UserDataBase *UserDataBase :: userDb = NULL;
//打开本地的数据库
UserDataBase::UserDataBase(QObject *parent) : QObject(parent)
{
    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE","smart_home_db");
    db.setDatabaseName("F:\\Qt_Project\\SmartHome\\SmartHome.db");
    bool ok = db.open();
    if(!ok){
        qDebug()<< "Fail to open database,error:" << db.lastError().text();
    }
}
//用户数据构造
UserDataBase *UserDataBase::getUserDataBase()
{
    if(!userDb){
        userDb = new UserDataBase;
    }

    return userDb;
}
//添加注册用户信息
bool UserDataBase::addRegisterUser(const QString &username, const QString &password, const QString &phone)
{
      QSqlDatabase db = QSqlDatabase :: database("smart_home_db");
      QSqlQuery query(db);
      query.prepare("INSERT INTO User(username,password,phone)"
                    "VALUES(?,?,?)");
      query.addBindValue(username);
      query.addBindValue(password);
      query.addBindValue(phone);
      bool ok = query.exec();
      if (!ok){
          qDebug() << "Fail add regiser user:"<<query.lastError().text();
      }

      return ok;
}
//用户名查询
bool UserDataBase::queryUsername(const QString &username)
{
    QSqlDatabase db = QSqlDatabase :: database("smart_home_db");
    QSqlQuery query(db);
    query.prepare("select * from User where username=?");
    query.addBindValue(username);
    
    bool ok = query.exec();
    if (!ok){
        qDebug() << "Fail add regiser user:"<<query.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }else{
        return false;
    }

    return ok;
}
//密码是否正确查询
bool UserDataBase::Checkusernamepassword(const QString &username,const QString &password)
{
    QSqlDatabase db = QSqlDatabase :: database("smart_home_db");
    QSqlQuery query(db);
    query.prepare("select * from User where username =? and password=?");
    query.addBindValue(username);
    query.addBindValue(password);

    bool ok = query.exec();
    if (!ok){
        qDebug() << "Fail add regiser user:"<<query.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }else{
        return false;
    }

    return ok;
}
//电话号码查询
bool UserDataBase::queryTelephone(const QString &phone)
{
    QSqlDatabase db = QSqlDatabase :: database("smart_home_db");
    QSqlQuery query(db);
    query.prepare("select * from User where phone=?");
    query.addBindValue(phone);
    
    bool ok = query.exec();
    if (!ok){
        qDebug() << "Fail add regiser user:"<<query.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }else{
        return false;
    }

    return ok;
}


