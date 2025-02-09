#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main_Okno_Zapisu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->wartoscA, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscA_1, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscA_2, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscA_3, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));

    connect(ui->wartoscB, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscB_1, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscB_2, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));
    connect(ui->wartoscB_3, SIGNAL(currentIndexChanged()), this, SLOT(aktualizujModel()));

}

MainWindow::~MainWindow()
{
    delete ui;
    if (wykresy != nullptr) {
        delete wykresy;
    }

}

void MainWindow::on_ZakonczProgram_clicked()
{
    this->close();
}

void MainWindow::on_OkienkoZapiszPlik_clicked()
{
    mainOknoZapisu zapisz;
    zapisz.setModal(true);
    zapisz.exec();
}

void MainWindow::aktualizujWartosciObliczonejLayout()
{
    if (!ui->WykresWartosciZO->layout()) {
        ui->WykresWartosciZO->setLayout(new QVBoxLayout);
    }
    if (wykresy) {
        ui->WykresWartosciZO->layout()->addWidget(wykresy->getChartViewWartosciObliczonej());
    } else {
        qDebug() << "Błąd: wykres jest nullptr!";
    }
}

void MainWindow::aktualizujUchybLayout()
{
    if (!ui->WykresUchybu->layout()) {
        ui->WykresUchybu->setLayout(new QVBoxLayout);
    }
    if (wykresy) {
        ui->WykresUchybu->layout()->addWidget(wykresy->getChartViewUchybu());
    } else {
        qDebug() << "Błąd: wykres jest nullptr!";
    }
}

void MainWindow::aktualizujRegulatorLayout()
{
    if (!ui->WykresPID->layout()) {
        ui->WykresPID->setLayout(new QVBoxLayout);
    }
    if (wykresy) {
        ui->WykresPID->layout()->addWidget(wykresy->getChartViewRegulatora());
    } else {
        qDebug() << "Błąd: wykres jest nullptr!";
    }
}

void MainWindow::on_StartWykresom_clicked()
{
    // Przyjęcie wartości
    wartoscZadana = ui->wartoscWynik->value();
    Kp = ui->wartoscKP->value();
    Ti = ui->wartoscTI->value();
    Td = ui->wartoscTD->value();
    a = {ui->wartoscA->value(), ui->wartoscA_1->value(), ui->wartoscA_2->value(), ui->wartoscA_3->value()};
    b = {ui->wartoscB->value(), ui->wartoscB_1->value(), ui->wartoscB_2->value(), ui->wartoscB_3->value()};
    wartoscZaklocenia = ui->wartoscZaklocenia->value();
    wartoscInterwalu = ui->wartoscIntewal->value();
/*
    if(ui->nastawaP->isChecked())
        jakanastawa = 1;
    else if(ui->nastawaI->isChecked())
        jakanastawa = 2;
    else if(ui->nastawaD->isChecked())
        jakanastawa = 3;
    else if(ui->PID->isChecked())
        jakanastawa = 4;
*/

    if(ui->sygnalProstokatny->isChecked())
        chceSygnal = JakiSygnal::Prostokatny;
    else if(ui->sygnalSinuoidalny->isChecked())
        chceSygnal = JakiSygnal::Sinusoidalny;
    else if(ui->sygnalSkokowy->isChecked())
        chceSygnal = JakiSygnal::Skokowy;

    qDebug() << "Nowe wartości: "
             << "wartoscZadana:" << wartoscZadana
             << "Kp:" << Kp
             << "Ti:" << Ti
             << "Td:" << Td
             << "a:" << &a
             << "b:" << &b
             << "wartoscZaklocenia:" << wartoscZaklocenia
             << "wartoscInterwalu:" << wartoscInterwalu
             << "chceSygnal:" << &chceSygnal;

    if (!wykresy)
    {
        wykresy = new RobieWykres(a, b, Kp, Ti, Td,1, chceSygnal, wartoscZadana, wartoscZaklocenia, wartoscInterwalu, this);
        if (!wykresy) {
            qDebug() << "Błąd: nie można utworzyć RobieWykres!";
            return;
        }
    }
    else
    {
        wykresy->setNoweWartosciWykresu(a, b, Kp, Ti, Td,1, chceSygnal, wartoscZadana, wartoscZaklocenia, wartoscInterwalu);
    }

    wykresy->setTimerStop(false);

    aktualizujWartosciObliczonejLayout();
    aktualizujUchybLayout();
    aktualizujRegulatorLayout();
}

void MainWindow::on_Reset_clicked()
{
    if (wykresy)
    {
        wykresy->Resetuj();
        wykresy->setTimerStop(true); // Zatrzymanie wykresu
    }

    // Resetowanie wartości w GUI
    ui->wartoscWynik->setValue(0);
    ui->wartoscKP->setValue(0);
    ui->wartoscTI->setValue(0);
    ui->wartoscTD->setValue(0);
    ui->wartoscA->setValue(0);
    ui->wartoscA_1->setValue(0.0);
    ui->wartoscA_2->setValue(0.0);
    ui->wartoscA_3->setValue(0.0);
    ui->wartoscB->setValue(0);
    ui->wartoscB_1->setValue(0.0);
    ui->wartoscB_2->setValue(0.0);
    ui->wartoscB_3->setValue(0.0);
    ui->wartoscZaklocenia->setValue(0);
    ui->wartoscIntewal->setValue(0);

    // Resetowanie wartości w zmiennych
    wartoscZadana = 0;
    Kp = 0;
    Ti = 0;
    Td = 0;
    a = {0, 0.0, 0.0, 0.0};
    b = {0, 0.0, 0.0, 0.0};
    wartoscZaklocenia = 0;
    wartoscInterwalu = 0;
    chceSygnal = JakiSygnal::Skokowy;
}

void MainWindow::on_StopWykresom_clicked()
{
    if (wykresy)
        wykresy->setTimerStop(true);
}

void MainWindow::on_wartoscKP_valueChanged(double kp)
{
    if(wykresy)
        wykresy->setPIDkp(kp);
}


void MainWindow::on_wartoscTI_valueChanged(double ti)
{
    if(wykresy)
        wykresy->setPIDkp(ti);
}


void MainWindow::on_wartoscTD_valueChanged(double td)
{
    if(wykresy)
        wykresy->setPIDkp(td);
}

/*
void MainWindow::on_sygnalSkokowy_cliked(bool checked)
{
    if(checked)
        wykresy->setSygnal(JakiSygnal::Skokowy);
}


void MainWindow::on_sygnalSinuoidalny_cliked(bool checked)
{
    if(checked)
        wykresy->setSygnal(JakiSygnal::Sinusoidalny);
}


void MainWindow::on_sygnalProstokatny_cliked(bool checked)
{
    if(checked)
        wykresy->setSygnal(JakiSygnal::Prostokatny);
}
*/

void MainWindow::on_wartoscWynik_valueChanged(double zadana)
{
    if(wykresy)
        wykresy->setWartoscZadana(zadana);
}


void MainWindow::on_wartoscIntewal_valueChanged(int wi)
{
    if(wykresy)
        wykresy->setInterwal(wi);
}


void MainWindow::on_wartoscZaklocenia_valueChanged(int zaklocenie)
{
    if(wykresy)
        wykresy->setZaklocenie(zaklocenie);
}

