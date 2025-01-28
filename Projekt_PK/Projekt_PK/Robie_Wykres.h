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
    explicit RobieWykres(JakiSygnal rodzajSygnalu,double wartosczaklocenia, QWidget *parent = nullptr);
    ~RobieWykres();

private slots:
    void aktualizacjawykresu(); // Aktualizuje wykres

private:
    QLineSeries *seria;         // Seria danych
    QChartView *chartview;      // Widok wykresu
    QTimer *timer;              // Timer do aktualizacji
    Regulator *regulPID;        // Regulator
    Sprzezenie *sprzerzenie;    // Sprzężenie
    int interwal;            // interwal

    void trzorzeniewykresu();          // Tworzy wykres
};

#endif // ROBIE_WYKRES_H
