/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *regex_txt;
    QLineEdit *src_txt;
    QLineEdit *dst_txt;
    QPushButton *run_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 180, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 220, 71, 16));
        regex_txt = new QLineEdit(centralwidget);
        regex_txt->setObjectName(QString::fromUtf8("regex_txt"));
        regex_txt->setGeometry(QRect(280, 140, 113, 24));
        src_txt = new QLineEdit(centralwidget);
        src_txt->setObjectName(QString::fromUtf8("src_txt"));
        src_txt->setGeometry(QRect(280, 180, 113, 24));
        dst_txt = new QLineEdit(centralwidget);
        dst_txt->setObjectName(QString::fromUtf8("dst_txt"));
        dst_txt->setGeometry(QRect(280, 220, 113, 24));
        run_button = new QPushButton(centralwidget);
        run_button->setObjectName(QString::fromUtf8("run_button"));
        run_button->setGeometry(QRect(300, 270, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 140, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        run_button->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Regex:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
