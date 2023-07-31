#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream arquivoSaida;
	
	arquivoSaida.open("Output.txt", ios::app);
	
	if(arquivoSaida.is_open())
	{
		arquivoSaida << "Texto :D";
		
		arquivoSaida.close();
	}
	
	arquivoSaida.open("Output.txt", ios::app);
	
	if(arquivoSaida.is_open())
	{
		arquivoSaida << "Texto 2 B)";
		
		arquivoSaida.close();
	}
	
	return 0;
}