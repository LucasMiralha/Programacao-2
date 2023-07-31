//#include <stdio>
#include <iostream>
using namespace std;

// Comandos basicos c++ 05/08/2022

int main()
{
	int i = 5, x, y, a, b, c;
	float f = 1.79;
	char ch = 'A';
	bool bl = false;
	
    //printf("Hello world!");
    std::cout << "Hello world" << std::endl << "Outro texto" << std::endl;
    std::cout << "My bell of conquests is so grand, because I lived a grand life";
    std::cout << std::endl;
    std::cout << "123456789" << std::endl;
    std::cout << "O\tO";
    std::cout << "\n";
    std::cout << "A";
    
    std::cout << std::endl << "Valor de X = " << i << std::endl;
    
    std::cout << "Digite dois numero: " << std::endl;
    //scanf(%i, &i);
	std::cin >> x >> y;
    
    b = x < y;
    
    if(b == 1)
	{
    std::cout << "Verdadeiro" << std::endl;
	}
	else
	{
    std::cout << "Falso" << std::endl;
	}
	
	//pos namespaces std
	cout << "Digite um numero(A): "<< endl;
	cin >> a;
	cout << "Digite outro numero(B): "<< endl;
	cin >> b;
	cout << "Digite mais um numero(C): "<< endl;
	cin >> c;
	cout << "A + B = " << a+b << endl;
	cout << "(A + B) * C = " << (a+b)*c << endl;
	
    return 0;
}