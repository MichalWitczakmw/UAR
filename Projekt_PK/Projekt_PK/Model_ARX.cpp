#include "Model_ARX.h"

double ModelARX::ObliczWyjscie(const deque<double>& wejscia, const deque<double>& wyjscia)
{
    double y = 0.0;
    for (size_t i = 0; i < m_Bwsopoczynniki.size(); ++i)
    {
        if (i < wejscia.size())
            y += m_Bwsopoczynniki[i] * wejscia[wejscia.size() - 1 - i];
    }
    for (size_t i = 1; i < m_Awsopoczynniki.size(); ++i)
    {
        if (i - 1 < wyjscia.size())
            y -= m_Awsopoczynniki[i] * wyjscia[wyjscia.size() - i];
    }
    return y + f_zaklocenie();
}

void ModelARX::AktualizujBufory(deque<double>& wejscia, deque<double>& wyjscia, double noweWejscie, double noweWyjscie)
{
    if (!wejscia.empty() && wejscia.size() == m_Bwsopoczynniki.size() + m_opoznienie)
        wejscia.pop_front();
    if (!wejscia.empty() && wyjscia.size() == m_Awsopoczynniki.size() - 1)
        wyjscia.pop_front();

    wejscia.push_back(noweWejscie);
    wyjscia.push_back(noweWyjscie);
}
