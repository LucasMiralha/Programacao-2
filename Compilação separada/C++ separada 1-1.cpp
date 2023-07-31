#include <iostream>
#include "C++ separada 1-2.h"

using namespace std;

int main()
{
    DiaAno hoje;
    DiaAno amanha = DiaAno(13, 9);

    cout << "Dia: " << hoje.getDia() << " Mes: " << hoje.getMes() << "\n";
    cout << "Dia: " << amanha.getDia() << " Mes: " << amanha.getMes() << "\n";
    return 0;
}
