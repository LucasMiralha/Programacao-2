#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream arquivoEntrada;
	
	arquivoEntrada.open("Input.txt");
	
	int numero;
	
	while(!arquivoEntrada.eof())
	{
		arquivoEntrada >> numero;
		cout << numero << endl;
	}
	
	arquivoEntrada.seekg(3);
	arquivoEntrada >> numero;
	cout << numero << endl;
	
	arquivoEntrada.close();
	
	return 0;
}