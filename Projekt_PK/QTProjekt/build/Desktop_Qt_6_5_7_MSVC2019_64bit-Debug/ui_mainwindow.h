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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
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
    QHBoxLayout *horizontalLayout_10;
    QPushButton *StartWykresom;
    QPushButton *StopWykresom;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *OkienkoZapiszPlik;
    QPushButton *ZakonczProgram;
    QChartView *WykresProstokatny;
    QChartView *WykresSkokowy;
    QChartView *WykresSinusoidalny;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1318, 778);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 361, 481));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        NazwaWyniku = new QLabel(layoutWidget);
        NazwaWyniku->setObjectName("NazwaWyniku");
        NazwaWyniku->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(NazwaWyniku);

        wartoscWynik = new QDoubleSpinBox(layoutWidget);
        wartoscWynik->setObjectName("wartoscWynik");
        wartoscWynik->setSingleStep(0.010000000000000);

        horizontalLayout_7->addWidget(wartoscWynik);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NazwaKP = new QLabel(layoutWidget);
        NazwaKP->setObjectName("NazwaKP");
        NazwaKP->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(NazwaKP);

        wartoscKP = new QDoubleSpinBox(layoutWidget);
        wartoscKP->setObjectName("wartoscKP");
        wartoscKP->setSingleStep(0.010000000000000);

        horizontalLayout->addWidget(wartoscKP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NazwaTI = new QLabel(layoutWidget);
        NazwaTI->setObjectName("NazwaTI");
        NazwaTI->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(NazwaTI);

        wartoscTI = new QDoubleSpinBox(layoutWidget);
        wartoscTI->setObjectName("wartoscTI");
        wartoscTI->setSingleStep(0.010000000000000);

        horizontalLayout_2->addWidget(wartoscTI);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        NazwaTD = new QLabel(layoutWidget);
        NazwaTD->setObjectName("NazwaTD");
        NazwaTD->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(NazwaTD);

        wartoscTD = new QDoubleSpinBox(layoutWidget);
        wartoscTD->setObjectName("wartoscTD");
        wartoscTD->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(wartoscTD);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        StartWykresom = new QPushButton(layoutWidget);
        StartWykresom->setObjectName("StartWykresom");

        horizontalLayout_10->addWidget(StartWykresom);

        StopWykresom = new QPushButton(layoutWidget);
        StopWykresom->setObjectName("StopWykresom");

        horizontalLayout_10->addWidget(StopWykresom);


        verticalLayout->addLayout(horizontalLayout_10);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 530, 361, 51));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        OkienkoZapiszPlik = new QPushButton(layoutWidget1);
        OkienkoZapiszPlik->setObjectName("OkienkoZapiszPlik");

        horizontalLayout_13->addWidget(OkienkoZapiszPlik);

        ZakonczProgram = new QPushButton(layoutWidget1);
        ZakonczProgram->setObjectName("ZakonczProgram");

        horizontalLayout_13->addWidget(ZakonczProgram);

        WykresProstokatny = new QChartView(centralwidget);
        WykresProstokatny->setObjectName("WykresProstokatny");
        WykresProstokatny->setGeometry(QRect(440, 250, 551, 251));
        WykresProstokatny->setMinimumSize(QSize(350, 150));
        WykresSkokowy = new QChartView(centralwidget);
        WykresSkokowy->setObjectName("WykresSkokowy");
        WykresSkokowy->setGeometry(QRect(440, 0, 551, 251));
        WykresSkokowy->setMinimumSize(QSize(350, 150));
        WykresSinusoidalny = new QChartView(centralwidget);
        WykresSinusoidalny->setObjectName("WykresSinusoidalny");
        WykresSinusoidalny->setGeometry(QRect(440, 500, 551, 231));
        WykresSinusoidalny->setMinimumSize(QSize(350, 150));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 260, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 20, 81, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(670, 520, 91, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1318, 21));
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
        NazwaWyniku->setText(QCoreApplication::translate("MainWindow", "Wpisz wynik do uzyskania", nullptr));
        NazwaKP->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        NazwaTI->setText(QCoreApplication::translate("MainWindow", "TI", nullptr));
        NazwaTD->setText(QCoreApplication::translate("MainWindow", "TD", nullptr));
        StartWykresom->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        StopWykresom->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        OkienkoZapiszPlik->setText(QCoreApplication::translate("MainWindow", "Zapis do pliku", nullptr));
        ZakonczProgram->setText(QCoreApplication::translate("MainWindow", " Wyjd\305\272 z Programu", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Prostok\304\205tny", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Skokowy", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sinusoidalny", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
