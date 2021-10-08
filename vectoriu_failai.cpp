#include <bits/stdc++.h>

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

int main()
{
    char yn = 'n';
    int n = 0, m = 0, laik;
    double sum = 0;
    cout << "Jeigu norite skaityti is failo iveskite f/F, bet koks kitas simbolis leis ivedineti ranka duomenis \n"; cin >> yn;
    vector<Studentas> p;
    if(yn == 'f' || yn == 'F')
    {
        cout << "Iveskite 1, 2 arba 3, jeigu norite nuskaityti 10 000, 100 000 arba 1 000 000, dydzio failus atitinkamai \n"; cin >> laik;
        while(laik < 1 || laik > 3 || !cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka neteisingai ivedete, iveskite dar karta \n"; cin >> laik;
        }
        string failas;
        if(laik == 1) failas = "Studentai10000.txt";
        else if (laik == 2) failas = "Studentai100000.txt";
        else failas = "Studentai1000000.txt";
        ifstream df(failas);
        if(df.fail())
        {
        cout << "Failas neegzistuoja arba blogai uzvadintas \n";
        return 0;
        }
        cout << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << setw(25) << left << "Galutinis (mediana)" << "\n";
        cout << "--------------------------------------------------------------------------------" << "\n";
        df.ignore(65536,'\n');
        while(df.peek() != EOF)
        {
            p.resize(p.size()+ 1);
            df >> p.at(n).vardas >> p.at(n).pavarde;
            while(df >> laik)
            {
                p.at(n).nd.push_back(laik);
                sum += laik;
                p.at(n).egz = laik;
                m++;
            }
            if(!df)
            {
                sum -= p.at(n).egz;
                p.at(n).nd.pop_back();
                m--;
                df.clear();
                p.at(n).vid = sum/(m);
                sort(p.at(n).nd.begin(), p.at(n).nd.end());
                if(m % 2 != 0)
                {
                   p.at(n).med = p.at(n).nd[(m/2)];
                }
                else
                {
                    p.at(n).med = (p.at(n).nd[(m/2)] + p.at(n).nd[(m/2)-1])/2;
                }
                m = 0;
            }
            sum = 0; n++;
        }
        df.close();
        sort(p.begin(), p.end(), palyginimas);
        for(int x = 0; x < n; x++)
        {
            cout << setw(18) << p[x].vardas << setw(18) << p[x].pavarde;
            cout << fixed << setprecision(2) << setw(25) << p[x].vid*0.4 + p[x].egz*0.6 << fixed << setprecision(2) << setw(25) << p[x].med*0.4 + p[x].egz*0.6 << "\n";
        }
        return 0;
    }
    else
    {
    srand(time(NULL));
    char arrand;
    yn = 'n';
    while(yn == 'n')
    {
        p.resize(p.size()+ 1);
        cout << "Iveskite studento varda ir pavarde \n"; cin >> p.at(n).vardas >> p.at(n).pavarde;
        for(int x = 0; x < 100; x++)
        {
            cout << "Jeigu norite sugeneruoti namu darbo pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n"; cin >> arrand;
            if (arrand == 'r' || arrand == 'R')
            {
                laik = rand() % 10 + 1;
            }
            else
            {
                cout << "Ivesti studento namu darbo " << x+1 << " pazymi (1-10), jeigu pazymiai baigesi iveskite 0 \n"; cin >> laik;
            }
            arrand = 'a'; sum += laik;
            while(laik < 0 || laik > 10 || !cin)
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka neteisingai suvedete, bandykite dar karta \n"; cin >> laik;
            }
            p.at(n).nd.push_back(laik);
            if (laik == 0)
            {
                p.at(n).vid = sum/x;
                sort(p.at(n).nd.begin(), p.at(n).nd.end());
                if(x % 2 != 0)
                {
                    p.at(n).med = p.at(n).nd[(x/2)+1];
                }
                else
                {
                    p.at(n).med = (p.at(n).nd[(x/2)+1] + p.at(n).nd[(x/2)])/2;
                }
                break;
            }
        }
        cout << "Jeigu norite sugeneruoti egzamino pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n"; cin >> arrand;
        if (arrand == 'r' || arrand == 'R')
        {
            p[n].egz = rand() % 10 + 1;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Iveskite egzamino rezultata (1-10) \n"; cin >> p.at(n).egz;
        }
        while(p.at(n).egz < 0 || p.at(n).egz > 10 || !cin)
        {
            cout << "Kazka neteisingai suvedete, bandykite dar karta \n"; cin >> p.at(n).egz;
        }
        cout << "Jei studenai baigesi irasykite, bet koki simboli, jei ne rasykite n" << "\n"; cin >> yn;
        sum = 0; n++;
    }
        cout << "Jeigu norite galutinio pazymio su mediana, rasykite m/M, jeigu vidurkio, bet koki kita simboli \n"; cin >> yn;
        cout << setw(15) << left << "Vardas" << setw(15)  << left << "Pavarde";
        if (yn == 'm' || yn == 'M') cout << setw(5) << "Galutinis (mediana)" << "\n";
        else cout << setw(5) << "Galutinis (vidurkis)" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        sort(p.begin(), p.end(), palyginimas);
        for(int x = 0; x < n; x++)
        {
            cout << setw(15) << p[x].vardas << setw(15) << p[x].pavarde;
            if(yn == 'm' || yn == 'M') cout << fixed << setprecision(2) << setw(5) << p[x].med*0.4 + p[x].egz*0.6 << "\n";
            else cout << fixed << setprecision(2) << setw(5) << p[x].vid*0.4 + p[x].egz*0.6 << "\n";
        }
    }
    return 0;
}
