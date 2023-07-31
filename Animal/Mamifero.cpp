#include <iostream>
#include <string>
#include "Mamifero.hpp"

using namespace std;

Mamifero::Mamifero() : Animal()
{
	corPelo = "SemCor";
}
Mamifero::Mamifero(string nCor, double nPeso, double nAltura, string nAlimento) : Animal(nPeso, nAltura, nAlimento)
{
	corPelo = nCor;
}

void Mamifero::setCor(string nCor)
{
	corPelo = nCor;
}

string Mamifero::getCor()
{
	return corPelo;
}

void Mamifero::som()
{
	cout << "Cor do pelo: " << corPelo << endl;
	cout << "Alimentacao: " << getAlimento() << endl;
}