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
#include <QtWidgets/QFormLayout>
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
    QWidget *widget;
    QFormLayout *formLayout;
    QChartView *WykresProstokatny;
    QChartView *WykresSinusoidalny;
    QChartView *WykresSkokowy;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *wynik_3;
    QDoubleSpinBox *wynik_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QDoubleSpinBox *wartoscKP_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QDoubleSpinBox *wartoscKI_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QDoubleSpinBox *wartoscKD_3;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_16;
    QLabel *wynik_5;
    QDoubleSpinBox *wynik_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_10;
    QDoubleSpinBox *wartoscKP_4;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_11;
    QDoubleSpinBox *wartoscKI_4;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_12;
    QDoubleSpinBox *wartoscKD_4;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *wynik_2;
    QDoubleSpinBox *wynik;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *wartoscKP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *wartoscKI;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *wartoscKD;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1318, 778);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(431, 1, 481, 671));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::FieldsStayAtSizeHint);
        formLayout->setRowWrapPolicy(QFormLayout::RowWrapPolicy::DontWrapRows);
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(0, 0, 0, 0);
        WykresProstokatny = new QChartView(widget);
        WykresProstokatny->setObjectName("WykresProstokatny");
        WykresProstokatny->setMinimumSize(QSize(350, 150));

        formLayout->setWidget(3, QFormLayout::LabelRole, WykresProstokatny);

        WykresSinusoidalny = new QChartView(widget);
        WykresSinusoidalny->setObjectName("WykresSinusoidalny");
        WykresSinusoidalny->setMinimumSize(QSize(350, 150));

        formLayout->setWidget(2, QFormLayout::LabelRole, WykresSinusoidalny);

        WykresSkokowy = new QChartView(widget);
        WykresSkokowy->setObjectName("WykresSkokowy");
        WykresSkokowy->setMinimumSize(QSize(350, 150));

        formLayout->setWidget(1, QFormLayout::LabelRole, WykresSkokowy);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(150, 290, 191, 160));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        wynik_3 = new QLabel(layoutWidget_3);
        wynik_3->setObjectName("wynik_3");

        horizontalLayout_8->addWidget(wynik_3);

        wynik_4 = new QDoubleSpinBox(layoutWidget_3);
        wynik_4->setObjectName("wynik_4");
        wynik_4->setSingleStep(0.010000000000000);

        horizontalLayout_8->addWidget(wynik_4);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        wartoscKP_3 = new QDoubleSpinBox(layoutWidget_3);
        wartoscKP_3->setObjectName("wartoscKP_3");
        wartoscKP_3->setSingleStep(0.010000000000000);

        horizontalLayout_9->addWidget(wartoscKP_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName("label_8");

        horizontalLayout_12->addWidget(label_8);

        wartoscKI_3 = new QDoubleSpinBox(layoutWidget_3);
        wartoscKI_3->setObjectName("wartoscKI_3");
        wartoscKI_3->setSingleStep(0.010000000000000);

        horizontalLayout_12->addWidget(wartoscKI_3);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName("label_9");

        horizontalLayout_14->addWidget(label_9);

        wartoscKD_3 = new QDoubleSpinBox(layoutWidget_3);
        wartoscKD_3->setObjectName("wartoscKD_3");
        wartoscKD_3->setSingleStep(0.010000000000000);

        horizontalLayout_14->addWidget(wartoscKD_3);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        pushButton_6 = new QPushButton(layoutWidget_3);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_15->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget_3);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout_15->addWidget(pushButton_7);


        verticalLayout_3->addLayout(horizontalLayout_15);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(150, 490, 191, 160));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        wynik_5 = new QLabel(layoutWidget_4);
        wynik_5->setObjectName("wynik_5");

        horizontalLayout_16->addWidget(wynik_5);

        wynik_6 = new QDoubleSpinBox(layoutWidget_4);
        wynik_6->setObjectName("wynik_6");
        wynik_6->setSingleStep(0.010000000000000);

        horizontalLayout_16->addWidget(wynik_6);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_10 = new QLabel(layoutWidget_4);
        label_10->setObjectName("label_10");

        horizontalLayout_17->addWidget(label_10);

        wartoscKP_4 = new QDoubleSpinBox(layoutWidget_4);
        wartoscKP_4->setObjectName("wartoscKP_4");
        wartoscKP_4->setSingleStep(0.010000000000000);

        horizontalLayout_17->addWidget(wartoscKP_4);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_11 = new QLabel(layoutWidget_4);
        label_11->setObjectName("label_11");

        horizontalLayout_18->addWidget(label_11);

        wartoscKI_4 = new QDoubleSpinBox(layoutWidget_4);
        wartoscKI_4->setObjectName("wartoscKI_4");
        wartoscKI_4->setSingleStep(0.010000000000000);

        horizontalLayout_18->addWidget(wartoscKI_4);


        verticalLayout_4->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName("label_12");

        horizontalLayout_19->addWidget(label_12);

        wartoscKD_4 = new QDoubleSpinBox(layoutWidget_4);
        wartoscKD_4->setObjectName("wartoscKD_4");
        wartoscKD_4->setSingleStep(0.010000000000000);

        horizontalLayout_19->addWidget(wartoscKD_4);


        verticalLayout_4->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        pushButton_9 = new QPushButton(layoutWidget_4);
        pushButton_9->setObjectName("pushButton_9");

        horizontalLayout_20->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget_4);
        pushButton_10->setObjectName("pushButton_10");

        horizontalLayout_20->addWidget(pushButton_10);


        verticalLayout_4->addLayout(horizontalLayout_20);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(150, 80, 191, 160));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        wynik_2 = new QLabel(widget1);
        wynik_2->setObjectName("wynik_2");

        horizontalLayout_7->addWidget(wynik_2);

        wynik = new QDoubleSpinBox(widget1);
        wynik->setObjectName("wynik");
        wynik->setSingleStep(0.010000000000000);

        horizontalLayout_7->addWidget(wynik);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        wartoscKP = new QDoubleSpinBox(widget1);
        wartoscKP->setObjectName("wartoscKP");
        wartoscKP->setSingleStep(0.010000000000000);

        horizontalLayout->addWidget(wartoscKP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        wartoscKI = new QDoubleSpinBox(widget1);
        wartoscKI->setObjectName("wartoscKI");
        wartoscKI->setSingleStep(0.010000000000000);

        horizontalLayout_2->addWidget(wartoscKI);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        wartoscKD = new QDoubleSpinBox(widget1);
        wartoscKD->setObjectName("wartoscKD");
        wartoscKD->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(wartoscKD);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName("pushButton");

        horizontalLayout_10->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_10);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(490, 680, 361, 51));
        horizontalLayout_13 = new QHBoxLayout(widget2);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(widget2);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout_13->addWidget(pushButton_8);

        pushButton_3 = new QPushButton(widget2);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_13->addWidget(pushButton_3);

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
        wynik_3->setText(QCoreApplication::translate("MainWindow", "Wynik", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "KI", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "KD", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        wynik_5->setText(QCoreApplication::translate("MainWindow", "Wynik", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "KI", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "KD", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        wynik_2->setText(QCoreApplication::translate("MainWindow", "Wynik", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "KP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "KI", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "KD", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Zapis do pliku", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Wyjd\305\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
