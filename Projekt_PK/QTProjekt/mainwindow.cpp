#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main_Okno_Zapisu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete sprzerzenie;
    //delete regulPID;
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


void MainWindow::on_StartWykresom_clicked()
{
    //przyjecie wartosci
    wartoscZadana = ui->wartoscWynik->value();
    Kp = ui->wartoscKP->value();
    Ti = ui->wartoscTI->value();
    Td = ui->wartoscTD->value();
    a = {ui->wartoscA->value()};
    b = {ui->wartoscB->value()};
    wartoscZaklocenia = ui->wartoscZaklocenia->value();

    // Tworzenie trzech okienek z wykresami
    //zamiast 1 to wartoscZaklocenia,
    wykresWartosciWyjsciowej = new RobieWykres(a,b,Kp,Ti,Td,JakiSygnal::Skokowy, wartoscZaklocenia, this);
    wykresUchybu = new RobieWykres(a,b,Kp,Ti,Td,JakiSygnal::Sinusoidalny,wartoscZaklocenia, this);
    wykresRegulatoraPID = new RobieWykres(a,b,Kp,Ti,Td,JakiSygnal::Prostokatny,wartoscZaklocenia, this);

    ui->WykresSkokowy->setLayout(new QVBoxLayout);
    ui->WykresSinusoidalny->setLayout(new QVBoxLayout);
    ui->WykresProstokatny->setLayout(new QVBoxLayout);

    ui->WykresSkokowy->layout()->addWidget(wykresWartosciWyjsciowej);
    ui->WykresSinusoidalny->layout()->addWidget(wykresUchybu);
    ui->WykresProstokatny->layout()->addWidget( wykresRegulatoraPID);
}


void MainWindow::on_StopWykresom_clicked()
{

}



void MainWindow::on_Reset_clicked()
{
    wykresWartosciWyjsciowej->Resetuj();
    wykresUchybu->Resetuj();
    wykresRegulatoraPID->Resetuj();
}

