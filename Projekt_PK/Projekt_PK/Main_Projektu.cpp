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
			if (i > aktywacja)
				wartoscZadana.push(wartoscStala);
		}
	}

	queue<double> Sinusoidalnie(int aktywacja, double wartoscStala)
	{

		for (int i = 0; i < wartoscZadana.size(); i++)
		{
			wartoscZadana.push(sin((i % aktywacja) * 2 * m_PI / aktywacja));
		}
	}

	queue<double> SygnalProstokatny(int aktywacja, double wartoscStala)
	{

		for (int i = 0; i < wartoscZadana.size(); i++)
		{
			wartoscZadana.push(sin((i % aktywacja) * 2 * m_PI / aktywacja));
		}
	}

private:
	queue<double> wartoscZadana = {};
	const double m_PI = 3.14;
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