#include "playmedia.h"
#include "ui_playmedia.h"
#include "majorwindow.h"
#include <QDir>
#include <QTableWidgetItem>
#include <QFileDialog>

PlayMedia::PlayMedia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayMedia)
{
    ui->setupUi(this);

    flag_start = 1;

    //歌曲列表
    playlist = new QMediaPlaylist;
    //播放器
    player = new QMediaPlayer;
    //表单控件
    item = new QTableWidgetItem();

    /***音量控制滑块****/
    //设置滑动条控件的最小值
    ui->horizontalSlider->setMinimum(0);
    //设置滑动条控件的最大值
     ui->horizontalSlider->setMaximum(100);
    //设置滑动条控件的值
     ui->horizontalSlider->setValue(50);

    //信号和槽 当滑动条的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件的显示文本
    connect( ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue(int)));






    /*******tablewidget设置******************/
    //设置表头高度
    ui->tableWidget->horizontalHeader()->setFixedHeight(30);
    //设置表头背景颜色
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:pink;}");
    //设置表头字体加粗
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    //设置表头自适应宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //item->setIcon(icon); //icon为图标
    //item->setText(name); //显示的文本
    //设置样式为灰色
    QColor color("gray");
    item->setTextColor(color);//文本颜色
    //设置表格不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置选择的时候每次选择一行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //取消表头的在选中单元格时的高亮状态。
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

#if 0
    playlist->addMedia(QUrl::fromLocalFile("F:/Kugou/英语/Avril Lavigne - Head Above Water.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("../Avril Lavigne - I Fell In Love With The Devil (Radio Edit).mp3"));
    playlist->addMedia(QUrl::fromLocalFile("../EGOIST - エウテルペ (欧忒耳佩).mp3"));

    //playlist->addMedia(QUrl::fromLocalFile("F:/Kugou/英语/Avril Lavigne - Head Above Water.mp3"));
    //player->setPlaylist(playlist);
#endif

}

PlayMedia::~PlayMedia()
{
    delete ui;
}

//点击添加歌曲按钮打开对话框添加歌曲
void PlayMedia::on_addsong_pushButton_clicked()
{
    QString fileFull = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath(),"text(*.mp3)");//获取文件完整路径
    QFileInfo fileinfo = QFileInfo(fileFull);//文件信息对象
    QString filename = fileinfo.fileName();//获取文件名称

    qDebug() << fileFull;
    qDebug() << filename;

    /* 如果是空文件 弹出提示*/
    if(fileFull.isEmpty())
    {
        QMessageBox::information(this,"Warning Message!","Please select a file");
        return;
    }
    /**********将所选的文件添加到播放列表中**********/
    playlist->addMedia(QUrl::fromLocalFile(fileFull));
    player->setPlaylist(playlist);


    int row_count = ui->tableWidget->rowCount(); //获取表单行数
    ui->tableWidget->insertRow(row_count); //插入新行
    ui->tableWidget->setItem(row_count, 0, new QTableWidgetItem(filename));//设置这一行的第一列数
}
//音量控制
void PlayMedia::setLineEditValue(int value)
{
    int pos = ui->horizontalSlider->value();
    QString str = QString("%1").arg(pos);
    ui->lineEdit->setText(str);
    player->setVolume(value);
}

//播放按钮
void PlayMedia::on_play_pause_Button_pressed()
{
    if(playlist->isEmpty())
    {
        QMessageBox::warning(NULL,"Warning","playlist NULL!");
    }else
    {
        int currentIndex = playlist->currentIndex();
        ui->tableWidget->item(currentIndex,0)->setSelected(true);
        player->setVolume(50);
        if(flag_start)
        {   //设置样式
            ui->play_pause_Button->setStyleSheet("border-image: url(:/my_image/Player Pause.ico);");
            player->play();
            flag_start = 0;
        }
        else
        {
            ui->play_pause_Button->setStyleSheet("border-image: url(:/my_image/Player Play.ico);");
            player->pause();
            flag_start = 1;
        }
    }
}
//上一首
void PlayMedia::on_fwd_Button_clicked()
{
    if(playlist->isEmpty())
    {
        QMessageBox::warning(NULL,"Warning","playlist NULL!");
    }else
    {
        int currentIndex = playlist->currentIndex();
        ui->tableWidget->item(currentIndex,0)->setSelected(false);

        if(--currentIndex < 0)
        {
            QMessageBox::information(this,"Information","It's the first song!");
            currentIndex = 0;
        }
        ui->tableWidget->item(currentIndex,0)->setSelected(true);
        playlist->setCurrentIndex(currentIndex);
        player->play();
    }
}

//下一首
void PlayMedia::on_rew_Button_clicked()
{
    if(playlist->isEmpty())
    {
        QMessageBox::warning(NULL,"Warning","playlist NULL!");
    }else
    {
        int currentIndex = playlist->currentIndex();
        ui->tableWidget->item(currentIndex,0)->setSelected(false);
        if(++currentIndex == playlist->mediaCount())
        {
            QMessageBox::information(this,"Information","It's the last song!");
            currentIndex = 0;
        }
        ui->tableWidget->item(currentIndex,0)->setSelected(true);
        playlist->setCurrentIndex(currentIndex);
        player->play();
    }
}
//停止播放
void PlayMedia::on_end_Button_clicked()
{
    ui->play_pause_Button->setStyleSheet("border-image: url(:/my_image/Player Play.ico);");
    player->stop();
}
//返回主菜单
void PlayMedia::on_pushButton_clicked()
{
    MajorWindow * major = new MajorWindow;
    major->show();
    this->close();
    player->stop();
}

