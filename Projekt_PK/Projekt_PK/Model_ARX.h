#ifndef MODEL_ARX_H
#define MODEL_ARX_H

#include "Main_Projektu.h"

class LosoweZaklocenie
{
private:
    random_device rd;
    mt19937 gen;
    normal_distribution<double> dist;

public:
    LosoweZaklocenie(double mean = 0.0, double stddev = 1) : gen(rd()), dist(mean, stddev) {}

    double operator()()
    {
        return dist(gen);
    }
};

class ModelARX
{
private:
    deque<double> aCoeffs;
    deque<double> bCoeffs;
    int delay;
    LosoweZaklocenie zaklocenie;

public:
    ModelARX(const deque<double>& a, const deque<double>& b, int delay)
        : aCoeffs(a), bCoeffs(b), delay(delay), zaklocenie(0.0, 0.01) {}

    double ObliczWyjscie(const deque<double>& wejscia, const deque<double>& wyjscia);

    void AktualizujBufory(deque<double>& wejscia, deque<double>& wyjscia, double noweWejscie, double noweWyjscie);
};

#endif // !MODEL_ARX_H
