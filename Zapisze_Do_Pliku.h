#ifndef ZAPISZE_DO_PLIKU_H
#define ZAPISZE_DO_PLIKU_H

#include "Main_Projektu.h"
#include <QString>

class ZapiszeDoPliku
{
public:
    ZapiszeDoPliku()
    {}
    ~ZapiszeDoPliku() {}

    void zapiszBinarnie();
    void zapiszTekstowo(double KP, double TI, double TD,double WZ,double ZK,int I,deque<double> a,deque<double> b,int jaki, QString sciezka);
    void wczytajTekstowo(double &KP, double &TI, double &TD, double &WZ, double &ZK, int &I, std::deque<double> &a, std::deque<double> &b, int &jaki, QString sciezka);

};

#endif // ZAPISZE_DO_PLIKU_H
