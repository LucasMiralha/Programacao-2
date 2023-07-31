#include <iostream>
#include "drone.hpp"

using namespace std;

int main() 
{	
	drone Wai3;
	drone Hou7;

	Hou7 = drone(420, 20, 20, 20);
	
	Wai3.info();
	Hou7.info();
	
	Wai3.andarDireita(7);
	Wai3.andarFrente(20);
	Wai3.andarCima(44);
	
	Hou7.andarEsquerda(13);
	Hou7.andarFrente(0);
	Hou7.andarCima(24);
	
	Wai3.info();
	Hou7.info();
	
	return 0;
}