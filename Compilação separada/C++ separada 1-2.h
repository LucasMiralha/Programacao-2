#include <string>

using namespace std;

class DiaAno
{
    private:
        int dia;
        int mes;

    public:
        DiaAno(int nDia, int nMes);
        DiaAno();
        ~DiaAno();

        void setDia(int valor);
        void setMes(int valor);

        int getDia();
        int getMes();
};