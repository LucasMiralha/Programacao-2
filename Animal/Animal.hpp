#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

using namespace std;

class Animal
{
	private:
		double peso;
		double altura;
		string alimento;	
		
	public:
		Animal();
		Animal(double nPeso, double nAltura, string nAlimento);
		void setPeso(double nPeso);
		double getPeso();
		void setAltura(double nAltura);
		double getAltura();
		void setAlimento(string nAlimento);
		string getAlimento();
		virtual void som();
			
};

#endif