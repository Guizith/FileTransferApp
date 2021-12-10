#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void refresh();
    void stopfunc();

    void on_run_button2_clicked(bool checked);

    void on_Save_Button_clicked();

    void on_pushButton_2_clicked();
    void putlog(char srcc[], char dstt[]);
    void putstartlog();

private:
    Ui::MainWindow *ui;
    QTimer* tempo;
};
#endif // MAINWINDOW_H
