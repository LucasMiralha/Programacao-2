#include <iostream>
using namespace std;

int main()
{
	
	int i = 1, j = 1, u;
	char a;
	
	cout << "Voce deseja desenhar o padrao?" << endl << "Y (ou y) - Sim" << endl << "Q (ou q) - Sair" << endl;
	cin >> a;
	
	if(a == 'Y' || a == 'y')
	{
		for(u = 0; u < 8; u++)
		{
			if(u%2 == 0)
			{
				for(i = 1; i <= 9; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			else
			{
				for(j = 1; j <= 9; j++)
				{
					cout << " *";
				}
				cout << endl;
			}
		}
	}
	else if(a == 'Q' || a == 'q')
	{
		cout << "Saindo";
	}
	else
	{
		cout << "Comando nao reconhecido, fechando programa";
	}
	
	return 0;
}