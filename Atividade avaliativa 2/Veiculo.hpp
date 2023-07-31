#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

class Veiculo
{
	private:
		string fabrica;
		int motor;
		Pessoa proprietario;
		
	public:	
		Veiculo();
		Veiculo(string nFabrica, int nMotor, Pessoa nProprietario);
		void setFab(string oFab);
		string getFab();
		void setMotor(int iMot);
		int getMotor();
		void setProp(Pessoa oProp);
		Pessoa getProp();
		Veiculo& operator + (int const oMotor);
};

#endif