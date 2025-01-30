#include "Sprzerzenie_Zwrotne.h"

double Sprzezenie::Symuluj(int i)
{
    double wejscie;
    static double czas=0;
    switch (sygnal)
    {
    case JakiSygnal::Sinusoidalny:
        wejscie = SygnalSinusoidalny(6, 1.0, czas);
        break;
    case JakiSygnal::Prostokatny:
        wejscie = SygnalProstokatny(3, 0.5, 1.0, czas);
        break;
    default:
        wejscie = SygnalSkokowy(5, 1.0, czas);
    }

    // Obliczenie uchybu na podstawie wartoœci zadanej i wyjœcia modelu
    double aktualneWyjscie = model.ObliczWyjscie(wejscia, wyjscia);
    m_uchyb = m_wartoscZadana - aktualneWyjscie;

    // Sterowanie na podstawie uchybu
    double sterowanie = regulator.ObliczSterowanie(m_uchyb);

    // Modyfikacja wejœcia do modelu na podstawie sterowania
    double wejscieDoModelu = wejscie + sterowanie;

    // Aktualizacja modelu ARX
    model.AktualizujBufory(wejscia, wyjscia, wejscieDoModelu, aktualneWyjscie);

    // Wyœwietlanie wyników
   // cout << "Czas: " << i << " s\n";
   // cout << "Wejscie (z generatora): " << wejscie << " Sterowanie: " << sterowanie
   //     << " Wejscie do modelu: " << wejscieDoModelu << " Wyjscie (z ARX): " << aktualneWyjscie << "\n";
    czas +=i;
    return aktualneWyjscie;
}
