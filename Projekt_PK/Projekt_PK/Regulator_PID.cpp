#include "Regulator_PID.h"

double Regulator::ObliczSterowanie(double uchyb)
{
    double P = Kp * uchyb;
    sumaUchybow += uchyb;
    double I = Ti * sumaUchybow;
    double D = Td * (uchyb - poprzedniUchyb);
    poprzedniUchyb = uchyb;

    return P + I + D;
}

void Regulator::ResetPamieci()
{
    sumaUchybow = 0.0;
    poprzedniUchyb = 0.0;
    Kp = 0.0;
    Ti = 0.0;
    Td = 0.0;
}
