#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include <iostream>
#include <string>
#include "Veiculo.hpp"

using namespace std;

class Caminhao : public Veiculo
{
	private:
		double carga;
		int tracao;
		
	public:
		Caminhao();
		Caminhao(string nFabrica, int nMotor, Pessoa nProprietario, double nCarga, int nTracao);
		void setCarga(double iCarga);
		double getCarga();	
		void setTracao(int oTracao);
		int getTracao();
		Caminhao& operator + (double const oCarga);
};

#endif