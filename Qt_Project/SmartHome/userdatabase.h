#ifndef USERDATABASE_H
#define USERDATABASE_H


#include <QObject>

class UserDataBase : public QObject
{
    Q_OBJECT
public:
    static UserDataBase *getUserDataBase();
    bool addRegisterUser(const QString &username,const QString & password,const QString &phone);
    bool queryUsername(const QString &username);
    bool Checkusernamepassword(const QString &username,const QString &password);
    bool queryTelephone(const QString &phone);

signals:

public slots:

private:
    explicit UserDataBase(QObject *parent = nullptr);
    static   UserDataBase *userDb;
};

#endif // USERDATABASE_H
