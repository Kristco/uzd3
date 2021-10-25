#include "strukturos.h"
#include "skaiciavimai.h"

random_device rnd;
mt19937 mersenne_engine {rnd()};
uniform_int_distribution<int> dist {1, 10};

int gen () {
    return dist(mersenne_engine);
}

void vidurkis_galut(vector<Studentas>& p, int nd_sk, int studento_sk){
    double suma = 0;
    p.at(studento_sk).vid = accumulate(p.at(studento_sk).nd.begin(), p.at(studento_sk).nd.end(), suma) / nd_sk;
    p.at(studento_sk).galut = p.at(studento_sk).vid * 0.4 + p.at(studento_sk).egz * 0.6;
}
