#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel * model;
    QSqlQuery query;

private slots:
    void on_CheckBtn_clicked();
    void on_FirstBtn_clicked();
    void on_PrevBtn_clicked();
    void on_NextBtn_clicked();
    void on_LastBtn_clicked();
    void on_DetailBtn_clicked();
};

#endif // MAINWINDOW_H
