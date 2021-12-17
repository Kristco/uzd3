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
    Studentas(ifstream& df);
    inline string getVardas() const {return vardas;}
    inline string getPavarde() const {return pavarde;}
    double getGalut();
    void readStud(ifstream&);

};

#endif //UZD1_KLASES_H
