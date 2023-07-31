#include <iostream>
#include <cstdlib>

using namespace std;

int MaiorValor(int a, int b);
int MaiorValor(int a, int b, int c);
int MaiorValor(int a, int b, int c, int d);

int main()
{
	
	int a = 0, b = 0, c = 0, d = 0;
	int inseridos;
	
	system("cls");
	
	cout << "Digite quantos numeros serao inseridos (entre 2 e 4):";
	cin >> inseridos;
	cout << endl;
	
	switch(inseridos)
	{
		case 2:
			cout << "Digite a: ";
			cin >> a;
			cout << endl;
			cout << "Digite b: ";
			cin >> b;
			cout << endl;
			cout << "Maior numero: " << MaiorValor(a, b);
			break;
		case 3:
			cout << "Digite a: ";
			cin >> a;
			cout << endl;
			cout << "Digite b: ";
			cin >> b;
			cout << endl;
			cout << "Digite c: ";
			cin >> c;
			cout << endl;
			cout << "Maior numero: " << MaiorValor(a, b, c);
			break;
		case 4:
			cout << "Digite a: ";
			cin >> a;
			cout << endl;
			cout << "Digite b: ";
			cin >> b;
			cout << endl;
			cout << "Digite c: ";
			cin >> c;
			cout << endl;
			cout << "Digite d: ";
			cin >> d;
			cout << endl;
			cout << "Maior numero: " << MaiorValor(a, b, c, d);
			break;
		default:
			cout << "Valor invalido!" << endl;
			main();
			break;
	}
	
	return 0;
}

int MaiorValor(int a, int b)
{
	int base = -9999;
	int resultado;
	
	if(a > base)
	{
		resultado = a;
	}
	if(b > resultado)
	{
		resultado = b;
	}
	
	return resultado;
}

int MaiorValor(int a, int b, int c)
{
	int base = -9999;
	int resultado;
	
	if(a > base)
	{
		resultado = a;
	}
	if(b > resultado)
	{
		resultado = b;
	}
	if(c > resultado)
	{
		resultado = c;
	}
	
	return resultado;
}

int MaiorValor(int a, int b, int c, int d)
{
	int base = -9999;
	int resultado;
	
	if(a > base)
	{
		resultado = a;
	}
	if(b > resultado)
	{
		resultado = b;
	}
	if(c > resultado)
	{
		resultado = c;
	}
	if(d > resultado)
	{
		resultado = d;
	}
	
	return resultado;
}