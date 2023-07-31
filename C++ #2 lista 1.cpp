#include <iostream>
using namespace std;

int main()
{
	float compra, venda;
	
	cout << "Digite o valor do produto: " << endl;
	cin >> compra;
	
	if(compra >= 20)
	{
		venda = compra *1.30;
	}
	else
	{
		venda = compra *1.45;
	}
	
	cout << "Valor de venda sugerido: " << venda << endl;
	
	return 0;
}