#include <bits/stdc++.h>

using namespace std;

random_device rnd;
mt19937 mersenne_engine {rnd()};
uniform_int_distribution<int> dist {1, 10};

int gen () {
    return dist(mersenne_engine);
};

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
};

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

void generavimas(vector<Studentas>& p, int kiekis){
    p.resize(kiekis+1);
    string vardas = "Vardas", pavarde = "Pavarde";
    for(int x = 1; x <= kiekis; x++)
    {
        p.at(x).nd.resize(10);
        p.at(x).vardas = vardas + to_string(x);
        p.at(x).pavarde = pavarde + to_string(x);
        generate(begin(p.at(x).nd), end(p.at(x).nd), gen);
        /*cout << p.at(x).vardas << " " << p.at(x).pavarde << "\n";
        for(int y = 0; y < 10; y++)
        {
            cout << p.at(x).nd[y] << " ";
        }
        cout << "\n";*///Testavimas ar generuoja ir kiek isveda
    }
};

int main()
{
    vector<Studentas> p;
    generavimas(p, 10);
    return 0;
}
