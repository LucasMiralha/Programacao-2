#ifndef VEICULO2_HPP
#define VEICULO2_HPP

#include <iostream>

class Veiculo
{
	private:
		int peso;
		int velocMax;
		float preco;
		
	public:
		Veiculo();
		Veiculo(int nPeso, int nVelmax, float nPreco);
		void GetV();
		void PrintV();	
};

#endif