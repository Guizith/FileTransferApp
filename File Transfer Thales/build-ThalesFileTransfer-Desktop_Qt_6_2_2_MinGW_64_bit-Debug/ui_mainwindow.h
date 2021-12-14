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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Save_Button_2;
    QAction *Load_Config;
    QAction *Log_Report_Directory;
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *regex_txt;
    QLineEdit *src_txt;
    QLineEdit *dst_txt;
    QLineEdit *refresh_txt;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *run_button;
    QPushButton *run_button2;
    QPushButton *chart_button;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuSetting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(396, 424);
        Save_Button_2 = new QAction(MainWindow);
        Save_Button_2->setObjectName(QString::fromUtf8("Save_Button_2"));
        Load_Config = new QAction(MainWindow);
        Load_Config->setObjectName(QString::fromUtf8("Load_Config"));
        Log_Report_Directory = new QAction(MainWindow);
        Log_Report_Directory->setObjectName(QString::fromUtf8("Log_Report_Directory"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 220, 51, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 100, 97, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 100, 110, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        regex_txt = new QLineEdit(layoutWidget1);
        regex_txt->setObjectName(QString::fromUtf8("regex_txt"));

        verticalLayout_2->addWidget(regex_txt);

        src_txt = new QLineEdit(layoutWidget1);
        src_txt->setObjectName(QString::fromUtf8("src_txt"));

        verticalLayout_2->addWidget(src_txt);

        dst_txt = new QLineEdit(layoutWidget1);
        dst_txt->setObjectName(QString::fromUtf8("dst_txt"));

        verticalLayout_2->addWidget(dst_txt);

        refresh_txt = new QLineEdit(layoutWidget1);
        refresh_txt->setObjectName(QString::fromUtf8("refresh_txt"));
        refresh_txt->setAutoFillBackground(false);

        verticalLayout_2->addWidget(refresh_txt);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 250, 211, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        run_button = new QPushButton(layoutWidget2);
        run_button->setObjectName(QString::fromUtf8("run_button"));

        horizontalLayout->addWidget(run_button);

        run_button2 = new QPushButton(layoutWidget2);
        run_button2->setObjectName(QString::fromUtf8("run_button2"));
        run_button2->setCheckable(true);

        horizontalLayout->addWidget(run_button2);

        chart_button = new QPushButton(centralwidget);
        chart_button->setObjectName(QString::fromUtf8("chart_button"));
        chart_button->setGeometry(QRect(80, 290, 211, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 330, 131, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 10, 71, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        label_7->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 50, 201, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        label_8->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 140, 21, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 180, 21, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 396, 21));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSetting->menuAction());
        menuSetting->addAction(Save_Button_2);
        menuSetting->addAction(Load_Config);
        menuSetting->addAction(Log_Report_Directory);
        menuSetting->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Save_Button_2->setText(QCoreApplication::translate("MainWindow", "Save Config", nullptr));
        Load_Config->setText(QCoreApplication::translate("MainWindow", "Load Config", nullptr));
        Log_Report_Directory->setText(QCoreApplication::translate("MainWindow", "Log Report Directory", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Default: 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Regex:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Refresh Rate(seg):", nullptr));
        run_button->setText(QCoreApplication::translate("MainWindow", "Run Once", nullptr));
        run_button2->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        chart_button->setText(QCoreApplication::translate("MainWindow", "Log Transfer Chart", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "*need gnuplot installed", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "THALES ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "File Transfer Software", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
