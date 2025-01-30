#ifndef ZAPISZE_DO_PLIKU_H
#define ZAPISZE_DO_PLIKU_H

#include "Main_Projektu.h"

class ZapiszeDoPliku
{
public:
    ZapiszeDoPliku(bool zapisBinarny, double KI, double KP, double KD, double wynik, string sciezka)
    {
        if (zapisBinarny)
            zapiszBinarnie();
        else
            zapiszTekstowo();
    }
    ~ZapiszeDoPliku() {}

private:
    void zapiszBinarnie();
    void zapiszTekstowo();

};

#endif // ZAPISZE_DO_PLIKU_H
