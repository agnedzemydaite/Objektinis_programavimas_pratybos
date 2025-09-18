# Studentų galutinio įvertinimo skaičiavimo programa
## Programos aprasymas
Programos tikslas: apskaičiuoti pateiktų studentų galutinį įvertinimą, pagal nurodytą formulę:
### galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas

Vartotojas gali pasirinkti vieną iš keturių pasirinkimų:
1. Įvesti studento duomenis su nurodytu namų darbų skaičiumi(n)
2. Įvesti studento duomenis be nurodyto namų darbų skaičiaus(n)
3. Įvesti studento duomenis, kur namų darbų ir egzamino balai yra automatikšai sugeneruojami
4. Įvesti studento duomenis iš failo

Įvedus duomenis, vartotojas gali pasirinkti, pagal kokius kriterijus bus apskaičiuotas ir atspausdintas galutinis įvertinimas:
1. Pagal vidurkį
2. Pagal medianą
3. Pagal vidurkį ir medianą

Galiausiai vartotojas gali pasirinkti, ar rezultatus rikiuoti pagal studentų vardus ar pavardes.

Programos išvedimo forma:
Vardas  Pavardė      Gautinis (Vid.)  Galutinis (Med.)
Arvydas Sabonis      x.xx             x.xx
Rimas   Kurtinaitis  y.yy             y.yy
...

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
|studentai10000.txt     |  0.305s. |
|studentai100000.txt    |  2.805s. |
|studentai1000000.txt   |  23.414s.|

P.S. Rezultatai buvo vedami į tekstinį failą.

## Dokumentai

Programa
- v0.1.

Tekstiniai failai
- kursiokai.txt
- studentai10000.txt



