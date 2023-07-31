#include <iostream>
#include <cmath>

using namespace std;

double inflacao(float, float);

int main()
{
	float preco_ano_passado, preco_atual;
	double porcentagem;
	
	cout << "Insira o preco do produto ha 1 ano atras: ";
	cin >> preco_ano_passado;
	cout << "Insira o preco atual do produto: ";
	cin >> preco_atual;
	cout << endl;
	
	porcentagem = inflacao(preco_ano_passado, preco_atual);
	
	cout << "A taxa de inflacao nesse produto foi de: " << porcentagem-100 << "%" << endl;
	
	return 0;
}

double inflacao(float preco_ano_passado, float preco_atual)
{
	return ((preco_atual*100)/preco_ano_passado);
}