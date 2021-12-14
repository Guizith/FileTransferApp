#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_run_button_clicked();
    void stopfunc();

    void on_run_button2_clicked(bool checked);

    //void on_Save_Button_clicked();

    //void on_pushButton_2_clicked();
    void putlog(char srcc[], char dstt[]);
    void putstartlog();

    void on_chart_button_clicked();

    void on_Save_Button_2_triggered();

    void on_Load_Config_triggered();

    void on_Log_Report_Directory_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    QTimer* tempo;  //refresh time
    QString logpath = (QDir::tempPath()); //caminho padrao de log
    bool startlogg = false; //Confirmacao de start log
};
#endif // MAINWINDOW_H
