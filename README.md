# Studentų galutinio įvertinimo skaičiavimo programa
## Programos aprašymas
V0.3 turi 2 programos versijas: vector ir list. Programos versijos skiriasi tik tuo, kad naudojami skirtingi konteineriai, saugant duomenis.

Programos tikslas: apskaičiuoti pateiktų studentų galutinį įvertinimą, pagal nurodytą formulę:
### galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas

Programa sugeneruoja 5 atsitiktinius studentų sąrašų failus, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.

Vartotojas gali pasirinkti vieną iš keturių pasirinkimų:
1. Įvesti studento duomenis su nurodytu namų darbų skaičiumi(n)
2. Įvesti studento duomenis be nurodyto namų darbų skaičiaus(n)
3. Įvesti studento duomenis, kur namų darbų ir egzamino balai yra automatikšai sugeneruojami
4. Įvesti studento duomenis iš failo

Jei vartotojas pasirenka (1-3) funcijas, tai ekrane yra atspausdinama kiekvieno studento saugojimo atmintyje adresas.

_Vieta atmintyje_


Įvedus duomenis, vartotojas gali pasirinkti, pagal kokį kriterijų nori surušiuoti studentų duomenis į failus vargsiukai.txt ir kietiakai.txt. 
1. Pagal vidurkį.
2. Pagal medianą.

Studentai į grupes skirtstomi pagal:
- Studentai, kurių galutinis balas < 5.0 yra “vargšiukai”.
- Studentai, kurių galutinis balas >= 5.0 galėtume yra "kietiakiai".

Toliau vartotojas gali pasirinkti, pagal kokius kriterijus bus apskaičiuotas ir atspausdintas galutinis įvertinimas:
1. Pagal vidurkį
2. Pagal medianą
3. Pagal vidurkį ir medianą

Toliau vartotojas gali pasirinkti, ar rezultatus rikiuoti pagal studentų vardus, pavardes ar galutinį rezultatą.

Po to vartotojas gali pasirinkti ar duomenis spausdinti į ekraną ar į failus.

Galiausiai vartotojas gali pasirinkti, ar nori kad į ekraną atspausdintų visus studentų duomenis.

Programos išvedimo forma:
Vardas  Pavardė      Gautinis (Vid.)  Galutinis (Med.)
Arvydas Sabonis      x.xx             x.xx
Rimas   Kurtinaitis  y.yy             y.yy
...

Gale programos atspausdinama, kiek laiko (ms) užtruko failo testavimas.

## Klaidų tikrinimas
- Programa tikrina skaičių įvedimą, neleidžiant įvesti ne skaitmenų. Pvz.: a5, penki.
- Programa tikrina ar vartotojas nieko neįvedė t.y. paspaudė "enter" mygtuką.
- Programa neleidžia įvesti balų, kurie nėra sveikieji skaičiai intervale [1; 10].
- Programa įvedus vardą ir pavardę praleidžia simbolius faile, kurie nėra skaitmenys.
- Programa praleidžia skaičius faile, kurie nėra sveikieji skaičiai intervale [1; 10].

Padarius klaidą, vartotjui pranešama, kad buvo padarytą klaida ir leidžia įvesti iš naujo.

## Spartos tyrimas
**Testavimo sistemos parametrai:**
- Apple M3 Pro (11-core CPU)
- 18 GB RAM
- 512 GB SSD


Versijų sparta buvo matuojama su 5 tekstiniais failais, kuriose ND skaičius yra 10:
- 1000.txt
- 10000.txt
- 100000.txt
- 1000000.txt
- 10000000.txt

Matavome 3 dalykus:
- Duomenų nuskaitymą iš failo.
- Studentų rūšiavimą į dvi grupes.
- Duomenų išvedimą į du naujus failus.

<b>Matavimai buvo atliekami 5 kartus ir apskaičiuotas vidurkis.</b>

### Vector versija

| Įrašų skaičius | Nuskaitymas | Rušiavimas | Išvedimas | Bendras laikas |
-----------------|-------------|------------|-----------|----------------|
|1000            |  0.002 s    | 0 s        | 0.003 s   |    0.005 s     |
|10 000          |   0.006 s   |  0.001 s   | 0.033 s   |     0.04 s     |
|100 000         |   0.051 s   |  0.015 s   |  0.332 s  |     0.398 s    | 
|1 000 000       |   0.494 s   |   0.044 s  |    0.5 s  |    1.038 s     |
|10 000 000      |   4.885 s   |  0.465 s   |  5.092 s  |    10.442 s    |

### List versija

| Įrašų skaičius | Nuskaitymas | Rušiavimas | Išvedimas | Bendras laikas |
-----------------|-------------|------------|-----------|----------------|
|1000            |   0.003 s   |  0 s       |  0.003 s  |    0.006 s     |
|10 000          |    0.014 s  |   0.005 s  |  0.042 s  |    0.061 s     |
|100 000         |    0.129 s  |  0.069 s   |  0.432 s  |    0.63 s      | 
|1 000 000       |   1.289 s   |   0.114 s  |  0.705 s  |    2.108 s     |
|10 000 000      |  12.786 s   |  1.407 s   |   8.59 s  |    22.783 s    |

### Išvados

Abejoms versijoms atlikus spartos tyrimą, matome, kad visais atvejais *Vector* versija buvo greitesnė. Su mažesniu įrašų skaičiumi abiejų versijų greitis labai neišsiskiria, tačiau lyginant 1 mln. ir 10 mln. įrašus, pastebime, kad naudojant vektoriaus konteinerio tipą funkcijos veikia dvigubai greičiau.



