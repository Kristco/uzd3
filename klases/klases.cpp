#include "klases.h"

Studentas::Studentas(ifstream& df)
{
    readStud(df);
}

double Studentas::getGalut() {
    double galut = 0.4 * (accumulate(nd.begin(), nd.end(), 0.0) / 7) + 0.6 * this->egz;
    return galut;
}

void Studentas::readStud(ifstream& df) {
    df >> this->vardas >> this->pavarde;
    nd.resize(7);
    for (int x = 0; x < 7; x++)
    {
        df >> this->nd.at(x);
    }
    df >> this->egz;
}
