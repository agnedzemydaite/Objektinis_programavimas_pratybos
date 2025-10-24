#include "ivestys.h"

using std::string;
using std::list;
using std::function;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

studentas ivest_su_n(){
    
    int n, laik_paz, sum = 0;
    studentas s;
    cout << "Iveskite studento duomenis" << endl;
    cout << "Vardas: "; s.var = vardo_iv();
    cout << "Pavarde: "; s.pav = vardo_iv();
    cout << "Kiek pazymiu turi studentas: " << s.var << " " << s.pav << ": "; n = n_iv("Kiek pazymiu turi studentas:");
    
    if(n != 0) cout << "Iveskite studento pazymius: " << endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << " "; laik_paz = skaiciu_iv(to_string(i+1));
        s.paz.push_back(laik_paz);
        sum += laik_paz;
    }
    
    cout << "Iveskite egzamino pazymi: "; s.egz = skaiciu_iv("Iveskite egzamino pazymi:");
    s.gal_vid = vidurkis(s, n, sum);
    s.gal_med = mediana(s, n);
    
    return s;
}

studentas ivest_be_n(){
    int n = 0, paz, sum = 0;
    string laik_paz;
    studentas s;
    cout << "Iveskite studento duomenis" << endl;
    cout << "Vardas: "; s.var = vardo_iv();
    cout << "Pavarde: "; s.pav = vardo_iv();
    cout << "Iveskite studento pazymius: " << endl;
    
    while(true){
        cout << n + 1 << " ";
        getline(cin, laik_paz);
        if(laik_paz.empty()) break;
        
        else{
            bool neskaicius = false;
            for(char ch : laik_paz){
                if(!isdigit(ch)){
                    neskaicius = true;
                    break;
                }
            }
            
            if(neskaicius == true){
                cout << "Padarete klaida, bandykite is naujo " << endl;
                continue;
            }
            
            paz = stoi(laik_paz);
            if( paz == 0 || paz > 10){
                cout << "Padarete klaida, bandykite is naujo " << endl;
                continue;
            }
            s.paz.push_back(paz);
            n++;
            sum += paz;
            
        }
    }
    cout << "Iveskite egzamino pazymi: "; s.egz = skaiciu_iv("Iveskite egzamino pazymi:");
    s.gal_vid = vidurkis(s, n, sum);
    s.gal_med = mediana(s, n);
    
    return s;
}

studentas rando(){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> kiek_dist(0,20);
    uniform_int_distribution<int> paz_dist(1,10);
    
    int n, laik_paz, sum = 0;
    studentas s;
    cout << "Iveskite studento duomenis" << endl;
    cout << "Vardas: "; s.var = vardo_iv();
    cout << "Pavarde: "; s.pav = vardo_iv();
    n =  kiek_dist(mt);
    for(int i = 0; i < n; i++){
        laik_paz = paz_dist(mt);
        s.paz.push_back(laik_paz);
        sum += laik_paz;
    }
    s.egz = paz_dist(mt);
    s.gal_vid = vidurkis(s, n, sum);
    s.gal_med = mediana(s, n);
    
    return s;
}

void ivest_f(list <studentas> & studentai, int & stud_n, string & pav, double & testavimas){
    testavimas = 0;
    pav = "";
    ifstream fin;
    
    while (true){
        cout << "Iveskite failo pavadinima: ";
        getline(cin, pav);

        fin.open(pav);
        if (!fin){
            cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
            fin.clear();
        }
        else{
            break;
        }
    }
    auto start = high_resolution_clock::now();
    
    studentas s;
    string x;
    getline(fin, x);

    stud_n = 0;
    while(fin >> s.var >> s.pav){
        int sk = 0, n = 0, sum = 0;
        bool klaida = false;
        
        s.paz.clear();
        s.egz = 0;
        s.gal_vid = 0;
        s.gal_med = 0;
        
        getline(fin,x);
        
        for(int i = 0; i < x.size(); i++){
            if(isdigit(x[i])){
                if(!klaida){
                    sk = sk * 10 + (x[i] - '0');
                }
            }
            else if(isalpha(x[i])){
                klaida = true;
            }
            else{
                if(sk != 0 && !klaida){
                    if(sk >= 1 && sk <= 10){
                        s.paz.push_back(sk);
                        sum += sk;
                        n++;
                    }
                    else{
                        cout << stud_n+1 << " Eiluteje pazymys nera intervale 1-10. Si skaiciu praleisime." << endl;
                    }
                }
                sk = 0;
                klaida = false;
            }
        }
        
        if(sk != 0 && !klaida){
            if(sk >= 1 && sk <= 10){
                s.paz.push_back(sk);
                sum += sk;
                n++;
            }
            else{
                cout << n+1 << " Eiluteje pazymys nera intervale 1-10. Si skaiciu praleisime." << endl;
            }
        }
        if(!s.paz.empty()){
            s.egz = s.paz.back();
            s.paz.pop_back();
            n--;
            sum -= s.egz;
        }
        
        
        s.gal_vid = vidurkis(s, n, sum);
        s.gal_med = mediana(s, n);
        
        studentai.push_back(s);
        stud_n++;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    testavimas = duration;
    cout << "Failo nuskaitymas uztruko: " << duration << " ms" << endl;
    fin.close();
}

void stud_iv(list <studentas> & studentai, int & n, studentas (*funkc)()){
    cout << "Kiek studentu grupeje? "; n = n_iv("Kiek studentu grupeje?");
    for(auto i = 0; i < n; i++){
        studentai.push_back(funkc());
    }
}



