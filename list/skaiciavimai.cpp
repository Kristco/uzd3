#include "strukturos.h"
#include "skaiciavimai.h"

random_device rnd;
mt19937 mersenne_engine {rnd()};
uniform_int_distribution<int> dist {1, 10};

int gen () {
    return dist(mersenne_engine);
}

void vidurkis_galut(Studentas& p){
    double suma = 0;
    p.vid = accumulate(p.nd.begin(), p.nd.end(), suma) / p.nd.size();
    p.galut = p.vid * 0.4 + p.egz * 0.6;
}
