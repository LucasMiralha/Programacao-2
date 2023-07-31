#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <iostream>

class Motor
{
	private: 
		int numCilindro;
		int potencia;
	
	public:
		Motor();
		Motor(int nCili, int nPot);
		void GetM();
		void PrintM();		
};

#endif