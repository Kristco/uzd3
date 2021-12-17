#ifndef UZD1_KLASES_H
#define UZD1_KLASES_H

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

class Studentas {

private:
    string vardas, pavarde;
    vector<double> nd;
    double egz;

public:
    Studentas() : egz(0) {};

    ~Studentas() = default;
    Studentas(const Studentas &laik)
    {
        vardas = laik.vardas;
        pavarde = laik.pavarde;
        nd = laik.nd;
        egz = laik.egz;
    }
    void swap(Studentas &laik)
    {
        ::swap(vardas, laik.vardas);
        ::swap(pavarde, laik.pavarde);
        ::swap(nd, laik.nd);
        ::swap(egz, laik.egz);
    }
    Studentas & operator = (Studentas laik)
    {
        swap(laik);
        return *this;
    }
    Studentas(ifstream& df);
    string getVardas() const {return vardas;}
    string getPavarde() const {return pavarde;}
    double getGalut();
    void readStud(ifstream&);

};

#endif //UZD1_KLASES_H