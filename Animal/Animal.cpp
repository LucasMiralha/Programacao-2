#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

Animal::Animal()
{
	peso = 0.0;
	altura = 0.0;	
	alimento = "NaoDefinido";
}

Animal::Animal(double nPeso, double nAltura, string nAlimento)
{
	peso = nPeso;
	altura = nAltura;
	alimento = nAlimento;	
}

void Animal::setPeso(double nPeso)
{
	peso = nPeso;	
}

double Animal::getPeso()
{
	return peso;
}

void Animal::setAltura(double nAltura)
{
	altura = nAltura;
}

double Animal::getAltura()
{
	return altura;
}

void Animal::setAlimento(string nAlimento)
{
	alimento = nAlimento;
}

string Animal::getAlimento()
{
	return alimento;
}

void Animal::som()
{
	cout << "Som de um animal" << endl;
}