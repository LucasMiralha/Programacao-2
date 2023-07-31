#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>

using namespace std;

struct Arma
{
	int dano;
	int dado;
	string nome;
	string info;
};

struct Armadura
{
	int defesa;
	int buff;
	int debuff;
	string nome;
	string info;
};

struct Personagem
{
	int forca;
	int destreza;
	int constituicao;
	int agilidade;
	Arma arma;
	Armadura armadura;
	int hp;
	int x;
	int y;
	char aparencia;
	string nome;
};

void jogo();
void derrota();

Personagem fase1(Personagem jogador);
Personagem fase2(Personagem jogador);
Personagem fase3(Personagem jogador);
Personagem fase4(Personagem jogador);
Personagem fase5(Personagem jogador);

void bau(int fase, Personagem *jogador);

int combate(Personagem jogador, Personagem inimigo);

void criacao(Personagem *jogador);
void levelup(Personagem *jogador);

int main()
{
	int menu;
	
	cout << "Recomenda-se jogar em tela cheia" << endl;
	system("pause");
	system("cls");
	
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t########  ########     ###     ######    #######  ##    ## ####  ######     ########     ###    ##    ## ########    ####### " << endl;
	cout << "\t\t\t\t\t\t\t##     ## ##     ##   ## ##   ##    ##  ##     ## ###   ## #### ##    ##    ##     ##   ## ##   ###   ## ##               ## " << endl;
	cout << "\t\t\t\t\t\t\t##     ## ##     ##  ##   ##  ##        ##     ## ####  ##  ##  ##          ##     ##  ##   ##  ####  ## ##               ## " << endl;
	cout << "\t\t\t\t\t\t\t##     ## ########  ##     ## ##   #### ##     ## ## ## ## ##    ######     ########  ##     ## ## ## ## ######      ####### " << endl;
	cout << "\t\t\t\t\t\t\t##     ## ##   ##   ######### ##    ##  ##     ## ##  ####            ##    ##     ## ######### ##  #### ##          ##      " << endl;
	cout << "\t\t\t\t\t\t\t##     ## ##    ##  ##     ## ##    ##  ##     ## ##   ###      ##    ##    ##     ## ##     ## ##   ### ##          ##      " << endl;
	cout << "\t\t\t\t\t\t\t########  ##     ## ##     ##  ######    #######  ##    ##       ######     ########  ##     ## ##    ## ########    ####### " << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t______________________________________________________________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t1 - Jogar." << endl;
	cout << "\t\t\t\t\t\t\t\t\t2 - Tutorial e controles." << endl;
	cout << "\t\t\t\t\t\t\t\t\t3 - Sair." << endl;
	cout << "\t\t\t\t\t\t\t______________________________________________________________________________________________________________________" << endl;
	
	cin >> menu;
			
	system("cls");
			
	switch(menu)
	{
	
	    case 1:
		
			jogo();
	    	break;
	    
	    case 2:
		
			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t---------------------------------------TUTORIAL---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\tCONTROLES:                                           \tJOGABILIDADE:" << endl;
			cout << "\t\t\t\t\t\t\t\t\tW - Se movimenta para cima                           \t& - Seu personagem" << endl;
			cout << "\t\t\t\t\t\t\t\t\tA - Se movimenta para esquerda                       \t@ - Chave" << endl;
			cout << "\t\t\t\t\t\t\t\t\tS - Se movimenta para baxixo                         \tD - Porta fechada" << endl;
			cout << "\t\t\t\t\t\t\t\t\tD - Se movimenta para direita                        \t= - Porta aberta" << endl;
			cout << "\t\t\t\t\t\t\t\t\tI - Interagir com o objeto que o jogador esta em cima\t# - Espinhos" << endl;
			cout << "\t\t\t\t\t\t\t\t\t                                                     \t< - Teleportes" << endl;
			cout << "\t\t\t\t\t\t\t\t\t                                                     \tO - Botao" << endl;
			cout << "\t\t\t\t\t\t\t\t\t                                                     \t! - Inimigo" << endl;
			cout << "\t\t\t\t\t\t\t\t\t                                                     \tB - Bau" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t---------------------------------------REGRAS---------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t\t1) So existe 1 chave por fase, ela sempre ira abrir a porta final" << endl;
			cout << "\t\t\t\t\t\t\t\t\t2) Voce pode morrer ate 3 vezes por fase, apos 3 mortes, voce volta para o menu inicial" << endl;
			cout << "\t\t\t\t\t\t\t\t\t3) Um botao O faz uma acao aleatoria na fase" << endl;
			cout << "\t\t\t\t\t\t\t\t\t4) Um teleporte tem duas entradas e saidas, entrando em >, voce sai em <, e vice-versa" << endl;
			cout << "\t\t\t\t\t\t\t\t\t5) Ao esbarrar com um inimigo ! voce automaticamente entrara em combate" << endl;
			cout << "\t\t\t\t\t\t\t\t\t6) Um bau sempre tera itens melhores que os atualmente equipados" << endl;
			cout << "\t\t\t\t\t\t\t\t\t7) Get real '-'" << endl;

			cout << endl << endl;

			system("pause");
			system("cls");
			
			main();
		    break;
	
	    case 3:
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tVoce saiu do jogo!" << endl;
			exit(1);
			break;
		
		
		default:
	    	main();
	    	break;
	    
	}
	
	return 0;
}

void jogo()
{
	int sn;
	Personagem jogador;
	
	system("cls");
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "|Depois da suposta extincao dos dragoes, o mundo vivia em paz e finalmente pode prosperar...       |" << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t                                  .-.                                        " << endl;
	cout << "\t                                 /___|                                       " << endl;
	cout << "\t                                 |___|                                       " << endl;
	cout << "\t                                 |]_[|                                       " << endl;
	cout << "\t                                 / I |                                       " << endl;
	cout << "\t                              JL/  |  |JL                                    " << endl;
	cout << "\t   .-.                    i   ()   |   ()   i                    .-.         " << endl;
	cout << "\t   |_|     .^.           /_|  LJ=======LJ  /_|           .^.     |_|         " << endl;
	cout << "\t._/___|._./___|_._._._._.L_J_/.-.     .-.|_L_J._._._._._/___|._./___|._._._  " << endl;
	cout << "\t       ., |-,-| .,       L_J  |_| [I] |_|  L_J       ., |-,-| .,        .,   " << endl;
	cout << "\t       JL |-O-| JL       L_J%%%%%%%%%%%%%%%L_J       JL |-O-| JL        JL   " << endl;
	cout << "\tIIIIII_HH_'-'-'_HH_IIIIII|_|=======H=======|_|IIIIII_HH_'-'-'_HH_IIIIII_HH   " << endl;
	cout << "\t-------[]-------[]-------[_]----|.=I=./----[_]-------[]-------[]--------[]-  " << endl;
	cout << "\t _/|_  ||||_I_//||  _/|_ [_] []_/_L_J_|_[] [_] _/|_  ||||_I_//||  _/|_  |||  " << endl;
	cout << "\t |__|  ||=/_|_|=||  |__|_|_|   _L_L_J_J_   |_|_|__|  ||=/_|_|=||  |__|  ||-  " << endl;
	cout << "\t |__|  |||__|__|||  |__[___]__--__===__--__[___]__|  |||__|__|||  |__|  |||  " << endl;
	cout << "\tIIIIIII[_]IIIII[_]IIIIIL___J__II__|_|__II__L___JIIIII[_]IIIII[_]IIIIIIII[_]  " << endl;
	cout << "\t |_I_/ [_]|_I_/[_] |_I_[_]|II/[]|_|I/_/[]|II/[_]|_I_/ [_]|_I_/[_] |_I_/ [_]  " << endl;
	cout << "\t./   |.L_J/   |L_J./   L_JI  I[]/     |[]I  IL_J    |.L_J/   |L_J./   |.L_J  " << endl;
	cout << "\t|     |L_J|   |L_J|    L_J|  |[]|     |[]|  |L_J     |L_J|   |L_J|     |L_J  " << endl;
	cout << "\t|_____JL_JL___JL_JL____|-||  |[]|     |[]|  ||-|_____JL_JL___JL_JL_____JL_J  " << endl;
	cout << "\t                       '-''--'--'-----'--'--''-'                             " << endl;
	sleep(3);
	system("pause");
	system("cls");
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "|Ate que uma influencia de natureza ardilosa, surgiu...                                            |" << endl;
	cout << "|Vindo das profundezas das tumbas que um dia serviram de cemiterio para os dragoes                 |" << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t\t	             *    .            " << endl;
	cout << "\t\t        '  +   ___    @    .      " << endl;
	cout << "\t\t            .-  __ -.   +         " << endl;
	cout << "\t\t    *      |:.'`__`'.|       '    " << endl;
	cout << "\t\t        . |:: .'_ `. :|   *       " << endl;
	cout << "\t\t   @      |:: '._' : :| .         " << endl;
	cout << "\t\t      +    |:'.__.' :|       '    " << endl;
	cout << "\t\t             `-...-'   '   +      " << endl;
	cout << "\t\t   '    @   .            .    @   " << endl;
	cout << "\t\t     *             +              " << endl;
	sleep(3);
	system("pause");
	system("cls");
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "|Outra maldicao foi imposta forcadamente na realidade                                              |" << endl;
	cout << "|E o mundo foi engulfado em uma noite sem fim                                                      |" << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t	.         _  .          .          .    +     .          .          .      .  " << endl;
	cout << "\t        .(_)          .            .            .            .       :           " << endl;
	cout << "\t        .   .      .    .     .     .    .      .   .      . .  .  -+-        .  " << endl;
	cout << "\t          .           .   .        .           .          /         :  .         " << endl;
	cout << "\t    . .        .  .      /.   .      .    .     .     .  / .      . ' .          " << endl;
	cout << "\t        .  +       .    /     .          .          .   /      .                 " << endl;
	cout << "\t       .            .  /         .            .        *   .         .     .     " << endl;
	cout << "\t      .   .      .    *     .     .    .      .   .       .  .                   " << endl;
	cout << "\t          .           .           .           .           .         +  .         " << endl;
	cout << "\t  . .        .  .       .   .      .    .     .     .    .      .   .            " << endl;
	cout << "\t                                                                                 " << endl;
	cout << "\t .   +      .          ___/|_._/~~|_...__/|__.._._/~|        .         .   .     " << endl;
	cout << "\t       .          _.--'                              `--./|          .   .       " << endl;
	cout << "\t           /~~|/~|                                         `-/~|_            .   " << endl;
	cout << "\t .      .-'                                                      `-/|_           " << endl;
	cout << "\t  _/|.-'                                                          __/~|/|-.__    " << endl;
	cout << "\t.'                                                                           `.  " << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "|E agora e com voce, heroi...                                                                      |" << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	sleep(3);	
	system("pause");
	system("cls");
	
	criacao(&jogador);
	
	jogador = fase1(jogador);
	jogador = fase2(jogador);
    jogador = fase3(jogador);
	jogador = fase4(jogador);
	jogador = fase5(jogador);
	
	system("cls");
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "|Assim como Sckhar foi morto, Vosik, o sacerdote dos dragoes, caiu...                              |" << endl;
	cout << "|Pela suas maos, oh, meu destruidor de desejos...                                                  |" << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "Deseja jogar de novo?" << endl;
	cout << "1 - Sim\t2 - Nao" << endl;
	cin >> sn;
	switch(sn)
	{
		case 1:
			system("cls");
			main();
			break;
		case 2:
		default:
			exit(1);
			break;
	}
}

void derrota()
{
	int sn;
	system("cls");
	cout << "<A>         " << endl;
	cout << " 1 1,_____          " << endl;
	cout << "       ___`1             ##     ##  " << endl;
	cout << "       1('>|`-__            ##               ******         *********    *************************       *************************       *************************     " << endl;
	cout << "         ~      ~~~--__   ##           _____        _______ *** _____        _____       ________        _________      __        ***********    " << endl;
	cout << "               ______  (@1>   ********|=====|******|=======|***|=====| **** |=====| ** *|========|  *** |=========| **_|==|_ ************************         **** " << endl;
	cout << "              /######~~~~1|***********|=|   |=|****|=|  ***    |=|   =| **  |=|   =| * *|=|    |=|  ******  |=|   ***|=|  |=|***************************    ****      " << endl;
	cout << "      1       `--____*************##**|=|    |=| * |=|   ***** |=|  =| *****|=|  =| *** |=|    |=| **  *****|=|  ****|=|  |=|****************************       ****   " << endl;
	cout << "      / ~~~--_____    ~~~/ ******* ***|=|    |=|***|====|   * *|= =|   *****|=|==|***** |=|    |=|  ** ** **|=|***** |======|********************************         " << endl;
	cout << "                 `~~~~~       **#***#*|=|    |=|** |=|   **** *|=|  =|  ****|=|  =|**** |=|    |=|   ***  **|=|  ****|=|  |=|******************************          " << endl;
	cout << "                              ********|=|   |=| ** |=|****** **|=|   =|  ***|=|   =| ** |=|    |=|   *******|=|******|=|  |=|******************       ****  " << endl;
	cout << "                                ******|======| ****|=======|   |=|    =|   *|=|    =|  *|========| **** *** |=|      |=|  |=|***       ***********        ****  " << endl;
	cout << "                                    ************************** ************* **************** ******************* **********************  " << endl << endl << endl << endl;
	cout << "Deseja jogar de novo?" << endl;
	
	
	
	cout << "1 - Sim\t2 - Nao" << endl;
	cin >> sn;
	switch(sn)
	{
		case 1:
			system("cls");
			main();
			break;
		case 2:
		default:
			exit(1);
			break;
	}
}


void bau(int fase, Personagem *jogador)
{
	int randomNum;
	int sn;
	srand(time(NULL));
	randomNum = rand()%3;
	switch(fase)
	{
		case 1: 
			switch(randomNum)
			{
				case 0:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Claymore" << endl;
					cout << "2d8 + 2" << endl;
					cout << "FOR: B" << endl;
					cout << "DES: C" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Claymore");
							jogador->arma.info = ("2d8 + 2\nFOR: B\nDES: c");
							jogador->arma.dado = 5;
							jogador->arma.dano = 2+jogador->forca*+jogador->destreza*0.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 1:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Estrela da manha" << endl;
					cout << "3d6 + 0" << endl;
					cout << "FOR: A" << endl;
					cout << "DES: -" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Estrela da manha");
							jogador->arma.info = ("3d6 + 0\nFOR: A\nDES: -");
							jogador->arma.dado = 6;
							jogador->arma.dano = jogador->forca*1.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 2:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << "DEF: " << jogador->armadura.defesa << endl; 
					cout << endl << "Armadura encontrada" << endl;
					cout << "Traje belico" << endl;
					cout << "DEF: 6" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Traje belico");
							jogador->armadura.defesa = 6;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;		
			}
			break;
		case 2:
			switch(randomNum)
			{
				case 0:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Lanca vermelha" << endl;
					cout << "3d6 + 1d4 + 1" << endl;
					cout << "FOR: B" << endl;
					cout << "DES: B" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Lanca vermelha");
							jogador->arma.info = ("3d6 + 1d4 + 1\nFOR: B\nDES: B");
							jogador->arma.dado = 7;
							jogador->arma.dano = 1+jogador->forca+jogador->destreza;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 1:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Tachi" << endl;
					cout << "3d6 + 2" << endl;
					cout << "FOR: B" << endl;
					cout << "DES: A" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Tachi");
							jogador->arma.info = ("3d6 + 2\nFOR: B\nDES: A");
							jogador->arma.dado = 8;
							jogador->arma.dano = 2+jogador->forca+jogador->destreza*1.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 2:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << "DEF: " << jogador->armadura.defesa << endl; 
					cout << endl << "Armadura encontrada" << endl;
					cout << "Armadura de guarda" << endl;
					cout << "DEF: 9" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Armadura de guarda");
							jogador->armadura.defesa = 9;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;		
			}
			break;
		case 3:
			if(jogador->arma.dado == 9)
			{
				randomNum = rand()%2+1;
			}
			if(jogador->armadura.defesa == 11)
			{
				randomNum = 0;
			}
			if(jogador->armadura.defesa == 12)
			{
				randomNum = rand()%2;
			}
			switch(randomNum)
			{
				case 0:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Adaga da noite" << endl;
					cout << "6d4 + 3" << endl;
					cout << "FOR: C" << endl;
					cout << "DES: A" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Adaga da noite");
							jogador->arma.info = ("6d4 + 3\nFOR: C\nDES: A");
							jogador->arma.dado = 9;
							jogador->arma.dano = 3+jogador->forca*0.5+jogador->destreza*1.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 1:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << "DEF: " << jogador->armadura.defesa << endl; 
					cout << endl << "Armadura encontrada" << endl;
					cout << "Armadura antiga" << endl;
					cout << "DEF: 11" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Armadura antiga");
							jogador->armadura.defesa = 11;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 2:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << endl << "Armadura encontrada" << endl;
					cout << "Armadura de ossos" << endl;
					cout << "DEF: 12" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Armadura de ossos");
							jogador->armadura.defesa = 12;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;		
			}
			break;
		case 4:
			switch(randomNum)
			{
				case 0:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Foice funeraria" << endl;
					cout << "4d8 + 1" << endl;
					cout << "FOR: B" << endl;
					cout << "DES: A" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Foice funeraria");
							jogador->arma.info = ("4d8 + 1\nFOR: B\nDES: A");
							jogador->arma.dado = 10;
							jogador->arma.dano = 3+jogador->forca+jogador->destreza*1.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 1:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << "DEF: " << jogador->armadura.defesa << endl; 
					cout << endl << "Armadura encontrada" << endl;
					cout << "Armadura de prata" << endl;
					cout << "DEF: 15" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Armadura de prata");
							jogador->armadura.defesa = 15;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 2:
					cout << "Voce encontrou uma armadura" << endl;
					cout << "Sua armadura atual" << endl;
					cout << jogador->armadura.nome << endl;
					cout << "DEF: " << jogador->armadura.defesa << endl; 
					cout << endl << "Armadura encontrada" << endl;
					cout << "Armadura runica" << endl;
					cout << "DEF: 16" << endl;
					cout << endl;
					cout << "Voce quer levar a armadura encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->armadura.nome = ("Armadura runica");
							jogador->armadura.defesa = 16;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;		
			}
			break;
		case 5:
			switch(randomNum)
			{
				case 0:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Divisora de ondas" << endl;
					cout << "5d8 + 1" << endl;
					cout << "FOR: S" << endl;
					cout << "DES: B" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Divisora");
							jogador->arma.info = ("5d8 + 1\nFOR: S\nDES: B");
							jogador->arma.dado = 11;
							jogador->arma.dano = 1+jogador->forca*2+jogador->destreza;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 1:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Devora treva" << endl;
					cout << "5d8 + 2" << endl;
					cout << "FOR: B" << endl;
					cout << "DES: S" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Devora treva");
							jogador->arma.info = ("5d8 + 2\nFOR: B\nDES: S");
							jogador->arma.dado = 12;
							jogador->arma.dano = 2+jogador->forca+jogador->destreza*2;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;
				case 2:
					cout << "Voce encontrou uma arma" << endl;
					cout << "Sua arma atual" << endl;
					cout << jogador->arma.nome << endl;
					cout << jogador->arma.info << endl; 
					cout << endl << "Arma encontrada" << endl;
					cout << "Lanca do caminho real" << endl;
					cout << "4d8 + 6" << endl;
					cout << "FOR: A" << endl;
					cout << "DES: A" << endl;
					cout << endl;
					cout << "Voce quer levar a arma encontrada?" << endl;
					cout << "1) Sim\t2) Nao" << endl;
					cin >> sn;
					switch(sn)
					{
						case 1:
							jogador->arma.nome = ("Lanca do caminho real");
							jogador->arma.info = ("4d8 + 6\nFOR: A\nDES: A");
							jogador->arma.dado = 13;
							jogador->arma.dano = 6+jogador->forca*1.5+jogador->destreza*1.5;
							break;
						case 2:
						default:
							break;
					}
					system("pause");
					break;		
			}
			break;				
	}
}

Personagem fase1(Personagem jogador)
{
	
	Personagem inimigo;
	int x = 25, y = 25, i = 0, j = 0;
	int contadorMortes = 0;
	bool chave = false;
	bool inimigoMorto = false;
	bool termino = false;
	bool bauAberto = false;
	char acao;
	
	char fase1[25][25] = {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','*','*','*','*','*','*','*',' ','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','D'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};

	jogador.y = 22;
	jogador.x = 4;
	
	inimigo.y = 11;
	inimigo.x = 10;
	
	inimigo.nome = ("Guarda");
	inimigo.forca = 9;
	inimigo.armadura.defesa = 3;
	inimigo.agilidade = 5;
	inimigo.hp = 41;
	
	do
	{
		system("cls");
		
		//Evitando que o jogador suma com objetos passando por cima deles
		if(chave == false)
		{
		fase1[2][2] = '@';
		}
		fase1[13][13] = 'D';
		fase1[7][2] = '=';
		fase1[21][14] = 'B';
		fase1[13][21] = '=';
		if(inimigoMorto == false)
		{
		fase1[11][10] = '!';
		}
		if(inimigoMorto == true)
		{
			fase1[13][13] = '=';
		}
		
		fase1[jogador.y][jogador.x] = jogador.aparencia;
		
		for(i = 0; i < x; i++)
		{
			for(j = 0; j < y; j++)
			{
				cout << fase1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
			
		acao = getch();
		//cin >> acao;
		switch(acao)
		{
			case 'w':
			case 'W':
			case 72:
			{
				if(fase1[jogador.y-1][jogador.x] == '*' || fase1[jogador.y-1][jogador.x] == 'D')
				{
					fase1[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else
				{
					fase1[jogador.y][jogador.x] = ' ';
					jogador.y -= 1;
					fase1[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'a':
			case 'A':
			case 75:
			{
				if(fase1[jogador.y][jogador.x-1] == '*' || fase1[jogador.y][jogador.x-1] == 'D')
				{
					fase1[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else
				{
					fase1[jogador.y][jogador.x] = ' ';
					jogador.x -= 1;
					fase1[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 's':
			case 'S':
			case 80:
			{
				if(fase1[jogador.y+1][jogador.x] == '*' || fase1[jogador.y+1][jogador.x] == 'D')
				{
					fase1[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else
				{
					fase1[jogador.y][jogador.x] = ' ';
					jogador.y += 1;
					fase1[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'd':
			case 'D':
			case 77:
			{
				if(fase1[jogador.y][jogador.x+1] == '*' || fase1[jogador.y][jogador.x+1] == 'D')
				{
					fase1[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else
				{
					fase1[jogador.y][jogador.x] = ' ';
					jogador.x += 1;
					fase1[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'i':
			case 'I':
			{
				if(fase1[jogador.y][jogador.x] ==  fase1[2][2])
				{
					fase1[21][24] = '=';
					chave = true;	
				}
				if(fase1[jogador.y][jogador.x] == fase1[21][14] && bauAberto == false)
				{
					bau(1, &jogador);
					bauAberto = true;
				}
				else if(fase1[jogador.y][jogador.x] == fase1[21][14] && bauAberto == true)
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				break;
			}
				
			default:
				break;		
		}
		
		if(fase1[jogador.y][jogador.x] == fase1[inimigo.y][inimigo.x] && inimigoMorto == false)
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
				jogador.y = 22;
				jogador.x = 4;
				chave = false;
				inimigoMorto = false;
				termino = false;
				bauAberto = false;
			}
			else
			{
				levelup(&jogador);
				fase1[10][11] = ' ';
				inimigoMorto = true;
			}
		}
		
		if(chave == true)
		{
			if(fase1[jogador.y][jogador.x] == fase1[21][24])
			{
				termino = true;
			}
		}
		
		if(contadorMortes == 3)
		{
			derrota();
		}
		
	}while(termino == false);
	return jogador;
}

Personagem fase2(Personagem jogador)
{
	
	int x = 50, y = 50, i = 0, j = 0;
	int contadorMortes = 0;
	bool chave = false;
	bool inimigoMorto1 = false;
	bool inimigoMorto2 = false;
	bool inimigoMorto3 = false;
	bool inimigoMorto4 = false;
	bool botao1 = false;
	bool botao2 = false;
	Personagem inimigo1;
	Personagem inimigo2;
	Personagem inimigo3;
	Personagem inimigo4;
	bool bauAberto = false;
	char acao;
	bool termino = false;
	
	char fase2[50][50] = {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#','S','A','I','D','A','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','E','X','I','T','#',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ','*'},
						  {'*',' ','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','*',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ','#',' ','#',' ','#',' ','#',' ','*'},
    				      {'*',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#','*',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','*',' ','#',' ',' ','#',' ',' ','#',' ','*'},
						  {'*',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','*',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','*',' ','#',' ',' ',' ',' ',' ','#',' ','*'},
    				      {'*','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','*','*','*',' ','#',' ',' ',' ','#',' ',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ','*'},
						  {'*','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','*',' ','#',' ',' ',' ','#',' ',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','#',' ','#',' ',' ',' ',' ','*','*','*',' ','#',' ','#',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ','*',' ','*','*','*',' ','*','*','*',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*'},
						  {'*','#','#',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','!','*','*','*','*','*','*','*','#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ','*'},
    				      {'*',' ','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ','#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'}, 
						  {'*',' ',' ',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','*',' ',' ',' ','*','*','*',' ','*','*','*',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','*','#','#','#','#','*','#','#','#','#','*',' ','*',' ','#','#','#','#','#','#','*'},
    				      {'*',' ',' ',' ',' ','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ','#','#',' ',' ',' ',' ','*','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ','*','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ','#',' ',' ',' ',' ',' ','*',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','*','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ','#','#',' ',' ',' ',' ',' ','*',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ','*','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','#','#',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*','#',' ',' ',' ',' ',' ','#',' ','*',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ','#','#',' ',' ','B','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','#',' ',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ',' ','#','#',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','#',' ',' ',' ',' ','#',' ',' ','*',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*','#',' ',' ',' ',' ',' ','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ','#','#',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ','#','#',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
    				      {'*',' ',' ',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ','*'},
						  {'*',' ',' ',' ',' ','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ','*','*',' ','*','*','#','#',' ',' ','#','*','*',' ','*','*',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ','#',' ','#','*',' ',' ',' ','*',' ',' ',' ','#',' ','*',' ',' ',' ','*',' ','*'},
    				      {'=',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','*',' ',' ',' ','*','#',' ','#',' ','#','*',' ',' ',' ','*',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ',' ','*',' ',' ',' ','*',' ','#',' ','#',' ','*',' ',' ',' ','*',' ','*'},
    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};
  
	jogador.y = 46; // Jogador Posição
	jogador.x = 0;
	
	inimigo1.y = 11; //mumia posição
	inimigo1.x = 13;
	
	inimigo2.y = 23; //esqueleto posição
	inimigo2.x = 15;
	
	inimigo3.y = 47;  // mimico posição
	inimigo3.x = 35;
	
	inimigo4.y = 39; // mimico 2 posição 
	inimigo4.x = 28;
	
	inimigo1.nome = ("Mumia");
	inimigo1.forca = 10;
	inimigo1.armadura.defesa = 7;
	inimigo1.agilidade = 7;
	inimigo1.hp = 54;
	
	inimigo2.nome = ("Esqueleto");
	inimigo2.forca = 10;
	inimigo2.armadura.defesa = 9;
	inimigo2.agilidade = 6;
	inimigo2.hp = 59;
	
	inimigo3.nome = ("Mimico");
	inimigo3.forca = 11;
	inimigo3.armadura.defesa = 8;
	inimigo3.agilidade = 15;
	inimigo3.hp = 51;
	
	inimigo4.nome = ("Mimico");
	inimigo4.forca = 11;
	inimigo4.armadura.defesa = 8;
	inimigo4.agilidade = 15;
	inimigo4.hp = 51;
	
	
	fase2[jogador.y][jogador.x] = jogador.aparencia;
	
	do
	{
		system("cls");
		
		if(chave == false)
		{
		fase2[47][13] = '@'; //chave
		}
		///////////////////////////////////////////////////////////
		if(botao1 == false)
		{
		fase2[46][23] = 'O'; //botão 1
		fase2[28][40] = 'D'; //Porta 1
		}
		if(botao1 == true)
		{
		fase2[46][23] = 'O'; //botão 1
		fase2[28][40] = '='; //Porta 1
		}
		///////////////////////////////////////////////////////////
		if(botao2 == false)
		{
		fase2[3][3] = 'O';   //botão 2
		fase2[35][40] = 'D'; // Porta 2
		}
		if(botao2 == true)
		{
		fase2[3][3] = 'O';   //botão 2
		fase2[35][40] = '='; // Porta 2
		}
		///////////////////////////////////////////////////////////
		if(chave == false)
		{
		fase2[0][38] = 'D'; // Porta saida
		}
		if(chave == true)
		{
		fase2[0][38] = '='; // Porta saida
		}
		if(inimigoMorto1 == false) //inimigo 1
		{
		fase2[11][13] = '!';
		}
		if(inimigoMorto1 == true)
		{
		fase2[11][13] = '=';
		}
		if(inimigoMorto2 == false) //inimigo 2
		{
		fase2[23][15] = '!';
		}
		if(inimigoMorto2 == true)
		{
		fase2[23][15] = '=';
		}
		if(inimigoMorto3 == false) // Mimic
		{
		fase2[47][35] = 'B';
		}		
		if(inimigoMorto3 == true)
		{
		fase2[47][35] = ' ';
		}
		if(inimigoMorto4 == false) // Mimic 2
		{
		fase2[39][28] = 'B';
		}		
		if(inimigoMorto4 == true)
		{
		fase2[39][28] = ' ';
		}
		if(bauAberto == false)
		{
		fase2[47][45] = 'B';
		}
		if(bauAberto == true)
		{
		fase2[47][45] = 'B';
		}

		
		fase2[jogador.y][jogador.x] = jogador.aparencia; 
		for(i = 0; i < x; i++)
		{
			for(j = 0; j < y; j++)
			{
				cout << fase2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
		
		acao = getch();
		//cin >> acao;
		switch(acao)
		{
			case 'w':
			case 'W':
			case 72:
			{
				if(fase2[jogador.y-1][jogador.x] == '*' || fase2[jogador.y-1][jogador.x] == 'D')
				{
					fase2[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase2[jogador.y-1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase2[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 46;
					jogador.x = 0;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase2[jogador.y][jogador.x] = ' ';
					jogador.y -= 1;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'a':
			case 'A':
			case 75:
			{
				if(fase2[jogador.y][jogador.x-1] == '*' || fase2[jogador.y][jogador.x-1] == 'D')
				{
					fase2[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase2[jogador.y][jogador.x-1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase2[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 46;
					jogador.x = 0;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase2[jogador.y][jogador.x] = ' ';
					jogador.x -= 1;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 's':
			case 'S':
			case 80:
			{
				if(fase2[jogador.y+1][jogador.x] == '*' || fase2[jogador.y+1][jogador.x] == 'D')
				{
					fase2[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase2[jogador.y+1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase2[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 46;
					jogador.x = 0;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase2[jogador.y][jogador.x] = ' ';
					jogador.y += 1;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'd':
			case 'D':
			case 77:
			{
				if(fase2[jogador.y][jogador.x+1] == '*' || fase2[jogador.y][jogador.x+1] == 'D')
				{
					fase2[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase2[jogador.y][jogador.x+1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase2[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 46;
					jogador.x = 0;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase2[jogador.y][jogador.x] = ' ';
					jogador.x += 1;
					fase2[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
			case 'i':      // Botão Interação ///////////////////
			case 'I': 
			{
				if(fase2[jogador.y][jogador.x] ==  fase2[47][13]) // Abrir Porta Final ///////////////////
				{
					fase2[0][38] = '=';
					chave = true;	
				}
				if(fase2[jogador.y][jogador.x] == fase2[46][23]) // Abrir Porta 1 ///////////////////////
				{
					fase2[28][40] = '=';
					botao1 = true;
				}
				if(fase2[jogador.y][jogador.x] == fase2[3][3]) //Abrir Porta 2 ////////////////////////
				{
					fase2[35][40] = '=';
					botao2 = true;
				}
				if(fase2[jogador.y][jogador.x] == fase2[inimigo3.y][inimigo3.x] && inimigoMorto3== false)  // Combate do mimic      ///////////////////////////////////
				{
					cout << "Nao era um BAU, era um MIMICO!!" << endl;
					if(combate(jogador, inimigo3) == 1)
					{
						contadorMortes++;
						if(contadorMortes != 3)
						{
							cout << endl << "Voce morreu!" << endl;
							cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
							sleep(1);
							cout << "Retornando em 3..." << endl;
							sleep(1);
							cout << "2..." << endl;
							sleep(1);
							cout << "1..." << endl;
							sleep(1);
						}
							jogador.y = 46;
							jogador.x = 0;
							chave = false;
							inimigoMorto3= false;
							termino = false;
							if(bauAberto == false)
							{
							bauAberto = false;
							}
					}
					else
					{
						levelup(&jogador);
						fase2[41][45] = ' ';
						inimigoMorto3 = true;
						fase2[inimigo3.y][inimigo3.x] = ' ';
					}		
				}
				
				if(fase2[jogador.y][jogador.x] == fase2[inimigo4.y][inimigo4.x] && inimigoMorto4== false)  // Combate do mimic  2222222222    ///////////////////////////////////
				{
					cout << "Nao era um BAU, era um MIMICO!!" << endl;
					if(combate(jogador, inimigo4) == 1)
					{
						contadorMortes++;
						if(contadorMortes != 3)
						{
							cout << endl << "Voce morreu!" << endl;
							cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
							sleep(1);
							cout << "Retornando em 3..." << endl;
							sleep(1);
							cout << "2..." << endl;
							sleep(1);
							cout << "1..." << endl;
							sleep(1);
						}
							jogador.y = 46;
							jogador.x = 0;
							chave = false;
							inimigoMorto4= false;
							termino = false;
							if(bauAberto == false)
							{
							bauAberto = false;
							}
					}
					else
					{
						levelup(&jogador);
						fase2[41][45] = ' ';
						inimigoMorto4 = true;
						fase2[inimigo4.y][inimigo4.x] = ' ';
					}		
				}
				if(fase2[jogador.y][jogador.x] == fase2[47][45] && bauAberto == false)
				{
					bau(2, &jogador);
					bauAberto = true;
				}
				else if(fase2[jogador.y][jogador.x] == fase2[47][45] && bauAberto == true)
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				break;
			}
			default:
				break;		
		}
		
		if(fase2[jogador.y][jogador.x] == fase2[inimigo1.y][inimigo1.x] && inimigoMorto1 == false)  // Combate do inimigo 1 ///////////////////////////////////
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo1) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
				jogador.y = 46;
				jogador.x = 0;
				chave = false;
				inimigoMorto1 = false;
				termino = false;
				if(bauAberto == false)
					{
					bauAberto = false;
					}
			}
			else
			{
				levelup(&jogador);
				fase2[11][13] = ' ';
				inimigoMorto1 = true;
			}
		}
		
		if(fase2[jogador.y][jogador.x] == fase2[inimigo2.y][inimigo2.x] && inimigoMorto2 == false)  // Combate do inimigo 2 ///////////////////////////////////
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo2) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
				jogador.y = 46;
				jogador.x = 0;
				chave = false;
				inimigoMorto2 = false;
				termino = false;
				if(bauAberto == false)
					{
					bauAberto = false;
					}
			}
			else
			{
				levelup(&jogador);
				fase2[23][15] = ' ';
				inimigoMorto2 = true;
			}
		}
		
		if(chave == true)
		{
			if(fase2[jogador.y][jogador.x] == fase2[0][38])
			{
				termino = true;
			}
		}
		
		if(contadorMortes == 3)
		{
			derrota();
		}
		
	}while(termino == false);
	return jogador;
}

Personagem fase3(Personagem jogador)
{
	int x = 75, y = 75, i = 0, j = 0;
	int contadorMortes = 0;
	bool chave = false;
	bool inimigoMorto1 = false;
	bool inimigoMorto2 = false;
	bool inimigoMorto3 = false;
	bool inimigoMorto4 = false;
	bool botao1 = false;
	bool botao2 = false;
	bool botao3 = false;
	bool tp1 = false;
	Personagem inimigo1;
	Personagem inimigo2;
	Personagem inimigo3;
	Personagem inimigo4;
	bool bauAberto1 = false;
	bool bauAberto2 = false;
	bool termino = false;
	char acao;
	
	char fase3[75][75] = {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ','.',' ',' ',' ','(',' ',')',' ',' ',' ','.',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ',' ',' ',' ',' ',' ',' ',' ','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*',' ',' ',' ','.',' ',' ',' ','(',' ',')',' ',' ',' ','.',' ',' ','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','A',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*',' ','*','*','*','*','*','*','*','*',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ','(',' ',')',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ','*','*','*','*','*','*','*',' ','*','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','1','*','*',' ',' ',' ',' ',' ',' ','*','*','1',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','1','Q','1','*',' ',' ',' ',' ','*','1','Q','1',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*'},
						  {'*',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#','#','#','*',' ',' ',' ',' ','*',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ','*',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ','*'},
						  {'*','#',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ','#','#','*',' ',' ',' ','*',' ',' ',' ','.',' ',' ',' ',' ','.',' ',' ',' ','*',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ','#','*'},
						  {'*',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ',' ','*',' ',' ','#','#','*',' ',' ',' ','*',' ',' ','.','.',' ',' ','.','.',' ',' ','*',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*'},
						  {'*',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','#','*',' ','#','#','*',' ',' ','#','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','*'},
						  {'*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ','#','*',' ','#',' ','*',' ','#','#','*',' ',' ','*',' ',' ',' ','.',' ',' ','.',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','#','#','*',' ','#','#','*',' ','#',' ',' ','*','*',' ','.',' ','.',' ',' ','.',' ','.',' ','*','*',' ',' ','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','#','*',' ',' ','#',' ',' ','#','#',' ','*','*',' ','.',' ',' ','.','.',' ',' ','.',' ','*','*',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ','#','*',' ',' ','#','*',' ','#',' ','*','*',' ',' ','.',' ',' ',' ',' ','.',' ',' ','*','*',' ','#','V',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ','*','*',' ',' ','*',' ','#','#','*',' ','#','*',' ','V',' ','*','#','*',' ',' ','.',' ',' ','.',' ',' ','*','#','*',' ','V',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ','*','*',' ',' ','*',' ',' ','#','*',' ',' ','#','*',' ',' ','*','<','*',' ',' ',' ',' ',' ',' ',' ',' ','*','>','*',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','*','*',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*','*',' ',' ',' ','*',' ','#',' ','*',' ','V','*',' ',' ','*','#','<','*',' ','O',' ',' ','O',' ','*','>','#','*',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','*','*',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ','*','*',' ',' ',' ',' ','*','#','#','*',' ',' ','*',' ',' ','*',' ','#','*',' ',' ',' ',' ',' ',' ','*','#',' ','*',' ',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','*',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ','*','*',' ',' ',' ',' ','*',' ','#',' ','*','*','*',' ',' ',' ','*',' ','#','*',' ',' ',' ',' ','*','#',' ','*',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','*','*',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*','*',' ',' ',' ',' ',' ','*','#','#','*',' ',' ',' ',' ',' ','*','^','#',' ','*',' ','*','*',' ','#','^','*',' ',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*','*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*',' ',' ',' ',' ',' ','*','V','#',' ','*',' ',' ',' ',' ','*','^',' ','#','#','#','#','#','#',' ','^','*',' ',' ','V','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','*','*',' ',' ',' ',' ',' ','*',' ','V',' ','*',' ',' ',' ',' ','*','*',' ',' ','#','#','#','#',' ',' ','*','*',' ',' ',' ','V',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*','*','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','^',' ','#',' ',' ','#',' ','^','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','^',' ',' ',' ',' ',' ',' ','^','*',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','#',' ',' ','V',' ',' ',' ','#',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','*','*','^',' ',' ',' ',' ','^','*',' ','*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*'},
						  {'*',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','*','*','#','^',' ',' ','^','#','*',' ','*',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ','*'},
						  {'*',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#','*',' ','*','*',' ',' ','*','*',' ',' ','*',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ','*'},
						  {'*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#',' ',' ','#',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*'},
						  {'*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*'},
						  {'*','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','*'},
						  {'*',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#','#','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ','#',' ',' ','#',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*'},
						  {'*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*'},
						  {'*','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#','*'},
						  {'*',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','#',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ','*'},
						  {'*',' ',' ','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','.',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','.','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','D','R','A','G','O','N','S',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','D','R','A','G','O','N','S',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','B','A','N','E',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*',' ','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ','B','A','N','E',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ','*','*','*','*','*','*','*',' ','*','*','*','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};
		
		
		
	jogador.y = 70; //posicao jogador inicial
	jogador.x = 3;
	
	inimigo1.y = 9; //posicao inimigo 1
	inimigo1.x = 62;
	
	inimigo2.y = 65; //posicao inimigo 2
	inimigo2.x = 62;
	
	inimigo3.y = 40; //posicao inimigo 3 mimic
	inimigo3.x = 12;
	
	inimigo4.y = 9; //posicao inimigo 4
	inimigo4.x = 12;
	
	
	inimigo1.nome = ("draconato"); /////////// STATUS DE INIMIGOS 
	inimigo1.forca = 11;
	inimigo1.armadura.defesa = 10;
	inimigo1.agilidade = 5;
	inimigo1.hp = 69;
	
	inimigo2.nome = ("Golem runico");
	inimigo2.forca = 11;
	inimigo2.armadura.defesa = 10;
	inimigo2.agilidade = 5;
	inimigo2.hp = 69;
	
	inimigo3.nome = ("Mimic drag");
	inimigo3.forca = 11;
	inimigo3.armadura.defesa = 10;
	inimigo3.agilidade = 5;
	inimigo3.hp = 69;
	
	inimigo4.nome = ("Sacerdote");
	inimigo4.forca = 11;
	inimigo4.armadura.defesa = 10;
	inimigo4.agilidade = 5;
	inimigo4.hp = 69;
	do 
	{
		system("cls");
		
		//Evitando que o jogador suma com objetos passando por cima deles
		
		fase3[65][4] = '=';
		fase3[18][2] = 'B';   // Bau 1
		fase3[18][72] = 'B';  // Bau 2
		if(chave == false)
		{
			fase3[63][13] = '@'; // Chave ///////////////////////////
			fase3[47][37] = 'D'; // Porta saida
		}
		if(chave == true)
		{
			fase3[47][37] = '=';
		}
		if(inimigoMorto1 == false) ///////// inimigo  1
		{
			fase3[9][62] = '!';
		}
		if(inimigoMorto1 == true)
		{
			fase3[9][62] = '=';
		}
		if(inimigoMorto2 == false) ///////// inimigo  2
		{
			fase3[65][62] = '!';
		}
		if(inimigoMorto2 == true)
		{
			fase3[65][62] = '=';
		}
		if(inimigoMorto4 == false) ///////// inimigo  4
		{
			fase3[9][12] = '!';
		}
		if(inimigoMorto4 == true)
		{
			fase3[9][12] = '=';
		}
		if(inimigoMorto3 == false) ///////// mimic
		{
			fase3[40][12] = 'B';
		}
		if(inimigoMorto3 == true)
		{
			fase3[40][12] = ' ';
		}		
		if(botao1 == false) /////////////// botao 1 porta superior esquerda 
		{
			fase3[3][12] = 'O';
			fase3[9][3] = 'D';
		}
		if(botao1 == true)
		{
			fase3[3][12] = 'O';
			fase3[9][3] = '=';	
		}
		if(botao2 == false)   //////////// botao 2 porta superior direita 
		{
			fase3[3][62] = 'O';
			fase3[9][70] = 'D';
		}
		if(botao2 == true)
		{
			fase3[3][62] = 'O';
			fase3[9][70] = '=';	
		}
		if(botao3 == false)   //////////// botao 3 porta inferior direita 
		{
			fase3[35][71] = 'O';
			fase3[65][70] = 'D';
		}
		if(botao3 == true)
		{
			fase3[35][71] = 'O';
			fase3[65][70] = '=';	
		}
		if(tp1 == true)
		{
			fase3[72][12] = '>'; //////////// TP SECRETO
			fase3[47][34] = '<';
		}


		fase3[59][5] = '<'; //////////// tp 1
		fase3[14][11] = '>';
		
		fase3[3][72] = '>'; //////////// tp2
		fase3[13][5] = '<';

		fase3[13][61] = '<'; //////////// tp3
		fase3[70][37] = '>';
		
		fase3[70][62] = '>'; //////////// tp4
		fase3[54][12] = '<';
		
		fase3[20][12] = '>'; //////////// tp5
		fase3[33][71] = '<';	
		
		fase3[60][13] = '>'; //////////// tp6
		fase3[61][71] = '<';
		
		fase3[13][71] = '>'; //////////// tp7
		fase3[71][71] = '<';
		
		fase3[61][62] = '>'; //////////// tp8
		fase3[22][63] = '<';
		
		fase3[53][63] = '>'; //////////// tp9
		fase3[63][10] = '<';	
		
		fase3[jogador.y][jogador.x] = jogador.aparencia;
		
		for(i = 0; i < x; i++)
		{
			for(j = 0; j < y; j++)
			{
				cout << fase3[i][j] << " ";
			}
			cout << endl;	
		}
		cout << endl;
			
		acao = getch();
		//cin >> acao;
		switch(acao)
		{
			case 'w':
			case 'W':
			case 72:
			{
				if(fase3[jogador.y-1][jogador.x] == '*' || fase3[jogador.y-1][jogador.x] == 'D')
				{
					fase3[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase3[jogador.y-1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase3[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase3[jogador.y][jogador.x] = ' ';
					jogador.y -= 1;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'a':
			case 'A':
			case 75:
			{
				if(fase3[jogador.y][jogador.x-1] == '*' || fase3[jogador.y][jogador.x-1] == 'D')
				{
					fase3[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase3[jogador.y][jogador.x-1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase3[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase3[jogador.y][jogador.x] = ' ';
					jogador.x -= 1;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 's':
			case 'S':
			case 80:
			{
				if(fase3[jogador.y+1][jogador.x] == '*' || fase3[jogador.y+1][jogador.x] == 'D')
				{
					fase3[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase3[jogador.y+1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase3[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase3[jogador.y][jogador.x] = ' ';
					jogador.y += 1;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'd':
			case 'D':
			case 77:
			{
				if(fase3[jogador.y][jogador.x+1] == '*' || fase3[jogador.y][jogador.x+1] == 'D')
				{
					fase3[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase3[jogador.y][jogador.x+1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase3[jogador.y][jogador.x] = ' ';
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase3[jogador.y][jogador.x] = ' ';
					jogador.x += 1;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'i':
			case 'I':
			{
				if(fase3[jogador.y][jogador.x] ==  fase3[63][13])
				{
					chave = true;	
				}
				if(fase3[jogador.y][jogador.x] == fase3[18][2] && bauAberto1 == false) ///////////      PRIMEIRO BAU
				{
					bau(3, &jogador);
					bauAberto1 = true;
				}
				else if(fase3[jogador.y][jogador.x] == fase3[18][2] && bauAberto1 == true)////////////////////////////////////////////////
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				if(fase3[jogador.y][jogador.x] == fase3[18][72] && bauAberto2 == false)  /////////////      SEGUNDO BAU
				{
					bau(3, &jogador);
					bauAberto2 = true;
				}
				else if(fase3[jogador.y][jogador.x] == fase3[18][72] && bauAberto2 == true) ///////////////////////////////////////////
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				if(fase3[jogador.y][jogador.x] == fase3[3][12])  ////////////////// Porta superior direito
				{
					botao1 = true;
					fase3[9][3] = '=';
				}
				if(fase3[jogador.y][jogador.x] == fase3[3][62])  ////////////////// Porta superior  esquerda
				{
					botao2 = true;
					fase3[9][70] = '=';
				}
				if(fase3[jogador.y][jogador.x] == fase3[35][71])  ////////////////// Porta inferior direita
				{
					botao3 = true;
					fase3[65][70] = '=';
				}			
				if(fase3[jogador.y][jogador.x] == fase3[59][5]) /////////////////////////////////////// tp
				{
					jogador.y = 14;
					jogador.x = 12;
				}
				if(fase3[jogador.y][jogador.x] == fase3[14][11]) /////////////////////////////////////// tp
				{
					jogador.y = 59;
					jogador.x = 6;
				}
				if(fase3[jogador.y][jogador.x] == fase3[3][72]) /////////////////////// tp 2
				{
					jogador.y = 13;
					jogador.x = 6;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[13][5]) /////////////////////////// tp 2
				{
					jogador.y = 3;
					jogador.x = 73;
				}
				if(fase3[jogador.y][jogador.x] == fase3[13][61]) /////////////////////// tp 3
				{					
					jogador.y = 70;
					jogador.x = 38;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[70][37]) /////////////////////////// tp 3
				{					
					jogador.y = 13;
					jogador.x = 62;
				}
				if(fase3[jogador.y][jogador.x] == fase3[70][62]) /////////////////////// tp 4
				{					
					jogador.y = 54;
					jogador.x = 13;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[54][12]) /////////////////////////// tp 4
				{					
					jogador.y = 70;
					jogador.x = 63;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[20][12]) /////////////////////// tp 5
				{					
					jogador.y = 33;
					jogador.x = 72;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[33][71]) /////////////////////////// tp 5
				{					
					jogador.y = 20;
					jogador.x = 13;
				}		
				if(fase3[jogador.y][jogador.x] == fase3[60][13]) /////////////////////// tp 6
				{					
					jogador.y = 61;
					jogador.x = 72;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[61][71]) /////////////////////////// tp 6
				{					
					jogador.y = 60;
					jogador.x = 14;
				}
				if(fase3[jogador.y][jogador.x] == fase3[13][71]) /////////////////////// tp 7
				{					
					jogador.y = 71;
					jogador.x = 72;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[71][71]) /////////////////////////// tp 7
				{					
					jogador.y = 13;
					jogador.x = 72;
				}
				if(fase3[jogador.y][jogador.x] == fase3[61][62]) /////////////////////// tp 8
				{					
					jogador.y = 22;
					jogador.x = 64;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[22][63]) /////////////////////////// tp 8
				{					
					jogador.y = 61;
					jogador.x = 63;
				}
				if(fase3[jogador.y][jogador.x] == fase3[53][63]) /////////////////////// tp 9
				{					
					jogador.y = 63;
					jogador.x = 11;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[63][10]) /////////////////////////// tp 9
				{					
					jogador.y = 53;
					jogador.x = 64;
				}
				if(fase3[jogador.y][jogador.x] == fase3[inimigo3.y][inimigo3.x] && inimigoMorto3== false)  // Combate do mimic      ///////////////////////////////////
				{
					cout << "Nao era um BAU, era um MIMICO!!" << endl;
					if(combate(jogador, inimigo3) == 1)
					{
						contadorMortes++;
						if(contadorMortes != 3)
						{
							cout << endl << "Voce morreu!" << endl;
							cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
							sleep(1);
							cout << "Retornando em 3..." << endl;
							sleep(1);
							cout << "2..." << endl;
							sleep(1);
							cout << "1..." << endl;
							sleep(1);
						}
						chave = false;
						inimigoMorto1 = false;
						inimigoMorto2 = false;
						inimigoMorto3 = false;
						inimigoMorto4 = false;
						botao1 = false;
						botao2 = false;
						botao3 = false;
						tp1 = false;
						bauAberto1 = false;
						bauAberto2 = false;
						termino = false;
						if(bauAberto1 == false)
						{
						bauAberto1 = false;
						}
						if(bauAberto2 == false)
						{
						bauAberto2 = false;
						}
						jogador.y = 72;
						jogador.x = 3;
						fase3[jogador.y][jogador.x] = jogador.aparencia;
					}
					else
					{
						levelup(&jogador);
						fase3[40][12] = ' ';
						inimigoMorto3 = true;
						fase3[inimigo3.y][inimigo3.x] = ' ';
					}		
				}
				break;
			}
			case 'k':
			{
				tp1 = true;
				if(fase3[jogador.y][jogador.x] == fase3[72][12]) /////////////////////// TP SECRETO
				{					
					jogador.y = 47;
					jogador.x = 35;
				}				
				if(fase3[jogador.y][jogador.x] == fase3[47][34]) /////////////////////////// TP SECRETO
				{					
					jogador.y = 72;
					jogador.x = 13;
				}
				chave = true;
				break;
			}
			default:
				break;		
		}
				
		if(fase3[jogador.y][jogador.x] == fase3[inimigo1.y][inimigo1.x] && inimigoMorto1 == false)
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo1) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
			}
			else
			{
				levelup(&jogador);
				fase3[9][62] = ' ';
				inimigoMorto1 = true;
				fase3[inimigo1.y][inimigo1.x] = '=';
			}
		}
		if(fase3[jogador.y][jogador.x] == fase3[inimigo2.y][inimigo2.x] && inimigoMorto2 == false)
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo2) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
			}
			else
			{
				levelup(&jogador);
				fase3[65][62] = ' ';
				inimigoMorto2 = true;
				fase3[inimigo2.y][inimigo2.x] = '=';
			}
		}
		
		if(fase3[jogador.y][jogador.x] == fase3[inimigo4.y][inimigo4.x] && inimigoMorto4 == false)
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo4) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
					chave = false;
					inimigoMorto1 = false;
					inimigoMorto2 = false;
					inimigoMorto3 = false;
					inimigoMorto4 = false;
					botao1 = false;
					botao2 = false;
					botao3 = false;
					tp1 = false;
					bauAberto1 = false;
					bauAberto2 = false;
					termino = false;
					if(bauAberto1 == false)
					{
					bauAberto1 = false;
					}
					if(bauAberto2 == false)
					{
					bauAberto2 = false;
					}
					jogador.y = 72;
					jogador.x = 3;
					fase3[jogador.y][jogador.x] = jogador.aparencia;
			}
			else
			{
				levelup(&jogador);
				fase3[65][62] = ' ';
				inimigoMorto4 = true;
				fase3[inimigo4.y][inimigo4.x] = '=';
			}
		}
		
		if(chave == true)
		{
			if(fase3[jogador.y][jogador.x] == fase3[47][37])
			{
				termino = true;
			}
		}
		
		if(contadorMortes == 3)
		{
			derrota();
		}
		
	}while(termino == false);
	return jogador;
}

Personagem fase4(Personagem jogador)
{
	int x = 25, y = 100, i = 0, j = 0;
	int contadorMortes = 0;
	bool chave = false;
	bool inimigoMorto = false;
	Personagem inimigo;
	bool bauAberto = false;
	char acao;
	bool termino = false;
	                        
						                                                                                                                                                                                        
	char fase4[25][100] = {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	                      {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
						  {'*',' ',' ',' ',' ','=',' ','=',' ','=','=','=',' ','=','=','=',' ','=','=','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','=',' ','=',' ','=',' ',' ',' ','=',' ','=',' ','=',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','=','=','=',' ','=','=','=',' ','=','=',' ',' ','=',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','=',' ','=',' ','=',' ',' ',' ','=',' ','=',' ','=',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ','=',' ','=',' ','=','=','=',' ','=',' ','=',' ','=','=','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*','*','*','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','B','*','*','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*','*',' ','*','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ','*',' ','*',' ','*',' ','*','*','*','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ','*','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','!',' ',' ','*','*',' ',' ',' ',' ',' ','*','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ','*',' ','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ','#',' ',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','*',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ','#','*','*','*',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
						  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};
	jogador.y = 19;
	jogador.x = 55;
	
	inimigo.nome = ("Esqueleto");
	inimigo.forca = 12;
	inimigo.armadura.defesa = 10;
	inimigo.agilidade = 8;
	inimigo.hp = 71;
	inimigo.y = 20;
	inimigo.x = 25;
	
	do
	{
		system("cls");
		
		//Evitando que o jogador suma com objetos passando por cima deles
		if(chave == false)
		{
		fase4[12][88] = '@';
		fase4[23][7] = 'D';
		}
	    if(chave == true) 
	    {
		fase4[23][7] = '=';
        }
        if(inimigoMorto == false)
        {
		fase4[20][25] = '!';
		}
		if(inimigoMorto == true)
        {
		fase4[20][25] = ' ';
		}
		fase4[14][24] = 'B';
		
		fase4[jogador.y][jogador.x] = jogador.aparencia;
		
		for(i = 0; i < x; i++)
		{
			for(j = 0; j < y; j++)
			{
				cout << fase4[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
			
		acao = getch();
		//cin >> acao;
		switch(acao)
		{
			case 'w':
			case 'W':
			case 72:
			{
				if(fase4[jogador.y-1][jogador.x] == '*' || fase4[jogador.y-1][jogador.x] == 'D')
				{
					fase4[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase4[jogador.y-1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase4[jogador.y][jogador.x] = ' ';
					chave = false;
					termino = false;
					inimigoMorto = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 19;
					jogador.x = 55;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase4[jogador.y][jogador.x] = ' ';
					jogador.y -= 1;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'a':
			case 'A':
			case 75:
			{
				if(fase4[jogador.y][jogador.x-1] == '*' || fase4[jogador.y][jogador.x-1] == 'D')
				{
					fase4[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase4[jogador.y][jogador.x-1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase4[jogador.y][jogador.x] = ' ';
					chave = false;
					termino = false;
					inimigoMorto = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 19;
					jogador.x = 55;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase4[jogador.y][jogador.x] = ' ';
					jogador.x -= 1;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 's':
			case 'S':
			case 80:
			{
				if(fase4[jogador.y+1][jogador.x] == '*' || fase4[jogador.y+1][jogador.x] == 'D')
				{
					fase4[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase4[jogador.y+1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase4[jogador.y][jogador.x] = ' ';
					chave = false;
					termino = false;
					inimigoMorto = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 19;
					jogador.x = 55;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase4[jogador.y][jogador.x] = ' ';
					jogador.y += 1;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'd':
			case 'D':
			case 77:
			{
				if(fase4[jogador.y][jogador.x+1] == '*' || fase4[jogador.y][jogador.x+1] == 'D')
				{
					fase4[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase4[jogador.y][jogador.x+1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase4[jogador.y][jogador.x] = ' ';
					chave = false;
					termino = false;
					inimigoMorto = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 19;
					jogador.x = 55;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase4[jogador.y][jogador.x] = ' ';
					jogador.x += 1;
					fase4[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
		    case 'i':
			case 'I':
			{
				if(fase4[jogador.y][jogador.x] ==  fase4[12][88])
				{
					fase4[23][7] = '=';
					chave = true;	
				}
				if(fase4[jogador.y][jogador.x] == fase4[14][24] && bauAberto == false)
				{
					bau(4, &jogador);
					bauAberto = true;
				}
				else if(fase4[jogador.y][jogador.x] == fase4[14][24] && bauAberto == true)
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				break;
			}
				
			default:
				break;		
		}
		
	
		if(fase4[jogador.y][jogador.x] == fase4[inimigo.y][inimigo.x] && inimigoMorto == false)  //Combate
		{
			cout << "Voce esbarrou em um inimigo!" << endl;
			if(combate(jogador, inimigo) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
				fase4[jogador.y][jogador.x] = ' ';
				chave = false;
				termino = false;
				inimigoMorto = false;
				if(bauAberto == false)
				{
				bauAberto = false;
				}
				jogador.y = 19;
				jogador.x = 55;
				fase4[jogador.y][jogador.x] = jogador.aparencia;
			}
			else
			{
				levelup(&jogador);
				inimigoMorto = true;
			}
		}
		
		if(chave == true)
		{
			if(fase4[jogador.y][jogador.x] == fase4[23][7])
			{
				termino = true;
			}
		}
		
		if(contadorMortes == 3)
		{
			derrota();
		}
		
	}while(termino == false);
	return jogador;
}

Personagem fase5(Personagem jogador)
{
	
	int x = 100, y = 100, i = 0, j = 0;
	int contadorMortes = 0;
	bool bossMorto = false;
	bool botao1 = false;
	bool botao2 = false;
	bool pbotao1 = false;
	bool pbotao2 = false;
	bool pbotao3 = false;
	bool pbotao4 = false;
	bool pbotao5 = false;
	bool bauAberto = false;
	char acao;
	
	Personagem boss;
	
	boss.hp = 612;
	boss.forca = 19;
	boss.armadura.defesa = 13;
	boss.agilidade = 18;
	boss.nome = ("Vosik, o imortal");
	
	char fase5[100][100] =   {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*',' ',' ','^','^','^','^','^',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*','*','*','*','*','*','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','#','#','#','#','#','#','#','#','#','#','#','*',' ',' ','#',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ','O',' ',' ',' ',' ','*',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*','^','*',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ','#',' ',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','^','*',' ',' ','#',' ','#',' ','#',' ','#',' ',' ','*','#',' ',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ','O',' ',' ',' ','*','^','*',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ','*','^','*',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','^','*',' ',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ','#','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','#','#','#','#','#','#','#','#','#','#','#','*',' ','#',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*','*','*','*','*','=','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','*','=','*','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
							  {'*','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*','#',' ','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
	    				      {'*','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',}, 
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','#',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ','#',' ',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ','#',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','*',' ',' ',' ','#','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','*',' ',' ','#',' ','*',},
	    				      {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#',' ',' ','#','#','*',' ','#',' ',' ','*',},
							  {'*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ',' ','#','#','*','#',' ',' ',' ','*',},
							  {'*','#','#',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','*',' ','#',' ',' ','*',},
	    				      {'*','*','*','*',' ',' ','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','*',' ',' ','#',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#','*',' ',' ','^','^','^','^','^',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','*',' ',' ',' ','#','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*','*','*','*','*','*','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*',' ',' ','#',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*',' ','#',' ',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ','O',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*','#',' ',' ',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D','D','D','D','D',' ',' ','!','!','*',},
							  {'*','B',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D','D','D','D','D',' ',' ','!','!','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*','#',' ',' ',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*',' ','#',' ',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','*',' ',' ','#',' ','*',},
 	    				      {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','*',' ',' ',' ','#','*',},
							  {'*','*','*','*',' ',' ','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','=','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#','#','#','*',' ',' ','#',' ','*',},
	    				      {'*','#','#',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','*',' ','#',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ',' ','#','#','*','#',' ',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#',' ',' ','#','#','*',' ','#',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','*',' ',' ',' ','#','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ','#',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','#',' ',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','=','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ','#',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','^','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','^','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',' ','O',' ','*','^','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','^','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','^','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ','*',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','*','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',}, 
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*','*','*','*',' ','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*',' ',' ','*','D','*',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','*','=','*','*','*','*','*','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#','#',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
							  {'*','*','*','*',' ','*','*','*','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ','O',' ',' ',' ','O',' ','*','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ','*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','*',' ',' ',' ',' ','O',' ',' ',' ',' ','=',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ','*','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#',' ',' ',' ',' ','*','#',' ',' ',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ','*','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','*',' ','#',' ',' ','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','*',' ',' ','#',' ','*',},
							  {'*',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*','*','*','*','*','*','*','*','*','*','*','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#','*',},
	    				      {'*',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','*',' ',' ','^','^','^','^','^',' ',' ','*','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#',' ','*',},
							  {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',}};

	jogador.y = 99;
	jogador.x = 4;
	
	do
	{
		system("cls");
		
		fase5[50][1] = 'B';//Bau
		fase5[91][2] = 'O';//botao1
		fase5[91][6] = 'O';//botao2		
		
		if(botao1 == false && botao2 == false)
		{
			fase5[88][4] = 'D';//porta1
			fase5[88][2] = ' ';//luz 1
			fase5[88][6] = ' ';//luz 2
		}
		else if(botao1 == true && botao2 == true)
		{
			fase5[88][4] = '=';//porta1
			fase5[88][2] = '^';//luz 1
			fase5[88][6] = '^';//luz 2
		}
		
		fase5[4][19] = 'O';//pbotao1
		if(pbotao1 == false)
		{
			fase5[49][90] = 'D';//porta final 1
			fase5[50][90] = 'D';//porta final 1
			fase5[1][19] = ' ';
			fase5[1][17] = ' ';
			fase5[1][21] = ' ';
			fase5[1][18] = ' ';
			fase5[1][20] = ' ';
		}
		else if(pbotao1 == true)
		{
			fase5[49][90] = '=';//porta final 1
			fase5[50][90] = '=';//porta final 1
			fase5[1][19] = '^';
			fase5[1][17] = '^';
			fase5[1][21] = '^';
			fase5[1][18] = '^';
			fase5[1][20] = '^';
		}
		
		fase5[93][33] = 'O';//pbotao2
		if(pbotao2 == false)
		{
			fase5[49][91] = 'D';//porta final 1
			fase5[50][91] = 'D';//porta final 1
			fase5[98][35] = ' ';
			fase5[98][34] = ' ';
			fase5[98][33] = ' ';
			fase5[98][32] = ' ';
			fase5[98][31] = ' ';
		}
		else if(pbotao2 == true)
		{
			fase5[49][91] = '=';//porta final 1
			fase5[50][91] = '=';//porta final 1
			fase5[98][35] = '^';
			fase5[98][34] = '^';
			fase5[98][33] = '^';
			fase5[98][32] = '^';
			fase5[98][31] = '^';
		}
		
		fase5[47][43] = 'O';//pbotao3
		if(pbotao3 == false)
		{
			fase5[49][92] = 'D';//porta final 1
			fase5[50][92] = 'D';//porta final 1
			fase5[44][45] = ' ';
			fase5[44][44] = ' ';
			fase5[44][43] = ' ';
			fase5[44][42] = ' ';
			fase5[44][41] = ' ';
		}
		else if(pbotao3 == true)
		{
			fase5[49][92] = '=';//porta final 1
			fase5[50][92] = '=';//porta final 1
			fase5[44][45] = '^';
			fase5[44][44] = '^';
			fase5[44][43] = '^';
			fase5[44][42] = '^';
			fase5[44][41] = '^';
		}
		
		fase5[6][76] = 'O';//pbotao4
		if(pbotao4 == false)
		{
			fase5[49][93] = 'D';//porta final 1
			fase5[50][93] = 'D';//porta final 1
			fase5[4][81] = ' ';
			fase5[5][81] = ' ';
			fase5[6][81] = ' ';
			fase5[7][81] = ' ';
			fase5[8][81] = ' ';
		}
		else if(pbotao4 == true)
		{
			fase5[49][93] = '=';//porta final 1
			fase5[50][93] = '=';//porta final 1
			fase5[4][81] = '^';
			fase5[5][81] = '^';
			fase5[6][81] = '^';
			fase5[7][81] = '^';
			fase5[8][81] = '^';
		}
		
		fase5[70][67] = 'O';//pbotao5
		if(pbotao5 == false)
		{
			fase5[49][94] = 'D';//porta final 1
			fase5[50][94] = 'D';//porta final 1
			fase5[68][70] = ' ';
			fase5[69][70] = ' ';
			fase5[70][70] = ' ';
			fase5[71][70] = ' ';
			fase5[72][70] = ' ';
		}
		else if(pbotao5 == true)
		{
			fase5[49][94] = '=';//porta final 1
			fase5[50][94] = '=';//porta final 1
			fase5[68][70] = '^';
			fase5[69][70] = '^';
			fase5[70][70] = '^';
			fase5[71][70] = '^';
			fase5[72][70] = '^';
		}
		
		
		fase5[jogador.y][jogador.x] = jogador.aparencia; 
		
		for(i = 0; i < x; i++)
		{
			for(j = 0; j < y; j++)
			{
				cout << fase5[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
		acao = getch();
		//cin >> acao;
		switch(acao)
		{
			case 'w':
			case 'W':
			case 72:
			{
				if(fase5[jogador.y-1][jogador.x] == '*' || fase5[jogador.y-1][jogador.x] == 'D')
				{
					fase5[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase5[jogador.y-1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase5[jogador.y][jogador.x] = ' ';
					botao1 = false;
					botao2 = false;
					pbotao1 = false;
					pbotao2 = false;
					pbotao3 = false;
					pbotao4 = false;
					pbotao5 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 99;
					jogador.x = 4;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase5[jogador.y][jogador.x] = ' ';
					jogador.y -= 1;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'a':
			case 'A':
			case 75:
			{
				if(fase5[jogador.y][jogador.x-1] == '*' || fase5[jogador.y][jogador.x-1] == 'D')
				{
					fase5[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase5[jogador.y][jogador.x-1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase5[jogador.y][jogador.x] = ' ';
					botao1 = false;
					botao2 = false;
					pbotao1 = false;
					pbotao2 = false;
					pbotao3 = false;
					pbotao4 = false;
					pbotao5 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 99;
					jogador.x = 4;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase5[jogador.y][jogador.x] = ' ';
					jogador.x -= 1;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 's':
			case 'S':
			case 80:
			{
				if(fase5[jogador.y+1][jogador.x] == '*' || fase5[jogador.y+1][jogador.x] == 'D')
				{
					fase5[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase5[jogador.y+1][jogador.x] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase5[jogador.y][jogador.x] = ' ';
					botao1 = false;
					botao2 = false;
					pbotao1 = false;
					pbotao2 = false;
					pbotao3 = false;
					pbotao4 = false;
					pbotao5 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 99;
					jogador.x = 4;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase5[jogador.y][jogador.x] = ' ';
					jogador.y += 1;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
				
			case 'd':
			case 'D':
			case 77:
			{
				if(fase5[jogador.y][jogador.x+1] == '*' || fase5[jogador.y][jogador.x+1] == 'D')
				{
					fase5[jogador.y][jogador.x] = jogador.aparencia; 
				}
				else if(fase5[jogador.y][jogador.x+1] == '#')
				{
					contadorMortes++;
					if(contadorMortes != 3)
					{
						cout << endl << "Voce morreu!" << endl;
						cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
						sleep(1);
						cout << "Retornando em 3..." << endl;
						sleep(1);
						cout << "2..." << endl;
						sleep(1);
						cout << "1..." << endl;
						sleep(1);
					}
					fase5[jogador.y][jogador.x] = ' ';
					botao1 = false;
					botao2 = false;
					pbotao1 = false;
					pbotao2 = false;
					pbotao3 = false;
					pbotao4 = false;
					pbotao5 = false;
					if(bauAberto == false)
					{
					bauAberto = false;
					}
					jogador.y = 99;
					jogador.x = 4;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				else
				{
					fase5[jogador.y][jogador.x] = ' ';
					jogador.x += 1;
					fase5[jogador.y][jogador.x] = jogador.aparencia;
				}
				break;
			}
			case 'i':      // Botão Interação ///////////////////
			case 'I': 
			{
				if(fase5[jogador.y][jogador.x] == fase5[50][1] && bauAberto == false)
				{
					bau(5, &jogador);
					bauAberto = true;
				}
				else if(fase5[jogador.y][jogador.x] == fase5[50][1] && bauAberto == true)
				{
					int aberto;
					aberto = rand()%3;
					switch(aberto)
					{
						case 0:
							cout << "Voce ja abriu esse bau!" << endl;
							system("pause");
							break;
						case 1:
							cout << "O bau esta vazio!" << endl;
							system("pause");
							break;
						case 2:
							cout << "Voce procura um pouco mais, mas o bau esta vazio!" << endl;
							system("pause");
							break;			
					}
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[91][2])
				{
					botao1 = true;
				}
				if(fase5[jogador.y][jogador.x] == fase5[91][6])
				{
					botao2 = true;
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[4][19])//pbotao1
				{
					pbotao1 = true;
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[93][33])//pbotao2
				{
					pbotao2 = true;
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[46][43])//pbotao3
				{
					pbotao3 = true;
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[6][72])//pbotao4
				{
					pbotao4 = true;
				}
				
				if(fase5[jogador.y][jogador.x] == fase5[69][67])//pbotao5
				{
					pbotao5 = true;
				}
				
				break;
			}
			case 'k':
				pbotao1 = true;
				pbotao2 = true;
				pbotao3 = true;
				pbotao4 = true;
				pbotao5 = true;
				break;
			default:
				break;		
		}
		
		if(fase5[jogador.y][jogador.x] == fase5[49][97] || fase5[jogador.y][jogador.x] == fase5[50][97] || fase5[jogador.y][jogador.x] == fase5[49][98] || fase5[jogador.y][jogador.x] == fase5[50][98] )
		{
			cout << "Voce encontrou o dragao!" << endl;
			if(combate(jogador, boss) == 1)
			{
				contadorMortes++;
				if(contadorMortes != 3)
				{
					cout << endl << "Voce morreu!" << endl;
					cout << "Voce ainda tem " << 3-contadorMortes << " vidas restantes" << endl;
					sleep(1);
					cout << "Retornando em 3..." << endl;
					sleep(1);
					cout << "2..." << endl;
					sleep(1);
					cout << "1..." << endl;
					sleep(1);
				}
				fase5[jogador.y][jogador.x] = ' ';
				botao1 = false;
				botao2 = false;
				pbotao1 = false;
				pbotao2 = false;
				pbotao3 = false;
				pbotao4 = false;
				pbotao5 = false;
				if(bauAberto == false)
					{
					bauAberto = false;
					}
				jogador.y = 99;
				jogador.x = 4;
				fase5[jogador.y][jogador.x] = jogador.aparencia;
			}
			else
			{
				bossMorto = true;
			}
		}
		
		if(contadorMortes == 3)
		{
			derrota();
		}
		
	}while(bossMorto == false);
	
	return jogador;
}

int combate(Personagem jogador, Personagem inimigo)
{
	
	int jg;//Variavel de controle para Jogar De novo
	int i, ai, encontro;//Variavel de controle de turno do Jogador; Variavel de controle de turno do Inimigo; Variavel aleatoria do encontro
	int defesaj = 0, defesai = 0;//Tracker de Defesa do Jogador; Tracker de Defesa do Inimigo
	int pocao = 0, pocaoi = 0;//Contador de pocoes do Jogador; Contador de pocoes do Inimigo
	int p1,p2,p3;//Dados de vida da pocao
	int danoj, danoi;//danoj = Dano do turno do Jogador; danoi = Dano do turno do Inimigo
	int hpmaxj, hpmaxi;//hpmaxj = HP maximo Jogador; hpmaxi = HP maximo Inimigo
	hpmaxj = jogador.hp;//Definindo HP maximo do jogador para o uso de pocoes
	hpmaxi = inimigo.hp;//Definindo HP maximo do inimigo para o uso de pocoes
	srand(time(NULL));//Definindo seed aleatoria para o combate
	system("pause");
	system("cls");
		if(inimigo.agilidade > jogador.agilidade)
		{
			do
			{
				//Turno inimigo
				system("cls");
				cout << endl << endl << endl;
				cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!"                                                             << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
				cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				ai = rand()%3;
				switch(ai)//Acao do inimigo decidida aleatoriamente
				{
					case 0:
						danoi = rand()%8+rand()%6+2+inimigo.forca;
						if(danoi <= jogador.armadura.defesa)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "!"                                                                       << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " ataca!" << endl << "\t\t\t\tMas parece nao surtir efeito!"                   << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else if(danoi > jogador.armadura.defesa)
						{
							danoi = danoi-jogador.armadura.defesa;
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "!"                                                                       << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " ataca!" << endl << "\t\t\t\tCausando " << danoi << " de dano"                << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							jogador.hp=jogador.hp-danoi;
							system("pause");
						}
						break;
					case 1:
						system("cls");
						cout << endl << endl << endl;
						cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\tV!"                                                             << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
						cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
						cout << "\t\t\t\t" << inimigo.nome << " defende!"                                                                    << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						inimigo.armadura.defesa=inimigo.armadura.defesa*2;
						defesai=1;
						system("pause");
						break;
					case 2:
						if(hpmaxi == inimigo.hp)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!P?"                                                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " pensa em tomar uma pocao, mas desiste de toma-la!"                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						}
						else
						{
							if(pocaoi != 3)
							{
								inimigo.hp=inimigo.hp+rand()%6+rand()%6+rand()%6+3;
								if(inimigo.hp > hpmaxi)
								{
									inimigo.hp = hpmaxi;
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
								else if(inimigo.hp == hpmaxi)
								{
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
								else if(inimigo.hp < hpmaxi)
								{
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
							}
							else
							{
								system("cls");
								cout << endl << endl << endl;
								cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!P?"                                                             << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
								cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
								cout << "\t\t\t\t" << inimigo.nome << " tenta beber uma pocao, mas o frasco ja esta vazio!"                          << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								system("pause");
							}
						}
						break;
				}
				if(defesaj == 1)//Tracker de defesa do jogador por turno
				{
					jogador.armadura.defesa=jogador.armadura.defesa/2;
					defesaj = 0;
				}			
			//Turno jogador
				system("cls");
				cout << endl << endl << endl;
				cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!"                                                             << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
				cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
				cout << "\t\t\t\tEscolha a acao"                                                                                     << endl;
				cout << "\t\t\t\t1 - Atacar\t2 - Defender\t3 - Beber pocao"                                                          << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cin >> i;
				switch(i)//Acoes que o player escolhe
				{
					case 1:
						switch(jogador.arma.dado)
                        {
                            case 1: 
                                danoj = rand()%6+rand()%6+2; 
                                break;
                            case 2: 
                                danoj = rand()%12+1; 
                                break;
                            case 3:  
                                danoj = rand()%4+rand()%4+rand()%4+3; 
                                break;
                            case 4:   
                                danoj = rand()%10+1; 
                                break;
                            case 5: 
                                danoj = rand()%8+rand()%8+2;
                                break;
                            case 6:   
                                danoj = rand()%6+rand()%6+rand()%6+3; 
                                break;
                            case 7: 
                                danoj = rand()%6+rand()%6+rand()%6+rand()%4+4;
                                break;
                            case 8: 
                                danoj = rand()%6+rand()%6+rand()%6+3;
                                break;
                            case 9:   
                                danoj = rand()%4+rand()%4+rand()%4+rand()%4+rand()%4+rand()%4+6; 
                                break;
                            case 10:  
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+4; 
                                break;
                            case 11: 
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+rand()%8+5; 
                                break;
                            case 12: 
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+rand()%8+5; 
                                break;
                            case 13:
                            	danoj = rand()%8+rand()%8+rand()%8+rand()%8+4; 
								break;   
                        }
						danoj = danoj+jogador.arma.dano;
						if(danoj < inimigo.armadura.defesa)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t\t\t\t\t\t" << jogador.aparencia << "!"                                                             << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tVoce ataca!" << endl << "\t\t\t\tMas parece nao surtir efeito!"                                     << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else if(danoj > inimigo.armadura.defesa)
						{
							danoj = danoj-inimigo.armadura.defesa;
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t\t\t\t\t\t" << jogador.aparencia << "!"                                                             << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tVoce ataca!" << endl << "\t\t\t\tCausando "<< danoj << " de dano"                                   << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							inimigo.hp=inimigo.hp-danoj;
							system("pause");
						}
						break;
					case 2:
						system("cls");
						cout << endl << endl << endl;
						cout << "\t\t\t\t" << jogador.aparencia << "V\t\t\t\t\t!"                                                            << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
						cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
						cout << "\t\t\t\tVoce defende"                                                                                       << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						jogador.armadura.defesa=jogador.armadura.defesa*2;
						defesaj=1;
						system("pause");
						break;
					case 3:
						if(hpmaxj == jogador.hp)
						{
							system("cls");
							cout << endl << endl << endl;									
							cout << "\t\t\t\t" << jogador.aparencia << "P?\t\t\t\t\t!"                                                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tSeu HP ja esta cheio!"                                                                              << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else
						{
							if(pocao != 3)
							{
								p1=rand()%6+jogador.constituicao/2;
								p2=rand()%6+jogador.constituicao/2;
								p3=rand()%6+jogador.constituicao/2;
								jogador.hp=jogador.hp+p1+p2+p3+3;
								if(jogador.hp > hpmaxj)
								{
									jogador.hp = hpmaxj;
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce encheu seu HP"                                                                                 << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
								else if(jogador.hp == hpmaxj)
								{
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce encheu seu HP"                                                                                 << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
								else if(jogador.hp < hpmaxj)
								{
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce recuperou "<<  p1+p2+p3+3 <<" de HP"                                                           << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
							}
							else
							{
								system("cls");
								cout << endl << endl << endl;									
								cout << "\t\t\t\t" << jogador.aparencia << "P?\t\t\t\t\t!"                                                           << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
								cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
								cout << "\t\t\t\tPocoes esgotadas!"                                                                                  << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								system("pause");
							}
						}
						break;
					default:
						jogador.hp=jogador.hp+danoi;
						break;	
				}
				if(defesai == 1)//Tracker de defesa do inimigo por turno
				{
					inimigo.armadura.defesa=inimigo.armadura.defesa/2;
					defesai = 0;
				}
			}while(inimigo.hp > 0 && jogador.hp > 0);
		}
		else if(inimigo.agilidade <= jogador.agilidade)//Mesma logica de round, so que com personagens trocados
		{
			do
			{
				//Turno jogador
				system("cls");
				cout << endl << endl << endl;
				cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!"                                                             << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
				cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
				cout << "\t\t\t\tEscolha a acao"                                                                                     << endl;
				cout << "\t\t\t\t1 - Atacar\t2 - Defender\t3 - Beber pocao"                                                          << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cin >> i;
				switch(i)//Acoes que o player escolhe
				{
					case 1:
						switch(jogador.arma.dado)
                        {
                            case 1: 
                                danoj = rand()%6+rand()%6+2; 
                                break;
                            case 2: 
                                danoj = rand()%12+1; 
                                break;
                            case 3:  
                                danoj = rand()%4+rand()%4+rand()%4+3; 
                                break;
                            case 4:   
                                danoj = rand()%10+1; 
                                break;
                            case 5: 
                                danoj = rand()%8+rand()%8+2;
                                break;
                            case 6:   
                                danoj = rand()%6+rand()%6+rand()%6+3; 
                                break;
                            case 7: 
                                danoj = rand()%6+rand()%6+rand()%6+rand()%4+4;
                                break;
                            case 8: 
                                danoj = rand()%6+rand()%6+rand()%6+3;
                                break;
                            case 9:   
                                danoj = rand()%4+rand()%4+rand()%4+rand()%4+rand()%4+rand()%4+6; 
                                break;
                            case 10:  
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+4; 
                                break;
                            case 11: 
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+rand()%8+5; 
                                break;
                            case 12: 
                                danoj = rand()%8+rand()%8+rand()%8+rand()%8+rand()%8+5; 
                                break;
                            case 13:
                            	danoj = rand()%8+rand()%8+rand()%8+rand()%8+4; 
								break;   
                        }
						danoj = danoj+jogador.arma.dano;
						if(danoj < inimigo.armadura.defesa)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t\t\t\t\t\t" << jogador.aparencia << "!"                                                             << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tVoce ataca!" << endl << "\t\t\t\tMas parece nao surtir efeito!"                                     << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else if(danoj > inimigo.armadura.defesa)
						{
							danoj = danoj-inimigo.armadura.defesa;
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t\t\t\t\t\t" << jogador.aparencia << "!"                                                             << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tVoce ataca!" << endl << "\t\t\t\tCausando "<< danoj << " de dano"                                   << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							inimigo.hp=inimigo.hp-danoj;
							system("pause");
						}
						break;
					case 2:
						system("cls");
						cout << endl << endl << endl;
						cout << "\t\t\t\t" << jogador.aparencia << "V\t\t\t\t\t!"                                                            << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
						cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
						cout << "\t\t\t\tVoce defende"                                                                                       << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						jogador.armadura.defesa=jogador.armadura.defesa*2;
						defesaj=1;
						system("pause");
						break;
					case 3:
						if(hpmaxj == jogador.hp)
						{
							system("cls");
							cout << endl << endl << endl;									
							cout << "\t\t\t\t" << jogador.aparencia << "P?\t\t\t\t\t!"                                                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\tSeu HP ja esta cheio!"                                                                              << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else
						{
							if(pocao != 3)
							{
								p1=rand()%6+jogador.constituicao/2;
								p2=rand()%6+jogador.constituicao/2;
								p3=rand()%6+jogador.constituicao/2;
								jogador.hp=jogador.hp+p1+p2+p3+3;
								if(jogador.hp > hpmaxj)
								{
									jogador.hp = hpmaxj;
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce encheu seu HP"                                                                                 << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
								else if(jogador.hp == hpmaxj)
								{
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce encheu seu HP"                                                                                 << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
								else if(jogador.hp < hpmaxj)
								{
									system("cls");
									cout << endl << endl << endl;									
									cout << "\t\t\t\t+" << jogador.aparencia << "P+\t\t\t\t\t!"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\tVoce recuperou "<<  p1+p2+p3+3 <<" de HP"                                                           << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocao++;
									system("pause");
								}
							}
							else
							{
								system("cls");
								cout << endl << endl << endl;									
								cout << "\t\t\t\t" << jogador.aparencia << "P?\t\t\t\t\t!"                                                           << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
								cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
								cout << "\t\t\t\tPocoes esgotadas!"                                                                                  << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								system("pause");
							}
						}
						break;
					default:
						jogador.hp=jogador.hp+danoi;
						break;	
				}
				if(defesai == 1)//Tracker de defesa do inimigo por turno
				{
					inimigo.armadura.defesa=inimigo.armadura.defesa/2;
					defesai = 0;
				}
				//Turno inimigo
				system("cls");
				cout << endl << endl << endl;
				cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!"                                                             << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
				cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
				cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
				ai = rand()%3;
				if(inimigo.hp<0)
				{
					ai = 4;//Se o HP do inimigo ja tiver sido zerado o turno dele sera pulado
				}
				switch(ai)//Acao do inimigo decidida aleatoriamente
				{
					case 0:
						danoi = rand()%8+rand()%6+2+inimigo.forca;
						if(danoi <= jogador.armadura.defesa)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "!"                                                                       << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " ataca!" << endl << "\t\t\t\tMas parece nao surtir efeito!"                   << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							system("pause");
						}
						else if(danoi > jogador.armadura.defesa)
						{
							danoi = danoi-jogador.armadura.defesa;
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "!"                                                                       << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " ataca!" << endl << "\t\t\t\tCausando " << danoi << " de dano"                << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							jogador.hp=jogador.hp-danoi;
							system("pause");
						}
						break;
					case 1:
						system("cls");
						cout << endl << endl << endl;
						cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\tV!"                                                             << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
						cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
						cout << "\t\t\t\t" << inimigo.nome << " defende!"                                                                    << endl;
						cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						inimigo.armadura.defesa=inimigo.armadura.defesa*2;
						defesai=1;
						system("pause");
						break;
					case 2:
						if(hpmaxi == inimigo.hp)
						{
							system("cls");
							cout << endl << endl << endl;
							cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!P?"                                                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
							cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
							cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
							cout << "\t\t\t\t" << inimigo.nome << " pensa em tomar uma pocao, mas desiste de toma-la!"                           << endl;
							cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
						}
						else
						{
							if(pocaoi != 3)
							{
								inimigo.hp=inimigo.hp+rand()%6+rand()%6+rand()%6+3;
								if(inimigo.hp > hpmaxi)
								{
									inimigo.hp = hpmaxi;
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
								else if(inimigo.hp == hpmaxi)
								{
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
								else if(inimigo.hp < hpmaxi)
								{
									system("cls");
									cout << endl << endl << endl;
									cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t+!P+"                                                          << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
									cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
									cout << "\t\t\t\t" << inimigo.nome << " bebeu uma pocao!"                                                            << endl;
									cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
									pocaoi++;
									system("pause");
								}
							}
							else
							{
								system("cls");
								cout << endl << endl << endl;
								cout << "\t\t\t\t" << jogador.aparencia << "\t\t\t\t\t!P?"                                                             << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								cout << "\t\t\t\t" << jogador.nome << "\t\t\t\t\t" << inimigo.nome                                                   << endl; 
								cout << "\t\t\t\tHP: " << jogador.hp << "\t\t\t\t\tHP: " << inimigo.hp                                               << endl;
								cout << "\t\t\t\t" << inimigo.nome << " tenta beber uma pocao, mas o frasco ja esta vazio!"                          << endl;
								cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
								system("pause");
							}
						}
						break;
				}
				if(defesaj == 1)//Tracker de defesa do jogador por turno
				{
					jogador.armadura.defesa=jogador.armadura.defesa/2;
					defesaj = 0;
				}
			}while(inimigo.hp > 0 && jogador.hp > 0);
		}
		if(inimigo.hp < 1)
		{
			cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\tVitoria" << endl;
			cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
			system("pause");
			return 0;
		}
		else if(jogador.hp < 1)
		{
			cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\tDerrota" << endl;
			cout << "\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
			system("pause");
			
			return 1;
		}
		return 0;
}

void criacao(Personagem *jogador)
{
    int att;
    int sn;
    int contador = 0;
    int ea, em, ep;
    int d1, d2, d3;

	srand(time(NULL));

	//Zerando os stats do jogador para nao serem usados outros numeros que poderiam estar na memoria
	jogador->forca=0;
    jogador->constituicao=0;
    jogador->destreza=0;
    jogador->agilidade=0;
    
    system("cls");
    
    cout << "Qual o seu nome?" << endl;
    cin >> jogador->nome;
    cout << endl;
    
    cout << "Escolha uma aparencia" << endl;
    cout << "1 -  &" << endl;
    cout << "2 -  $" << endl;
    cout << "3 -  U" << endl;
    
    cin >> ep;
    switch(ep)
    {
    	case 1:
    		jogador->aparencia = '&';
    		break;
    	case 2:
    		jogador->aparencia = '$';
    		break;
    	case 3:
    		jogador->aparencia = 'U';
    		break;
    	default:
    		criacao(jogador);
    		break;
	}
    
	cout << endl << endl;
    cout << "Escolha uma classe" << endl;
    cout << "1) Cacador                                    2) Arconte                                   3) Paladino                                   4) Vagabundo" << endl;
    cout << "   FOR: 4                                        FOR: 12                                      FOR: 8                                        FOR: 5" << endl;
    cout << "   DES: 10                                       DES: 3                                       DES: 8                                        DES: 5" << endl;
    cout << "   CON: 6                                        CON: 10                                      CON: 8                                        CON: 5" << endl;
    cout << "   AGL: 10                                       AGL: 5                                       AGL: 6                                        AGL: 5" << endl;
    cout << "   Arma: Florete                                 Arma: Espada larga                           Arma: Espada curta                            Arma: Porrete de madeira" << endl;
    cout << "         2d6 + 2                                       1d12 + 1                                     3d4 + 2                                       1d10 + 2          " << endl;
    cout << "         FOR: -                                        FOR: A                                       FOR: B                                        FOR: B            " << endl;
    cout << "         DES: A                                        DES: -                                       DES: B                                        DES: -            " << endl;
    cout << "   Armadura: Vestes de icaro                     Armadura: Armadura do alvorecer              Armadura: Armadura do erudito                 Armadura: Trapos        " << endl;
    cout << "         DEF: 3                                        DEF: 4                                       DEF: 4                                        DEF: 1            " << endl;

    
    //S: x2, A: x1,5, B: x1, C: x0,5; Multiplicadores que influenciam no dano
    cin >> ea;
    switch(ea)
    {
    	case 1:
    		jogador->forca = 4;
    		jogador->destreza = 10;
    		jogador->constituicao = 4;
    		jogador->agilidade = 10;
    		jogador->arma.dado = 1;
    		jogador->arma.dano = 2+(jogador->destreza*1.5);
    		jogador->armadura.defesa = 3;
    		jogador->arma.nome = ("Florete");
    		jogador->arma.info = ("2d6 + 2\nFOR: -\nDES: A");
    		jogador->armadura.nome = ("Vestes de icaro");
    		break;
    	case 2:
    		jogador->forca = 12;
    		jogador->destreza = 3;
    		jogador->constituicao = 10;
    		jogador->agilidade = 5;
    		jogador->arma.dado = 2;
    		jogador->arma.dano = 1+(jogador->forca*1.5);
    		jogador->armadura.defesa = 4;
    		jogador->arma.nome = ("Espada larga");
    		jogador->arma.info = ("1d12 + 1\nFOR: A\nDES: -");
    		jogador->armadura.nome = ("Armadura do alvorecer");
    		break;
    	case 3:
    		jogador->forca = 8;
    		jogador->destreza = 8;
    		jogador->constituicao = 8;
    		jogador->agilidade = 6;
    		jogador->arma.dado = 3;
    		jogador->arma.dano = 2+(jogador->forca*1)+(jogador->destreza*1);
    		jogador->armadura.defesa = 4;
    		jogador->arma.nome = ("Espada curta");
    		jogador->arma.info = ("3d4 + 2\nFOR: B\nDES: B");
    		jogador->armadura.nome = ("Armadura do erudito");
    		break;
    	case 4:
    		jogador->forca = 5;
    		jogador->destreza = 5;
    		jogador->constituicao = 5;
    		jogador->agilidade = 5;
    		jogador->arma.dado = 4;
    		jogador->arma.dano = 2+(jogador->forca*1);
    		jogador->armadura.defesa = 1;
    		jogador->arma.nome = ("Porrete de madeira");
    		jogador->arma.info = ("1d10 + 2\nFOR: B\nDES: -");
    		jogador->armadura.nome = ("Trapos");
    		break;
    	default:
    		criacao(jogador);
    		break;
	}

    //Rolando os dados de vida
    d1 = (rand()%6);
    d2 = (rand()%6);
    d3 = (rand()%6);
	jogador->hp=d1+d2+d3+3+2*jogador->constituicao;//Definindo a vida final usando HP = 3d6+2*CON
	
	system("cls");
	cout << endl << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << " Seus dados de vida: " << d1+1 << " " << d2+1 << " " << d3+1 << "                                   " << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "                                                " << jogador->aparencia << endl;
	cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << " Classe: ";
    switch(ea)
    {
    	case 1:
    		cout << "Cacador" << endl;
    		break;
    	case 2:
    		cout << "Arconte" << endl;
			break;
		case 3:
			cout << "Paladino" << endl;
			break;
		case 4:	
			cout << "Vagabundo" << endl;
			break;
	}
	cout << " Nome: " << jogador->nome << endl;
	cout << " HP: " << jogador->hp << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << " FOR: " << jogador->forca << endl;
    cout << " DES: " << jogador->destreza << endl;
    cout << " CON: " << jogador->constituicao << endl;
    cout << " AGL: " << jogador->agilidade << endl << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " 1 - Continuar\t2 - Redistribuir" << endl;
    
    cin >> sn;
    switch(sn)
    {
    	case 1:
    		cout << endl << "Boa sorte..." << endl;
    		system ("pause");
    		break;
    	case 2:
    		system("pause");
    		//Zerando os stats para redistribuicao
    		jogador->forca=0;
    		jogador->constituicao=0;
    		jogador->destreza=0;
    		jogador->agilidade=0;
			criacao(jogador);
			break;
	}
}

void levelup(Personagem *jogador)
{
	int att;
    int sn;
    int contador = 0;
    int ea, em;
    int lvlup_forca=0, lvlup_constituicao=0, lvlup_destreza=0, lvlup_agilidade=0;
    system("cls");
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " Voce upou de nivel!" << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    system("pause");
    for(contador = 0; contador < 10; contador ++)//10 pontos para distribuir
    {
    system("cls");
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " Escolha qual atributo voce deseja aumentar" << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " Pontos restantes: " << 10-contador << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " HP: " << jogador->hp+2*lvlup_constituicao << endl;
    cout << " 1 - FOR: " << jogador->forca+lvlup_forca << endl;
    cout << " 2 - DES: " << jogador->destreza+lvlup_destreza << endl;
    cout << " 3 - CON: " << jogador->constituicao+lvlup_constituicao << endl;
    cout << " 4 - AGL: " << jogador->agilidade+lvlup_agilidade << endl;
    
	cin >> att;
    switch(att)//Escolha manual
    	{
	    case 1:
	        lvlup_forca+=1;
	        break;
	    case 2:
	        lvlup_destreza+=1;
	        break;
	    case 3:
	        lvlup_constituicao+=1;
	        break;
		case 4:
			lvlup_agilidade+=1;
	    	break;
	    default:
	        contador-=1;
	        break;
	    }
    }
    //Soma dos atributos escolhidos com os atributos do jogador
    jogador->forca+=lvlup_forca;
    jogador->constituicao+=lvlup_constituicao;
    jogador->destreza+=lvlup_destreza;
    jogador->agilidade+=lvlup_agilidade;

	//Soma da CON com o HP
	jogador->hp=jogador->hp+2*lvlup_constituicao;
	
	system("cls");
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << "                                                " << jogador->aparencia << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
    cout << " Nome: " << jogador->nome << endl;
    cout << " HP: " << jogador->hp << endl;
    cout << " 1 - FOR: " << jogador->forca << endl;
    cout << " 2 - DES: " << jogador->destreza << endl;
    cout << " 3 - CON: " << jogador->constituicao << endl;
    cout << " 4 - AGL: " << jogador->agilidade << endl;
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
	cout << endl;
    cout << "1 - Continuar\t2 - Redistribuir pontos" << endl;

    cin >> sn;
    switch(sn)
    {
    	case 1:
    		system("pause");
    		break;
    	case 2:
    	default:
    		//Subtraindo os valores escolhidos, retornando para os atributos pre-levelup para a redistribuicao
    		jogador->forca-=lvlup_forca;
    		jogador->constituicao-=lvlup_constituicao;
    		jogador->destreza-=lvlup_destreza;
    		jogador->agilidade-=lvlup_agilidade;
    		jogador->hp-=jogador->constituicao;
			levelup(jogador);
			break;
	}
}
