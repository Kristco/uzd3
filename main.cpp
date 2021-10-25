#include "strukturos.h"
#include "duomenu_operacijos.h"

using namespace std;

int main()
{
    char yn;
    int n = 0;
    cout << "Jeigu norite skaityti is failo iveskite f/F, bet koks kitas simbolis leis ivedineti ranka duomenis \n"; cin >> yn;
    vector<Studentas> p;
    if(yn == 'f' || yn == 'F')  failo_nuskaitymas(p, n);
    else    ivedimas_ranka(p, n);
    isvedimas(p, n);
    return 0;
}
