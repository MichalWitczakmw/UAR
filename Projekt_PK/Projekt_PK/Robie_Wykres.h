#ifndef ROBIE_WYKRES_H
#define ROBIE_WYKRES_H

#include <QtCharts>
#include <QWidget>
#include <deque>
#include "../Projekt_PK/Sprzerzenie_Zwrotne.h"

class RobieWykres : public QWidget
{
    Q_OBJECT

public:
    explicit RobieWykres(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double Zadana, double wartosczaklocenia, int wartoscinterwalu, QWidget *parent = nullptr);
    ~RobieWykres();

    QChartView* getChartViewWartosciObliczonej();
    QChartView* getChartViewUchybu();
    QChartView* getChartViewRegulatora();

    void setNoweWartosciWykresu(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia);
    void setTimerStop(bool stopuj);
    void Resetuj();
    void resetCzasu();

public slots:
    void aktualizacjawykresu();

private:
    void inicjalizujWykres();
    void addAxisTitle(QChart *chart, const QString &xTitle, const QString &yTitle);

    QLineSeries *seriaWartosciObliczonej;
    QLineSeries *seriaWartosciZadanej;
    QLineSeries *seriaUchybu;
    QLineSeries *seriaPID;

    QChart *chartWartosciObliczonej;
    QChart *chartUchybu;
    QChart *chartRegulacji;

    QChartView *chartviewWartosci;
    QChartView *chartviewUchybu;
    QChartView *chartviewRegulatora;

    QTimer *timer;
    Sprzezenie *sprzerzenie;
    int interwal;
    double m_WartoscZadana;
    int terazczas;
};

#endif // ROBIE_WYKRES_H
