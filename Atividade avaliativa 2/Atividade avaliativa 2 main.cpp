#include <iostream>
#include <string>
#include "Veiculo.hpp"
#include "Pessoa.hpp"
#include "Caminhao.hpp"

using namespace std;

int main()
{
	double cargaExtra = 420.42042069;
	int cilindrosExtra = 2;
	
	Pessoa Pedro("Pedro");
	Pessoa Akira("Akira");
	Pessoa Calus("Calus");
	
	Caminhao toyota2002;
	Caminhao smasher;
	Caminhao optimusPrime;
	
	cout << Calus << endl << endl;
	
	toyota2002 = Caminhao("Toyota", 6, Pedro, 500.404040, 2);
	cout << "Proprietario: " << toyota2002.getProp() << endl;
	cout << "Marca: " << toyota2002.getFab() << endl;
	cout << "Cilindros: " << toyota2002.getMotor() << endl;
	cout << "Capacidade: " << toyota2002.getCarga() << endl;
	cout << "Tracao: " << toyota2002.getTracao() << endl;
	
	cout << endl << endl;
	
	cout << "Proprietario: " << smasher.getProp() << endl;
	smasher.setProp(Akira);
	cout << "Proprietario: " << smasher.getProp() << endl;
	cout << "Marca: " << smasher.getFab() << endl;
	cout << "Cilindros: " << smasher.getMotor() << endl;
	cout << "Capacidade: " << smasher.getCarga() << endl;
	cout << "Tracao: " << smasher.getTracao() << endl;
	cout << endl;
	smasher = Caminhao("Mitsubishi", 6, Akira, 400.45454545, 2);
	cout << "Proprietario: " << smasher.getProp() << endl;
	cout << "Marca: " << smasher.getFab() << endl;
	cout << "Cilindros: " << smasher.getMotor() << endl;
	cout << "Capacidade: " << smasher.getCarga() << endl;
	cout << "Tracao: " << smasher.getTracao() << endl;
	smasher+cilindrosExtra;
	cout << "Cilindros: " << smasher.getMotor() << endl;
	
	cout << endl << endl;
	
	optimusPrime.setCarga(600.100006);
	optimusPrime.setFab("Autobots");
	optimusPrime.setMotor(8);
	optimusPrime.setProp(Calus);
	optimusPrime.setTracao(6);
	
	cout << "Proprietario: " << optimusPrime.getProp() << endl;
	cout << "Marca: " << optimusPrime.getFab() << endl;
	cout << "Cilindros: " << optimusPrime.getMotor() << endl;
	cout << "Capacidade: " << optimusPrime.getCarga() << endl;
	cout << "Tracao: " << optimusPrime.getTracao() << endl;
	optimusPrime+cargaExtra;
	cout << "Capacidade: " << optimusPrime.getCarga() << endl;
	
	return 0;
}