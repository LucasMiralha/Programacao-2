#ifndef DRONE_HPP
#define DRONE_HPP

#include <iostream>

using namespace std;

class drone
{
	private:
		int serie;
		int x;
		int y;
		int z;
	public:
		drone();
		drone(int nSerie, int nx, int ny, int nz);
		int andarFrente(int ny);
		int andarTras(int ny);
		int andarDireita(int nx);
		int andarEsquerda(int nx);
		int andarCima(int nz);
		int andarBaixo(int nz);
		void info();
};

#endif