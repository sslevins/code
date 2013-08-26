#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>


Widget::Widget(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::Widget)
{
		ui->setupUi(this);

		this->playStatus = false;
		this->pauseStatus = true;

		ui->videoSlider->setRange(0, 100);
		ui->listWidget->setVisible(false);
		ui->addFileButton->setVisible(false);

		connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playOrPause()));
		connect(ui->videoSlider,SIGNAL(sliderMoved(int)),this, SLOT(seek(int)));
		connect(ui->openButton, SIGNAL(toggled(bool)), this,SLOT(openVideo(bool)));
		connect(ui->stopButton, SIGNAL(clicked()),this,SLOT(stop()));
		connect(ui->kuaijinButton, SIGNAL(clicked()), this, SLOT(kuaijin()));
		connect(ui->kuaituiButton,SIGNAL(clicked()), this,SLOT(kuaitui()));
		connect(ui->addFileButton,SIGNAL(clicked()), this, SLOT(addFileList()));
		connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(selectFile()));
		connect(ui->prevButton, SIGNAL(clicked()), this,SLOT(prevVideo()));
		connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextVideo()));
		connect(ui->muteButton, SIGNAL(toggled(bool)), this, SLOT(MuteOrNot(bool)));
		connect(ui->soundAddButton, SIGNAL(clicked()), this, SLOT(soundAdd()));
		connect(ui->soundSubButton, SIGNAL(clicked()), this, SLOT(soundSub()));

		timer = new QTimer(this);
		connect(timer,SIGNAL(timeout()),this,SLOT(get_time_pos()));
		timer->start(1000);

}

Widget::~Widget()
{
		delete ui;
}
void Widget::playOrPause()
{
		if(this->playStatus)
		{
				if(pauseStatus)
				{
						process->write("pause\n");
						ui->playButton->setIcon(QIcon(":/image/pause.png"));
						this->pauseStatus = false;
				}
				else
				{
						process->write("pause\n");
						ui->playButton->setIcon(QIcon(":/image/play.png"));
						this->pauseStatus = true;
				}
		}

}
void Widget::back_message_slots()
{
		while(process->canReadLine())
		{
				QString message(process->readLine());
				//          std::cerr << message.toStdString() <<std::endl;
				QStringList message_list = message.split("=");
				if(message_list[0] == "ANS_TIME_POSITION")
				{
						this->curr_time = message_list[1].toDouble();
						QTime time = int_to_time(curr_time);
						ui->playTimeLabel->setText(time.toString("hh:mm:ss"));
						ui->videoSlider->setValue(100*curr_time /fileLength);
				}
				else if(message_list[0] == "ANS_LENGTH")
				{
						this->fileLength = message_list[1].toDouble();
						QTime time = int_to_time(fileLength);
						ui->totalTimeLabel->setText(time.toString("hh:mm:ss"));
				}

		}
}
QTime Widget::int_to_time(int seconds )
{
		int sec = 0, min = 0, hour = 0;
		QTime time;
		if(seconds <60)
		{
				sec = seconds;
				min = 0;
				hour= 0;
		}
		if(seconds>=60 && seconds<3600)
		{
				sec = seconds % 60;
				min = seconds /60;
				hour = 0;
		}
		if(seconds >=3600)
		{
				sec = seconds % 60;
				min = (seconds /60) %60;
				hour = seconds /3600;
		}
		time.setHMS(hour, min, sec);
		return time;

}

void Widget::get_time_pos()
{
		if(this->playStatus && (!this->pauseStatus))
		{
				process->write("get_time_length\n");
				process->write("get_time_pos\n");
		}

}
void Widget::seek(int value)
{
		if(this->playStatus)
		{
				QString command = "seek "+ QString::number(value) + " 1\n";
				process->write(command.toAscii());
		}

}
void Widget::openVideo(bool isChecked)
{

		if(isChecked)
		{
				ui->listWidget->setVisible(true);
				ui->addFileButton->setVisible(true);
		}
		else
		{
				ui->listWidget->setVisible(false);
				ui->addFileButton->setVisible(false);
		}



}
void Widget::stop()
{
		if(this->playStatus)
		{
				process->write("quit\n");
				this->playStatus = false;
				ui->playButton->setIcon(QIcon(":/image/play.png"));
				ui->videoSlider->setValue(0);
				ui->playTimeLabel->setText("00:00:00");
				ui->totalTimeLabel->setText("00:00:00");
				ui->fileNameLabel->setText("nofile");
		}

}
void Widget::kuaijin()
{
		if(this->playStatus)
		{
				process->write("seek +10 0\n");
		}
}

void Widget::kuaitui()
{
		if(this->playStatus)
		{
				process->write("seek -10 0\n");
		}
}
void Widget::addFileList()
{
		int i;
		QStringList newFileList = QFileDialog::getOpenFileNames(this, tr("open file"),".","*.*");

		for(i=0; i < newFileList.count(); ++i)
		{
				if(!fileList.contains(newFileList[i]))
				{
						this->fileList.append(newFileList[i]);
				}
		}
		ui->listWidget->clear();

		for(i=0; i<fileList.size();i++)
		{
				ui->listWidget->addItem(QFileInfo(fileList.at(i)).fileName());
		}
}

void Widget::selectFile()
{

		QString fileName = QString(fileList.at(ui->listWidget->currentRow()));
		if(!fileName.isEmpty())
		{
				if(this->playStatus)
				{
						playStatus = false;
						process->write("quit\n");
						process->waitForFinished();
				}

				ui->fileNameLabel->setText(QFileInfo(fileName).fileName());
				QString command ="mplayer "  +fileName +  "  -slave -quiet -softvol -wid  "
						+QString::number(ui->videoFrame->winId());
				process = new QProcess(this);
				connect(process, SIGNAL(readyReadStandardOutput()),this,SLOT(back_message_slots()));
				process->setProcessChannelMode(QProcess::MergedChannels);
				process->start(command);
				this->playStatus = true;
				this->pauseStatus = false;

				ui->playButton->setIcon(QIcon(":/image/pause.png"));
		}
}
void Widget::prevVideo()
{
		if((ui->listWidget->currentRow() - 1)  >= 0)
		{
				ui->listWidget->setCurrentRow(ui->listWidget->currentRow() - 1);
				selectFile();
		}
		else
		{
				ui->prevButton->setToolTip(tr("the first one"));
		}

}

void Widget::nextVideo()
{
		if((ui->listWidget->currentRow() + 1) < ui->listWidget->count())
		{
				ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
				selectFile();
		}
		else
		{
				ui->nextButton->setToolTip(tr("the last one"));
		}
}

void Widget::MuteOrNot(bool isChecked)
{
		if(this->playStatus)
		{
				if(isChecked)
				{
						process->write("mute 1\n");
						ui->muteButton->setIcon(QIcon(":/image/mute.png"));
				}
				else
				{
						process->write("mute 0 \n");
						ui->muteButton->setIcon(QIcon(":/image/nomute.png"));
				}
		}
}

void Widget::soundAdd()
{
		if(this->playStatus)
		{
				process->write("volume +1\n");
		}
}

void Widget::soundSub()
{
		if(this->playStatus)
		{
				process->write("volume -1\n");
		}
}
