#ifndef AIRHTTP_H
#define AIRHTTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>

class Airhttp : public QObject
{
    Q_OBJECT
public:
    explicit Airhttp(QObject *parent = nullptr);
    void requestAirData(const QString &city);
    void parseAirData(const QByteArray &data);
    QString parseWindPower(const QString &windpower);//解析风力

signals:
    void readyWind(const QString &wind);
    void readyTemp(const QString &temp);
    void readyAirType(const QString &airType);

public slots:
    void readAirData(void);

private:
    QNetworkAccessManager *networkManager;

};

#endif // AIRHTTP_H
