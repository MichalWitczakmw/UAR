#include "Main_Projektu.h"

class Generator
{
public:
    Generator(int size) : iloscProbek(size), terazniejszyCzasZegara(0) {}

    double Skokowo(int aktywacja, double wartoscStala, int i)
    {
        return (i >= aktywacja) ? wartoscStala : 0.0;
    }

    double Sinusoidalnie(int okres, double amplituda, int i)
    {
        constexpr double m_PI = 3.14159265359;
        return amplituda * std::sin((i % okres) * 2 * m_PI / okres);
    }

    double SygnalProstokatny(int okres, double wypelnienie, double amplituda, int i)
    {
        return ((i % okres) < wypelnienie * okres) ? amplituda : 0.0;
    }

private:
    int iloscProbek;
    int terazniejszyCzasZegara;
};

class Regulator
{
public:
    Regulator(double kP, double kI, double kD) : Kp(kP), Ki(kI), Kd(kD), sumaUchybow(0.0), poprzedniUchyb(0.0) {}

    double ObliczSterowanie(double uchyb)
    {
        double P = Kp * uchyb;
        sumaUchybow += uchyb;
        double I = Ki * sumaUchybow;
        double D = Kd * (uchyb - poprzedniUchyb);
        poprzedniUchyb = uchyb;
        return P + I + D;
    }

    void ResetPamieci()
    {
        sumaUchybow = 0.0;
        poprzedniUchyb = 0.0;
    }

private:
    double Kp;
    double Ki;
    double Kd;
    double sumaUchybow;
    double poprzedniUchyb;
};

class RandomFunctor
{
public:
    RandomFunctor(double mean = 0.0, double stddev = 0.01) : gen(rd()), dist(mean, stddev) {}

    double operator()()
    {
        return dist(gen);
    }

private:
    std::random_device rd;
    std::mt19937 gen;
    std::normal_distribution<double> dist;
};

class ModelARX
{
public:
    ModelARX(const std::deque<double>& a, const std::deque<double>& b, int delay)
        : aCoeffs(a), bCoeffs(b), delay(delay), noiseGenerator(0.0, 0.01) {
    }

    double ObliczWyjscie(const std::deque<double>& wejscia, const std::deque<double>& wyjscia)
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
        return y + noiseGenerator();
    }

    void AktualizujBufory(std::deque<double>& wejscia, std::deque<double>& wyjscia, double noweWejscie, double noweWyjscie)
    {
        if (!wejscia.empty() && wejscia.size() == bCoeffs.size() + delay)
            wejscia.pop_front();
        if (!wejscia.empty() && wyjscia.size() == aCoeffs.size() - 1)
            wyjscia.pop_front();

        wejscia.push_back(noweWejscie);
        wyjscia.push_back(noweWyjscie);
    }

private:
    std::deque<double> aCoeffs;
    std::deque<double> bCoeffs;
    int delay;
    RandomFunctor noiseGenerator;
};

enum class JakiGenerator
{
    Skokowo = 0,
    Sinusoidalnie = 1,
    Kwadratowo = 2
};

class Sprzezenie : public Generator
{
public:
    Sprzezenie(int size, const std::deque<double>& aCoeffs, const std::deque<double>& bCoeffs, int delay, Regulator& reg, JakiGenerator jakigenerator, double wartoscZadana)
        : Generator(size), model(aCoeffs, bCoeffs, delay), regulator(reg), rozmiarBuforu(size), jakigen(jakigenerator), wartoscZadana(wartoscZadana) {
    }

    double Symuluj(int i)
    {
        double wejscie;
        switch (jakigen)
        {
        case JakiGenerator::Skokowo:
            wejscie = Skokowo(5, 1.0, i);
            break;
        case JakiGenerator::Sinusoidalnie:
            wejscie = Sinusoidalnie(6, 1.0, i);
            break;
        case JakiGenerator::Kwadratowo:
            wejscie = SygnalProstokatny(3, 0.5, 1.0, i);
            break;
        default:
            wejscie = Skokowo(5, 1.0, i);
        }

        // Obliczenie uchybu na podstawie wartoœci zadanej i wyjœcia modelu
        double aktualneWyjscie = model.ObliczWyjscie(wejscia, wyjscia);
        double uchyb = wartoscZadana - aktualneWyjscie;

        // Sterowanie na podstawie uchybu
        double sterowanie = regulator.ObliczSterowanie(uchyb);

        // Modyfikacja wejœcia do modelu na podstawie sterowania
        double wejscieDoModelu = wejscie + sterowanie;

        // Aktualizacja modelu ARX
        model.AktualizujBufory(wejscia, wyjscia, wejscieDoModelu, aktualneWyjscie);

        // Wyœwietlanie wyników
        std::cout << "Czas: " << i << " s\n";
        std::cout << "Wejscie (z generatora): " << wejscie << " Sterowanie: " << sterowanie
            << " Wejscie do modelu: " << wejscieDoModelu << " Wyjscie (z ARX): " << aktualneWyjscie << "\n";

        return aktualneWyjscie;
    }

private:
    ModelARX model;
    Regulator& regulator;
    int rozmiarBuforu;
    std::deque<double> wejscia;
    std::deque<double> wyjscia;
    JakiGenerator jakigen;
    double wartoscZadana;
};

#ifdef MAINPROJEKTU



int main()
{
    double wartoscZadana;
    std::cout << "Podaj wartosc zadana: ";
    std::cin >> wartoscZadana;

    std::deque<double> A{ 0.4,0.5};
    std::deque<double> B{ 0.6,0.7};

    int size = 10; // Rozmiar bufora
    int delay = 1; // OpóŸnienie transportowe

    Regulator regulator(1.0, 0.1, 0.05); // Parametry PID

    Sprzezenie sprzezenie(size, A, B, delay, regulator, JakiGenerator::Kwadratowo, wartoscZadana);
    int i = 0;
    double tolerance = 0.00001;
    int repeatCount = 0;
    double lastOutput = std::numeric_limits<double>::infinity();

    while (true)
    {
        double wyjscie = sprzezenie.Symuluj(i);

        // Sprawdzenie, czy wyjœcie osi¹ga wartoœæ zadan¹ w granicach tolerancji
        if (std::abs(wyjscie - wartoscZadana) < tolerance)
        {
            repeatCount++;
            if (repeatCount >= 3)
            {
                std::cout << "Osiagnieto wartosc zadana: " << wartoscZadana << " po " << i + 1 << " iteracjach." << std::endl;
                break;
            }
        }
        else
        {
            repeatCount = 0;
        }
        this_thread::sleep_for(chrono::milliseconds(500));

        lastOutput = wyjscie;
        i++;
    }
}
#endif // MAINPROJEKTU
