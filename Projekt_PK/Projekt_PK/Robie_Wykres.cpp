#include "Robie_Wykres.h"

RobieWykres::RobieWykres(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double Zadana, double wartoscZaklocenia, int wartoscinterwalu, QWidget *parent)
    : QWidget(parent), interwal(wartoscinterwalu), m_WartoscZadana(Zadana), terazczas(0)
{
    sprzerzenie = new Sprzezenie(a, b, 1, Kp, Ti, Td, rodzajSygnalu, m_WartoscZadana, wartoscZaklocenia);

    seriaWartosciObliczonej = new QLineSeries();
    seriaWartosciZadanej = new QLineSeries();
    seriaUchybu = new QLineSeries();
    seriaPID = new QLineSeries();

    seriaWartosciObliczonej->setName("Wartość Obliczona");
    seriaWartosciZadanej->setName("Wartość Zadana");
    seriaUchybu->setName("Uchyb");
    seriaPID->setName("Sterowanie PID");

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

QChartView* RobieWykres::getChartViewWartosciObliczonej() {
    return chartviewWartosci;
}

QChartView* RobieWykres::getChartViewUchybu() {
    return chartviewUchybu;
}

QChartView* RobieWykres::getChartViewRegulatora() {
    return chartviewRegulatora;
}

void RobieWykres::setNoweWartosciWykresu(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia)
{
    sprzerzenie->setSprzerzenie(a, b, Kp, Ti, Td, rodzajSygnalu, zadana, wartosczaklocenia);
    m_WartoscZadana = zadana;
    seriaWartosciObliczonej->clear();
    seriaWartosciZadanej->clear();
    seriaUchybu->clear();
    seriaPID->clear();
    resetCzasu();
}

void RobieWykres::resetCzasu()
{
    terazczas = 0;
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
    resetCzasu();
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
    chartWartosciObliczonej->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    chartWartosciObliczonej->axes(Qt::Horizontal).first()->setRange(0, 100);

    chartUchybu->addSeries(seriaUchybu);
    chartUchybu->createDefaultAxes();
    chartUchybu->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    chartUchybu->axes(Qt::Horizontal).first()->setRange(0, 100);

    chartRegulacji->addSeries(seriaPID);
    chartRegulacji->createDefaultAxes();
    chartRegulacji->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    chartRegulacji->axes(Qt::Horizontal).first()->setRange(0, 100);

    // Ustawienie tytułów osi
    chartWartosciObliczonej->title().append("Wykres wartosci");
    addAxisTitle(chartWartosciObliczonej, "czas", "Wartość");

    chartUchybu->title().append("Wykres Uchybu");
    addAxisTitle(chartUchybu, "czas", "Wartość");

    chartRegulacji->title().append("Wykres PID");
    addAxisTitle(chartRegulacji, "czas", "Wartość");

    // Dodanie legendy
    chartWartosciObliczonej->legend()->setVisible(true);
    chartWartosciObliczonej->legend()->setAlignment(Qt::AlignBottom);
    chartUchybu->legend()->setVisible(true);
    chartUchybu->legend()->setAlignment(Qt::AlignBottom);
    chartRegulacji->legend()->setVisible(true);
    chartRegulacji->legend()->setAlignment(Qt::AlignBottom);

    // Dodanie czarnej obwódki do legendy
    for (QLegendMarker* marker : chartWartosciObliczonej->legend()->markers()) {
        marker->setLabelBrush(QBrush(Qt::black));
        marker->setBrush(QBrush(Qt::NoBrush));
        marker->setPen(QPen(Qt::black));
    }

    for (QLegendMarker* marker : chartUchybu->legend()->markers()) {
        marker->setLabelBrush(QBrush(Qt::black));
        marker->setBrush(QBrush(Qt::NoBrush));
        marker->setPen(QPen(Qt::black));
    }

    for (QLegendMarker* marker : chartRegulacji->legend()->markers()) {
        marker->setLabelBrush(QBrush(Qt::black));
        marker->setBrush(QBrush(Qt::NoBrush));
        marker->setPen(QPen(Qt::black));
    }
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
        chartWartosciObliczonej->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));

        chartviewUchybu->chart()->axes(Qt::Horizontal).first()->setRange(qMax(0, terazczas - 50), terazczas);
        chartUchybu->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));

        chartviewRegulatora->chart()->axes(Qt::Horizontal).first()->setRange(qMax(0, terazczas - 50), terazczas);
        chartRegulacji->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    }

    chartviewWartosci->chart()->update();
    chartviewUchybu->chart()->update();
    chartviewRegulatora->chart()->update();
}

void RobieWykres::addAxisTitle(QChart *chart, const QString &xTitle, const QString &yTitle)
{
    QValueAxis *axisX = qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());

    if (axisX) {
        QGraphicsTextItem *xAxisTitle = new QGraphicsTextItem(xTitle);
        xAxisTitle->setFont(QFont("Arial", 10, QFont::Bold));
        xAxisTitle->setDefaultTextColor(Qt::black);
        chart->scene()->addItem(xAxisTitle);
        xAxisTitle->setPos(chart->plotArea().right() - xAxisTitle->boundingRect().width(), chart->plotArea().bottom() + 20);
    }

    if (axisY) {
        QGraphicsTextItem *yAxisTitle = new QGraphicsTextItem(yTitle);
        yAxisTitle->setFont(QFont("Arial", 10, QFont::Bold));
        yAxisTitle->setDefaultTextColor(Qt::black);
        chart->scene()->addItem(yAxisTitle);
        yAxisTitle->setPos(chart->plotArea().left() - yAxisTitle->boundingRect().width() - 20, chart->plotArea().top() - yAxisTitle->boundingRect().height());
    }
}
