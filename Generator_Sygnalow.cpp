#include "Generator_Sygnalow.h"

double Generator::SygnalSkokowy(int aktywacja, double wartoscStala, int i)
{
    return (i >= aktywacja) ? wartoscStala : 0.0;
}

double Generator::SygnalSinusoidalny(int okres, double amplituda, int i)
{
    return amplituda * sin((i % okres) * 2 * m_PI / okres);
}

double Generator::SygnalProstokatny(int okres, double wypelnienie, double amplituda, int i)
{
    return ((i % okres) < wypelnienie * okres) ? amplituda : 0.0;
}