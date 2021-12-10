#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <regex>
#include <dirent.h>
#include <qthread.h>
#include <QDateTime>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //objeto QTimer para auto refresh
    tempo = new QTimer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Transferencia do arquivo
void MainWindow::on_run_button_clicked()
{

//File name: ts321dsad.txt
// Regex =       (ts[^]?)
// Source =      X:\TesteCpp\
// Destination = C:\temp\

//Teste OK!

    //Leitura do campo
    QString src = ui->src_txt->text();
    QString dst = ui->dst_txt->text();
    QString rgx = ui->regex_txt->text();

    //Conversão
    QByteArray srcq = src.toLocal8Bit();
    QByteArray dstq = dst.toLocal8Bit();
    QByteArray rgxq = rgx.toLocal8Bit();
    const char* srcstr = srcq.data();
    const char* dststr = dstq.data();
    const char* rgxstr = rgxq.data();

    //Variaveis Regex
    std:: regex reg(rgxstr);
    std::cmatch matches;




    //Navegação até o diretorio source (replicar para dst e QMessageBox Error)
    bool errorsts = false;      //Flag para erros
    if (chdir(srcstr) == -1) {
            qDebug() << "Erro no src";
            errorsts = true;
            stopfunc();
        }

    //Listagem do diretorio
    DIR *dirp = opendir(".");

    //Verificação de erro de listagem
    if (!dirp) {
        errorsts = true;
        perror("Can't open directory");
        qDebug() << " Can't open directory" ;
    }


    //Verificação de erros no diretorio.
    if(errorsts == false){

       // Loop parar percorrer todo diretorio
          for (struct dirent *dent; (dent = readdir(dirp)) != NULL; )
          {
              const char *nm = dent->d_name;    //Armazenamento file name

              // pular . e ..
              if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0)
                  continue;

              //Variavel de match no file name com regex
              bool matched = std::regex_search(nm,matches,reg);

              //Copia do arquivo caso match = true
              if(matched == true){

                  char srcfile[256];
                  char dstfile[256];

                  //Alterar para secure function
                  strcpy(srcfile,srcstr);
                  strcat(srcfile,nm);
                  strcpy(dstfile,dststr);
                  strcat(dstfile,nm);

                  rename(srcfile,dstfile);
                }
             }
       closedir(dirp);
    }else{
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","The specified directory is invalid");
        messageBoxError.setFixedSize(500,200);
    }
}

void MainWindow::on_run_button2_clicked(bool checked)
{
    if(checked == true){

        ui->run_button2->setText("Stop");

        ui->regex_txt->setReadOnly(true);
        ui->src_txt->setReadOnly(true);
        ui->dst_txt->setReadOnly(true);
        ui->refresh_txt->setReadOnly(true);

        QPalette gray_p;
        gray_p.setColor(ui->regex_txt->backgroundRole(),QColor(Qt::gray));

        ui->regex_txt->setPalette(gray_p);
        ui->src_txt->setPalette(gray_p);
        ui->dst_txt->setPalette(gray_p);
        ui->refresh_txt->setPalette(gray_p);


        //Armazenamento e conversão do refresh rate
        QString refrashrates = ui->refresh_txt->text();
        int refrashrate = refrashrates.toInt();
        //connect funcao de refrash com objeto
        connect(tempo,SIGNAL(timeout()),this,SLOT(refresh()));
        tempo->start((refrashrate*1000));
    }else{

        ui->regex_txt->setReadOnly(false);
        ui->src_txt->setReadOnly(false);
        ui->dst_txt->setReadOnly(false);
        ui->refresh_txt->setReadOnly(false);

        QPalette gray_p;
        gray_p.setColor(ui->regex_txt->backgroundRole(),QColor(Qt::white));

        ui->regex_txt->setPalette(gray_p);
        ui->src_txt->setPalette(gray_p);
        ui->dst_txt->setPalette(gray_p);
        ui->refresh_txt->setPalette(gray_p);


        stopfunc();
        ui->run_button2->setText("Run");
    }
}

//Função de Refresh
void MainWindow::refresh(){
    on_run_button_clicked();
}

//Função de parada (acionada em possiveis erros de diretorio e no acionamento do botão Stop)
void MainWindow::stopfunc(){
    tempo->stop();
}
