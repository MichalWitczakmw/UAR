#include "Main_Projektu.h"

class Generator
{
public:
    Generator(){}

    // Funkcja generuj¹ca wartoœæ skoku jednostkowego dla konkretnej chwili czasu
    double Skokowo(int aktywacja, double wartoscStala, int i)
    {
        return (i >= aktywacja) ? wartoscStala : 0.0;
    }

    // Funkcja generuj¹ca wartoœæ sinusoidy dla konkretnej chwili czasu
    double Sinusoidalnie(int okres, double amplituda, int i)
    {
        constexpr double m_PI = 3.14;
        return amplituda * std::sin((i % okres) * 2 * m_PI / okres);
    }

    // Funkcja generuj¹ca wartoœæ sygna³u prostok¹tnego dla konkretnej chwili czasu
    double SygnalProstokatny(int okres, double wypelnienie, double amplituda, int i)
    {
        return ((i % okres) < wypelnienie * okres) ? amplituda : 0.0;
    }

    void AktualizujBufor(std::deque<double>& bufor, double nowaWartosc, int maxRozmiar)
    {
        if (bufor.size() == maxRozmiar)
        {
            bufor.pop_front();
        }
        bufor.push_back(nowaWartosc);
    }


};



class Sprzerzenie
{
public:
	Sprzerzenie() {}
	~Sprzerzenie() {}



private:

};
class Regulator
{
public:
	Regulator() {}
	~Regulator() {}

private:

};
class ModelARX
{
public:
	ModelARX() {}
	~ModelARX() {}

private:

};
class Zaklucenia
{
public:
	Zaklucenia() {}
	~Zaklucenia() {}

private:

};


int main()
{
    int size = 10; // Rozmiar sygna³u (liczba próbek)
    Generator generator;

    // Parametry sygna³ów
    int t = 5;              // chwila aktywacji
    double A_step = 1.0;    // wartoœæ sta³a dla skoku
    int T_sine = 6;         // okres dla sinusoidy
    double A_sine = 1.0;    // amplituda sinusoidy
    int T_square = 6;       // okres dla sygna³u prostok¹tnego
    double p = 0.5;         // wype³nienie sygna³u prostok¹tnego
    double A_square = 1.0;  // amplituda sygna³u prostok¹tnego

    std::deque<double> stepSignal;
    std::deque<double> sineSignal;
    std::deque<double> squareSignal;

  

    int i = 0;
    while (true)
    {
        // Generowanie nowych wartoœci sygna³ów
        double stepValue = generator.Skokowo(t, A_step, i);
        double sineValue = generator.Sinusoidalnie(T_sine, A_sine, i);
        double squareValue = generator.SygnalProstokatny(T_square, p, A_square, i);

        // Aktualizacja buforów
        generator.AktualizujBufor(stepSignal, stepValue, size);
        generator.AktualizujBufor(sineSignal, sineValue, size);
        generator.AktualizujBufor(squareSignal, squareValue, size);

        // Wyœwietlanie aktualnych wartoœci buforów
        std::cout << "Czas: " << i << " sekund" << std::endl;
        std::cout << "Bufor skoku jednostkowego: ";
        for (double val : stepSignal)
            std::cout << val << " ";
        std::cout << std::endl;

        std::cout << "Bufor sinusoidy: ";
        for (double val : sineSignal)
            std::cout << val << " ";
        std::cout << std::endl;

        std::cout << "Bufor sygna³u prostok¹tnego: ";
        for (double val : squareSignal)
            std::cout << val << " ";
        std::cout << std::endl;

        std::cout << std::endl;

        // Czekanie 1 sekundy
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Inkrementacja czasu
        i++;
    }
	
}