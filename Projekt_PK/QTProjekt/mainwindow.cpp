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
    // Tworzenie trzech okienek z wykresami
    //zamiast 1 to wartoscZaklocenia,
    robwykreSkokowy = new RobieWykres(JakiSygnal::Skokowy, 1, this);
    robwykreSinusoidalny = new RobieWykres(JakiSygnal::Sinusoidalny,1, this);
    robwykresProstokatny = new RobieWykres(JakiSygnal::Prostokatny,1, this);

    ui->WykresSkokowy->setLayout(new QVBoxLayout);
    ui->WykresSinusoidalny->setLayout(new QVBoxLayout);
    ui->WykresProstokatny->setLayout(new QVBoxLayout);

    ui->WykresSkokowy->layout()->addWidget(robwykreSkokowy);
    ui->WykresSinusoidalny->layout()->addWidget(robwykreSinusoidalny);
    ui->WykresProstokatny->layout()->addWidget(robwykresProstokatny);
}


void MainWindow::on_StopWykresom_clicked()
{

}


