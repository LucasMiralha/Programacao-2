#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
	int i, a, b;
	
	cout << "Digite um numero: ";
	cin >> a;
	cout << "Digite outro numero: ";
	cin >> b;
	cout << endl;
	
	for(i = 0; i <= a; i++)
	{
		system("cls");
		cout << "Numero 1: " << a - i << endl;
		cout << "Numero 2: " << b + i;
	}
	a-=i;
	b+=i;
	system("cls");
	cout << "Numero 1: " << a+1 << endl;
	cout << "Numero 2: " << b-1;
	
	return 0;
}