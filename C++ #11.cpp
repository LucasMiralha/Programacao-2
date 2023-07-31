#include <iostream>

using namespace std;

class Retangulo
{
	private:
		int es[2];
		int ei[2];
		int ds[2];
		int di[2];
		bool ret;	
		bool quad = false;
	public:
		void set()
		{
			cout << "Digite as coordenadas esquerda superior: " << endl;
			cin >> es[0] >> es [1]; 
			cout << "Digite as coordenadas esquerda inferior : " << endl;
			cin >> ei[0] >> ei [1]; 
			cout << "Digite as coordenadas direita superior: " << endl;
			cin >> ds[0] >> ds [1]; 
			cout << "Digite as coordenadas direita inferior: " << endl;
			cin >> di[0] >> di [1];
			
			if(es[0] == ei[0] && es[1] == ds[1] && ei[1] == di[1] && ds[0] == di[0])
			{
				cout << endl << "Retangulo reconhecido!" << endl;
				ret = true;
			}
			else
			{
				cout << endl << "Retangulo nao reconhecido!" << endl;
				ret = false;
			}
		}
		void quadrado()
		{
			if(ei[0] == es[0] && ei[1] == es[0] && ei[0] == di[1] && ei[1] == di[1] && ds[0] == es[1] && ds[1] == es[1] && ds[0] == di[0] && ds[1] == di[0])
			{
				cout << endl << "Quadrado reconhecido!" << endl;
				quad = true;
			}
		}
		void comprimentoLargura()
		{
			int comprimento, largura;
			
			if((di[0] - ei[0]) >= (es[1] - ei[1]))
			{
				comprimento = di[0] - ei[0];
				largura = es[1] - ei[1];
			}
			else
			{
				comprimento = es[1] - ei[1];
				largura = di[0] - ei[0];
			}
			
			cout << endl << "Comprimento: " << comprimento;
			cout << endl << "Largura: " << largura << endl;
		}
		void perimetroArea()
		{
			int perimetro, area;
			
			perimetro = (ds[0]-es[0])+(es[1]-ei[1])+(ds[1]-di[1])+(di[0]-ei[0]);
			area = (ds[0]-es[0])*(es[1]-ei[1]);
			
			cout << endl << "Perimetro: " << perimetro;
			cout << endl << "Area: " << area << endl;
		}
		char setCaracterPreenchimento()
		{
			char pree;
			
			cout << "Digite 1 caractere para ser o preenchimento do retangulo: ";
			cin >> pree;
			return pree;
		}
		char setCaracterPerimetro()
		{
			char peri;
			
			cout << endl << "O fundo da area de plotagem sera '#' entao outro caractere para conseguir visualizar o retangulo" << endl;
			
			cout << "Digite 1 caractere para ser o perimetro do retangulo: ";
			cin >> peri;
			return peri;
		}
		void desenhar(char pree, char peri)
		{
			char plot[25][25];
			int x = 25, y = 25;
			int i = 0, j = 0, a = 0, b = 0;
			int c, l;
			
			for(i = 0; i < x; i++)
			{
				for(j = 0; j < y; j++)
				{
					plot[i][j] = '#';
				}
			}
			
			c = di[0] - ei[0];
			l = es[1] - ei[1];

			i=0;
			j=0;
			
			for(i = 0; i < c; i++)
			{
				plot[j+ei[1]][i+ei[0]] = peri;
			}
			for(j = 0; j < l; j++)
			{
				plot[j+ei[1]][ei[0]] = peri;
				for(i = 0; i < c-2 && j < l-2; i++)
				{
					plot[j+ei[1]+1][i+ei[0]+1] = pree;
				}
				plot[j+ei[1]][di[0]-1] = peri;
			}
			for(i = 0; i < c; i++)
			{
				plot[j+es[0]-1][i+es[0]] = peri;
			}
			
			for(i = 0; i < x; i++)
			{
				for(j = 0; j < y; j++)
				{
					cout << plot[i][j];
				}
				cout << endl;
			}
			
		}
};

//di - ei (comprimento)
//es - ei (largura)

int main()
{
	Retangulo retangulo;
	
	retangulo.set();
	retangulo.comprimentoLargura();
	retangulo.perimetroArea();
	retangulo.quadrado();
	retangulo.desenhar(retangulo.setCaracterPreenchimento(), retangulo.setCaracterPerimetro());
	
	return 0;
}