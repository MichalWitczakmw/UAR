#include "Robie_Wykres.h"

RobieWykres::RobieWykres(deque<double> a, deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double Zadana, double wartoscZaklocenia, int wartoscinterwalu, QWidget *parent)
    : QWidget(parent), interwal(wartoscinterwalu), m_WartoscZadana(Zadana)
{
    sprzerzenie = new Sprzezenie(a, b, 1, Kp, Ti, Td, rodzajSygnalu, m_WartoscZadana, wartoscZaklocenia);

    seriaWartosciObliczonej = new QLineSeries();
    seriaWartosciZadanej = new QLineSeries();
    seriaUchybu = new QLineSeries();
    seriaPID = new QLineSeries();

    chartWartosciObliczonej = new QChart();
    chartUchybu = new QChart();
    chartRegulacji = new QChart();

    chartviewWartosci = new QChartView(chartWartosciObliczonej);
    chartviewUchybu = new QChartView(chartUchybu);
    chartviewRegulatora = new QChartView(chartRegulacji);

    chartviewWartosci->setRenderHint(QPainter::Antialiasing);
    chartviewUchybu->setRenderHint(QPainter::Antialiasing);
    chartviewRegulatora->setRenderHint(QPainter::Antialiasing);

    inicjalizujWykres();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RobieWykres::aktualizacjawykresu);
    timer->start(interwal);
}

RobieWykres::~RobieWykres()
{
    delete sprzerzenie;
    delete seriaWartosciObliczonej;
    delete seriaWartosciZadanej;
    delete seriaUchybu;
    delete seriaPID;
    delete chartviewWartosci;
    delete chartviewUchybu;
    delete chartviewRegulatora;
    delete timer;
}

void RobieWykres::setNoweWartosciWykresu(deque<double> a, deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia)
{
    sprzerzenie->setSprzerzenie(a, b, Kp, Ti, Td, rodzajSygnalu, zadana, wartosczaklocenia);
    m_WartoscZadana = zadana;
    seriaWartosciObliczonej->clear();
    seriaWartosciZadanej->clear();
    seriaUchybu->clear();
    seriaPID->clear();
}

void RobieWykres::setTimerStop(bool stopuj)
{
    if (stopuj)
        timer->stop();
    else
        timer->start(interwal);
}

void RobieWykres::Resetuj()
{
    sprzerzenie->ResetujPamiec();
}

void RobieWykres::inicjalizujWykres()
{
    // Inicjalizacja serii danych
    seriaWartosciZadanej->setColor(Qt::green);
    seriaUchybu->setColor(Qt::red);
    seriaPID->setColor(Qt::blue);

    // Tworzenie i konfiguracja wykresów
    chartWartosciObliczonej->addSeries(seriaWartosciObliczonej);
    chartWartosciObliczonej->addSeries(seriaWartosciZadanej);
    chartWartosciObliczonej->createDefaultAxes();
    chartWartosciObliczonej->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana/2), (m_WartoscZadana*1.5));
    chartWartosciObliczonej->axes(Qt::Horizontal).first()->setRange(0, 100);

    chartUchybu->addSeries(seriaUchybu);
    chartUchybu->createDefaultAxes();
    chartUchybu->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana/2), (m_WartoscZadana*1.5));
    chartUchybu->axes(Qt::Horizontal).first()->setRange(0, 100);

    chartRegulacji->addSeries(seriaPID);
    chartRegulacji->createDefaultAxes();
    chartRegulacji->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana/2), (m_WartoscZadana*1.5));
    chartRegulacji->axes(Qt::Horizontal).first()->setRange(0, 100);
}

void RobieWykres::aktualizacjawykresu()
{
    terazczas++;
    double newValue = sprzerzenie->Symuluj(terazczas);
    double uchyb = sprzerzenie->getuchyb();
    double regulator = sprzerzenie->getPID();

    seriaWartosciObliczonej->append(terazczas, newValue);
    seriaWartosciZadanej->append(terazczas, m_WartoscZadana);
    seriaUchybu->append(terazczas, uchyb);
    seriaPID->append(terazczas, regulator);

    if (terazczas > 50) {
        if (!seriaWartosciObliczonej->points().isEmpty())
            seriaWartosciObliczonej->remove(0);
        if (!seriaWartosciZadanej->points().isEmpty())
            seriaWartosciZadanej->remove(0);
        if (!seriaUchybu->points().isEmpty())
            seriaUchybu->remove(0);
        if (!seriaPID->points().isEmpty())
            seriaPID->remove(0);

        chartviewWartosci->chart()->axes(Qt::Horizontal).first()->setRange(qMax(0, terazczas - 50), terazczas);
        chartviewUchybu->chart()->axes(Qt::Horizontal).first()->setRange(qMax(0, terazczas - 50), terazczas);
        chartviewRegulatora->chart()->axes(Qt::Horizontal).first()->setRange(qMax(0, terazczas - 50), terazczas);
    }

    chartviewWartosci->chart()->update();
    chartviewUchybu->chart()->update();
    chartviewRegulatora->chart()->update();
}
