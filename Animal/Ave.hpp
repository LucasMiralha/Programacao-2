#ifndef AVE_HPP
#define AVE_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

class Ave : public Animal
{
	private:
		string corPena;	
		
	public:
		Ave();
		Ave(string nCor, double nPeso, double nAltura, string nAlimento);
		void setCor(string nCor);
		string getCor();
		void som();
			
};

#endif