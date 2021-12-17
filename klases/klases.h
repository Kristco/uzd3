#ifndef UZD1_KLASES_H
#define UZD1_KLASES_H

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

/**
 * Abstrakti klasė Zmogus
 */
class Zmogus {

protected:
    string vardas;
    string pavarde;

public:
    Zmogus() {};
    ~Zmogus() {};
    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;

};


/**
 * Klasė Studentas, kuri yra Zmogaus išvestinė klasė
 */
class Studentas : public Zmogus {
    /**
    * Informacija apie studentą
    * \param vardas Studento indentifikuojamas vardas
    * \param pavarde Studento indentifikuojama pavardė
    * \param nd Studento namų darbų rezultatai saugomi vectoriuje
    * \param egz Studento egzamino rezultatas
    */
private:
    string vardas, pavarde;
    vector<double> nd;
    double egz;

public:
    /**
     * Konstruktorius
     */
    Studentas() : egz(0) {};
    /**
     * Destruktorius
     */
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
    /**
     * Funkcija, kuri nuskaito studentų informaciją iš failo
     */
    void readStud(ifstream&);

};

#endif //UZD1_KLASES_H