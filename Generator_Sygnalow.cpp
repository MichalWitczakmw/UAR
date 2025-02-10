#include "Generator_Sygnalow.h"
#include <qdebug.h>

double Generator::SygnalSkokowy(int aktywacja, double wartoscStala, int i)
{
    return (i >= aktywacja) ? wartoscStala : 0.0;
}

double Generator::SygnalSinusoidalny(int okres, double amplituda, int i)
{
    double t = amplituda * sin((i* 2 * m_PI)/100 );
    qDebug() <<t;

    return t;
}

double Generator::SygnalProstokatny(int okres, double wypelnienie, double amplituda, int i)
{
    double t = ((i % okres) < wypelnienie * okres) ? amplituda : 0.0;
    qDebug() <<t;
    return t;
}
