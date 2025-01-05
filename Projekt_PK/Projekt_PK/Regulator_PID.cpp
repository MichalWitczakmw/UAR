#include "Regulator_PID.h"

double Regulator::ObliczSterowanie(double uchyb)
{
    double P = Kp * uchyb;
    sumaUchybow += uchyb;
    double I = Ki * sumaUchybow;
    double D = Kd * (uchyb - poprzedniUchyb);
    poprzedniUchyb = uchyb;

    return P + I + D;
}

void Regulator::ResetPamieci()
{
    sumaUchybow = 0.0;
    poprzedniUchyb = 0.0;
}
