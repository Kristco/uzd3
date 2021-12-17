#include "klases.h"

Studentas::Studentas(ifstream& df)
{
    readStud(df);
}

/**
 * Apskaičiuoja galutinį pazimį, kuris susideda 40% iš namų darbų ir 60% iš egzamino rezultato
 */
double Studentas::getGalut() {
    double galut = 0.4 * (accumulate(nd.begin(), nd.end(), 0.0) / 7) + 0.6 * this->egz;
    return galut;
}

/**
 * Nuskaito studento vardą, pavardę bei namų darbų ir egzamino rezultatus iš failo
 * @param df ifstream kintamasis
 */
void Studentas::readStud(ifstream& df) {
    df >> this->vardas >> this->pavarde;
    nd.resize(7);
    for (int x = 0; x < 7; x++)
    {
        df >> this->nd.at(x);
    }
    df >> this->egz;
}