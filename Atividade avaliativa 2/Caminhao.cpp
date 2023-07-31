#include <iostream>
#include <string>
#include "Caminhao.hpp"

using namespace std;

void Caminhao::setCarga(double iCarga)
{
	carga = iCarga;
}

double Caminhao::getCarga()
{
	return carga;
}

void Caminhao::setTracao(int oTracao)
{
	tracao = oTracao;
}

int Caminhao::getTracao()
{
	return tracao;
}

Caminhao::Caminhao():Veiculo()
{
	carga = 0;
	tracao = 0;
}

Caminhao::Caminhao(string nFabrica, int nMotor, Pessoa nProprietario, double nCarga, int nTracao):Veiculo(nFabrica, nMotor, nProprietario)
{
	carga = nCarga;
	tracao = nTracao;
}

Caminhao& Caminhao::operator + (double const oCarga)
{
	Caminhao cargo;
	cargo.carga = carga + oCarga;
	return cargo;
}