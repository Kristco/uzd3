#include "strukturos.h"
#include "duomenu_apdorojimas.h"
#include "failu_tvarkymas.h"


int main()
{
    double sum;
    int studentu_kiekis = 1000;
    vector <double> laikas;
    laikas.resize(4);
    list<Studentas> p; list<Studentas> lam; list<Studentas> fal;
    for(int x = 0; x < 5; x++) {
        sum = 0;
        generavimas(studentu_kiekis, laikas);
        failo_nuskaitymas(p, studentu_kiekis, laikas);
        rusiavimas(p, lam, fal, laikas);
        isvedimas_failas(lam, fal, studentu_kiekis, laikas);
        cout << "Studentu irasu skaicius " << studentu_kiekis << "\n";
        //cout << studentu_kiekis << " irasu skaiciui sugeneruoti uztruko " << laikas.at(0) << " sekundziu \n";
        cout << studentu_kiekis << " nuskaityti is failo sugeneruotus duomenis uztruko " << laikas.at(1) << " sekundziu \n";
        cout << studentu_kiekis << " rusiavimas i 2 skirtingus grupes uztruko " << laikas.at(2) << " sekundziu \n";
        //cout << studentu_kiekis << " isvesti i 2 skirtigus failus uztruko " << laikas.at(3) << " sekundziu \n";
        for (auto &it: laikas) sum += it;
        cout << "Isviso operacija, kai irasu buvo " << studentu_kiekis << ", uztruko: " << sum << " sekundziu \n" << "\n";
        studentu_kiekis *= 10;
    }
    return 0;
}
