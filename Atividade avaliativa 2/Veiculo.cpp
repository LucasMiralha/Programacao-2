#include <iostream>
#include <string>
#include "Veiculo.hpp"

using namespace std;

Veiculo::Veiculo()
{
	fabrica = " ";
	motor = 0;
	proprietario = Pessoa();
}

Veiculo::Veiculo(string nFabrica, int nMotor, Pessoa nProprietario)
{
	fabrica = nFabrica;
	motor = nMotor;
	proprietario = nProprietario;
}

void Veiculo::setFab(string oFab)
{
	fabrica = oFab;
}

string Veiculo::getFab()
{
	return fabrica;
}

void Veiculo::setMotor(int iMot)
{
	motor = iMot;
}

int Veiculo::getMotor()
{
	return motor;
}

void Veiculo::setProp(Pessoa oProp)
{
	proprietario = oProp;
}

Pessoa Veiculo::getProp()
{
	return proprietario;
}

Veiculo& Veiculo::operator + (int const oMotor)
{
	Veiculo gMotor;
	gMotor.motor += oMotor;
	return gMotor;
}