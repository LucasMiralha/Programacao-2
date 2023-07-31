#ifndef MAMIFERO_HPP
#define MAMIFERO_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

class Mamifero : public Animal
{
	private:
		string corPelo;	
		
	public:
		Mamifero();
		Mamifero(string nCor, double nPeso, double nAltura, string nAlimento);
		void setCor(string nCor);
		string getCor();
		void som();
			
};

#endif