#include <bits/stdc++.h>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector <double> nd;
    float egz;
    float vid;
    float med;
};

int main()
{
    int laik;
    char yn = 'n';
    int n = 0;
    float sum = 0;
    Studentas *p = new Studentas[100];
    while(yn == 'n')
    {
        cout << "Ivesti varda ir pavarde \n";
        cin >> p[n].vardas >> p[n].pavarde;
        for(int x = 0; x < 100; x++)
        {
            cout << "Ivesti studento namu darbo " << x+1 << " pazymi (1-10), jeigu pazymiai baigesi iveskite 0 \n";
            cin >> laik;
            sum += laik;
            while(laik < 0 || laik > 10 || !cin)
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
                cin >> laik;
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
        cout << "Iveskite egzamino rezultata (1-10) \n";
        cin >> p[n].egz;
        while(p[n].egz < 0 || p[n].egz > 10 || !cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
            cin >> p[n].egz;
        }
        cout << "Jei studenai baigesi irasykite, bet koki simboli, jei ne rasykite n" << "\n";
        cin >> yn;
        sum = 0;
        n++;
    }
    cout << "Jeigu norite galutinio pazymio su mediana, rasykite m/M, jeigu vidurkio, bet koki kita simboli \n";
    cin >> yn;
    cout << setw(15) << left << "Vardas" << setw(15)  << left << "Pavarde";
    if (yn == 'm' || yn == 'M')
        cout << setw(5) << "Galutinis (mediana)" << "\n";
    else
        cout << setw(5) << "Galutinis (vidurkis)" << "\n";
    cout << "-------------------------------------------------------------" << "\n";
    for(int x = 0; x < n; x++)
    {
        cout << setw(15) << p[x].vardas << setw(15) << p[x].pavarde;
        if(yn == 'm')
            cout << fixed << setprecision(2) << setw(5) << p[x].med*0.4 + p[x].egz*0.6 << "\n";
        else
            cout << fixed << setprecision(2) << setw(5) << p[x].vid*0.4 + p[x].egz*0.6 << "\n";
    }
    delete[] p;
    return 0;
}
