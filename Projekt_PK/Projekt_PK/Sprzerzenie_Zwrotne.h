#ifndef SPRZERZENIE_ZWROTNE_H
#define SPRZERZENIE_ZWROTNE_H

#include "Main_Projektu.h"
#include "Generator_Sygnalow.h"
#include "Regulator_PID.h"
#include "Model_ARX.h"

class Sprzezenie : public Generator
{
private:
    ModelARX model;
    Regulator& regulator;
    JakiSygnal sygnal;

    deque<double> wejscia;
    deque<double> wyjscia;

    double wartoscZadana;

public:
    Sprzezenie(const deque<double>& Awspoczynniki, const deque<double>& Bwspoczynniki, int delay, Regulator& reg, JakiSygnal jakisygnal, double wartoscZadana, double zaklocenieMax)
        : Generator(), model(Awspoczynniki, Bwspoczynniki, delay, (zaklocenieMax/100)*wartoscZadana), regulator(reg), sygnal(jakisygnal), wartoscZadana(wartoscZadana) {
    }

    double Symuluj(int i);


};

#endif // !SPRZERZENIE_ZWROTNE_H
