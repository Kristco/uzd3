#include "klases/klases.h"
#include "klases/klases_duomenu_apdorojimas.h"


int main()
{
    int kartai = 2;
    int studentu_kiekis = 100000;
    vector <double> laikas;
    laikas.resize(4);
    cout << "------------------------------------------------------------------------------------- \n";
    vector<Studentas> v_klases; vector<Studentas> laim_klases; vector<Studentas> fail_klases;
    for (int x = 0; x < kartai; x++) {
        generavimas(studentu_kiekis, laikas);
        klases_failo_nuskaitymas(v_klases, studentu_kiekis, laikas);
        klases_grupes_skirstymas(v_klases, laim_klases, fail_klases, laikas);
        klases_spausdinimas(studentu_kiekis, laim_klases, fail_klases, laikas);
        cout << studentu_kiekis << " nuskaitymas i vektoriu naudojant klases uztruko " << laikas.at(0) << " sekundziu \n";
        cout << studentu_kiekis << " rusiavimas i 2 skirtingus grupes naudojant klases uztruko " << laikas.at(1) << " sekundziu \n";
        cout << studentu_kiekis << " isvedimas su klasemis uztruko " << laikas.at(2) << " sekundziu \n";
        cout << "------------------------------------------------------------------------------------- \n";
        v_klases.clear(); laim_klases.clear(); fail_klases.clear();
        studentu_kiekis *= 10;
    }
}