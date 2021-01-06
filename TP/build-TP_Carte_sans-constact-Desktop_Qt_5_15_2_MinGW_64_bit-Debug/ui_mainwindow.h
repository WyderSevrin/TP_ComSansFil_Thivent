/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *Payer;
    QSpinBox *decrementeValue;
    QLabel *label_3;
    QLineEdit *unitValue;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QPushButton *Update;
    QLineEdit *txtNom;
    QLineEdit *txtPrenom;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QPushButton *Charger;
    QSpinBox *incrementeValue;
    QLabel *label_5;
    QPushButton *Quitter;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QGroupBox *groupBox_4;
    QTextEdit *logShow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 492);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(300, 160, 461, 111));
        Payer = new QPushButton(groupBox);
        Payer->setObjectName(QString::fromUtf8("Payer"));
        Payer->setGeometry(QRect(370, 60, 75, 23));
        decrementeValue = new QSpinBox(groupBox);
        decrementeValue->setObjectName(QString::fromUtf8("decrementeValue"));
        decrementeValue->setGeometry(QRect(261, 60, 91, 21));
        decrementeValue->setMaximum(9999);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 30, 91, 16));
        unitValue = new QLineEdit(groupBox);
        unitValue->setObjectName(QString::fromUtf8("unitValue"));
        unitValue->setGeometry(QRect(260, 20, 91, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 60, 151, 16));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 20, 461, 121));
        Update = new QPushButton(groupBox_2);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(370, 80, 75, 23));
        txtNom = new QLineEdit(groupBox_2);
        txtNom->setObjectName(QString::fromUtf8("txtNom"));
        txtNom->setGeometry(QRect(120, 30, 221, 21));
        txtPrenom = new QLineEdit(groupBox_2);
        txtPrenom->setObjectName(QString::fromUtf8("txtPrenom"));
        txtPrenom->setGeometry(QRect(120, 60, 221, 21));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 47, 13));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 47, 13));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(300, 290, 461, 111));
        Charger = new QPushButton(groupBox_3);
        Charger->setObjectName(QString::fromUtf8("Charger"));
        Charger->setGeometry(QRect(370, 40, 75, 23));
        incrementeValue = new QSpinBox(groupBox_3);
        incrementeValue->setObjectName(QString::fromUtf8("incrementeValue"));
        incrementeValue->setGeometry(QRect(260, 40, 81, 21));
        incrementeValue->setMaximum(9999);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 40, 151, 16));
        Quitter = new QPushButton(centralwidget);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        Quitter->setGeometry(QRect(30, 360, 221, 41));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(30, 20, 221, 41));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(30, 80, 221, 41));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 160, 221, 171));
        logShow = new QTextEdit(groupBox_4);
        logShow->setObjectName(QString::fromUtf8("logShow"));
        logShow->setGeometry(QRect(10, 20, 201, 141));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(Connect, SIGNAL(clicked()), MainWindow, SLOT(on_Connect_Clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "D\303\251crementer", nullptr));
        Payer->setText(QCoreApplication::translate("MainWindow", "Payer", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251 \303\240 d\303\251cr\303\251menter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Identit\303\251", nullptr));
        Update->setText(QCoreApplication::translate("MainWindow", "Mise \303\240 Jour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Incr\303\251menter", nullptr));
        Charger->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251 \303\240 incr\303\251menter", nullptr));
        Quitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Infos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
