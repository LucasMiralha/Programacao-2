#ifndef CARROPASSEIO_HPP
#define CARROPASSEIO_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Motor.hpp"
#include "Veiculo2.hpp"

using namespace std;

class CarroPasseio : public Motor, public Veiculo
{
	private:
		string cor;
		string modelo;
		
	public:
		CarroPasseio();
		CarroPasseio(string nCor, string nModelo);
		void Get();
		void Print();
			
};

#endif