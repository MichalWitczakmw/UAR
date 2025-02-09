#ifndef ROBIE_WYKRES_H
#define ROBIE_WYKRES_H

#include <QtCharts>
#include <QWidget>
#include <deque>
#include "Sprzerzenie_Zwrotne.h"
#include "Zapisze_Do_Pliku.h"

class RobieWykres : public QWidget
{
    Q_OBJECT

public:
    explicit RobieWykres(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td,int wnastawa, JakiSygnal rodzajSygnalu, double Zadana, double wartosczaklocenia, int wartoscinterwalu, QWidget *parent = nullptr);
    ~RobieWykres();

    QChartView* getChartViewWartosciObliczonej();
    QChartView* getChartViewUchybu();
    QChartView* getChartViewRegulatora();

    void setNoweWartosciWykresu(std::deque<double> a, std::deque<double> b, double Kp, double Ti, double Td,int wnastawa, JakiSygnal rodzajSygnalu, double zadana, double wartosczaklocenia, int warinterwal);
    void setTimerStop(bool stopuj);
    void Resetuj();
    void resetCzasu();
    void setInterwal(int warinterwal);
    void setPIDkp(double kp){sprzerzenie->setPIDkp(kp);}
    void setPIDti(double ti){sprzerzenie->setPIDti(ti);}
    void setPIDtd(double td){sprzerzenie->setPIDtd(td);}
    void setSygnal(JakiSygnal jks){sprzerzenie->setSygnal(jks);}
    void setWartoscZadana(double wz){m_WartoscZadana = wz; sprzerzenie->setWZ(wz);}
    void setZaklocenie(int z){sprzerzenie->setARX(1,z);}
    void setWSPAB(deque<double>a,deque<double> b){sprzerzenie->setWspolczynAB(a,b);}


    void zapiszDOPliku(QString sciezka);
    void wczytajZPliku(QString sciezka);

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

    ZapiszeDoPliku * zapisuj;


    int interwal;
    double m_WartoscZadana;
    double regulator;
    int terazczas;
    int nastawa;
};

#endif // ROBIE_WYKRES_H
