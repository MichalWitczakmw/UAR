#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main_Okno_Zapisu.h"
#include <QFileDialog>
#include <QString>

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

    connect(ui->sygnalSkokowy, SIGNAL(toggled(bool)), this, SLOT(on_sygnalSkokowy_toggled(bool)));
    connect(ui->sygnalSinuoidalny, SIGNAL(toggled(bool)), this, SLOT(on_sygnalSinuoidalny_toggled(bool)));
    connect(ui->sygnalProstokatny, SIGNAL(toggled(bool)), this, SLOT(on_sygnalProstokatny_toggled(bool)));

    connect(wykresy, &RobieWykres::daneWczytane, this, &MainWindow::onDaneWczytane);

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


void MainWindow::on_groupBox_clicked()
{
    connect(ui->wartoscA, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscA_1, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscA_2, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscA_3, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));

    connect(ui->wartoscB, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscB_1, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscB_2, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));
    connect(ui->wartoscB_3, SIGNAL(valueChanged(double)), this, SLOT(on_wartosc_valueChanged()));

    // Pierwsza aktualizacja wartości
    on_wartosc_valueChanged();
}
// Aktualizuje kolejki deque i propaguje je do dalszej części programu
void MainWindow::on_wartosc_valueChanged()
{
    std::deque<double> a = {ui->wartoscA->value(), ui->wartoscA_1->value(),
                            ui->wartoscA_2->value(), ui->wartoscA_3->value()};
    std::deque<double> b = {ui->wartoscB->value(), ui->wartoscB_1->value(),
                            ui->wartoscB_2->value(), ui->wartoscB_3->value()};

    wykresy->setWSPAB(a, b);
}


void MainWindow::on_ZapiszPrzycisk_clicked()
{
    if (wykresy)
        wykresy->setTimerStop(true);
    QString nazwaPliku = QFileDialog::getOpenFileName(this,"Zapisz Plik","C://");
    wykresy->zapiszDOPliku(nazwaPliku);
}


void MainWindow::on_WycztajPrzycisk_clicked()
{
    if (wykresy)
        wykresy->setTimerStop(true);

    QString nazwaPliku = QFileDialog::getOpenFileName(this, "Otwórz Plik", "C://");

    if (!nazwaPliku.isEmpty()) {
        qDebug() << "Plik wybrany do wczytania: " << nazwaPliku;
        wykresy->wczytajZPliku(nazwaPliku);
    } else {
        qWarning() << "Nie wybrano pliku!";
    }
}

void MainWindow::onDaneWczytane(double KP, double TI, double TD, double WZ, double ZK, int I, std::deque<double> a, std::deque<double> b)
{
    qDebug() << "Otrzymano sygnał daneWczytane! Aktualizacja UI...";

    ui->wartoscA->setValue(a.size() > 0 ? a[0] : 0);
    ui->wartoscA_1->setValue(a.size() > 1 ? a[1] : 0);
    ui->wartoscA_2->setValue(a.size() > 2 ? a[2] : 0);
    ui->wartoscA_3->setValue(a.size() > 3 ? a[3] : 0);

    ui->wartoscB->setValue(b.size() > 0 ? b[0] : 0);
    ui->wartoscB_1->setValue(b.size() > 1 ? b[1] : 0);
    ui->wartoscB_2->setValue(b.size() > 2 ? b[2] : 0);
    ui->wartoscB_3->setValue(b.size() > 3 ? b[3] : 0);

    ui->wartoscIntewal->setValue(I);
    ui->wartoscKP->setValue(KP);
    ui->wartoscTI->setValue(TI);
    ui->wartoscTD->setValue(TD);
    ui->wartoscWynik->setValue(WZ);
    ui->wartoscZaklocenia->setValue(ZK);
}

