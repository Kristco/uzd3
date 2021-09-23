#include <bits/stdc++.h>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    double nd[100];
    int egz;
    float vid;
    float med;
};

int main()
{
    char yn = 'n';
    int n = 0;
    float sum = 0;
    Studentas *p = new Studentas[10];
    while(yn == 'n')
    {
        cin >> p[n].vardas >> p[n].pavarde;
        for(int x = 0; x < 10; x++)
        {
            cin >> p[n].nd[x];
            sum += p[n].nd[x];
            if (p[n].nd[x] == 0)
            {
                p[n].vid = sum/x;
                sort(p[n].nd, p[n].nd+x);
                if(x % 2 != 0)
                {
                    p[n].med = p[n].nd[x/2];
                }
                else
                {
                    p[n].med = (p[n].nd[x/2] + p[n].nd[(x/2)-1])/2;
                }
                break;
            }
        }
        cin >> p[n].egz;
        cout << "ar baigesi studentai?  y/n" << "\n";
        cin >> yn;
        sum = 0;
        n++;
    }
    cout << "Galutiniai pazymiai su vidurkiu ar mediana? v/m";
    cin >> yn; cout << "\n";
    cout << setw(15) << left << "Vardas" << setw(15)  << left << "Pavarde";
    if (yn == 'm') 
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
