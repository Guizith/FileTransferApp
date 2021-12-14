#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <regex>
#include <dirent.h>
#include <QDir>
#include <QDateTime>
#include <QLineEdit>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //qDebug() << QDir::tempPath();
    ui->setupUi(this);
    //objeto QTimer para auto refresh
    tempo = new QTimer(this);
    //Registrando inicializacao no arquivo de log
    putstartlog();



}

MainWindow::~MainWindow()
{
    delete ui;
}

//Transferencia do arquivo
void MainWindow::on_run_button_clicked()
{

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

    bool rgxerror = false;
    if(rgx == ""){
        QMessageBox messageBoxQuestion;
        QMessageBox::StandardButton ans;
        ans = messageBoxQuestion.question(0,"Error","no regex typed, do you want to continue?",QMessageBox::Yes|QMessageBox::No);
        messageBoxQuestion.setFixedSize(500,200);
        if(ans == QMessageBox::No){
            rgxerror = true;
        }
    }


    //Navegação até o diretorio source/destination (replicar para dst e QMessageBox Error)
    bool errorsts = false;      //Flag para erros
    if (chdir(dststr) == -1) {
            errorsts = true;
            stopfunc();
        }

    if (chdir(srcstr) == -1) {
            errorsts = true;
            stopfunc();
        }


    //Listagem do diretorio
    DIR *dirp = opendir(".");

    if (!dirp) {
        errorsts = true;
        //perror("Can't open directory");
    }


    //Verificação de erros no diretorio.
    if(errorsts == false && rgxerror == false){

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

                  strcpy(srcfile,srcstr);
                  strcat(srcfile,nm);
                  strcpy(dstfile,dststr);
                  strcat(dstfile,nm);

                  //Registro de log de transferencia de arquivo
                  rename(srcfile,dstfile);
                  putlog(srcfile,dstfile);
                }
             }
       closedir(dirp);
    }else if(errorsts == true){
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","The specified directory is invalid");
        messageBoxError.setFixedSize(500,200);
        stopfunc();
    }else if(rgxerror == true){
        stopfunc();
    }
}

void MainWindow::on_run_button2_clicked(bool checked)
{
    if(checked == true){
        ui->Load_Config->setDisabled(true);
        ui->Save_Button_2->setDisabled(true);
        ui->Log_Report_Directory->setDisabled(true);
        ui->run_button->setDisabled(true);
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);

        //reset text button
        ui->run_button2->setText("Stop");

        //Trava alterações enquanto ativado e pinta campos de gray
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
        //Refresh minimo/default
        if(refrashrate < 1)
            refrashrate = 1;

        //connect funcao de refrash com objeto
        connect(tempo,SIGNAL(timeout()),this,SLOT(on_run_button_clicked()));
        tempo->start((refrashrate*1000));
    }else{

        //Liberacao de campos ao parar auto refresh
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
        //reset button text
        ui->run_button2->setText("Run");
        ui->Load_Config->setDisabled(false);
        ui->Save_Button_2->setDisabled(false);
        ui->Log_Report_Directory->setDisabled(false);
        ui->run_button->setDisabled(false);
        ui->pushButton->setDisabled(false);
        ui->pushButton_2->setDisabled(false);
    }
}


//Função de parada (acionada em possiveis erros de diretorio e no acionamento do botão Stop)
void MainWindow::stopfunc(){
    tempo->stop();
}


//salva log transfer
void MainWindow::putlog(char srcc[], char dstt[]){

    //salva Start log se nao foi salvo na inicializacao (por erro de diretorio)
    if(startlogg == false){
        putstartlog();
    }

    QFile data = (logpath+"\\FileTransferLog.txt");
    if (data.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&data);

        out << QDateTime::currentDateTime().toString("dd:MM:yyyy  hh:mm:ss");
        out << " -Source:" << srcc;
        out << " -Destination:" << dstt;
        out << "\n";

        data.close();
    }else{
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","Error in write log, go to \"Setting -> Log Repository Directory and set new repository to save logs\"");
        messageBoxError.setFixedSize(500,200);
    }


}

//salva log start
void MainWindow::putstartlog(){

    QFile data = (logpath+"\\FileTransferLog.txt");
    if (data.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&data);
        out << QDateTime::currentDateTime().toString("dd:MM:yyyy  hh:mm:ss") << " -Program Inicialization";
        out << "\n";

        data.close();
        startlogg = true;
    }else{
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","Error in write log, go to \"Setting -> Log Repository Directory\" and set new repository to save logs");
        messageBoxError.setFixedSize(500,200);

        //Trava campos
        ui->regex_txt->setReadOnly(true);
        ui->src_txt->setReadOnly(true);
        ui->dst_txt->setReadOnly(true);
        ui->refresh_txt->setReadOnly(true);
        ui->Load_Config->setDisabled(true);
        ui->Save_Button_2->setDisabled(true);
        ui->run_button->setDisabled(true);
        ui->run_button2->setDisabled(true);
        ui->chart_button->setDisabled(true);
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);

        QPalette gray_p;
        gray_p.setColor(ui->regex_txt->backgroundRole(),QColor(Qt::gray));

        ui->regex_txt->setPalette(gray_p);
        ui->src_txt->setPalette(gray_p);
        ui->dst_txt->setPalette(gray_p);
        ui->refresh_txt->setPalette(gray_p);

    }


}

//Funcao para gerar grafico
void MainWindow::on_chart_button_clicked()
{
    //1100 = chat busca datas de no maximo 3 anos
    QString date[1100];     //Vetor string para armazenamento de datas unicas
    int contdate[1100];     //Vetor int para contar quantos arquivos foram transferidos em cada data unica
    int contpos = 1;        //Variavel para contar as datas unicas.

    //contdate = zeros
    for(int i=0;i<1024;i++){
        contdate[i] = 0;
    }

    //Expressão regular para encontrar apenas transferencias de arquivos
    std:: regex reg("([^]-Source:[^])");
    std::cmatch matches;

    //qDebug() << QDir::tempPath();
    QFile data(logpath+"\\FileTransferLog.txt");


    //Abertura do arquivo de logs
    if(data.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&data);
            while(!stream.atEnd()){

                QString line = stream.readLine();
                //Conversão
                QByteArray lineq = line.toLocal8Bit();
                const char* linestr = lineq.data();

                //Variavel de match no file name com regex
                bool matched = std::regex_search(linestr,matches,reg);

                //Se a linha lida eh log de transferencia
                if(matched == true){

                    //Variavel de verificacao se a data ja esta no vetor de datas unicas
                    bool contain = false;
                    //Variavel para registro de posicao caso a data ja esteja no vetor
                    int containpos = -1;

                    //For if para verificao completa do vetor
                    for(int i = 0; i<contpos;i++){
                        if(date[i] == line.left(10)){
                            contain = true;
                            containpos = i;
                        }
                    }

                    //Se contem apenas soma +1 na posicao encontrada
                    if(contain){
                        contdate[containpos] = contdate[containpos] +1;
                    }
                    //Senao adiciona a nova data no vetor
                    else{
                        date[contpos] = line.left(10);
                        contdate[contpos] = contdate[contpos] +1;
                        contpos++;
                    }

                }
            }
    }

    data.close();

    //Arquivo para plotagem dos dados coletados
    QFile chart(logpath+"\\FileTransferChartData.txt");
    //Abertura arquivo de plot
    if(chart.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&chart);
        out << "Date" << "  " << "Transferred-file-count" << "\n";
        for(int i =1; i<contpos;i++){
            out << date[i] << " " << contdate[i] << "\n";
        }
    }

    chart.close();

    //Script para plotagem do grafico
    QFile chartPlot(logpath+"\\scriptChartPlot_gnu.plt");
    //Abertura arquivo de plot
    if(chartPlot.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&chartPlot);
        out << "reset\n";
        out << "clear\n";
        out << "set key top left outside horizontal autotitle columnhead\n";
        out << "set xtics out nomirror\n";
        out << "set ytics out nomirror\n";
        out << "set style fill solid border -1\n";
        out << "set grid\n";
        out << "set boxwidth 0.8 relative\n";
        out << "set style data histograms\n";
        out << "plot \"FileTransferChartData.txt\" using 2:xticlabels(1) lc rgb 'blue'\n";
    }

    chartPlot.close();

    //roda o script
    QDir::setCurrent(logpath);
    std::system("start scriptChartPlot_gnu.plt");

}

//Funcao para salvar configuracoes atuais
void MainWindow::on_Save_Button_2_triggered()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "C://",tr("Configuration File (*.conf)"));
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << ui->regex_txt->text();
        out << "\n";
        out << ui->src_txt->text();
        out << "\n";
        out << ui->dst_txt->text();
        out << "\n";
        out << ui->refresh_txt->text();
        out << "\n";
        data.close();
    }else{
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","Can't save file");
        messageBoxError.setFixedSize(500,200);
    }

}

//Funcar para carregar configuracoes
void MainWindow::on_Load_Config_triggered()
{
    QFile file(QFileDialog::getOpenFileName(this,tr("Open File"),"C://",tr("Configuration File (*.conf)")));
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        ui->regex_txt->setText(stream.readLine());
        ui->src_txt->setText(stream.readLine());
        ui->dst_txt->setText(stream.readLine());
        ui->refresh_txt->setText(stream.readLine());
        file.close();
        //qDebug() << regx << src << dst << refresh;


    }else{
        QMessageBox messageBoxError;
        messageBoxError.critical(0,"Error","Can't laod file");
        messageBoxError.setFixedSize(500,200);


    }
}

//Funcao para alteracao do diretorio de log
void MainWindow::on_Log_Report_Directory_triggered()
{
    QString newpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    logpath = newpath;
    //qDebug() << logpath;
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
    ui->Load_Config->setDisabled(false);
    ui->Save_Button_2->setDisabled(false);
    ui->run_button->setDisabled(false);
    ui->run_button2->setDisabled(false);
    ui->chart_button->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(false);

}

//Botao search src
void MainWindow::on_pushButton_clicked()
{
    QString pathchoose = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    ui->src_txt->setText(pathchoose+"/");
}

//Botao search dst
void MainWindow::on_pushButton_2_clicked()
{
    QString pathchoose = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    ui->dst_txt->setText(pathchoose+"/");
}


void MainWindow::on_actionQuit_triggered()
{
   close();
}

