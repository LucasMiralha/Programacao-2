#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float velocidade_vento, indice;
	int graus_celsius;
	
	cout << "Insira a velocidade do vento: ";
	cin >> velocidade_vento;
	cout << "Insira a temperatura em graus celsius: ";
	cin >> graus_celsius;
	
	if(graus_celsius <= 10)
	{
		indice = 13.12 + 0.6215 * graus_celsius - 11.37 * pow(velocidade_vento, 0.16) + 0.3965 * graus_celsius * pow(velocidade_vento, 0.016);
		cout << "O indice de frio do vento eh aproximadamente: " << indice << " Graus Celsius" << endl;
	}
	else
	{
		cout << "Temperatura muito alta para calcular o indice de frio do vento" << endl << "Encerrando programa";
	}
	
	return 0;
}