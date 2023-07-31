#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

Pessoa::Pessoa()
{
	nome = " ";
}

Pessoa::Pessoa(string oNome)
{
	nome = oNome;
}

Pessoa::Pessoa(const Pessoa& oObjeto)
{
	nome = oObjeto.nome;
}

string Pessoa::getNome() const
{
	return nome;
}

Pessoa& Pessoa::operator = (const Pessoa& ladoDir)
{
	nome = ladoDir.nome;
	return *this;
}

istream& operator >> (istream& inStream, Pessoa& pessoaObjeto)
{
	inStream >> pessoaObjeto.nome;
	return inStream;
}

ostream& operator << (ostream& outStream, const Pessoa& pessoaObjeto)
{
	outStream << pessoaObjeto.nome;
	return outStream;
}