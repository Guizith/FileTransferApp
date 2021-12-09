#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Transferencia do arquivo ao clicar
void MainWindow::on_run_button_clicked()
{

//X:\TesteCpp\tstt.txt
//C:\temp\tstt.txt

    //Leitura do campo
    QString src = ui->src_txt->text();
    QString dst = ui->dst_txt->text();

    //Conversão
    QByteArray srcq = src.toLocal8Bit();
    QByteArray dstq = dst.toLocal8Bit();
    const char* srcstr = srcq.data();
    const char* dststr = dstq.data();

    // Transfer
    std::rename(srcstr,dststr);

    qDebug() << src + "   ---    " + dst;


}
