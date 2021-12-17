#include "vector/strukturos.h"
#include "vector/duomenu_apdorojimas.h"
#include "vector/skaiciavimai.h"

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
        for(int y = 0; y < 7; y++)  rf << setw(8) << left << gen();
        rf << gen() << "\n";
    }
    rf.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}

void failo_nuskaitymas_vector(vector<Studentas_V>& p, int n, vector<double>& laikas){
    string failas;
    failas = "Studentai" + to_string(n) + ".txt";
    auto start = system_clock::now();
    ifstream df(failas);
    df.ignore(65536,'\n');
    p.resize(n+1);
    for(int x = 1; x <= n; x++) {
        p.at(x).nd.resize(7);
        df >> p.at(x).vardas >> p.at(x).pavarde;
        for (int y = 0; y < 7; y++) {
            df >> p.at(x).nd.at(y);
        }
        df >> p.at(x).egz;
        vidurkis_galut_vector(p, 7, x);
    }
    df.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(1) = diff.count();
}

void isvedimas_failas_vector(vector<Studentas_V> lam, vector<Studentas_V> fal, int n, vector<double>& laikas){
    ofstream lf("Laimetojai" + to_string(n) + ".txt");
    ofstream ff("Luzeriai" + to_string(n) + ".txt");
    auto start = system_clock::now();
    lf << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    lf << "--------------------------------------------------------" << "\n";
    ff << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    ff << "--------------------------------------------------------" << "\n";
    for(int x = 0; x < lam.size(); x++)
    {
        lf  << lam.at(x).vardas << setw(18) << lam.at(x).pavarde;
        lf << fixed << setprecision(2) << setw(25) << lam.at(x).galut << "\n";
    }
    for(int x = 0; x < fal.size(); x++)
    {
        ff << setw(18) << fal.at(x).vardas << setw(18) << fal.at(x).pavarde;
        ff << fixed << setprecision(2) << setw(25) << fal.at(x).galut << "\n";
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(3) = diff.count();
}