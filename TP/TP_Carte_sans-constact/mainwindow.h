#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MfErrNo.h"

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
    void on_Connect_clicked();


    void on_Disconnect_clicked();

    void on_Quitter_clicked();

    void affichage();


    void on_Update_clicked();
    void loadCredit();

    void read();
    void write();

    void incremente();
    void decrementer();

    void on_Payer_clicked();

    void on_Charger_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
