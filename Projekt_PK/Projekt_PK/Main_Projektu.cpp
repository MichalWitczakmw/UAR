#include "Main_Projektu.h"

class Generator
{
public:
	Generator(){}
	~Generator(){}

	queue<double> Skokowo(int aktywacja, double wartoscStala)
	{
		for (int i = 0; i < wartoscZadana.size() ; i++)
		{
			if (terazniejszyCzasZegara > aktywacja)
				wartoscZadana.push(wartoscStala);
			else
				wartoscZadana.push(0.0);
			tik();
		}
		return wartoscZadana;
	}

	queue<double> Sinusoidalnie( double wartoscStala)
	{

		for (int i = 0; i < wartoscZadana.size(); i++)
		{
			wartoscZadana.push(sin((i % (int)(2*m_PI)/ (2 * m_PI))));
		}
		return wartoscZadana;
	}

	queue<double> SygnalProstokatny(int aktywacja, double wartoscStala)
	{

		for (int i = 0; i < wartoscZadana.size(); i++)
		{
			wartoscZadana.push(sin((i % aktywacja) * 2 * m_PI / aktywacja));
		}
		return wartoscZadana;
	}

private:
	queue<double> wartoscZadana = {};
	const double m_PI = 3.14;
	int terazniejszyCzasZegara = 0;

	void tik()
	{
		this_thread::sleep_for(chrono::seconds(1));
		terazniejszyCzasZegara++;
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
	cout << "siema";
	
}