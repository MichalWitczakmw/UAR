#ifndef MODEL_ARX_H
#define MODEL_ARX_H

#include "Main_Projektu.h"

class LosoweZaklocenie
{
private:
    random_device randomowo;
    mt19937 generuj;
    normal_distribution<double> dystrybucja;

public:
    LosoweZaklocenie(double minimum, double maximum) : generuj(randomowo()), dystrybucja(minimum, maximum) {}

    double operator()()
    {
        return dystrybucja(generuj);
    }
};

class ModelARX
{
private:
    deque<double> m_Awsopoczynniki;
    deque<double> m_Bwsopoczynniki;
    int delay;
    LosoweZaklocenie zaklocenie;
    double m_maxZaklocenie = 1;

public:
    ModelARX(const deque<double>& a, const deque<double>& b, int delay, double maxZaklocenie)
        : m_Awsopoczynniki(a), m_Bwsopoczynniki(b), delay(delay), zaklocenie(0.0, maxZaklocenie) {}

    double ObliczWyjscie(const deque<double>& wejscia, const deque<double>& wyjscia);

    void AktualizujBufory(deque<double>& wejscia, deque<double>& wyjscia, double noweWejscie, double noweWyjscie);
};

#endif // !MODEL_ARX_H
