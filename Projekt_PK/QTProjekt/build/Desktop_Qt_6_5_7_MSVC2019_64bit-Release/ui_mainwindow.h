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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *wartosciWykresow;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *NazwaWyniku;
    QDoubleSpinBox *wartoscWynik;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nazwaZaklocenia;
    QSpinBox *wartoscZaklocenia;
    QHBoxLayout *horizontalLayout_9;
    QLabel *nazwaInterwal;
    QSpinBox *wartoscIntewal;
    QGroupBox *wartosciRegulatoraPID;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *NazwaKP;
    QDoubleSpinBox *wartoscKP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NazwaTI;
    QDoubleSpinBox *wartoscTI;
    QHBoxLayout *horizontalLayout_3;
    QLabel *NazwaTD;
    QDoubleSpinBox *wartoscTD;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *nazwawartosciA;
    QDoubleSpinBox *wartoscA;
    QDoubleSpinBox *wartoscA_1;
    QDoubleSpinBox *wartoscA_2;
    QDoubleSpinBox *wartoscA_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *nazwawartosciB;
    QDoubleSpinBox *wartoscB;
    QDoubleSpinBox *wartoscB_1;
    QDoubleSpinBox *wartoscB_2;
    QDoubleSpinBox *wartoscB_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *sygnalSkokowy;
    QRadioButton *sygnalSinuoidalny;
    QRadioButton *sygnalProstokatny;
    QGroupBox *Przyciski;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *StartWykresom;
    QPushButton *StopWykresom;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *ZapiszPrzycisk;
    QPushButton *WycztajPrzycisk;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *ZakonczProgram;
    QVBoxLayout *verticalLayout_2;
    QChartView *WykresWartosciZO;
    QHBoxLayout *horizontalLayout_8;
    QChartView *WykresUchybu;
    QChartView *WykresPID;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1514, 857);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        wartosciWykresow = new QGroupBox(centralwidget);
        wartosciWykresow->setObjectName("wartosciWykresow");
        wartosciWykresow->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_5 = new QGridLayout(wartosciWykresow);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        NazwaWyniku = new QLabel(wartosciWykresow);
        NazwaWyniku->setObjectName("NazwaWyniku");
        NazwaWyniku->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(NazwaWyniku);

        wartoscWynik = new QDoubleSpinBox(wartosciWykresow);
        wartoscWynik->setObjectName("wartoscWynik");
        wartoscWynik->setMaximum(10000.000000000000000);
        wartoscWynik->setSingleStep(0.010000000000000);
        wartoscWynik->setValue(10.000000000000000);

        horizontalLayout_7->addWidget(wartoscWynik);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        nazwaZaklocenia = new QLabel(wartosciWykresow);
        nazwaZaklocenia->setObjectName("nazwaZaklocenia");
        nazwaZaklocenia->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(nazwaZaklocenia);

        wartoscZaklocenia = new QSpinBox(wartosciWykresow);
        wartoscZaklocenia->setObjectName("wartoscZaklocenia");
        wartoscZaklocenia->setMinimum(0);
        wartoscZaklocenia->setMaximum(5);

        horizontalLayout_4->addWidget(wartoscZaklocenia);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        nazwaInterwal = new QLabel(wartosciWykresow);
        nazwaInterwal->setObjectName("nazwaInterwal");
        nazwaInterwal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(nazwaInterwal);

        wartoscIntewal = new QSpinBox(wartosciWykresow);
        wartoscIntewal->setObjectName("wartoscIntewal");
        wartoscIntewal->setMinimum(100);
        wartoscIntewal->setMaximum(1000);
        wartoscIntewal->setValue(100);
        wartoscIntewal->setDisplayIntegerBase(10);

        horizontalLayout_9->addWidget(wartoscIntewal);


        verticalLayout_8->addLayout(horizontalLayout_9);


        gridLayout_5->addLayout(verticalLayout_8, 0, 0, 1, 1);


        verticalLayout_9->addWidget(wartosciWykresow);

        wartosciRegulatoraPID = new QGroupBox(centralwidget);
        wartosciRegulatoraPID->setObjectName("wartosciRegulatoraPID");
        wartosciRegulatoraPID->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_2 = new QGridLayout(wartosciRegulatoraPID);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NazwaKP = new QLabel(wartosciRegulatoraPID);
        NazwaKP->setObjectName("NazwaKP");
        NazwaKP->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(NazwaKP);

        wartoscKP = new QDoubleSpinBox(wartosciRegulatoraPID);
        wartoscKP->setObjectName("wartoscKP");
        wartoscKP->setMaximum(10.000000000000000);
        wartoscKP->setSingleStep(0.010000000000000);
        wartoscKP->setValue(1.000000000000000);

        horizontalLayout->addWidget(wartoscKP);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NazwaTI = new QLabel(wartosciRegulatoraPID);
        NazwaTI->setObjectName("NazwaTI");
        NazwaTI->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(NazwaTI);

        wartoscTI = new QDoubleSpinBox(wartosciRegulatoraPID);
        wartoscTI->setObjectName("wartoscTI");
        wartoscTI->setMaximum(10.000000000000000);
        wartoscTI->setSingleStep(0.010000000000000);
        wartoscTI->setValue(0.600000000000000);

        horizontalLayout_2->addWidget(wartoscTI);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        NazwaTD = new QLabel(wartosciRegulatoraPID);
        NazwaTD->setObjectName("NazwaTD");
        NazwaTD->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(NazwaTD);

        wartoscTD = new QDoubleSpinBox(wartosciRegulatoraPID);
        wartoscTD->setObjectName("wartoscTD");
        wartoscTD->setMaximum(10.000000000000000);
        wartoscTD->setSingleStep(0.010000000000000);
        wartoscTD->setValue(0.500000000000000);

        horizontalLayout_3->addWidget(wartoscTD);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_11->addLayout(verticalLayout_5);


        gridLayout_2->addLayout(verticalLayout_11, 0, 0, 1, 1);


        verticalLayout_9->addWidget(wartosciRegulatoraPID);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox->setFlat(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        nazwawartosciA = new QLabel(groupBox);
        nazwawartosciA->setObjectName("nazwawartosciA");
        nazwawartosciA->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(nazwawartosciA);

        wartoscA = new QDoubleSpinBox(groupBox);
        wartoscA->setObjectName("wartoscA");
        wartoscA->setMinimum(-99.000000000000000);
        wartoscA->setSingleStep(0.010000000000000);
        wartoscA->setValue(0.600000000000000);

        verticalLayout_3->addWidget(wartoscA);

        wartoscA_1 = new QDoubleSpinBox(groupBox);
        wartoscA_1->setObjectName("wartoscA_1");
        wartoscA_1->setMinimum(-99.000000000000000);
        wartoscA_1->setSingleStep(0.010000000000000);
        wartoscA_1->setValue(0.000000000000000);

        verticalLayout_3->addWidget(wartoscA_1);

        wartoscA_2 = new QDoubleSpinBox(groupBox);
        wartoscA_2->setObjectName("wartoscA_2");
        wartoscA_2->setMinimum(-99.000000000000000);
        wartoscA_2->setSingleStep(0.010000000000000);
        wartoscA_2->setValue(0.000000000000000);

        verticalLayout_3->addWidget(wartoscA_2);

        wartoscA_3 = new QDoubleSpinBox(groupBox);
        wartoscA_3->setObjectName("wartoscA_3");
        wartoscA_3->setMinimum(-99.000000000000000);
        wartoscA_3->setSingleStep(0.010000000000000);
        wartoscA_3->setValue(0.000000000000000);

        verticalLayout_3->addWidget(wartoscA_3);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        nazwawartosciB = new QLabel(groupBox);
        nazwawartosciB->setObjectName("nazwawartosciB");
        nazwawartosciB->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(nazwawartosciB);

        wartoscB = new QDoubleSpinBox(groupBox);
        wartoscB->setObjectName("wartoscB");
        wartoscB->setMinimum(-99.000000000000000);
        wartoscB->setSingleStep(0.010000000000000);
        wartoscB->setValue(0.400000000000000);

        verticalLayout_4->addWidget(wartoscB);

        wartoscB_1 = new QDoubleSpinBox(groupBox);
        wartoscB_1->setObjectName("wartoscB_1");
        wartoscB_1->setMinimum(-99.000000000000000);
        wartoscB_1->setSingleStep(0.010000000000000);
        wartoscB_1->setValue(0.000000000000000);

        verticalLayout_4->addWidget(wartoscB_1);

        wartoscB_2 = new QDoubleSpinBox(groupBox);
        wartoscB_2->setObjectName("wartoscB_2");
        wartoscB_2->setMinimum(-99.000000000000000);
        wartoscB_2->setSingleStep(0.010000000000000);
        wartoscB_2->setValue(0.000000000000000);

        verticalLayout_4->addWidget(wartoscB_2);

        wartoscB_3 = new QDoubleSpinBox(groupBox);
        wartoscB_3->setObjectName("wartoscB_3");
        wartoscB_3->setMinimum(-99.000000000000000);
        wartoscB_3->setSingleStep(0.010000000000000);
        wartoscB_3->setValue(0.000000000000000);

        verticalLayout_4->addWidget(wartoscB_3);


        horizontalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        verticalLayout_9->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        sygnalSkokowy = new QRadioButton(groupBox_2);
        sygnalSkokowy->setObjectName("sygnalSkokowy");
        sygnalSkokowy->setChecked(true);

        verticalLayout_6->addWidget(sygnalSkokowy);

        sygnalSinuoidalny = new QRadioButton(groupBox_2);
        sygnalSinuoidalny->setObjectName("sygnalSinuoidalny");

        verticalLayout_6->addWidget(sygnalSinuoidalny);

        sygnalProstokatny = new QRadioButton(groupBox_2);
        sygnalProstokatny->setObjectName("sygnalProstokatny");

        verticalLayout_6->addWidget(sygnalProstokatny);


        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 1, 1);


        verticalLayout_9->addWidget(groupBox_2);

        Przyciski = new QGroupBox(centralwidget);
        Przyciski->setObjectName("Przyciski");
        Przyciski->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_4 = new QGridLayout(Przyciski);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        StartWykresom = new QPushButton(Przyciski);
        StartWykresom->setObjectName("StartWykresom");

        horizontalLayout_10->addWidget(StartWykresom);

        StopWykresom = new QPushButton(Przyciski);
        StopWykresom->setObjectName("StopWykresom");

        horizontalLayout_10->addWidget(StopWykresom);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        ZapiszPrzycisk = new QPushButton(Przyciski);
        ZapiszPrzycisk->setObjectName("ZapiszPrzycisk");

        horizontalLayout_6->addWidget(ZapiszPrzycisk);

        WycztajPrzycisk = new QPushButton(Przyciski);
        WycztajPrzycisk->setObjectName("WycztajPrzycisk");

        horizontalLayout_6->addWidget(WycztajPrzycisk);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        ZakonczProgram = new QPushButton(Przyciski);
        ZakonczProgram->setObjectName("ZakonczProgram");

        horizontalLayout_13->addWidget(ZakonczProgram);


        verticalLayout_7->addLayout(horizontalLayout_13);


        gridLayout_4->addLayout(verticalLayout_7, 0, 0, 1, 1);


        verticalLayout_9->addWidget(Przyciski);


        gridLayout_6->addLayout(verticalLayout_9, 0, 1, 1, 1);

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


        gridLayout_6->addLayout(verticalLayout_2, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

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
        wartosciWykresow->setTitle(QCoreApplication::translate("MainWindow", "Wartosci wykres\303\263w", nullptr));
        NazwaWyniku->setText(QCoreApplication::translate("MainWindow", "Wartosc Zadana", nullptr));
        nazwaZaklocenia->setText(QCoreApplication::translate("MainWindow", "zaklozenie w %", nullptr));
        nazwaInterwal->setText(QCoreApplication::translate("MainWindow", "interwa\305\202", nullptr));
        wartosciRegulatoraPID->setTitle(QCoreApplication::translate("MainWindow", "Regulator PID", nullptr));
        NazwaKP->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        NazwaTI->setText(QCoreApplication::translate("MainWindow", "TI", nullptr));
        NazwaTD->setText(QCoreApplication::translate("MainWindow", "TD", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Model ARX", nullptr));
        nazwawartosciA->setText(QCoreApplication::translate("MainWindow", "Wsp\303\263\305\202czynniki A", nullptr));
        nazwawartosciB->setText(QCoreApplication::translate("MainWindow", "Wsp\303\263\305\202czynniki B", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Jaki chcesz sygna\305\202", nullptr));
        sygnalSkokowy->setText(QCoreApplication::translate("MainWindow", "Skokowy", nullptr));
        sygnalSinuoidalny->setText(QCoreApplication::translate("MainWindow", "Sinusoidalny", nullptr));
        sygnalProstokatny->setText(QCoreApplication::translate("MainWindow", "Prostok\304\205tny", nullptr));
        Przyciski->setTitle(QCoreApplication::translate("MainWindow", "Opcje kontrolne", nullptr));
        StartWykresom->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        StopWykresom->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        ZapiszPrzycisk->setText(QCoreApplication::translate("MainWindow", "Zapis", nullptr));
        WycztajPrzycisk->setText(QCoreApplication::translate("MainWindow", "Wczytaj", nullptr));
        ZakonczProgram->setText(QCoreApplication::translate("MainWindow", " Wyjd\305\272 z Programu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
