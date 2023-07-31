#include <iostream>

using namespace std;

void trapezio(int menor, int maior);

int main()
{
	int menor, maior;
	
	cout << "Digite o tamanho da base menor: ";
	cin >> menor;
	cout << "Digite o tamanho da base maior: ";
	cin >> maior;
	cout << endl;
	
	trapezio(menor, maior);
	
	return 0;
}

void trapezio(int menor, int maior)
{
	int i = 0, j = 0, a = 0, b = -2, c = 0;
	
	for(i = 0; i <= menor; i++)
	{
		cout << "*";
	}
	cout << endl;
	for(j = 0; j <= (maior-menor); j++)
	{
		cout << "*";
		for(a = 0; a <= (b+menor); a++)
		{
			cout << " ";
		}
		cout << "*";
		cout << endl;
		b++;
	}
	for(c = 0; c <= maior; c++)
	{
		cout << "*";
	}
}