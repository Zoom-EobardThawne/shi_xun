#include "airhttp.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

Airhttp::Airhttp(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager;
}
//返回天气信息
void Airhttp::requestAirData(const QString &city)
{
    QString httpUrl = "http://wthrcdn.etouch.cn/weather_mini?city=" + city;
    QNetworkRequest httpRequest(httpUrl);
    QNetworkReply *httpReply = networkManager->get(httpRequest);

    connect(httpReply,SIGNAL(finished()),this,SLOT(readAirData()));
    connect(httpReply,SIGNAL(finished()),httpReply,SLOT(deleteLater()));
}

void Airhttp::parseAirData(const QByteArray &data)
{
    //json object  <---> json document  <----> json data
       QJsonDocument jsonDoc  = QJsonDocument::fromJson(data);
       QJsonObject jsonObject = jsonDoc.object();
       QJsonObject dataObject = jsonObject["data"].toObject();
       QJsonArray  forecastArray = dataObject["forecast"].toArray();
       QJsonObject currentDayObject = forecastArray[0].toObject();
       QString  highTemperature =currentDayObject["high"].toString();
       QString  lowTemperature  =currentDayObject["low"].toString();
       QString  windPower       =currentDayObject["fengli"].toString();
       QString  windDirection   =currentDayObject["fengxiang"].toString();
       QString  airType         =currentDayObject["type"].toString();

       QString temperature = QString("%1~\n%2").arg(lowTemperature).arg(highTemperature);
       QString wind        = windDirection +parseWindPower(windPower);

       emit readyTemp(temperature);
       emit readyWind(wind);
       emit readyAirType(airType);

#if 0
       qDebug() << "highTemperature : " << highTemperature;
       qDebug() << "lowTemperature  : " << lowTemperature;
       qDebug() << "windDirection   : " << windDirection;
       qDebug() << "windPower       : " << windPower;
       qDebug() << "airType         : " << airType;
#endif
}

QString Airhttp::parseWindPower(const QString &windpower)
{
    QStringList windList = windpower.split('[');
    QString power = windList[2];
    int i;
    for(i=0;i<power.size();i++){
        if(power.at(i)==']'){
            break;
        }
    }
    return power.left(i);
}
//读取当前的返回信息
void Airhttp::readAirData()
{   //在槽函数中获取发送信号的对象
    QNetworkReply *httpReply =(QNetworkReply *)this->sender();

    QByteArray data = httpReply->readAll();
    parseAirData(data);

}



