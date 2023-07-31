#include <iostream>
#include <cstdlib>

using namespace std;

float tamanho_chapeu(float, float);
float tamanho_casaco(float, float, int);
float tamanho_cintura(float, int);

int main()
{
	int menu, idade;
	float peso, altura;	
	
	system("cls");
	
	cout << "Calculadora de tamanho de roupas" << endl << endl;
	cout << "Digite seu peso em libras: ";
	cin >> peso;
	cout << "Digite sua altura em polegadas: ";
	cin >> altura;
	cout << "Digite sua idade: ";
	cin >> idade;
	cout << endl << endl;
		
	tamanho_chapeu(peso, altura);

	tamanho_casaco(peso, altura, idade);

	tamanho_cintura(peso, idade);
	
	cout << "Deseja repetir a operacao?" << endl;
	cout << "1 - Sim\t2 - Nao" << endl;
	cin >> menu;
	if(menu == 1)
	{
		main();
	}
	else
	{
		cout << "Encerrando o programa" << endl;
	}
	
	return 0;
}

float tamanho_chapeu(float peso, float altura)
{
	float t_chapeu;
	
	t_chapeu = (peso/altura)*2.9;
	
	cout << "O tamanho do seu chapeu deve ser: " << t_chapeu << endl << endl;
	
	return 0;
}

float tamanho_casaco(float peso, float altura, int idade)
{
	float t_casaco;
	
	if(idade < 30)
	{
		t_casaco = altura * (peso/288);
	}
	else if(idade >= 30 || idade <= 39)
	{
		t_casaco = altura * (peso/288) + 1/8;
	}
	else if(idade >= 40 || idade <= 49)
	{
		t_casaco = altura * (peso/288) + 2/8;
	}
	else if(idade >= 50 || idade <= 59)
	{
		t_casaco = altura * (peso/288) + 3/8;
	}
	else if(idade >= 60 || idade <= 69)
	{
		t_casaco = altura * (peso/288) + 4/8;
	}
	else if(idade >= 70 || idade <= 79)
	{
		t_casaco = altura * (peso/288) + 5/8;
	}
	else if(idade >= 80 || idade <= 89)
	{
		t_casaco = altura * (peso/288) + 6/8;
	}
	else if(idade >= 90 || idade <= 99)
	{
		t_casaco = altura * (peso/288) + 7/8;
	}
	
	cout << "O tamanho do seu casaco deve ser: " << t_casaco << endl << endl;
	
	return 0;
}

float tamanho_cintura(float peso, int idade)
{
	float t_cintura;
	int acrescimo = 0, i = 1;
	
	do
	{
		acrescimo += 0.2;
		i++;
	}while(i <= idade/2);

	t_cintura = peso/5.7 + acrescimo;
	
	cout << "O tamanho da sua cintura eh: " << t_cintura << endl << endl;
	
	return 0;
}