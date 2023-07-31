#include <iostream>
#include "Animal.hpp"
#include "Mamifero.hpp"
#include "Ave.hpp"

using namespace std;

int main()
{
	Animal *ditto;
	Animal jabuti;
	Animal tartaruga(80.76, 1.23, "Folhas");
	Mamifero sphinx("Rosa", 10.54, 0.98, "Racao");
	Ave cacatua("Branco", 4.32, 0.29, "Sementes");
	
	cout << "Informacoes jabuti: " << endl;
	cout << "Altura: " << jabuti.getAltura() << endl;
	cout << "Peso: " << jabuti.getPeso() << endl; 
	cout << "Alimento: " << jabuti.getAlimento() << endl;
	jabuti.som();
	
	jabuti.setPeso(7.86);
	jabuti.setAltura(9.88);
	jabuti.setAlimento("Frutas");
	
	cout << endl;
	
	cout << "Informacoes jabuti: " << endl;
	cout << "Altura: " << jabuti.getAltura() << endl;
	cout << "Peso: " << jabuti.getPeso() << endl; 
	cout << "Alimento: " << jabuti.getAlimento() << endl;
	jabuti.som();
	
	cout << endl;
	
	cout << "Informacoes sphinx: " << endl;
	cout << "Altura: " << sphinx.getAltura() << endl;
	cout << "Peso: " << sphinx.getPeso() << endl; 
	sphinx.som();
	
	sphinx.setCor("Laranja");
	sphinx.setAlimento("Lasanha");
	
	cout << endl;
	
	cout << "Informacoes sphinx: " << endl;
	cout << "Altura: " << sphinx.getAltura() << endl;
	cout << "Peso: " << sphinx.getPeso() << endl; 
	sphinx.som();
	
	cout << endl;	
	
	cout << "Informacoes cacatua: " << endl;
	cout << "Altura: " << cacatua.getAltura() << endl;
	cout << "Peso: " << cacatua.getPeso() << endl; 
	cacatua.som();
	
	cacatua.setCor("Amarelo");
	
	cout << endl;
	
	cout << "Informacoes cacatua: " << endl;
	cout << "Altura: " << cacatua.getAltura() << endl;
	cout << "Peso: " << cacatua.getPeso() << endl; 
	cacatua.som();
	
	cout << endl;
	
	cout << "Informacoes tartaruga: " << endl;
	cout << "Altura: " << tartaruga.getAltura() << endl;
	cout << "Peso: " << tartaruga.getPeso() << endl; 
	cout << "Alimento: " << tartaruga.getAlimento() << endl;
	tartaruga.som();
	
	cout << endl;
	
	ditto = &sphinx;
	cout << "Informacoes ditto: " << endl;
	cout << "Altura: " << ditto->getAltura() << endl;
	cout << "Peso: " << ditto->getPeso() << endl; 
	ditto->som();
	cout << endl;
	ditto = &cacatua;
	cout << "Informacoes ditto: " << endl;
	cout << "Altura: " << ditto->getAltura() << endl;
	cout << "Peso: " << ditto->getPeso() << endl; 
	ditto->som();
	cout << endl;
	ditto = &tartaruga;
	cout << "Informacoes ditto: " << endl;
	cout << "Altura: " << ditto->getAltura() << endl;
	cout << "Peso: " << ditto->getPeso() << endl; 
	ditto->som();
	cout << endl;
	ditto = &jabuti;
	cout << "Informacoes ditto: " << endl;
	cout << "Altura: " << ditto->getAltura() << endl;
	cout << "Peso: " << ditto->getPeso() << endl; 
	ditto->som();
	
	return 0;
}