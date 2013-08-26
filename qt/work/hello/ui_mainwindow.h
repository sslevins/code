/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 4 16:48:48 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *Tra_Num_Line;
    QLabel *label;
    QPushButton *CheckBtn;
    QGroupBox *groupBox_2;
    QPushButton *DetailBtn;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *Ttype_LineEdit;
    QLineEdit *Tid_LineEdit;
    QPushButton *FirstBtn;
    QPushButton *PrevBtn;
    QPushButton *NextBtn;
    QPushButton *LastBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(552, 466);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 471, 41));
        groupBox->setAutoFillBackground(true);
        groupBox->setFlat(true);
        Tra_Num_Line = new QLineEdit(groupBox);
        Tra_Num_Line->setObjectName(QString::fromUtf8("Tra_Num_Line"));
        Tra_Num_Line->setGeometry(QRect(60, 10, 141, 27));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 41, 17));
        CheckBtn = new QPushButton(groupBox);
        CheckBtn->setObjectName(QString::fromUtf8("CheckBtn"));
        CheckBtn->setGeometry(QRect(220, 10, 61, 27));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 220, 471, 181));
        groupBox_2->setAutoFillBackground(true);
        groupBox_2->setFlat(false);
        DetailBtn = new QPushButton(groupBox_2);
        DetailBtn->setObjectName(QString::fromUtf8("DetailBtn"));
        DetailBtn->setGeometry(QRect(180, 150, 93, 27));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 20, 401, 111));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 90, 481, 121));
        groupBox_3->setAutoFillBackground(true);
        groupBox_3->setFlat(true);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 37, 62, 17));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(263, 38, 51, 20));
        Ttype_LineEdit = new QLineEdit(groupBox_3);
        Ttype_LineEdit->setObjectName(QString::fromUtf8("Ttype_LineEdit"));
        Ttype_LineEdit->setGeometry(QRect(70, 30, 141, 27));
        Tid_LineEdit = new QLineEdit(groupBox_3);
        Tid_LineEdit->setObjectName(QString::fromUtf8("Tid_LineEdit"));
        Tid_LineEdit->setGeometry(QRect(320, 30, 151, 27));
        FirstBtn = new QPushButton(groupBox_3);
        FirstBtn->setObjectName(QString::fromUtf8("FirstBtn"));
        FirstBtn->setGeometry(QRect(10, 80, 91, 27));
        PrevBtn = new QPushButton(groupBox_3);
        PrevBtn->setObjectName(QString::fromUtf8("PrevBtn"));
        PrevBtn->setGeometry(QRect(130, 80, 91, 27));
        NextBtn = new QPushButton(groupBox_3);
        NextBtn->setObjectName(QString::fromUtf8("NextBtn"));
        NextBtn->setGeometry(QRect(250, 80, 91, 27));
        LastBtn = new QPushButton(groupBox_3);
        LastBtn->setObjectName(QString::fromUtf8("LastBtn"));
        LastBtn->setGeometry(QRect(370, 80, 91, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 552, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\201\253\350\275\246\350\275\246\346\254\241\346\237\245\350\257\242\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\350\275\246\346\254\241\357\274\232", 0, QApplication::UnicodeUTF8));
        CheckBtn->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        DetailBtn->setText(QApplication::translate("MainWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "tid", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "ttype", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\247\213\345\217\221\347\253\231", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\211\200\346\234\211\345\210\227\350\275\246\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\347\201\253\350\275\246\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\347\201\253\350\275\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        FirstBtn->setText(QApplication::translate("MainWindow", "\357\275\234<\347\254\254\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
        PrevBtn->setText(QApplication::translate("MainWindow", "<<\345\211\215\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
        NextBtn->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\235\241>>", 0, QApplication::UnicodeUTF8));
        LastBtn->setText(QApplication::translate("MainWindow", "\346\234\200\345\220\216\344\270\200\346\235\241>|", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
