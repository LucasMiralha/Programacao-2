#include <iostream>

using namespace std;

int main()
{
	char fase1[25][25];
	int x = 0, y = 0;
	for(x=0; x<25;x++)
	{
		fase1[x][y] = "*";
		cout << fase1[x][y];
	}
	cout << endl;
	for(y=1;y<25;y++)
	{
		cout << "*";
		for(x=1; x<25;x++)
		{
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}
	for(x=0; x<25;x++)
	{
		cout << "*";
	}
}