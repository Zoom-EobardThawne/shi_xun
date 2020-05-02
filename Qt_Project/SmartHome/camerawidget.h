#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QObject>
#include <QVideoWidget>
#include "majorwindow.h"

class CameraWidget : public QVideoWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // CAMERAWIDGET_H
