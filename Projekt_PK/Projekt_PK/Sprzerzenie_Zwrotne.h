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
    Regulator regulator;
    JakiSygnal sygnal;

    deque<double> wejscia;
    deque<double> wyjscia;

    double m_wartoscZadana;
    double m_uchyb;

public:
    Sprzezenie(const deque<double>& Awspoczynniki, const deque<double>& Bwspoczynniki, int delay, double Kp,double Ti, double Td, JakiSygnal jakisygnal, double wZadana, double zaklocenieMax)
        : Generator(), m_wartoscZadana(wZadana), model(Awspoczynniki, Bwspoczynniki, delay, (zaklocenieMax/100)*m_wartoscZadana), regulator({Kp,Ti,Td}), sygnal(jakisygnal) {
    }

    double Symuluj(int i);

    // ARX
    void setARX(int opuz,double zak)
    {
        model.setOpoznienei(opuz);
        model.setZaklocenie(zak);
    }
    double getModelARX_zaklocenie() const {return model.getMaxZaklocenie();}
    double getModelARX_opuznienie() const {return model.getopoznienie();}
    deque<double> getModelARX_Awspolczynnik() const {return model.getAWspoczynnik();}
    deque<double> getModelARX_Bwspolczynnik() const {return model.getBWsopoczynniki();}

    //PID
    void setPID(double kp, double ti, double td)
    {
        regulator.setParametryPID(kp,ti,td);
    }
    double getPID_Kp() const {return regulator.getKp();}
    double getPID_Ti() const {return regulator.getTi();}
    double getPID_Td() const {return regulator.getTd();}

    //sprzerzenie
    void setSprzerzenie();
    double getuchyb() const {return m_uchyb;}


    void ResetujPamiec()
    {
        model.ResetPamieci();
        regulator.ResetPamieci();
        wyjscia.clear();
        wejscia.clear();
        m_wartoscZadana = 0.0;
        m_uchyb = 0.0;
    }

};

#endif // !SPRZERZENIE_ZWROTNE_H
