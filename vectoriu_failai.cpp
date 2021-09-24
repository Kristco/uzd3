#include <bits/stdc++.h>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector <double> nd;
    double egz;
    double vid;
    double med;
};

int main()
{
    char yn = 'n';
    int n = 0, m = 0, laik;
    double sum = 0;
    cout << "Jeigu norite skaityti is failo iveskite f/F, bet koks kitas simbolis leis ivedineti ranka duomenis \n"; cin >> yn;
    Studentas *p = new Studentas[2000000];
    if(yn == 'f' || yn == 'F')
    {
        cout << "Iveskite 1, 2 arba 3, jeigu norite nuskaityti 10 000, 100 000 arba 1 000 000, dydzio failus atitinkamai \n"; cin >> laik;
        while(laik < 1 || laik > 3 || !cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka neteisingai ivedete, iveskite dar karta \n"; cin >> laik;
        }
        string fail;
        if(laik == 1) fail = "Studentai10000.txt";
        else if (laik == 2) fail = "Studentai100000.txt";
        else fail = "Studentai1000000.txt";
        cout << setw(18) << left << "Vardas" << setw(18)  << left << "Pavarde" << setw(25) << left << "Galutinis (vidurkis)" << setw(25) << left << "Galutinis (mediana)" << "\n";
        cout << "--------------------------------------------------------------------------------" << "\n";
        ifstream df(fail);
        df.ignore(65536,'\n');
        while(df.peek() != EOF)
        {
            df >> p[n].vardas >> p[n].pavarde;
            cout << setw(18) << p[n].vardas << setw(18) << p[n].pavarde;
            while(df >> laik)
            {
                p[n].nd.push_back(laik);
                sum += laik;
                p[n].egz = laik;
                m++;
            }
            if(!df)
            {
                sum -= p[n].egz;
                p[n].nd.pop_back();
                m--;
                df.clear();
                p[n].vid = sum/(m);
                sort(p[n].nd.begin(), p[n].nd.end());
                if(m % 2 != 0)
                {
                   p[n].med = p[n].nd[(m/2)];
                }
                else
                {
                    p[n].med = (p[n].nd[(m/2)] + p[n].nd[(m/2)-1])/2;
                }
                cout << fixed << setprecision(2) << setw(25) << p[n].vid*0.4 + p[n].egz*0.6 << fixed << setprecision(2) << setw(25) << p[n].med*0.4 + p[n].egz*0.6 << "\n";
                m = 0;
            }
            sum = 0; n++;
        }
        df.close();
        delete[] p;
        return 0;
    }
    else
    {
    srand(time(NULL));
    char arrand;
    yn = 'n';
    while(yn == 'n')
    {
        cout << "Iveskite studento varda ir pavarde \n"; cin >> p[n].vardas >> p[n].pavarde;
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
            p[n].nd.push_back(laik);
            if (laik == 0)
            {
                p[n].vid = sum/x;
                sort(p[n].nd.begin(), p[n].nd.end());
                if(x % 2 != 0)
                {
                    p[n].med = p[n].nd[(x/2)+1];
                }
                else
                {
                    p[n].med = (p[n].nd[(x/2)+1] + p[n].nd[(x/2)])/2;
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
            cout << "Iveskite egzamino rezultata (1-10) \n"; cin >> p[n].egz;
        }
        while(p[n].egz < 0 || p[n].egz > 10 || !cin)
        {
            cout << "Kazka neteisingai suvedete, bandykite dar karta \n"; cin >> p[n].egz;
        }
        cout << "Jei studenai baigesi irasykite, bet koki simboli, jei ne rasykite n" << "\n"; cin >> yn;
        sum = 0; n++;
    }
        cout << "Jeigu norite galutinio pazymio su mediana, rasykite m/M, jeigu vidurkio, bet koki kita simboli \n"; cin >> yn;
        cout << setw(15) << left << "Vardas" << setw(15)  << left << "Pavarde";
        if (yn == 'm' || yn == 'M') cout << setw(5) << "Galutinis (mediana)" << "\n";
        else cout << setw(5) << "Galutinis (vidurkis)" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        for(int x = 0; x < n; x++)
        {
            cout << setw(15) << p[x].vardas << setw(15) << p[x].pavarde;
            if(yn == 'm' || yn == 'M') cout << fixed << setprecision(2) << setw(5) << p[x].med*0.4 + p[x].egz*0.6 << "\n";
            else cout << fixed << setprecision(2) << setw(5) << p[x].vid*0.4 + p[x].egz*0.6 << "\n";
        }
        delete[] p;
    }
    return 0;
}
