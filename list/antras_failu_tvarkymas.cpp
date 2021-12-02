#include "antras_failu_tvarkymas.h"
#include "strukturos.h"

void antras_isvedimas_failas(list<Studentas> p, list<Studentas> fal, int n, vector<double>& laikas, int d){
    ofstream lf("LaimetojaiL2" + to_string(n) + ".txt");
    ofstream ff("LuzeriaiL2" + to_string(n) + ".txt");
    auto start = system_clock::now();
    lf << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    lf << "--------------------------------------------------------" << "\n";
    ff << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    ff << "--------------------------------------------------------" << "\n";

    int a = 0;
    for(auto iter : fal)
    {
        a++;
        ff << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        ff << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
        if (a == d) break;
    }
    a=0;
    for(auto iter : p)
    {
        a++;
        lf << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        lf << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
        if (a == (n-d)) break;
    }

    /*for(Studentas iter : p)
    {
        a++;
        lf << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        lf << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
        if (a == (n-d)) break;
    }
*/
    fal.clear();
    p.clear();

    /*for(auto iter : lam)
    {
        lf << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        lf << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
    }
    for(auto iter : fal)
    {
        ff << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        ff << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
    }*/
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(3) = diff.count();
}