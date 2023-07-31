#include <iostream>
#include "C++ separada 1-2.h"

using namespace std;

void DiaAno::setDia(int valor)
{
    if(valor >= 1 && valor <= 31)
    {
        dia = valor;
    }
    else
    {
        cout << "Valor inválido!\n";
        dia = 1;
    }
}
void DiaAno::setMes(int valor)
{
    if(valor >= 1 && valor <= 12)
    {
        mes = valor;
    }
    else
    {
        cout << "Valor inválido!\n";
        mes = 1;
    }
}

int DiaAno::getDia()
{
    return dia;
}
int DiaAno::getMes()
{
    return mes;
}

DiaAno::DiaAno(int nDia, int nMes)
{
    setDia(nDia);
    setMes(nMes);
}
DiaAno::DiaAno()
{
    dia = 1;
    mes = 1;
}

DiaAno::~DiaAno()
{
    cout << "Limpando Memória\n";
}