#include <string>
#include <iostream>
#include <vector>
#include "Motor.hpp"
#include "Veiculo2.hpp"
#include "CarroPasseio.hpp"

using namespace std;

int main()
{
	CarroPasseio carro;
	
	carro.PrintM();
	carro.PrintV();
	carro.Print();
	
	cout << endl;
	
	carro.GetM();
	carro.GetV();
	carro.Get();
	
	cout << endl;
	
	carro.PrintM();
	carro.PrintV();
	carro.Print();
	
	return 0;
}