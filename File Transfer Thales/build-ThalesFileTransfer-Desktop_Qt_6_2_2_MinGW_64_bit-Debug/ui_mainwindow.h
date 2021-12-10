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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QPushButton *Save_Button;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *regex_txt;
    QLineEdit *src_txt;
    QLineEdit *dst_txt;
    QLineEdit *refresh_txt;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *run_button;
    QPushButton *run_button2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(338, 344);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 180, 51, 16));
        Save_Button = new QPushButton(centralwidget);
        Save_Button->setObjectName(QString::fromUtf8("Save_Button"));
        Save_Button->setGeometry(QRect(60, 250, 101, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 250, 101, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 10, 71, 21));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 60, 97, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(160, 60, 110, 141));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        regex_txt = new QLineEdit(widget1);
        regex_txt->setObjectName(QString::fromUtf8("regex_txt"));

        verticalLayout_2->addWidget(regex_txt);

        src_txt = new QLineEdit(widget1);
        src_txt->setObjectName(QString::fromUtf8("src_txt"));

        verticalLayout_2->addWidget(src_txt);

        dst_txt = new QLineEdit(widget1);
        dst_txt->setObjectName(QString::fromUtf8("dst_txt"));

        verticalLayout_2->addWidget(dst_txt);

        refresh_txt = new QLineEdit(widget1);
        refresh_txt->setObjectName(QString::fromUtf8("refresh_txt"));
        refresh_txt->setAutoFillBackground(false);

        verticalLayout_2->addWidget(refresh_txt);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(60, 210, 211, 26));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        run_button = new QPushButton(widget2);
        run_button->setObjectName(QString::fromUtf8("run_button"));

        horizontalLayout->addWidget(run_button);

        run_button2 = new QPushButton(widget2);
        run_button2->setObjectName(QString::fromUtf8("run_button2"));
        run_button2->setCheckable(true);

        horizontalLayout->addWidget(run_button2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 338, 21));
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
        label_5->setText(QCoreApplication::translate("MainWindow", "Default: 1", nullptr));
        Save_Button->setText(QCoreApplication::translate("MainWindow", "Save Configs", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Load Configs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Thales Group", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Regex:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Refresh Rate(seg):", nullptr));
        run_button->setText(QCoreApplication::translate("MainWindow", "Run One Time", nullptr));
        run_button2->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
