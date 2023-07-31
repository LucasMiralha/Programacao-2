#include <iostream>
#include "Veiculo2.hpp"

using namespace std;

Veiculo::Veiculo()
{
	peso = 0;
	velocMax = 0;
	preco = 0.0;
}

Veiculo::Veiculo(int nPeso, int nVelmax, float nPreco)
{
	peso = nPeso;
	velocMax = nVelmax;
	preco = nPreco;
}

void Veiculo::GetV()
{
	int p, vm, pr;
	cout << "Insira o peso do veiculo: ";
	cin >> p;
	cout << "Insira a velocidade maxima do veiculo: ";
	cin >> vm;
	cout << "Insira preco do veiculo: ";
	cin >> pr;
	
	peso = p;
	velocMax = vm;
	preco = pr;
}

void Veiculo::PrintV()
{
	cout << "Peso do veiculo: " << peso << endl; 
	cout << "Velocidade maxima do veiculo: " << velocMax << endl;
	cout << "Preco do veiculo: " << preco << endl;
}