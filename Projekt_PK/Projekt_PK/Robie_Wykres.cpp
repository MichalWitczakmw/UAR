#include "Robie_Wykres.h"

RobieWykres::RobieWykres(JakiSygnal signalType, QWidget *parent)
    : QWidget(parent), currentTime(0)
{
    // Inicjalizacja regulatora i sprzężenia
    regulPID = new Regulator(1, 0.1, 0.1);
    std::deque<double> a = {0.4};
    std::deque<double> b = {0.6};
    sprzerzenie = new Sprzezenie(a, b, 1, *regulPID, signalType, 10.5);

    // Inicjalizacja serii danych
    seria = new QLineSeries();
    seria->append(0, sprzerzenie->Symuluj(currentTime));

    // Tworzenie i konfiguracja wykresu
    trzorzeniewykresu();

    // Tworzenie i uruchamianie timera
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RobieWykres::aktualizacjawykresu);
    timer->start(100); // Aktualizacja co 100 ms
}

RobieWykres::~RobieWykres()
{
    delete regulPID;
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
    currentTime++;

    // Symulacja nowej wartości
    double newValue = sprzerzenie->Symuluj(currentTime);
    seria->append(currentTime, newValue);

    // Utrzymywanie zakresu osi X
    if (currentTime > 50) {
        seria->remove(0);
        chartview->chart()->axes(Qt::Horizontal).first()->setRange(currentTime - 50, currentTime);
    }
}
