#include "vector/strukturos.h"
#include "vector/skaiciavimai.h"


random_device rndv;
mt19937 mersenne_engines {rndv()};
uniform_int_distribution<int> distv {1, 10};


int gen() {
    return distv(mersenne_engines);
}

void vidurkis_galut_vector(vector<Studentas_V>& p, int nd_sk, int studento_sk){
    double suma = 0;
    p.at(studento_sk).vid = accumulate(p.at(studento_sk).nd.begin(), p.at(studento_sk).nd.end(), suma) / nd_sk;
    p.at(studento_sk).galut = p.at(studento_sk).vid * 0.4 + p.at(studento_sk).egz * 0.6;
}