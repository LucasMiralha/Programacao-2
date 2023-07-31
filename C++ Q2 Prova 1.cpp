#include <iostream>

using namespace std;

class maquinaTempo
{
	private:
		int ano;
		int x;
		int y;
		int z;
		
	public:
		maquinaTempo()
		{
			ano = 997;
			x = 41;
			y = 13;
			z = 20;
		}
		maquinaTempo(int nAno, int nx, int ny, int nz)
		{
			ano = nAno;
			x = nx;
			y = ny;
			z = nz;
		}
		int andarFrente(int ny)
		{
			y+=ny;
			return y;
		}
		int andarTras(int ny)
		{
			y-=ny;
			return y;
		}
		int andarDireita(int nx)
		{
			x+=nx;
			return x;
		}
		int andarEsquerda(int nx)
		{
			x-=nx;
			return x;
		}
		int andarCima(int nz)
		{
			z+=nz;
			return z;
		}
		int andarBaixo(int nz)
		{
			z-=nz;
			return z;
		}
		int viajar(int nAno)
		{
			ano = nAno;
			return ano;
		}
		void info()
		{
			cout << "Ano: " << ano << endl;	
			cout << "X: " << x << endl;
			cout << "Y: " << y << endl;
			cout << "Z: " << z << endl;
		}
	
};

int main()
{
	int nAno, nx, ny, nz;
	
	maquinaTempo Azan, Sarek;
	
	Azan = maquinaTempo();
	Sarek = maquinaTempo(1945, 15, 15, 15);
	
	Azan.andarEsquerda(34);
	Azan.andarFrente(7);
	Azan.andarCima(24);
	Azan.viajar(2112);
	
	Sarek.andarEsquerda(8);
	Sarek.andarFrente(5);
	Sarek.andarCima(29);
	Sarek.viajar(2112);
	
	cout << "Azan: " << endl;
	Azan.info();
	cout << endl;
	cout<< "Sarek: " << endl;
	Sarek.info();
	
	return 0;
}