#include <iostream>

using namespace std;

class Casa
{
	private:
		int qtdPessoas;
		
	public:
		Casa()
		{
			qtdPessoas = 0;
		}
		void setQtdPessoas(int nQtdPessoas)
		{
			qtdPessoas = nQtdPessoas;
		}
		int getQtdPessoas()
		{
			return qtdPessoas;	
		}	
		Casa operator+(const Casa& c)
		{
			Casa casa;
			casa.qtdPessoas = this->qtdPessoas + c.qtdPessoas;
			return casa;
		}
		Casa operator-(const Casa& c)
		{
			Casa casa;
			casa.qtdPessoas = this->qtdPessoas - c.qtdPessoas;
			return casa;
		}
};

int main()
{
	Casa casaVermelha;
	Casa casaAzul;
	Casa copia;
	
	copia.setQtdPessoas(5);
	casaVermelha.setQtdPessoas(5);
	casaAzul.setQtdPessoas(4);
	
	cout << "Numero de residentes na casa vermelha: " << casaVermelha.getQtdPessoas() << endl;
	cout << "Numero de residentes na casa azul: " << casaAzul.getQtdPessoas() << endl << endl;
	
	cout << "Os residentes da casa vermelha se mudaram para a casa azul" << endl;
	
	casaAzul = casaAzul + casaVermelha;
	casaVermelha = casaVermelha - copia;
	
	cout << "Numero de residentes na casa vermelha: " << casaVermelha.getQtdPessoas() << endl;
	cout << "Numero de residentes na casa azul: " << casaAzul.getQtdPessoas() << endl << endl;
	
	cout << "Os antigos residentes da casa vermelha voltaram para la" << endl << endl;
	
	casaVermelha = casaVermelha + copia;
	casaAzul = casaAzul - casaVermelha;
	
	cout << "Numero de residentes na casa vermelha: " << casaVermelha.getQtdPessoas() << endl;
	cout << "Numero de residentes na casa azul: " << casaAzul.getQtdPessoas() << endl;
	
	return 0;
}