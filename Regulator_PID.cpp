#include "Regulator_PID.h"

double Regulator::ObliczSterowanie(double uchyb)
{
    double P = m_Kp * uchyb;
    m_sumaUchybow += uchyb;
    double I = m_Ti * m_sumaUchybow;
    double D = m_Td * (uchyb - m_poprzedniUchyb);
    m_poprzedniUchyb = uchyb;

    return P + I + D;
}

void Regulator::ResetPamieci()
{
    m_sumaUchybow = 0.0;
    m_poprzedniUchyb = 0.0;
    m_Kp = 0.0;
    m_Ti = 0.0;
    m_Td = 0.0;
}
