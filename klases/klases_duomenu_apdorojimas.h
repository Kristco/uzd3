#ifndef UZD1_KLASES_DUOMENU_APDOROJIMAS_H
#define UZD1_KLASES_DUOMENU_APDOROJIMAS_H

#include "klases.h"

void klases_failo_nuskaitymas(vector<Studentas>& stud, int n, vector<double>& laikas);

void klases_grupes_skirstymas(vector<Studentas> &stud, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas);

void klases_spausdinimas(int n, vector<Studentas> &laim, vector<Studentas> &fail, vector<double>& laikas);

#endif //UZD1_KLASES_DUOMENU_APDOROJIMAS_H
