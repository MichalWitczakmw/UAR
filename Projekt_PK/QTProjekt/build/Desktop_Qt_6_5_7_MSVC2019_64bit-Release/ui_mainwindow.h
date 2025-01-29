/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *NazwaWyniku;
    QDoubleSpinBox *wartoscWynik;
    QHBoxLayout *horizontalLayout;
    QLabel *NazwaKP;
    QDoubleSpinBox *wartoscKP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NazwaTI;
    QDoubleSpinBox *wartoscTI;
    QHBoxLayout *horizontalLayout_3;
    QLabel *NazwaTD;
    QDoubleSpinBox *wartoscTD;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nazwaZaklocenia;
    QSpinBox *wartoscZaklocenia;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nazwaA;
    QDoubleSpinBox *wartoscA;
    QHBoxLayout *horizontalLayout_6;
    QLabel *nazwaB;
    QDoubleSpinBox *wartoscB;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *StartWykresom;
    QPushButton *Reset;
    QPushButton *StopWykresom;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *OkienkoZapiszPlik;
    QPushButton *ZakonczProgram;
    QVBoxLayout *verticalLayout_2;
    QChartView *WykresWartosciZO;
    QHBoxLayout *horizontalLayout_8;
    QChartView *WykresUchybu;
    QChartView *WykresPID;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1514, 857);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_11 = new QHBoxLayout(centralwidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        NazwaWyniku = new QLabel(centralwidget);
        NazwaWyniku->setObjectName("NazwaWyniku");
        NazwaWyniku->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(NazwaWyniku);

        wartoscWynik = new QDoubleSpinBox(centralwidget);
        wartoscWynik->setObjectName("wartoscWynik");
        wartoscWynik->setSingleStep(0.010000000000000);
        wartoscWynik->setValue(10.000000000000000);

        horizontalLayout_7->addWidget(wartoscWynik);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NazwaKP = new QLabel(centralwidget);
        NazwaKP->setObjectName("NazwaKP");
        NazwaKP->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(NazwaKP);

        wartoscKP = new QDoubleSpinBox(centralwidget);
        wartoscKP->setObjectName("wartoscKP");
        wartoscKP->setMaximum(10.000000000000000);
        wartoscKP->setSingleStep(0.010000000000000);
        wartoscKP->setValue(1.000000000000000);

        horizontalLayout->addWidget(wartoscKP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NazwaTI = new QLabel(centralwidget);
        NazwaTI->setObjectName("NazwaTI");
        NazwaTI->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(NazwaTI);

        wartoscTI = new QDoubleSpinBox(centralwidget);
        wartoscTI->setObjectName("wartoscTI");
        wartoscTI->setMaximum(10.000000000000000);
        wartoscTI->setSingleStep(0.010000000000000);
        wartoscTI->setValue(0.600000000000000);

        horizontalLayout_2->addWidget(wartoscTI);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        NazwaTD = new QLabel(centralwidget);
        NazwaTD->setObjectName("NazwaTD");
        NazwaTD->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(NazwaTD);

        wartoscTD = new QDoubleSpinBox(centralwidget);
        wartoscTD->setObjectName("wartoscTD");
        wartoscTD->setMaximum(10.000000000000000);
        wartoscTD->setSingleStep(0.010000000000000);
        wartoscTD->setValue(0.500000000000000);

        horizontalLayout_3->addWidget(wartoscTD);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        nazwaZaklocenia = new QLabel(centralwidget);
        nazwaZaklocenia->setObjectName("nazwaZaklocenia");
        nazwaZaklocenia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(nazwaZaklocenia);

        wartoscZaklocenia = new QSpinBox(centralwidget);
        wartoscZaklocenia->setObjectName("wartoscZaklocenia");
        wartoscZaklocenia->setMinimum(1);
        wartoscZaklocenia->setMaximum(5);

        horizontalLayout_4->addWidget(wartoscZaklocenia);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        nazwaA = new QLabel(centralwidget);
        nazwaA->setObjectName("nazwaA");
        nazwaA->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(nazwaA);

        wartoscA = new QDoubleSpinBox(centralwidget);
        wartoscA->setObjectName("wartoscA");
        wartoscA->setSingleStep(0.010000000000000);
        wartoscA->setValue(0.600000000000000);

        horizontalLayout_5->addWidget(wartoscA);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        nazwaB = new QLabel(centralwidget);
        nazwaB->setObjectName("nazwaB");
        nazwaB->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(nazwaB);

        wartoscB = new QDoubleSpinBox(centralwidget);
        wartoscB->setObjectName("wartoscB");
        wartoscB->setSingleStep(0.010000000000000);
        wartoscB->setValue(0.400000000000000);

        horizontalLayout_6->addWidget(wartoscB);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        StartWykresom = new QPushButton(centralwidget);
        StartWykresom->setObjectName("StartWykresom");

        horizontalLayout_10->addWidget(StartWykresom);

        Reset = new QPushButton(centralwidget);
        Reset->setObjectName("Reset");

        horizontalLayout_10->addWidget(Reset);

        StopWykresom = new QPushButton(centralwidget);
        StopWykresom->setObjectName("StopWykresom");

        horizontalLayout_10->addWidget(StopWykresom);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        OkienkoZapiszPlik = new QPushButton(centralwidget);
        OkienkoZapiszPlik->setObjectName("OkienkoZapiszPlik");

        horizontalLayout_13->addWidget(OkienkoZapiszPlik);

        ZakonczProgram = new QPushButton(centralwidget);
        ZakonczProgram->setObjectName("ZakonczProgram");

        horizontalLayout_13->addWidget(ZakonczProgram);


        verticalLayout->addLayout(horizontalLayout_13);


        horizontalLayout_11->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        WykresWartosciZO = new QChartView(centralwidget);
        WykresWartosciZO->setObjectName("WykresWartosciZO");
        WykresWartosciZO->setMinimumSize(QSize(350, 150));

        verticalLayout_2->addWidget(WykresWartosciZO);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        WykresUchybu = new QChartView(centralwidget);
        WykresUchybu->setObjectName("WykresUchybu");
        WykresUchybu->setMinimumSize(QSize(350, 150));

        horizontalLayout_8->addWidget(WykresUchybu);

        WykresPID = new QChartView(centralwidget);
        WykresPID->setObjectName("WykresPID");
        WykresPID->setMinimumSize(QSize(350, 150));

        horizontalLayout_8->addWidget(WykresPID);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_11->addWidget(label_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1514, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        NazwaWyniku->setText(QCoreApplication::translate("MainWindow", "Wartosc Zadana", nullptr));
        NazwaKP->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        NazwaTI->setText(QCoreApplication::translate("MainWindow", "TI", nullptr));
        NazwaTD->setText(QCoreApplication::translate("MainWindow", "TD", nullptr));
        nazwaZaklocenia->setText(QCoreApplication::translate("MainWindow", "zaklozenie w %", nullptr));
        nazwaA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        nazwaB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        StartWykresom->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        StopWykresom->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        OkienkoZapiszPlik->setText(QCoreApplication::translate("MainWindow", "Zapis do pliku", nullptr));
        ZakonczProgram->setText(QCoreApplication::translate("MainWindow", " Wyjd\305\272 z Programu", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Skokowy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
