#include <iostream>

using namespace std;

//template <class T> void TrocarValores(T& a, T& b)

template<class T> 
void TrocarValores(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n1 = 10;
	int n2 = 25;
	
	cout << "n1: " << n1 << endl << "n2: " << n2 << endl;
	TrocarValores<int>(n1, n2);
	cout << "n1: " << n1 << endl << "n2: " << n2 << endl;
	cout << endl;
	
	float n3 = 25.69;
	float n4 = 56.78;
	
	cout << "n3: " << n3 << endl << "n4: " << n4 << endl;
	TrocarValores<float>(n3, n4);
	cout << "n3: " << n3 << endl << "n4: " << n4 << endl;
	cout << endl;
	
	char c1 = 'A';
	char c2 = 'B';
	
	cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	TrocarValores<char>(c1, c2);
	cout << "c1: " << c1 << endl << "c2: " << c2 << endl;
	cout << endl;
	
	return 0;
}