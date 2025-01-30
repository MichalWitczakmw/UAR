/********************************************************************************
** Form generated from reading UI file 'main_Okno_Zapisu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_OKNO_ZAPISU_H
#define UI_MAIN_OKNO_ZAPISU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainOknoZapisu
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *ZapiszTutaj;
    QLineEdit *ScieszkaDoZapisu;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ZapiszZapis;
    QPushButton *ZamknijZapis;
    QCheckBox *binarnieCZYtekstowo;

    void setupUi(QDialog *mainOknoZapisu)
    {
        if (mainOknoZapisu->objectName().isEmpty())
            mainOknoZapisu->setObjectName("mainOknoZapisu");
        mainOknoZapisu->resize(900, 538);
        layoutWidget = new QWidget(mainOknoZapisu);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 140, 351, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ZapiszTutaj = new QLabel(layoutWidget);
        ZapiszTutaj->setObjectName("ZapiszTutaj");

        horizontalLayout->addWidget(ZapiszTutaj);

        ScieszkaDoZapisu = new QLineEdit(layoutWidget);
        ScieszkaDoZapisu->setObjectName("ScieszkaDoZapisu");

        horizontalLayout->addWidget(ScieszkaDoZapisu);

        layoutWidget1 = new QWidget(mainOknoZapisu);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(220, 360, 381, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ZapiszZapis = new QPushButton(layoutWidget1);
        ZapiszZapis->setObjectName("ZapiszZapis");

        horizontalLayout_2->addWidget(ZapiszZapis);

        ZamknijZapis = new QPushButton(layoutWidget1);
        ZamknijZapis->setObjectName("ZamknijZapis");

        horizontalLayout_2->addWidget(ZamknijZapis);

        binarnieCZYtekstowo = new QCheckBox(mainOknoZapisu);
        binarnieCZYtekstowo->setObjectName("binarnieCZYtekstowo");
        binarnieCZYtekstowo->setGeometry(QRect(280, 240, 131, 31));
        binarnieCZYtekstowo->setChecked(false);

        retranslateUi(mainOknoZapisu);

        QMetaObject::connectSlotsByName(mainOknoZapisu);
    } // setupUi

    void retranslateUi(QDialog *mainOknoZapisu)
    {
        mainOknoZapisu->setWindowTitle(QCoreApplication::translate("mainOknoZapisu", "Dialog", nullptr));
        ZapiszTutaj->setText(QCoreApplication::translate("mainOknoZapisu", "Gdzie zapisa\304\207", nullptr));
        ZapiszZapis->setText(QCoreApplication::translate("mainOknoZapisu", "Zapisz", nullptr));
        ZamknijZapis->setText(QCoreApplication::translate("mainOknoZapisu", "Wyjd\305\272 z Zapisu", nullptr));
        binarnieCZYtekstowo->setText(QCoreApplication::translate("mainOknoZapisu", "Binarnie/Tekstowo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainOknoZapisu: public Ui_mainOknoZapisu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_OKNO_ZAPISU_H
