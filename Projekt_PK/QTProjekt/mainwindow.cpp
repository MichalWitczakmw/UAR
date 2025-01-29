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
    /*
    if (wykresWartosciWyjsciowej)
    {
        delete wykresWartosciWyjsciowej;
        wykresWartosciWyjsciowej = nullptr;
    }
    if (wykresUchyb)
    {
        delete wykresUchyb;
        wykresUchyb = nullptr;
    }
    if (wykresRegulatoraPID)
    {
        delete wykresRegulatoraPID;
        wykresRegulatoraPID = nullptr;
    }
*/
    if(wykresy !=nullptr)
        delete wykresy;
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
    //przyjecie wartosci
    wartoscZadana = ui->wartoscWynik->value();
    Kp = ui->wartoscKP->value();
    Ti = ui->wartoscTI->value();
    Td = ui->wartoscTD->value();
    a = {ui->wartoscA->value()};
    b = {ui->wartoscB->value()};
    wartoscZaklocenia = ui->wartoscZaklocenia->value();

    if (!wykresy)
    {
        wykresy = new RobieWykres(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia, 100, this);
        if (!wykresy) {
            qDebug() << "Błąd: nie można utworzyć RobieWykres!";
            return;
        }
    }

    wykresy->setNoweWartosciWykresu(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia);
    wykresy->setTimerStop(false);

    aktualizujWartosciObliczonejLayout();
    aktualizujUchybLayout();
    aktualizujRegulatorLayout();
    /*
    if(niebylo)
    {
    // Tworzenie trzech okienek z wykresami
    wykresWartosciWyjsciowej = new RobieWykres(a,b,Kp,Ti,Td,JakiSygnal::Prostokatny,wartoscZadana, wartoscZaklocenia,100, this);

    if(wykresWartosciWyjsciowej)
        wykresWartosciWyjsciowej->setTimerStop(false);
    wykresUchyb = wykresWartosciWyjsciowej;

    ui->WykresWartosciZO->setLayout(new QVBoxLayout);
    ui->WykresUchybu->setLayout(new QVBoxLayout);
    //ui->WykresPID->setLayout(new QVBoxLayout);
    niebylo = false;
    }

    if (niebylo) {
        wykresWartosciWyjsciowej = new RobieWykres(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia, 100, this);

        ui->WykresWartosciZO->setLayout(new QVBoxLayout);
        ui->WykresUchybu->setLayout(new QVBoxLayout);
        ui->WykresPID->setLayout(new QVBoxLayout);

        ui->WykresWartosciZO->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewWartosciObliczonej());
        ui->WykresUchybu->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewUchybu());
        ui->WykresPID->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewRegulatora());

        niebylo = false;
    }
    if (ui->WykresWartosciZO->layout()->count() == 0) {
        ui->WykresWartosciZO->layout()->addWidget(wykresWartosciWyjsciowej);
    }
    ui->WykresUchybu->layout()->addWidget(wykresUchyb);
    //ui->WykresProstokatny->layout()->addWidget( wykresRegulatoraPID);
    //this->replot()
    wykresWartosciWyjsciowej->aktualizacjawykresu();
    wykresWartosciWyjsciowej->setNoweWartosciWykresu(a,b,Kp,Ti,Td,JakiSygnal::Prostokatny,wartoscZadana,wartoscZaklocenia);
    if(wykresWartosciWyjsciowej)
    {
        wykresWartosciWyjsciowej->setTimerStop(false);
    }

    if (!wykresWartosciWyjsciowej) {
        wykresWartosciWyjsciowej = new RobieWykres(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia, 100, this);

        //ui->WykresUchybu->setLayout(new QVBoxLayout);
        //ui->WykresPID->setLayout(new QVBoxLayout);

        if (!ui->WykresWartosciZO->layout())
            ui->WykresWartosciZO->setLayout(new QVBoxLayout);
        ui->WykresWartosciZO->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewWartosciObliczonej());
        if (!ui->WykresUchybu->layout())
            ui->WykresUchybu->setLayout(new QVBoxLayout);
        ui->WykresUchybu->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewWartosciObliczonej());
        if (!ui->WykresPID->layout())
            ui->WykresPID->setLayout(new QVBoxLayout);
        ui->WykresPID->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewWartosciObliczonej());
        //ui->WykresUchybu->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewUchybu());
        //ui->WykresPID->layout()->addWidget(wykresWartosciWyjsciowej->getChartViewRegulatora());
    }

    // Jeśli instancja nie istnieje, tworzę ją
    if (!wykresWartosciWyjsciowej) {
        wykresWartosciWyjsciowej = new RobieWykres(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia, 100, this);
    }
    // Aktualizacja wartości
    wykresWartosciWyjsciowej->setNoweWartosciWykresu(a, b, Kp, Ti, Td, JakiSygnal::Prostokatny, wartoscZadana, wartoscZaklocenia);
    wykresWartosciWyjsciowej->setTimerStop(false);

    // Aktualizacja layoutów
    aktualizujWartosciObliczonejLayout();
    aktualizujUchybLayout();
    aktualizujRegulatorLayout();
    */
}

void MainWindow::on_Reset_clicked()
{
    if (wykresy)
        wykresy->Resetuj();
}

void MainWindow::on_StopWykresom_clicked()
{
    if(wykresy)
        wykresy->setTimerStop(true);
}



