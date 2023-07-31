#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	int i = 0;
	int soma = 0;
	double rnd, med = 0.0, desp = 0.0, num, xi = 0.0, xt = 0.0;
	fstream arquivo;
	
	srand(time(NULL));
	
	arquivo.open("AvContinua.txt", ios::app);
	
	for(i = 0; i < 10; i++)
	{
		if(arquivo.is_open())
		{
			rnd = (rand()%19999) + 0.01*((rand()%100)+1);
		
			arquivo << rnd << endl;
		}
	}
	
	arquivo.close();
	arquivo.open("AvContinua.txt", ios::in);
	
	while(!arquivo.eof())
	{
		arquivo >> num;
		med+=num;
		soma++;
	}
	
	arquivo.close();
	arquivo.open("AvContinua.txt", ios::in);
	
	while(!arquivo.eof())
	{
		arquivo >> num;
		xi = pow((num-med), 2);
		xt+=xi;
	}
	
	med = med/soma;
	desp = sqrt(xt/soma);
	
	arquivo.close();
	
	cout << "Media: " << med << endl;
	cout << "Desvio padrao: " << desp << endl;
	
	return 0;
}