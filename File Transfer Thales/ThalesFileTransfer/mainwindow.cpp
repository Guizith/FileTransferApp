#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <regex>
#include <dirent.h>


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

//Transferencia do arquivo ao clicar (ALTERAR PARA CLICK TRUE/FALSE COM ATUALIZAÇÃO POR SEGUNDOS)
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


    //qDebug() << rgxstr;


    //Navegação até o diretorio source (replicar para dst e QMessageBox Error)
    if (chdir(srcstr) == -1) {
            perror(srcstr);
            qDebug() << "Erro no src";
        }


    DIR *dirp = opendir(".");
        if (!dirp) {
            perror("Can't open directory");
            qDebug() << " Can't open directory" ;
        }



           // Loop parar percorrer todo diretorio
              for (struct dirent *dent; (dent = readdir(dirp)) != NULL; )
              {
                  const char *nm = dent->d_name;

                  // pular . e ..
                  if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0)
                      continue;

                  //qDebug() << nm;

                  //Variavel de match no file name com regex
                  bool matched = std::regex_search(nm,matches,reg);
                  //qDebug() << matched;

                  //Copia do arquivo caso match = true
                  if(matched == true){
                      qDebug() << "aaaaaaaa";

                      char srcfile[256];
                      char dstfile[256];

                      //Alterar para secure function
                      strcpy(srcfile,srcstr);
                      strcat(srcfile,nm);
                      strcpy(dstfile,dststr);
                      strcat(dstfile,nm);



                        rename(srcfile,dstfile);

                        //qDebug() << srcfile << "+"<< srcfile;

                     }


                  }



           closedir(dirp);

    //qDebug() << dststr;


}
