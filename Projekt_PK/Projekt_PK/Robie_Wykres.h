#ifndef ROBIE_WYKRES_H
#define ROBIE_WYKRES_H

#include <QtCharts>
#include <QWidget>
#include <deque>
#include "Sprzerzenie_Zwrotne.h"

class RobieWykres : public QWidget
{
    Q_OBJECT

public:
    explicit RobieWykres(deque<double> a, deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double Zadana, double wartosczaklocenia, int wartoscinterwalu, QWidget *parent = nullptr);
    ~RobieWykres();

    QChartView* getChartViewWartosciObliczonej() { return chartviewWartosci; }
    QChartView* getChartViewUchybu() { return chartviewUchybu; }
    QChartView* getChartViewRegulatora() { return chartviewRegulatora; }

    void setNoweWartosciWykresu(deque<double> a, deque<double> b, double Kp, double Ti, double Td, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia);
    void setTimerStop(bool stopuj);
    void Resetuj();

public slots:
    void aktualizacjawykresu();

private:
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

    void inicjalizujWykres();
};

#endif // ROBIE_WYKRES_H
