#ifndef ROOMWINDOW_H
#define ROOMWINDOW_H

#include <QMainWindow>

namespace Ui {
class RoomWindow;
}

class RoomWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomWindow(QWidget *parent = 0);
    ~RoomWindow();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::RoomWindow *ui;
    int flag;
};

#endif // ROOMWINDOW_H
