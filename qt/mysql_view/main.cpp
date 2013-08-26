#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QHeaderView>
#include <QtSql/QSqlRelationalTableModel>
#include <QSqlRelation>

bool createConnection(QSqlDatabase & db)
{
    db.setDatabaseName("crashcourses");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open())
    {
        qDebug() << "db open failure!";
        return false;
    }

    qDebug() << "connection established";
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    if(!createConnection(db))
        return 1;
/*
    QSqlQueryModel * mode = new QSqlQueryModel;
    mode->setQuery("select prod_id, vend_name, prod_name, prod_price from products, vendors where products.vend_id = vendors.vend_id", db);
    mode->setHeaderData(0, Qt::Horizontal, "prod_id");
    mode->setHeaderData(1, Qt::Horizontal, "vend_name");
    mode->setHeaderData(2, Qt::Horizontal, "prod_name");
    mode->setHeaderData(3, Qt::Horizontal, "prod_price");
*/

    QSqlRelationalTableModel * mode =
            new QSqlRelationalTableModel;
    mode->setTable("products");
    QSqlRelation relation("vendors",
                          "vend_id",
                          "vend_name");

    mode->setRelation(1, relation);
    mode->select();
    mode->setHeaderData(0, Qt::Horizontal, "prod_id");
    mode->setHeaderData(1, Qt::Horizontal, "vend_name");
    mode->setHeaderData(2, Qt::Horizontal, "prod_name");
    mode->setHeaderData(3, Qt::Horizontal, "prod_price");

    QTableView * tableview = new QTableView(&w);
    tableview->verticalHeader()->hide();
    tableview->setModel(mode);

    w.setCentralWidget(tableview);
    w.resize(600, 400);
    w.show();
    
    return a.exec();
}
