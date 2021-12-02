#include "strukturos.h"
#include "failu_tvarkymas.h"
#include "skaiciavimai.h"

void failo_nuskaitymas(list<Studentas>& p, int n, vector<double>& laikas){
    string failas;
    failas = "Studentai" + to_string(n) + ".txt";
    auto start = system_clock::now();
    ifstream df(failas);
    df.ignore(65536,'\n');
    for(int x = 0; x < n; x++) {
        Studentas pone;
        pone.nd.resize(7);
        df >> pone.vardas >> pone.pavarde;
        for (int y = 0; y < 7; y++) {
            df >> pone.nd.at(y);
        }
        df >> pone.egz;
        vidurkis_galut(pone);
        p.push_back(pone);
    }
    df.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(1) = diff.count();
}

void isvedimas_failas(list<Studentas> lam, list<Studentas> fal, int n, vector<double>& laikas){
    ofstream lf("LaimetojaiL1" + to_string(n) + ".txt");
    ofstream ff("LuzeriaiL1" + to_string(n) + ".txt");
    auto start = system_clock::now();
    lf << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    lf << "--------------------------------------------------------" << "\n";
    ff << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    ff << "--------------------------------------------------------" << "\n";
    for(auto iter : lam)
    {
        lf << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        lf << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
    }
    for(auto iter : fal)
    {
        ff << setw(18) << iter.vardas << setw(18) << iter.pavarde;
        ff << fixed << setprecision(2) << setw(25) << iter.galut << "\n";
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(3) = diff.count();
    lam.clear();
    fal.clear();
}