#include "list/strukturos.h"
#include "list/duomenu_apdorojimas.h"
#include "list/failu_tvarkymas.h"

#include "vector/strukturos_vector.h"
#include "vector/duomenu_apdorojimas_vector.h"
#include "vector/failu_tvarkymas_vector.h"




int main()
{
    double sum;
    int studentu_kiekis = 1000;
    vector <double> laikas;
    laikas.resize(4);
    ofstream rf("laikas.txt");
    list<Studentas> p; list<Studentas> lam; list<Studentas> fal;
    cout << "List:---------- \n \n";
    for(int x = 0; x < 3; x++) {
        sum = 0;
        generavimas(studentu_kiekis, laikas);
        failo_nuskaitymas(p, studentu_kiekis, laikas);
        rusiavimas(p, lam, fal, laikas);
        isvedimas_failas(lam, fal, studentu_kiekis, laikas);
        cout << "Studentu irasu skaicius " << studentu_kiekis << "\n";
        cout << studentu_kiekis << " nuskaityti is failo sugeneruotus duomenis uztruko " << laikas.at(1) << " sekundziu \n";
        cout << studentu_kiekis << " rusiavimas i 2 skirtingus grupes uztruko " << laikas.at(2) << " sekundziu \n";
        sum = laikas.at(1)+laikas.at(2);
        cout << "Isviso operacija, kai irasu buvo " << studentu_kiekis << ", uztruko: " << sum << " sekundziu \n" << "\n";
        rf << studentu_kiekis << " " << fixed << setprecision(5) << sum << "\n";
        studentu_kiekis *= 10;
    }

    cout << "Vector:--------- \n \n";

    studentu_kiekis = 1000;
    vector<Studentas_V> v; vector<Studentas_V> lem; vector<Studentas_V> fel;
    for(int x = 0; x < 3; x++) {
        sum = 0;
        generavimas_vector(studentu_kiekis, laikas);
        failo_nuskaitymas_vector(v, studentu_kiekis, laikas);
        rusiavimas_vector(v, lem, fel, studentu_kiekis, laikas);
        isvedimas_failas_vector(lem, fel, studentu_kiekis, laikas);
        cout << "Studentu irasu skaicius " << studentu_kiekis << "\n";
        //cout << studentu_kiekis << " irasu skaiciui sugeneruoti uztruko " << laikas.at(0) << " sekundziu \n";
        cout << studentu_kiekis << " nuskaityti is failo sugeneruotus duomenis uztruko " << laikas.at(1) << " sekundziu \n";
        cout << studentu_kiekis << " rusiavimas i 2 skirtingus grupes uztruko " << laikas.at(2) << " sekundziu \n";
        //cout << studentu_kiekis << " isvesti i 2 skirtigus failus uztruko " << laikas.at(3) << " sekundziu \n";
        sum = laikas.at(1)+laikas.at(2);
        cout << "Isviso operacija, kai irasu buvo " << studentu_kiekis << ", uztruko: " << sum << " sekundziu \n" << "\n";
        studentu_kiekis *= 10;
    }
}