#include "strukturos.h"
#include "duomenu_apdorojimas.h"
#include "skaiciavimai.h"

void rusiavimas(list<Studentas> p, list<Studentas>& lam, list<Studentas>& fal, vector<double>& laikas)
{
    auto start = system_clock::now();
    for(auto iter : p)
    {
        if (iter.galut < 5)  fal.push_back(iter);
        else    lam.push_back(iter);
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
}

void generavimas(int kiekis, vector<double>& laikas)
{
    string vardas = "Vardas", pavarde = "Pavarde";
    ofstream rf("Studentai" + to_string(kiekis) + ".txt");
    auto start = system_clock::now();
    rf << setw(18) << left << "Vardas" << setw(18) << "Pavarde";
    for(int x = 1; x <= 7; x++)  rf << setw(8) << left << "ND" + to_string(x);
    rf << "Egz." << "\n";
    for(int x = 1; x <= kiekis; x++)
    {
        rf << setw(18) << left << "Vardas" + to_string(x) << setw(18) << "Pavarde" + to_string(x);
        for(int y = 0; y < 7; y++)  rf << setw(8) << left << gen();
        rf << gen() << "\n";
    }
    rf.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}