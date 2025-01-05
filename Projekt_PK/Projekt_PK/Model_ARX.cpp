#include "Model_ARX.h"

double ModelARX::ObliczWyjscie(const deque<double>& wejscia, const deque<double>& wyjscia)
{
    double y = 0.0;
    for (size_t i = 0; i < bCoeffs.size(); ++i)
    {
        if (i < wejscia.size())
            y += bCoeffs[i] * wejscia[wejscia.size() - 1 - i];
    }
    for (size_t i = 1; i < aCoeffs.size(); ++i)
    {
        if (i - 1 < wyjscia.size())
            y -= aCoeffs[i] * wyjscia[wyjscia.size() - i];
    }
    return y + zaklocenie();
}

void ModelARX::AktualizujBufory(deque<double>& wejscia, deque<double>& wyjscia, double noweWejscie, double noweWyjscie)
{
    if (!wejscia.empty() && wejscia.size() == bCoeffs.size() + delay)
        wejscia.pop_front();
    if (!wejscia.empty() && wyjscia.size() == aCoeffs.size() - 1)
        wyjscia.pop_front();

    wejscia.push_back(noweWejscie);
    wyjscia.push_back(noweWyjscie);
}