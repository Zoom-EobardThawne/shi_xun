#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>


namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

private slots:
    void on_registerushButton_clicked();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
