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
    srand(time(NULL));
    int laik;
    char yn = 'n', arrand;
    int n = 0;
    float sum = 0;
    vector <Studentas> stu;
    while(yn == 'n')
    {
        stu.resize(stu.size()+ 1);
        cout << "Iveskite studento varda ir pavarde \n";
        cin >> stu[n].vardas >> stu[n].pavarde;
        for(int x = 0; x < 100; x++)
        {
            cout << "Jeigu norite sugeneruoti namu darbo pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n";
            cin >> arrand;
            if (arrand == 'r' || arrand == 'R')
            {
                laik = rand() % 10 + 1;
            }
            else
            {
                cout << "Ivesti studento namu darbo " << x+1 << " pazymi (1-10), jeigu pazymiai baigesi iveskite 0 \n";
                cin >> laik;
            }
            arrand = 'a';
            sum += laik;
            while(laik < 0 || laik > 10 || !cin)
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
                cin >> laik;
            }
            stu[n].nd.push_back(laik);
            if (laik == 0)
            {
                stu[n].vid = sum/x;
                sort(stu[n].nd.begin(), stu[n].nd.end());
                if(x % 2 != 0)
                {
                    stu[n].med = stu[n].nd[(x/2)+1];
                }
                else 
                {
                    stu[n].med = (stu[n].nd[(x/2)+1] + stu[n].nd[(x/2)])/2;
                }
                break;
            }
        }
        cout << "Jeigu norite sugeneruoti egzamino pazymi, iveskite raide r, jeigu ivesite bet koki kita simboli pazymi galesite ivesti pats \n";
        cin >> arrand;
        if (arrand == 'r' || arrand == 'R')
        {
            stu[n].egz = rand() % 10 + 1;
        }
        else
        {
            cout << "Iveskite egzamino rezultata (1-10) \n";
            cin >> stu[n].egz;
        }
        while(stu[n].egz < 0 || stu[n].egz > 10 || !cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka neteisingai suvedete, bandykite dar karta \n";
            cin >> stu[n].egz;
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
        cout << setw(15) << stu[x].vardas << setw(15) << stu[x].pavarde;
        if(yn == 'm')
            cout << fixed << setprecision(2) << setw(5) << stu[x].med*0.4 + stu[x].egz*0.6 << "\n";
        else
            cout << fixed << setprecision(2) << setw(5) << stu[x].vid*0.4 + stu[x].egz*0.6 << "\n";
    }
    return 0;
}
