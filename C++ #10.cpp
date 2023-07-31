#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int i, j, a, b, numero, posicao[100], ocorrencias = 0, vetor[100];
	srand(time(NULL));
	
	for(b = 0; b < 100; b++)
	{
		posicao[b] = 0;
	}
	
	for(i = 0; i < 100; i++)
	{
		vetor[i] = rand() % 100;
		cout << vetor[i] << endl;
	}
	
	cout << endl << "Digite algum numero: ";
	cin >> numero;
	cout << endl;
	
	for(j = 0; j < 100; j++)
	{
		if(numero == vetor[j])
		{
			ocorrencias+=1;
			posicao[j] = j;
		}
	}
	
	cout << "Seu numero: " << numero << " apareceu " << ocorrencias << " vezes" << endl;
	cout << "Nas posicoes: " << endl;
	
	for(a = 0; a < 100; a++)
	{
		if(posicao[a] > 0)
		{
			cout << posicao[a]+1;
			cout << endl;
		}
		
	}
	
	return 0;
}