//
// Created by Kri on 10/15/2021.
//

#ifndef UZD1_FUNKCIJOS_STRUKTUROS_H
#define UZD1_FUNKCIJOS_STRUKTUROS_H

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

random_device rnd;
mt19937 mersenne_engine {rnd()};
uniform_int_distribution<int> dist {1, 10};

int gen () {
    return dist(mersenne_engine);
}

struct Studentas {
    string vardas, pavarde;
    vector <double> nd;
    double egz;
    double vid;
    double galut;
};

bool palyginimas(const Studentas pirmas, const Studentas antras){
    return pirmas.galut > antras.galut;
}

void vidurkis_galut(vector<Studentas>& p, int nd_sk, int studento_sk){
    double suma = 0;
    p.at(studento_sk).vid = accumulate(p.at(studento_sk).nd.begin(), p.at(studento_sk).nd.end(), suma) / nd_sk;
    p.at(studento_sk).galut = p.at(studento_sk).vid * 0.4 + p.at(studento_sk).egz * 0.6;
}

void isvedimas_failas(vector<Studentas> lam, vector<Studentas> fal, long int n, vector<double>& laikas){
    ofstream lf("Laimetojai" + to_string(n) + ".txt");
    ofstream ff("Luzeriai" + to_string(n) + ".txt");
    auto start = system_clock::now();
    lf << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    lf << "--------------------------------------------------------" << "\n";
    ff << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    ff << "--------------------------------------------------------" << "\n";
    for(int x = 0; x < lam.size(); x++)
    {
        lf << setw(18) << lam.at(x).vardas << setw(18) << lam.at(x).pavarde;
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

void rusiavimas(vector<Studentas> p, vector<Studentas>& lam, vector<Studentas>& fal, long int kiekis, vector<double>& laikas)
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

void failo_nuskaitymas(vector<Studentas>& p, long int n, vector<double>& laikas){
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
        vidurkis_galut(p, 7, x);
    }
    df.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(1) = diff.count();
}

void generavimas(long int kiekis, vector<double>& laikas){
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

#endif //UZD1_FUNKCIJOS_STRUKTUROS_H
