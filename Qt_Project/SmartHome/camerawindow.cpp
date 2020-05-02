#include "camerawindow.h"
#include "ui_camerawindow.h"


CameraWindow::CameraWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraWindow)
{
    ui->setupUi(this);
    camera = new QCamera;
    imageCapture =new QCameraImageCapture(camera); //图片捕获

    camera->setViewfinder(ui->camerawidget);//设置显示区域
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);//设置捕获的目的
    camera->setCaptureMode(QCamera::CaptureStillImage);//设置捕获模式为将捕获的图片作为文件

    connect(imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(cameraImageCaptured(int,QImage)));
    connect(ui->pushButton_3,SIGNAL(clicked()),imageCapture,SLOT(capture())); //将按键和图片捕获的槽函数绑定，点击按钮进行拍照
}

CameraWindow::~CameraWindow()
{
    delete ui;
}

void CameraWindow::on_pushButton_clicked()
{
    camera->start();
}

void CameraWindow::on_pushButton_2_clicked()
{
    camera->stop();
}

void CameraWindow::cameraImageCaptured(int, QImage image)
{
    //保存图片格式，路径
    QString savepath=QFileDialog::getSaveFileName(this,"Save Capture","Capture",
                                                  "Image png(*.png);;Image jpg(*.jpe);;Image bmp(*.bmp)");
    if(!savepath.isEmpty()){
        image.save(savepath);
    }
}



