#ifndef PLAYMEDIA_H
#define PLAYMEDIA_H

#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QSlider>
#include <QLineEdit>

namespace Ui {
class PlayMedia;
}

class PlayMedia : public QDialog
{
    Q_OBJECT

public:
    explicit PlayMedia(QWidget *parent = 0);
    ~PlayMedia();

private slots:
    void on_play_pause_Button_pressed();

    void on_fwd_Button_clicked();

    void on_rew_Button_clicked();

    void on_end_Button_clicked();

    void on_pushButton_clicked();

    void on_addsong_pushButton_clicked();

    void setLineEditValue(int value);
private:
    Ui::PlayMedia *ui;
    QMediaPlaylist *playlist;//播放列表
    QMediaPlayer *player;//播放器
    QString mediaPath;//媒体路径
    int flag_start;//标志位
    QTableWidgetItem *item;//歌曲表单控件
};

#endif // PLAYMEDIA_H
