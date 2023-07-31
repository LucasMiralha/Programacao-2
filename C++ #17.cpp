#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	fstream arquivo;
	string nome;
	
	arquivo.open("Pessoas.txt");
	
	int esc;
	
	do
	{
		cout << "1 - Escrever " << endl;
		cout << "2 - Ler" << endl;
		cin >> esc;
		
		if(esc == 1)
		{
			arquivo.open("Pessoas.txt", ios::app);
			if(arquivo.is_open())
			{
				cout << "Nome: ";
				cin.ignore(1);
				getline(cin, nome);
				
				arquivo << nome << endl;
				
				arquivo.close();
			}
		}
		else if(esc == 2)
		{
			arquivo.open("Pessoas.txt", ios::in);
			arquivo.seekg(0);
			while(!arquivo.eof())
			{
				getline(arquivo, nome);
				cout << nome << endl;
			}
			arquivo.close();
		}
		
	}while(esc != 0);
	
	return 0;
}