#include <QLabel>
#include <QApplication>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

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
    return true;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db =
            QSqlDatabase::addDatabase("QMYSQL");
    if (!createConnection(db))
        return 1;

    QSqlQuery query(db);
    query.exec("select * from products");

    if (query.isActive())
        qDebug() << "select is running";
    else
        qDebug() << "select is not run";

    if (query.isValid())
        qDebug() << "current is valid";
    else
        qDebug() << "current is invalid";


    QSqlRecord rec = query.record();

    while (query.next())
    {
        rec = query.record();
        int prod_id_idx = rec.indexOf("prod_id");
        int vend_id_idx = rec.indexOf("vend_id");
        int prod_name_idx = rec.indexOf("prod_name");

        qDebug() << rec.value(prod_id_idx).toString()
                 << rec.value(vend_id_idx).toInt()
                 << rec.value(prod_name_idx).toString();
    }

    if (query.first()) // 1
    {
        rec = query.record();
        qDebug() << "The first record is: "
                 << rec.value(0).toString()
                 << rec.value(1).toInt()
                 << rec.value(2).toString();
    }

    if (query.next()) // 2
    {
        rec = query.record();
        qDebug() << "The first record is: "
                 << rec.value(0).toString()
                 << rec.value(1).toInt()
                 << rec.value(2).toString();

    }

    if (query.last()) // reverse 1
    {
        rec = query.record();
        qDebug() << "The last record is: "
                 << rec.value(0).toString()
                 << rec.value(1).toInt()
                 << rec.value(2).toString();
    }

    if (query.previous()) // reverse 2
    {
        rec = query.record();
        qDebug() << "The record before last record is: "
                 << rec.value(0).toString()
                 << rec.value(1).toInt()
                 << rec.value(2).toString();

    }

    query.exec("select * from customers where cust_id = 10005");
    if (query.next())
    {
        rec = query.record();
        int cust_email_idx = rec.indexOf("cust_email");
        int cust_name_idx = rec.indexOf("cust_name");

        if (query.isNull(cust_email_idx))
            qDebug() << rec.value(cust_name_idx).toString() <<
                        "didn't fix a email";
    }


    QLabel label("hello world!");

    label.show();

    int ret = app.exec();

    query.clear();
    db.close();

    return ret;
}



