#ifndef REGULATOR_PID_H
#define REGULATOR_PID_H

#include "Main_Projektu.h"

class Regulator
{
private:
    double m_Kp;
    double m_Ti;
    double m_Td;
    double m_sumaUchybow;
    double m_poprzedniUchyb;

public:
    Regulator(double kP, double TI, double TD) : m_Kp(kP), m_Ti(TI), m_Td(TD), m_sumaUchybow(0.0), m_poprzedniUchyb(0.0) {}

    double ObliczSterowanie(double uchyb);

    void ResetPamieci();

    void setParametryPID(double kp, double ti, double td)
    {
        if(kp != m_Kp && ti != m_Ti && td != m_Td)
        {
            m_Kp = kp;
            m_Ti = ti;
            m_Td = td;
        }
    }

    double getKp() const {return m_Kp;}
    double getTi() const {return m_Ti;}
    double getTd() const {return m_Td;}
    double getPID() const {return m_Kp+m_Ti+m_Td;}
};

#endif // !REGULATOR_PID_H
