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
    LosoweZaklocenie() : generuj(randomowo()), dystrybucja(0, 0.1) {}

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
    int m_opoznienie;
    LosoweZaklocenie f_zaklocenie;//f_ mieliśmy na myśli funktor
    double m_maxZaklocenie = 1;

public:
    ModelARX(const deque<double>& a, const deque<double>& b, int opznienie, double maxZaklocenie)
        : m_Awsopoczynniki(a), m_Bwsopoczynniki(b), m_opoznienie(opznienie), f_zaklocenie() {}

    double ObliczWyjscie(const deque<double>& wejscia, const deque<double>& wyjscia);

    void AktualizujBufory(deque<double>& wejscia, deque<double>& wyjscia, double noweWejscie, double noweWyjscie);

    void setOpoznienei (int opuznij)
    {
        if(opuznij>m_opoznienie)
            m_opoznienie = opuznij;
    }
    void setZaklocenie(double zakloc)
    {
        if(zakloc !=m_maxZaklocenie && zakloc<100 && zakloc >0.0)
            m_maxZaklocenie = zakloc;

    }

    double getMaxZaklocenie() const{return m_maxZaklocenie;}
    deque<double> getAWspoczynnik() const{return m_Awsopoczynniki;}
    deque<double> getBWsopoczynniki() const{return m_Bwsopoczynniki;}
    int getopoznienie() const{return m_opoznienie;}

    void ResetPamieci()
    {
        m_opoznienie = 0;
        m_maxZaklocenie = 0.0;
        m_Awsopoczynniki.clear();
        m_Bwsopoczynniki.clear();
    }
};

#endif // !MODEL_ARX_H
