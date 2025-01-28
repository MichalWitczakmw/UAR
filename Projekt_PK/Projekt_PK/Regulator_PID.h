#ifndef REGULATOR_PID_H
#define REGULATOR_PID_H

#include "Main_Projektu.h"

class Regulator
{
private:
    double Kp;
    double Ti;
    double Td;
    double sumaUchybow;
    double poprzedniUchyb;

public:
    Regulator(double kP, double TI, double TD) : Kp(kP), Ti(TI), Td(TD), sumaUchybow(0.0), poprzedniUchyb(0.0) {}

    double ObliczSterowanie(double uchyb);

    void ResetPamieci();
};

#endif // !REGULATOR_PID_H
