#include <iostream>

using namespace std;

int analise(int raio, int x, int y, int a, int b, int c, int d, int e, int f, int g, int h);

int main()
{
	
	int raio, x, y;
	int a, b, c, d, e, f, g, h;
	
	cout << "Digite as coordenadas do centro da circunferencia: ";
	cin >> x >> y; 
	cout << "Digite o raio da circunferencia: ";
	cin >> raio;
	cout << endl;
	cout << "Digite as coordenadas do ponto superior esquerdo do retangulo: ";
	cin >> a >> b;
	cout << "Digite as coordenadas do ponto superior direito do retangulo: ";
	cin >> c >> d;
	cout << "Digite as coordenadas do ponto inferior esquerdo do retangulo: ";
	cin >> e >> f;
	cout << "Digite as coordenadas do ponto inferior direito do retangulo: ";
	cin >> g >> h;
	
	analise(raio, x, y, a, b, c, d, e, f, g, h);
	
	return 0;
}

int analise(int raio, int x, int y, int a, int b, int c, int d, int e, int f, int g, int h)
{
	int circulo[1][1];
	int pse[1][1], psd[1][1], pie[1][1], pid[1][1];
	
	
	
	
}