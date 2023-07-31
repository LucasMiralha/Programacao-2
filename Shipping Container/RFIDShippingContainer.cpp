#include <iostream>
#include <string>
#include <vector>
#include "RFIDShippingContainer.hpp"

using namespace std;

void RFIDShippingContainer::add(string nReg)
{
	int i;
	string copia;
	bool repetido;
	
	//Nao consegui achar uma maneira eficiente de numerar as caixas
	//por isso o codigo so funciona uma vez
	//Pensei e tentei fazer uma manipulacao de string, a minha ideia original seria:
	//Quando o .add eh chamado, ele recebe uma string, essa string receberia um espaco
	//vazio no primeiro caractere dela (ex: recebeu: caixa de maca. a string ficaria:  caixa de maca)
	//esse espaco vazio iria servir para alocar o int de vezes repetidas e apaga-lo quando ele precisar
	//ser substituido por outro numero. Isso iria funcionar ate o numero 9, porque esse metodo nao
	//suporta numeros de dois digitos. Por ter somente um espaco que eh adicionado e apagado.
	//Nisso eu precisaria de uma copia da string para poder separa-la, converter o primeiro 
	//membro dela para int, somar, e depois para string de novo e adiciona-lo na string original.
	//Nao sei se acabei complicando muitos as coisas, e se tinha uma forma mais facil que nao
	//consegui achar.
	
	repetido = false;
	
	for(i = 0; i < registro.size(); i++)
	{
		if(nReg == registro[i])
		{
			registro[i] = "2 " + nReg;
			repetido = true;
		}
	}
	
	if(repetido == false)
	{
		registro.push_back(nReg);
	}
}

string RFIDShippingContainer::getManifest()
{
	int i;
		
	for(i = 0; i < registro.size(); i++)
	{
		manifest = manifest + ". " + registro[i];
	}
	
	return manifest;
}