# Studentų galutinio įvertinimo skaičiavimo programa
## Programos aprašymas
Programos tikslas: apskaičiuoti pateiktų studentų galutinį įvertinimą, pagal nurodytą formulę:
### galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas

Programa sugeneruoja 5 atsitiktinius studentų sąrašų failus, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.

Vartotojas gali pasirinkti vieną iš keturių pasirinkimų:
1. Įvesti studento duomenis su nurodytu namų darbų skaičiumi(n)
2. Įvesti studento duomenis be nurodyto namų darbų skaičiaus(n)
3. Įvesti studento duomenis, kur namų darbų ir egzamino balai yra automatikšai sugeneruojami
4. Įvesti studento duomenis iš failo

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

Toliau vartotojas gali pasirinkti, ar rezultatus rikiuoti pagal studentų vardus ar pavardes.

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

## Efektyvumas
Programos efektyvumas buvo testuotas su 3 tekstiniais failais:
|         Failas        |  Laikas  |
------------------------|----------
|studentai10000.txt     |  0.305s |
|studentai100000.txt    |  2.805s |
|studentai1000000.txt   |  23.414s|

P.S. Rezultatai buvo vedami į tekstinį failą.

Programos efektyvumas buvo testuojamas 3 kartus, naudojant sugeneruotus failus, kur ND skaičius yra 10.
Testavome 3 dalykus:
- Duomenų nuskaitymą iš failo.
- Studentų rūšiavimą į dvi grupes.
- Duomenų išvedimą į du naujus failus.

| Įrašų skaičius | Vid. laikas |
-----------------|-------------
|1000            |    16 ms    |
|10 000          |    588 ms   |
|100 000         |    636 ms   |
|1 000 000       |    1.586s   |
|10 000 000      |    11.1s    |



