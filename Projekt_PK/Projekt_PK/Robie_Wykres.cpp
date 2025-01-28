#include "Robie_Wykres.h"

RobieWykres::RobieWykres(deque<double> a,deque<double> b,double Kp,double Ti, double Td,JakiSygnal rodzajSygnalu,double wartoscZaklocenia, QWidget *parent)
    : QWidget(parent), interwal(0)
{
    // Inicjalizacja regulatora i sprzężenia
    sprzerzenie = new Sprzezenie(a, b, 1, Kp, Ti, Td, rodzajSygnalu, 8, wartoscZaklocenia);

    // Inicjalizacja serii danych
    seria = new QLineSeries();
    seria->append(0, sprzerzenie->Symuluj(interwal));

    // Tworzenie i konfiguracja wykresu
    trzorzeniewykresu();

    // Tworzenie i uruchamianie timera
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RobieWykres::aktualizacjawykresu);
    timer->start(100); // Aktualizacja co 100 ms/zamienic na interwal
}

RobieWykres::~RobieWykres()
{
    delete sprzerzenie;
}

void RobieWykres::trzorzeniewykresu()
{
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(seria);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-2, 20);
    chart->axes(Qt::Horizontal).first()->setRange(0, 50);

    chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartview);
    setLayout(layout);
}

void RobieWykres::aktualizacjawykresu()
{
    interwal++;

    // Symulacja nowej wartości
    double newValue = sprzerzenie->Symuluj(interwal);
    seria->append(interwal, newValue);

    // Utrzymywanie zakresu osi X
    if (interwal > 50) {
        seria->remove(0);
        chartview->chart()->axes(Qt::Horizontal).first()->setRange(interwal - 50, interwal);
    }
}
