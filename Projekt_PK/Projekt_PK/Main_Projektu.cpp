#include "Main_Projektu.h"

#ifdef MAINPROJEKTU

#include "Generator_Sygnalow.h"
#include "Regulator_PID.h"
#include "Model_ARX.h"
#include "Sprzerzenie_Zwrotne.h"

int main()
{
    double wartoscZadana;
    cout << "Podaj wartosc zadana: ";
    cin >> wartoscZadana;

    deque<double> A{ 0.4};
    deque<double> B{ 0.6};
    int delay = 1; // OpóŸnienie transportowe

    Regulator regulator(1, 0.01, 0.05); // Parametry PID

    Sprzezenie sprzezenie(A, B, delay, regulator, JakiSygnal::Sinusoidalny, wartoscZadana);
    int i = 0;
    double tolerance = 0.001;
    int repeatCount = 0;
    double lastOutput = numeric_limits<double>::infinity();

    while (true)
    {
        double wyjscie = sprzezenie.Symuluj(i);
        cout << "obliczono: " << wyjscie << endl;
        // Sprawdzenie, czy wyjœcie osi¹ga wartoœæ zadan¹ w granicach tolerancji
        if (abs(wyjscie - wartoscZadana) < tolerance)
        {
            repeatCount++;
            if (repeatCount >= 3)
            {
                cout << "Osiagnieto wartosc zadana: " << wartoscZadana << " po " << i + 1 << " iteracjach." << endl;
                break;
            }
        }
        else
        {
            repeatCount = 0;
        }
       this_thread::sleep_for(chrono::milliseconds(100));

        lastOutput = wyjscie;
        i++;
    }
}
#endif // MAINPROJEKTU
