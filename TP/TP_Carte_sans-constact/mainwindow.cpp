#pragma comment(lib,"ODALID.lib")

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ODALID.h"
#include <QtGui>

#define Auth_KeyA				TRUE
#define Auth_KeyB				FALSE

unsigned char key_ff[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
unsigned char key_A[6] = { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5 }; //Pour lire
unsigned char key_B[6] = { 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5 }; //Pour ecrire

unsigned char key_C[6] = { 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5 }; //Pour lire compteur
unsigned char key_D[6] = { 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5 }; //Pour ecrire compteur


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

ReaderName MonLecteur;

char pszHost[] = "192.168.1.4";

void MainWindow::on_Connect_clicked(){
    uint16_t status = 0;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = OpenCOM(&MonLecteur);
    qDebug()<<"OpenCOM"<<status;
    affichage();
    this->loadCredit();

    //Pour le pimp
    status = LEDBuzzer(&MonLecteur, LED_YELLOW_ON);

    read();
}

void MainWindow::on_Disconnect_clicked()
{
    uint16_t status = 0;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = CloseCOM(&MonLecteur);
    qDebug()<<"OpenCOM"<<status;
    affichage();
}

void MainWindow::on_Quitter_clicked()
{
    int16_t status = 0;
    RF_Power_Control(&MonLecteur, FALSE, 0);
    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    close();
}

void MainWindow::affichage()
{
    char version[30];
    uint8_t serial[4];
    char stackReader[20];

    uint16_t status = Version(&MonLecteur, version, serial, stackReader);
    QString display = QString::number(status);

    ui->logShow->setPlainText(display);
    ui->logShow->update();
}

void MainWindow::read(){
    // RF field ON
    RF_Power_Control(&MonLecteur, TRUE, 0);
    BYTE atq[2];
    BYTE sak[1];
    BYTE uid[12];
    uint16_t uid_len = 12;

    int status = 0;
    status = ISO14443_3_A_PollCard(&MonLecteur,atq,sak,uid,&uid_len);

    if(status == 0){
        unsigned char data[16];
        unsigned char data2[16];

        //On charge les clés
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key_A, 2);
        if (status != MI_OK){
            qDebug()<<"Load Key A [FAILED]\n";
        }
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key_B, 2);
        if (status != MI_OK){
            qDebug()<<"Load Key B [FAILED]\n";
        }

        //Nom
        status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 10, data, Auth_KeyA, 2);
        if (status != MI_OK){
            qDebug()<<"lecture impossible";
        }else{
            QString result ="";
            for(int i =0; i<16;i++){
                if(data[i]=='\\'){
                    break;
                }else{
                   result = result+data[i];
                }
            }
            ui->txtNom->setText(result);
            ui->txtNom->update();
            qDebug()<<"Nom : "<<result;
        }
        //Prenom
        status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, data2, Auth_KeyA, 2);
        if (status != MI_OK){
            qDebug()<<"lecture impossible";

        }else{
            QString result ="";
            for(int i =0; i<16;i++){
                if(data2[i]=='\\'){
                    break;
                }else{
                   result = result+data2[i];
                }

            }
            ui->txtPrenom->setText(result);
            ui->txtPrenom->update();
            qDebug()<<"Prenom : "<<result;
        }

    }else{
      qDebug()<<"Pas de carte";
    }


}

void MainWindow::write(){
    // RF field ON
    RF_Power_Control(&MonLecteur, TRUE, 0);
    BYTE atq[2];
    BYTE sak[1];
    BYTE uid[12];
    uint16_t uid_len = 12;

    int status = 0;
    status = ISO14443_3_A_PollCard(&MonLecteur,atq,sak,uid,&uid_len);

    if(status == 0){
        QString stringDataNom = ui->txtNom->text();
        QString stringDataPrenom= ui->txtPrenom->text();

        unsigned char data[16];
         unsigned char data2[16];


        //On charge les clés
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key_A, 2);
        if (status != MI_OK){
            qDebug()<<"Load Key A [FAILED]\n";
        }
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key_B, 2);
        if (status != MI_OK){
            qDebug()<<"Load Key B [FAILED]\n";
        }

        mempcpy(data,stringDataNom.toStdString().c_str(),16);
        Mf_Classic_Write_Block(&MonLecteur,TRUE,10,data, Auth_KeyB, 2);


        mempcpy(data2,stringDataPrenom.toStdString().c_str(),16);
        Mf_Classic_Write_Block(&MonLecteur,TRUE,9,data2, Auth_KeyB, 2);
    }else{
      qDebug()<<"Pas de carte";
    }



}

void MainWindow::incremente()
{
    RF_Power_Control(&MonLecteur,TRUE, 0);
    BYTE atq[2];
    BYTE sak[1];
    BYTE uid[12];
    uint16_t uid_len = 12;

    int status = 0;
    int valeurToIncrement =  ui->incrementeValue->value();
    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    status = Mf_Classic_Increment_Value(&MonLecteur, TRUE, 14, valeurToIncrement, 14, Auth_KeyB, 3);
}

void MainWindow::decrementer()
{
    int valeurToIDecremente =  ui->decrementeValue->value();
    if(ui->unitValue->text().toInt() >= valeurToIDecremente){
        RF_Power_Control(&MonLecteur,TRUE, 0);
        BYTE atq[2];
        BYTE sak[1];
        BYTE uid[12];
        uint16_t uid_len = 12;

        int status = 0;
        status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
        status = Mf_Classic_Decrement_Value(&MonLecteur, TRUE, 14, valeurToIDecremente, 14, Auth_KeyB, 3);
    }
}


void MainWindow::on_Update_clicked()
{

    write();
    read();

}

void MainWindow::loadCredit()
{
    uint32_t val = 0;
    int status = 0;
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &val, Auth_KeyA, 3);
    QString cardeValue = "";
    cardeValue = QString::number((int) val);
    ui->unitValue->setText(cardeValue);
}

void MainWindow::on_Payer_clicked()
{
    this->decrementer();
    this->loadCredit();
}

void MainWindow::on_Charger_clicked()
{
    this->incremente();
    this->loadCredit();
}
