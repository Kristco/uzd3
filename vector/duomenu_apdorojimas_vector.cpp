#include "vector/strukturos_vector.h"
#include "vector/duomenu_apdorojimas_vector.h"
#include "vector/skaiciavimai_vector.h"

void rusiavimas_vector(vector<Studentas_V> p, vector<Studentas_V>& lam, vector<Studentas_V>& fal, int kiekis, vector<double>& laikas)
{
    auto start = system_clock::now();
    for(int y = 1; y <= kiekis; y++)
    {
        if (p.at(y).galut < 5)  fal.push_back(p.at(y));
        else    lam.push_back(p.at(y));
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
}