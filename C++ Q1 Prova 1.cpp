#include <iostream>

using namespace std;

int main()
{
	
	int carro[25];
	int ncar, lugares;
	int i = 0, j = 0;
	int sn, t = 0;
	
	for(i = 0; i < 25; i++)
	{
		carro[i] = 6;
	}
	
	do 
	{
		for(j = 0; j < 25; j++)
		{
			if(carro[j] == 0)
			{
				t += 1;
			}
		}
		
		system("cls");
		cout << "Digite o numero do carro (400 - 424) " << endl;
	    cin >> ncar;
		
		if(ncar >= 400 && ncar < 425)
		{
			cout << "Carro " << ncar << " selecionado" << endl;
			cout << "Este carro possui " << carro[ncar-400] << " lugares" << endl;
			cout << "Gostaria de reservar algum lugar nesse carro? " << endl;
			cout << "1) Sim\t2) Nao" << endl;
			cin >> sn;
			if(sn == 1)
			{
				system("cls");
				cout << "Carro " << ncar << endl;
				cout << "Lugares disponiveis " << carro[ncar-400] << endl;	
				cout << "Deseja reservar quantos lugares? " << endl;
				cin >> lugares;
				if(carro[ncar-400] - lugares >= 0)
				{
					cout << lugares << " reservados no carro " << ncar << endl;
					cout << "Restam " << carro[ncar-400] - lugares << " vagas no carro " << ncar << endl;
					carro[ncar-400] -= lugares;
				}
				else if(carro[ncar-400] - lugares < 0)
				{
					cout << "Este carro nao possui vagas suficientes, procure outro carro" << endl;
				}
			}
			system("pause");
		}
		else if(ncar == 0)
		{
			cout << "O programa sera encerrado" << endl;
		}
		else
		{
			cout << "numero invalido" << endl;
			system("pause");
		}
		
		if(t == 25)
		{
			cout << "Todos os carros lotados, encerrando programa" << endl;
			ncar = 0;
		}
		
	}while(ncar != 0);
	
	cout << "Encerrando";
	
	return 0;
}
