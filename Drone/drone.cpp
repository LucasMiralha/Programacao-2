#include <iostream>
#include "drone.hpp"

using namespace std;



drone::drone()
	{
		serie = 413;
		x = 0;
		y = 0;
		z = 0;
	}
drone::drone(int nSerie, int nx, int ny, int nz)
	{
		serie = nSerie;
		x = nx;
		y = ny;
		z = nz;
	}
	
int drone::andarFrente(int ny)
	{
		y+=ny;
		return y;
	}
int drone::andarTras(int ny)
	{
		y-=ny;
		return y;
	}
int drone::andarDireita(int nx)
	{
		x+=nx;
		return x;
	}
int drone::andarEsquerda(int nx)
	{
		x-=nx;
		return x;
	}
int drone::andarCima(int nz)
	{
		z+=nz;
		return z;
	}
int drone::andarBaixo(int nz)
	{
		z-=nz;
		return z;
	}	
	
void drone::info()
	{
		cout << "Serie: " << serie << endl;
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;
	}	