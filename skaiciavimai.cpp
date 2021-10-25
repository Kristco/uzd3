#include "strukturos.h"

bool palyginimas(const Studentas pirmas, const Studentas antras)
{
    return pirmas.vardas < antras.vardas;
}

void vidurkis_mediana(vector<Studentas>& p, int nd_sk, int studento_sk, double& suma){
    p.at(studento_sk).vid = accumulate(p.at(studento_sk).nd.begin(), p.at(studento_sk).nd.end(), suma) / nd_sk;
    sort(p.at(studento_sk).nd.begin(), p.at(studento_sk).nd.end());
    if(nd_sk % 2 != 0)  p.at(studento_sk).med = p.at(studento_sk).nd[(nd_sk / 2)];
    else    p.at(studento_sk).med = (p.at(studento_sk).nd[(nd_sk / 2)] + p.at(studento_sk).nd[(nd_sk / 2) - 1]) / 2;
    suma = 0;
}
