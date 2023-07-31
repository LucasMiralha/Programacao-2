#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
	private:
		string nome;
		
	public:
		Pessoa();
		Pessoa(string oNome);
		Pessoa(const Pessoa& oObjeto);
		string getNome() const;
		Pessoa& operator = (const Pessoa& ladoDir);
		friend istream& operator >> (istream& inStream, Pessoa& pessoaObjeto);
		friend ostream& operator << (ostream& outStream, const Pessoa& pessoaObjeto);	
};

#endif