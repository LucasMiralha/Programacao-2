#include <iostream>
#include <string>
#include "Ave.hpp"

using namespace std;

Ave::Ave() : Animal()
{
	corPena = "SemCor";
}
Ave::Ave(string nCor, double nPeso, double nAltura, string nAlimento) : Animal(nPeso, nAltura, nAlimento)
{
	corPena = nCor;
}

void Ave::setCor(string nCor)
{
	corPena = nCor;
}

string Ave::getCor()
{
	return corPena;
}

void Ave::som()
{
	cout << "Cor das penas: " << corPena << endl;
	cout << "Alimentacao: " << getAlimento() << endl;
}