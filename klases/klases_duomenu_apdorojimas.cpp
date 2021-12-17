#include "klases_duomenu_apdorojimas.h"


void klases_failo_nuskaitymas(vector<Studentas>& stud, int n, vector<double>& laikas) {
    stud.reserve(n);
    ifstream df;
    string failas = "Studentai" + to_string(n) + ".txt";
    df.open(failas);
    Studentas laik;
    auto start = system_clock::now();
    df.ignore(65536,'\n');
    for(int i = 0; i < n; i++)
    {
        laik.readStud(df);
        stud.push_back(laik);
    }
    df.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}


void klases_grupes_skirstymas(vector<Studentas> &stud, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas) {
    auto start = system_clock::now();
    for (auto iter : stud) {
        if (iter.getGalut() < 5) {
            fail.push_back(iter);
        } else {
            laim.push_back(iter);
        }
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(1) = diff.count();
}

void klases_spausdinimas(int n, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas) {
    ofstream lf("Laimetojai_klases" + to_string(n) + ".txt");
    ofstream ff("Luzeriai_klases" + to_string(n) + ".txt");
    auto start = system_clock::now();
    lf << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    lf << "--------------------------------------------------------" << "\n";
    ff << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << "\n";
    ff << "--------------------------------------------------------" << "\n";
    for (Studentas elem : fail) {
        ff << elem.getVardas() << " " << elem.getPavarde() << " " << fixed << setprecision(2) << elem.getGalut() << "\n";
    }
    for (Studentas elem : laim) {
        lf << elem.getVardas() << " " << elem.getPavarde() << " " << fixed << setprecision(2) << elem.getGalut() << "\n";
    }
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(2) = diff.count();
}

random_device rndv;
mt19937 mersenne_engines {rndv()};
uniform_int_distribution<int> distv {1, 10};


int gen() {
    return distv(mersenne_engines);
}

void generavimas(int kiekis, vector<double>& laikas)
{
    string vardas = "Vardas", pavarde = "Pavarde";
    ofstream rf("Studentai" + to_string(kiekis) + ".txt");
    auto start = system_clock::now();
    rf << setw(18) << left << "Vardas" << setw(18) << "Pavarde";
    for(int x = 1; x <= 7; x++)  rf << setw(8) << left << "ND" + to_string(x);
    rf << "Egz." << "\n";
    for(int x = 1; x <= kiekis; x++)
    {
        rf << setw(18) << left << "Vardas" + to_string(x) << setw(18) << "Pavarde" + to_string(x);
        for(int y = 0; y < 7; y++)  rf << setw(8) << left << gen();
        rf << gen() << "\n";
    }
    rf.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}