#include <iostream>

using namespace std;

void sequencia(int termo[999], int tamanho);

int main()
{
	int termo[999], tamanho;
	
	cout << "Digite o primeiro termo da sequencia: ";
	cin >> termo[0];
	cout << "Digite o segundo termo da sequencia: ";
	cin >> termo[1];
	cout << "Digite o numero de termos total: ";
	cin >> tamanho;
	cout << endl << endl;
	
	sequencia(termo, tamanho);
	
	return 0;
}

void sequencia(int termo[999], int tamanho)
{
	int i = 3;
	
	cout << "Termo 1: " << termo[0] << endl << "Termo 2: " << termo[1] << endl;
	
	for(i = 3; i <= tamanho; i++)
	{
		termo[i-1] = (4*termo[i-2]) - (4*termo[i-3]); 
		cout << "Termo " << i << ": " << termo[i-1] << endl;
	}
	
}