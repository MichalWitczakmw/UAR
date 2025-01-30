#include "Testy_UAR.h"

#ifdef TESTYUAR


void TestCalegoUkladu()
{
    try
    {
        // Parametry testu
        double wartoscZadana = 1.0; // Oczekiwana wartoœæ wyjœcia
        std::deque<double> A{ 0.4, 0.5 }; // Wspó³czynniki A dla modelu ARX
        std::deque<double> B{ 0.6, 0.7 }; // Wspó³czynniki B dla modelu ARX
        int rozmiarBuforu = 10;           // Rozmiar bufora
        int delay = 1;                    // OpóŸnienie transportowe
        double tolerance = 0.00001;       // Tolerancja b³êdu
        int maxIterations = 1000;         // Maksymalna liczba iteracji (zabezpieczenie przed nieskoñczon¹ pêtl¹)

        // Tworzenie regulatora PID
        Regulator regulator(1.0, 0.1, 0.05);

        // Tworzenie uk³adu sprzê¿enia zwrotnego
        Sprzezenie sprzezenie(rozmiarBuforu, A, B, delay, regulator, JakiGenerator::Sinusoidalnie, wartoscZadana);

        // Zmienne pomocnicze do testu
        int repeatCount = 0;
        double lastOutput = std::numeric_limits<double>::infinity();

        // Symulacja uk³adu
        for (int i = 0; i < maxIterations; ++i)
        {
            double wyjscie = sprzezenie.Symuluj(i);

            // Sprawdzenie, czy wartoœæ zadana zosta³a osi¹gniêta w granicach tolerancji
            if (std::abs(wyjscie - wartoscZadana) < tolerance)
            {
                repeatCount++;
                if (repeatCount >= 3) // Warunek stabilizacji na wartoœci zadanej
                {
                    std::cout << "Test passed: Uk³ad osi¹gn¹³ wartoœæ zadan¹ " << wartoscZadana
                        << " po " << i + 1 << " iteracjach." << std::endl;
                    return;
                }
            }
            else
            {
                repeatCount = 0; // Reset, jeœli nie osi¹gniêto wartoœci zadanej
            }

            // Symulacja opóŸnienia czasowego (np. 500 ms)
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            lastOutput = wyjscie;
        }

        // Jeœli uk³ad nie osi¹gn¹³ wartoœci zadanej w maksymalnej liczbie iteracji
        throw std::runtime_error("Test failed: Uk³ad nie osi¹gn¹³ wartoœci zadanej w maksymalnej liczbie iteracji.");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error during test: " << e.what() << std::endl;
    }
}

int main()
{
    // Uruchomienie testu ca³ego uk³adu
    TestCalegoUkladu();

    return 0;
}



#endif // TESTYUAR
