# Užd2 Naujų tipų kūrimas ir jų naudojimas

Ši programa sugeneruoja 5 skirtingų dydžių studentų failus (1 000, 10 000, 100 000, 1 000 000, 10 000 000), kuriuose yra po 7 namų darbus. Apskaičiuoja galutinį pažymį pagal vidurkį ir tada padalina į 2 skirtingus grupes. Programos išvedimas yra programos veikimo greičio analizė naudojant klases ir struktūras.


Sistemos parametrai:
- CPU - 6 Core, 12 Threads, 2,9Ghz
- RAM - 16GB 2666Mhz
- SSD - Read/Write 3500/3000 MB/s

5 kartų greičio vidurkiai:

![image](https://user-images.githubusercontent.com/69794082/146551731-6080f24c-1a67-44a9-9c75-e5088d746f7c.png)

Skirstimas į grupes užtrunka beveik 2x ilgiau naudojant klases negu su struktūromis, kitos užduotis veikia panašiu greičiu arba klasėse truputi greičiau

## Optimizacijos lygiai:
O1:

![image](https://user-images.githubusercontent.com/69794082/146551852-8e22012b-774b-4635-af59-5b78cd021da8.png)

O2:

![image](https://user-images.githubusercontent.com/69794082/146551982-f0aa5c26-0d84-4571-a877-68b815e430e9.png)

O3:

![image](https://user-images.githubusercontent.com/69794082/146552125-3529a391-7d92-436f-94e9-1669e865b220.png)

Optimizacija labai padėjo rušiavimui į skirtingas grupes, sutrumpinant tą laiką, ir klasėse ir struktūrose, per puse, ir šiaip pagreitino laiką bendrai, tačiau nėra žymaus skirtumo tarp skirtingų optimizacijos lygių.


Komentarai:
Buvo susidurta su sunkumais nuskaitant klases.

