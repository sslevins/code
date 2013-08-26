#include "mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget * widget = new QWidget(this);
    setCentralWidget(widget);

    QPushButton * button1 =
            new QPushButton("button1", widget);

    QPushButton * button2 =
            new QPushButton("button2", widget);

    QPushButton * button3 =
            new QPushButton("button3", widget);

    QPushButton * button4 =
            new QPushButton("button4", widget);

    //QHBoxLayout * layout = new QHBoxLayout(widget);
    //QVBoxLayout * layout = new QVBoxLayout(widget);
    //QGridLayout * layout = new QGridLayout(widget);
    QHBoxLayout * hlayout = new QHBoxLayout(widget);

    QVBoxLayout * vlayout1 = new QVBoxLayout();
    QVBoxLayout * vlayout2 = new QVBoxLayout();

    hlayout->insertLayout(0, vlayout1);
    hlayout->insertLayout(1, vlayout2);

    vlayout1->addWidget(button1);
    vlayout1->addWidget(button2);
    vlayout2->addWidget(button3);
    vlayout2->addWidget(button4);

    this->setGeometry(300, 300, 400, 100);

    //connect(button, SIGNAL(clicked()),
    //        this, SLOT(xxx()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::xxx(void)
{
    // include <QDebug>
    qDebug() << "here\n";
    // cout << "here\n";
}



