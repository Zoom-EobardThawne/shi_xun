#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include <QWidget>
#include <QCamera>
#include <QString>
#include <QImage>
#include <QFileDialog>
#include <QCameraImageCapture>


namespace Ui {
class CameraWindow;
}

class CameraWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CameraWindow(QWidget *parent = 0);
    ~CameraWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void cameraImageCaptured(int,QImage image);



private:
    Ui::CameraWindow *ui;
    QCamera *camera;
    QCameraImageCapture* imageCapture;
};

#endif // CAMERAWINDOW_H
