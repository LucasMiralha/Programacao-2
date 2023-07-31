#include <string>
#include <vector>
#include <iostream>
#include "Motor.hpp"
#include "Veiculo2.hpp"
#include "CarroPasseio.hpp"

using namespace std;

CarroPasseio::CarroPasseio() : Motor(), Veiculo()
{
	cor = " ";
	modelo = " ";
}

CarroPasseio::CarroPasseio(string nCor, string nModelo)
{
	cor = nCor;
	modelo = nModelo;
}

void CarroPasseio::Get()
{
	string c, m;
	
	fflush(stdin);
	cout << "Digite a cor do carro de passeio: ";
	cin >> c;
	fflush(stdin);
	cout << "Digite o modelo do carro de passeio: ";
	cin >> m;
	
	cor = c;
	modelo = m;
}

void CarroPasseio::Print()
{
	cout << "Cor do carro de passeio: " << cor << endl;
	cout << "Modelo do carro de passeio: " << modelo << endl;
}