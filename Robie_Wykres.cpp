#include "Robie_Wykres.h"

RobieWykres::RobieWykres(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td,int wnastawa, JakiSygnal rodzajSygnalu, double Zadana, double wartoscZaklocenia, int wartoscinterwalu, QWidget *parent)
    : QWidget(parent), interwal(wartoscinterwalu), m_WartoscZadana(Zadana), terazczas(0)
{
    sprzerzenie = new Sprzezenie(a, b, 1, Kp, Ti, Td, rodzajSygnalu, m_WartoscZadana, wartoscZaklocenia);

    nastawa = wnastawa;

    seriaWartosciObliczonej = new QLineSeries();
    seriaWartosciZadanej = new QLineSeries();
    seriaUchybu = new QLineSeries();
    seriaPID = new QLineSeries();

    seriaWartosciObliczonej->setName("Wartość Obliczona");
    seriaWartosciZadanej->setName("Wartość Zadana");
    seriaUchybu->setName("Uchyb");
    /*
    switch (nastawa) {
    case 1:
        seriaPID->setName("Nastawa P");
        break;
    case 2:
        seriaPID->setName("Nastawa I");
        break;
    case 3:
        seriaPID->setName("Nastawa D");
        break;
    case 4:
        seriaPID->setName("Sterowanie PID");
        break;
    default:
        seriaPID->setName("Sterowanie PID");
        break;
    }
    */
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

void RobieWykres::setInterwal(int warinterwal)
{
    if(warinterwal>50 && warinterwal<1000)
        interwal=warinterwal;
    else
        interwal = 100;
    timer->stop();
    timer->start(interwal);
}

void RobieWykres::setNoweWartosciWykresu(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td,int wnastawa, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia, int warinterwal)
{
    qDebug() << "Ustawianie nowych wartości: "
             << "a:" << &a
             << "b:" << &b
             << "Kp:" << Kp
             << "Ti:" << Ti
             << "Td:" << Td
             << "rodzajSygnalu:" << &rodzajSygnalu
             << "zadana:" << zadana
             << "wartosczaklocenia:" << wartosczaklocenia
             << "warinterwal:" << warinterwal;

    sprzerzenie->setSprzerzenie(a, b, Kp, Ti, Td, rodzajSygnalu, zadana, wartosczaklocenia);
    m_WartoscZadana = zadana;
    seriaWartosciObliczonej->clear();
    seriaWartosciZadanej->clear();
    seriaUchybu->clear();
    seriaPID->clear();
    resetCzasu();
    setInterwal(warinterwal); // Aktualizacja interwału
    /*
    nastawa = wnastawa;
    switch (nastawa) {
    case 1:
        regulator = sprzerzenie->getPID_Kp();
        break;
    case 2:
        regulator = sprzerzenie->getPID_Ti();
    case 3:
        regulator = sprzerzenie->getPID_Td();
    case 4:
        regulator = sprzerzenie->getPID();
    default:
        regulator = sprzerzenie->getPID();
        break;
    }
    */
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

    // Resetowanie wartości do domyślnych ustawień
    seriaWartosciObliczonej->clear();
    seriaWartosciZadanej->clear();
    seriaUchybu->clear();
    seriaPID->clear();

    m_WartoscZadana = 10;
    // Zaktualizuj zakresy osi pionowej
    chartWartosciObliczonej->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    chartUchybu->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));
    chartRegulacji->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana / 2), (m_WartoscZadana * 1.5));

    // Resetowanie interwału
    setInterwal(100);
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
    chartWartosciObliczonej->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana), (m_WartoscZadana * 2));
    chartWartosciObliczonej->axes(Qt::Horizontal).first()->setRange(0, 100);
    chartWartosciObliczonej->setTitle("Wykres Symulacji");

    chartUchybu->addSeries(seriaUchybu);
    chartUchybu->createDefaultAxes();
    chartUchybu->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana), (m_WartoscZadana * 2));
    chartUchybu->axes(Qt::Horizontal).first()->setRange(0, 100);
    chartUchybu->setTitle("Wykres Uchybu");

    chartRegulacji->addSeries(seriaPID);
    chartRegulacji->createDefaultAxes();
    chartRegulacji->axes(Qt::Vertical).first()->setRange(-(m_WartoscZadana), (m_WartoscZadana * 2));
    chartRegulacji->axes(Qt::Horizontal).first()->setRange(0, 100);
    chartRegulacji->setTitle("Wykres Regulatora");

    // Ustawienie tytułów osi
    //chartWartosciObliczonej->title().append("Wykres wartosci");
    addAxisTitle(chartWartosciObliczonej, "czas", "Wartość");

    //chartUchybu->title().append("Wykres Uchybu");
    addAxisTitle(chartUchybu, "czas", "Wartość");

    //chartRegulacji->title().append("Wykres PID");
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
    /*
    switch (nastawa) {
    case 1:
         regulator = sprzerzenie->getPID_Kp();
        break;
    case 2:
        regulator = sprzerzenie->getPID_Ti();
    case 3:
        regulator = sprzerzenie->getPID_Td();
    case 4:
        regulator = sprzerzenie->getPID();
    default:
        regulator = sprzerzenie->getPID();
        break;
    }
    */

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
