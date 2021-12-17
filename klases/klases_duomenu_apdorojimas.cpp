#include "klases_duomenu_apdorojimas.h"

/**
 * Nuskaito studentus iš pradinio failo
 * @param stud Vectorius, kuriame yra saugoma informacija apie studentą
 * @param n Studentų skaičius
 * @param laikas Vectorius, kuriame yra išsaugomas funkcijos veikimo greitis
 */
void klases_failo_nuskaitymas(vector<Studentas>& stud, int n, vector<double>& laikas) {
    stud.reserve(n);
    ifstream df;
    string failas = "Studentai" + to_string(n) + ".txt";
    df.open(failas);
    Studentas laik;
    auto start = system_clock::now();
    /**
     * Praleidžia pirmą eilutę esančia pradiniame faile
     */
    df.ignore(65536,'\n');
    for(int i = 0; i < n; i++)
    {
        /**
         * Studentas yra nuskaitomas iš failo, naudojant klasės funkciją ir išsaugomas vectoriuje
         */
        laik.readStud(df);
        stud.push_back(laik);
    }
    df.close();
    auto end  = system_clock::now();
    duration<double> diff = end - start;
    laikas.at(0) = diff.count();
}

/**
 * Suskirsto studentus į 2 skirtingas grupes
 * @param stud Vectorius, kuriame yra saugoma informacija apie studentą
 * @param laim Vectorius į kurį surašome studentus, kurių galinis rezultatas yra aukščiau 5
 * @param fail Vectorius į kurį surašome studentus, kurių galinis rezultatas yra žemiau 5
 * @param laikas Vectorius, kuriame yra išsaugomas funkcijos veikimo greitis
 */
void klases_grupes_skirstymas(vector<Studentas> &stud, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas) {
    auto start = system_clock::now();
    for (auto iter : stud) {
        /**
         * Iteruojama per studento vectorių ir suskirstoma į grupes
         */
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
/**
 * Išveda suskirstytus studentus į skirtingus failus
 * @param n Studentų skaičius
 * @param laim Vectorius, kuriame saugomi studentai, kurių galinis rezultatas yra aukščiau 5
 * @param fail Vectorius, kuriame saugomi studentai, kurių galinis rezultatas yra žemiau 5
 * @param laikas Vectorius, kuriame yra išsaugomas funkcijos veikimo greitis
 */
void klases_spausdinimas(int n, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas) {
    /**
     * Sukuriami failai į kuriuos bus išvesti suskirstyti studentai
     */
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

/**
 * Atsitiktinių rezultatų generavimo aprašas
 */
random_device rndv;
mt19937 mersenne_engines {rndv()};
uniform_int_distribution<int> distv {1, 10};


int gen() {
    return distv(mersenne_engines);
}

/**
 * Sugeneruoja visus studentus ir jų pažymius
 * @param kiekis Studentų kiekis
 * @param laikas Vectorius, kuriame yra išsaugomas funkcijos veikimo greitis
 */
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