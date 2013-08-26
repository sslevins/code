#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QTime>
#include <QTimer>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
   void playOrPause();
   void back_message_slots();
   void get_time_pos();
   void seek(int value);
   void openVideo(bool);
   void stop();
   void kuaijin();
   void kuaitui();
   void addFileList();
   void selectFile();
   void prevVideo();
   void nextVideo();
   void MuteOrNot(bool);
   void soundAdd();
   void soundSub();

private:
    Ui::Widget *ui;
    QProcess *process;
    bool playStatus;
    bool pauseStatus;
    int curr_time;
    int fileLength;
    QTime int_to_time(int);
    QTimer * timer;
    QStringList fileList;

};

#endif // WIDGET_H
