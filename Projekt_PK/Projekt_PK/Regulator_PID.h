#ifndef REGULATOR_PID_H
#define REGULATOR_PID_H

#include "Main_Projektu.h"

class Regulator
{
private:
    double Kp;
    double Ki;
    double Kd;
    double sumaUchybow;
    double poprzedniUchyb;

public:
    Regulator(double kP, double kI, double kD) : Kp(kP), Ki(kI), Kd(kD), sumaUchybow(0.0), poprzedniUchyb(0.0) {}

    double ObliczSterowanie(double uchyb);

    void ResetPamieci();
};

#endif // !REGULATOR_PID_H
