#include "Testy_UAR.h"

#ifdef TESTYUAR


void TestCalegoUkladu()
{
    try
    {
        // Parametry testu
        double wartoscZadana = 1.0; // Oczekiwana warto�� wyj�cia
        std::deque<double> A{ 0.4, 0.5 }; // Wsp�czynniki A dla modelu ARX
        std::deque<double> B{ 0.6, 0.7 }; // Wsp�czynniki B dla modelu ARX
        int rozmiarBuforu = 10;           // Rozmiar bufora
        int delay = 1;                    // Op�nienie transportowe
        double tolerance = 0.00001;       // Tolerancja b��du
        int maxIterations = 1000;         // Maksymalna liczba iteracji (zabezpieczenie przed niesko�czon� p�tl�)

        // Tworzenie regulatora PID
        Regulator regulator(1.0, 0.1, 0.05);

        // Tworzenie uk�adu sprz�enia zwrotnego
        Sprzezenie sprzezenie(rozmiarBuforu, A, B, delay, regulator, JakiGenerator::Sinusoidalnie, wartoscZadana);

        // Zmienne pomocnicze do testu
        int repeatCount = 0;
        double lastOutput = std::numeric_limits<double>::infinity();

        // Symulacja uk�adu
        for (int i = 0; i < maxIterations; ++i)
        {
            double wyjscie = sprzezenie.Symuluj(i);

            // Sprawdzenie, czy warto�� zadana zosta�a osi�gni�ta w granicach tolerancji
            if (std::abs(wyjscie - wartoscZadana) < tolerance)
            {
                repeatCount++;
                if (repeatCount >= 3) // Warunek stabilizacji na warto�ci zadanej
                {
                    std::cout << "Test passed: Uk�ad osi�gn�� warto�� zadan� " << wartoscZadana
                        << " po " << i + 1 << " iteracjach." << std::endl;
                    return;
                }
            }
            else
            {
                repeatCount = 0; // Reset, je�li nie osi�gni�to warto�ci zadanej
            }

            // Symulacja op�nienia czasowego (np. 500 ms)
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            lastOutput = wyjscie;
        }

        // Je�li uk�ad nie osi�gn�� warto�ci zadanej w maksymalnej liczbie iteracji
        throw std::runtime_error("Test failed: Uk�ad nie osi�gn�� warto�ci zadanej w maksymalnej liczbie iteracji.");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error during test: " << e.what() << std::endl;
    }
}

int main()
{
    // Uruchomienie testu ca�ego uk�adu
    TestCalegoUkladu();

    return 0;
}



#endif // TESTYUAR
