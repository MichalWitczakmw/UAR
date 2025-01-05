#ifndef GENERATOR_SYGNALOW_H
#define GENERATOR_SYGNALOW_H

#include "Main_Projektu.h"

enum class JakiSygnal
{
    Skokowy = 0,
    Sinusoidalny = 1,
    Prostokatny = 2
};


class Generator
{
private:
    const double m_PI = 3.14;
public:
    Generator(){}

    double SygnalSkokowy(int aktywacja, double wartoscStala, int i);

    double SygnalSinusoidalny(int okres, double amplituda, int i);

    double SygnalProstokatny(int okres, double wypelnienie, double amplituda, int i);
};

#endif // !GENERATOR_SYGNALOW_H
