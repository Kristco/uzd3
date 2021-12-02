#include "vector/strukturos_vector.h"
#include "vector/antras_duomenu_apdorojimas_vector.h"

bool Palyginimas(Studentas_V studentas)
{
    return studentas.galut < 5.00;
}

void rusiavimas_vector_antras(vector<Studentas_V>& p, vector<Studentas_V>& fal, int kiekis, vector<double>& laikas, int& d)
{
    auto start = system_clock::now();
    for(int y = 1; y <= kiekis; y++)
    {
        if (p.at(y).galut < 5)
        {
            fal.push_back(p.at(y));
            d++;
        }
    }
    remove_if(p.begin(), p.end(), Palyginimas);

    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
}