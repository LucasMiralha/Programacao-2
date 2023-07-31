#include <iostream>
#include "Motor.hpp"

using namespace std;

Motor::Motor()
{
	numCilindro = 0;
	potencia = 0;
}

Motor::Motor(int nCili, int nPot)
{
	numCilindro = nCili;
	potencia = nPot;
}

void Motor::GetM()
{
	int c, p;
	cout << "Insira a quatidade de cilindros do motor: ";
	cin >> c;
	cout << "Insira a potencia do motor: ";
	cin >> p;
	
	numCilindro = c;
	potencia = p;
}

void Motor::PrintM()
{
	cout << "Cilindros no motor: " << numCilindro << endl; 
	cout << "Potencia do motor: " << potencia << endl;
}