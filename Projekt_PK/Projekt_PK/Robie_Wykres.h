#ifndef ROBIE_WYKRES_H
#define ROBIE_WYKRES_H

#include <QtCharts>
#include <QWidget>
#include <deque>
#include "Sprzerzenie_Zwrotne.h"
#include "Regulator_PID.h"



class RobieWykres :public QWidget
{
    Q_OBJECT

public:
    explicit RobieWykres(deque<double> a,deque<double> b,double Kp,double Ti, double Td,JakiSygnal rodzajSygnalu,double wartosczaklocenia, QWidget *parent = nullptr);
    ~RobieWykres();

    double getSprzerzenieModelARX_zaklocenie()const  { return static_cast<double>(sprzerzenie->getModelARX_zaklocenie());}
    double getSprzerzenieUchyb() const {return static_cast<double>(sprzerzenie->getuchyb());}

    void Resetuj()
    {
        sprzerzenie->ResetujPamiec();
    }

private slots:
    void aktualizacjawykresu(); // Aktualizuje wykres

private:
    QLineSeries *seria;         // Seria danych
    QChartView *chartview;      // Widok wykresu
    QTimer *timer;              // Timer do aktualizacji
    Sprzezenie * sprzerzenie;    // Sprzężenie
    int interwal;            // interwal

    void trzorzeniewykresu();          // Tworzy wykres
};

#endif // ROBIE_WYKRES_H
