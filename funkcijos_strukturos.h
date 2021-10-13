//
// Created by Kri on 10/13/2021.
//

#ifndef UZD1_FUNKCIJOS_STRUKTUROS_H
#define UZD1_FUNKCIJOS_STRUKTUROS_H

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector <double> nd;
    double egz;
    double vid;
    double med;
};

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
};

void failo_nuskaitymas(vector<Studentas>& p, int& n){
    int m, laik;
    double sum = 0;
    string failas;
    cout << "Iveskite 1, 2 arba 3, jeigu norite nuskaityti 10 000, 100 000 arba 1 000 000, dydzio failus atitinkamai \n"; cin >> laik;
    while(laik < 1 || laik > 3 || !cin)
    {
        cin.clear();
        cin.ignore();
        cout << "Kazka neteisingai ivedete, iveskite dar karta \n"; cin >> laik;
    }
    if(laik == 1) failas = "Studentai10000.txt";
    else if (laik == 2) failas = "Studentai100000.txt";
    else failas = "Studentai1000000.txt";
    ifstream df(failas);
    if(df.fail())
    {
        cout << "Failas neegzistuoja arba blogai uzvadintas \n";
        abort();
    }
    df.ignore(65536,'\n');
    while(df.peek() != EOF)
    {
        p.resize(p.size()+ 1);
        df >> p.at(n).vardas >> p.at(n).pavarde;
        m = 0;
        while(df >> laik)
        {
            p.at(n).nd.push_back(laik);
            p.at(n).egz = laik;
            m++;
        }
        if(!df)
        {
            p.at(n).nd.pop_back();
            m--;
            df.clear();
            vidurkis_mediana(p, m, n, sum);
        }
        n++;
    }
    df.close();
};

void ivedimas_ranka(vector<Studentas>& p, int& n){
    char yn = 'n';
    int laik;
    double sum = 0;
    srand(time(NULL));
    char arrand;
    while(yn == 'n') {
        p.resize(p.size() + 1);
        cout << "Iveskite studento varda ir pavarde \n";
        cin >> p.at(n).vardas >> p.at(n).pavarde;
        for (int x = 0; x < 100; x++) {
            cout
                    << "Jeigu norite sugeneruoti namu darbo pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n";
            cin >> arrand;
            if (arrand == 'r' || arrand == 'R') {
                laik = rand() % 10 + 1;
            } else {
                cout << "Ivesti studento namu darbo " << x + 1
                     << " pazymi (1-10), jeigu pazymiai baigesi iveskite 0 \n";
                cin >> laik;
            }
            arrand = 'a';
            while (laik < 0 || laik > 10 || !cin) {
                cin.clear();
                cin.ignore();
                cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
                cin >> laik;
            }
            p.at(n).nd.push_back(laik);
            if (laik == 0) {
                p.at(n).nd.pop_back();
                vidurkis_mediana(p, x, n, sum);
                break;
            }
        }
        cout << "Jeigu norite sugeneruoti egzamino pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n";
        cin >> arrand;
        if (arrand == 'r' || arrand == 'R') {
            p[n].egz = rand() % 10 + 1;
        } else {
            cin.clear();
            cin.ignore();
            cout << "Iveskite egzamino rezultata (1-10) \n";
            cin >> p.at(n).egz;
        }
        while (p.at(n).egz < 0 || p.at(n).egz > 10 || !cin) {
            cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
            cin >> p.at(n).egz;
        }
        cout << "Jei studenai baigesi irasykite, bet koki simboli, jei ne rasykite n" << "\n";
        cin >> yn;
        n++;
    }
};

void isvedimas(vector<Studentas> p, int n){
    cout << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << setw(25) << left << "Galutinis (mediana)" << "\n";
    cout << "--------------------------------------------------------------------------------" << "\n";
    sort(p.begin(), p.end(), palyginimas);
    for(int x = 0; x < n; x++)
    {
        cout << setw(18) << p[x].vardas << setw(18) << p[x].pavarde;
        cout << fixed << setprecision(2) << setw(25) << p[x].vid*0.4 + p[x].egz*0.6 << fixed << setprecision(2) << setw(25) << p[x].med*0.4 + p[x].egz*0.6 << "\n";
    }
};

#endif //UZD1_FUNKCIJOS_STRUKTUROS_H
