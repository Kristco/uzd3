# Užd1 Failų sugeneravimas ir suskirstymas į skirtingas grupes

Ši programa sugeneruoja 5 skirtingų dydžių studentų failus (1 000, 10 000, 100 000, 1 000 000, 10 000 000), kuriuose yra po 7 namų darbus. Apskaičiuoja galutinį pažymį pagal vidurkį ir tada padalina į 2 skirtingus failus. Programos išvedimas yra programos veikimo greičio analizė, kaip greitai programa atlieka tam tikrus veiksmus. Yra naudojama **std::list**

Išvestis atrodo taip:

![image](https://user-images.githubusercontent.com/69794082/137543255-75207caf-ec00-42f6-9acf-9ec45bb9abae.png)

Sistemos parametrai: 
- CPU - 6 Core, 12 Threads, Base clock speed 2,9Ghz
- RAM - 16GB 2666Mhz
- SSD - Read/Write 3500/3000 MB/s

Programos buvo bandomos 5 kartus
Rezultatų vidurkis su **std::vector**:
- 1000 -- 0,0286sec;
- 10000 --  0,0787sec;
- 100000 -- 0,584sec;
- 1000000 -- 5,804sec;
- 10000000 -- 62,89sec.

Rezultatų vidurkis su **std::list**:
- 1000 -- 0,0148sec; (-48%)
- 10000 -- 0,0662sec; (-16%)
- 100000 -- 0,565sec;  (-3%)
- 1000000 -- 5,579sec;  (-4%)
- 10000000 -- 56,71sec.  (-10%)
- 
Vidutiniškai 16% pokytis palyginus su **std::vector**

Komentarai:
Kodas beveik nesiskiria nuo 0.4, tik visur vector buvo pakeisti į list.
