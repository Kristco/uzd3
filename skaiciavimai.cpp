#include "strukturos.h"
#include "skaiciavimai.h"

random_device rnd;
mt19937 mersenne_engine {rnd()};
uniform_int_distribution<int> dist {1, 10};

int gen () {
    return dist(mersenne_engine);
}

void vidurkis_galut(list<Studentas>& p){
    double suma = 0;
    p.back().vid = accumulate(p.back().nd.begin(), p.back().nd.end(), suma) / p.back().nd.size();
    p.back().galut = p.back().vid * 0.4 + p.back().egz * 0.6;
}
