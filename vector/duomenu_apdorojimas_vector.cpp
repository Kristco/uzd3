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

void generavimas_vector(int kiekis, vector<double>& laikas)
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
        for(int y = 0; y < 7; y++)  rf << setw(8) << left << gen_vector();
        rf << gen_vector() << "\n";
    }
    rf.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}