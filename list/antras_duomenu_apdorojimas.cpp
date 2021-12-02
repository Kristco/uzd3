#include "antras_duomenu_apdorojimas.h"
#include "strukturos.h"

bool Palyginimas2(Studentas studentas)
{
    return studentas.galut < 5.00;
}

void rusiavimas_antras(list<Studentas>& p, list<Studentas>& fal, vector<double>& laikas, int& d) {
    auto start = system_clock::now();
    for(auto iter : p) {
        if (iter.galut < 5) {
            fal.push_back(iter);
            d++;
        }
    }
    remove_if(p.begin(), p.end(), Palyginimas2);

    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
}


    /*
    auto start = system_clock::now();
    for(auto iter : p)
    {
        if (iter.galut < 5)
        {
            fal.push_back(iter);
        }
        else
        {
            lam.push_back(iter);
        }
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
    */