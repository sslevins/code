#include <QtGui/QApplication>
#include <QtGui/QApplication>
#include <QDebug>
#include <QSqlDatabase>

#include "mainwindow.h"

bool createConnection()
{
    QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setPassword("123456");
    db.setHostName("localhost");
    db.setDatabaseName("StationHelper");
    db.setPort(3306);
    if(!db.open())
    {
        qDebug()<<"connect failed\n";
        return false;
    }
    else
    {
        qDebug()<<"open database success\n";
    }
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
            return 0;

    MainWindow w;
    w.show();

    return a.exec();
}
