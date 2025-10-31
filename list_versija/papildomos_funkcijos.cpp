#include "papildomos_funkcijos.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

bool arskaicius(string i){
    for(char ch : i){
        if(!isdigit(ch)) return false;
    }
    return true;
}

void rikiavimas(list<studentas> & studentai, int pasirinkimas){
    if(pasirinkimas == 1){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.var < b.var;
            });
    }
    else if(pasirinkimas == 2){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.pav < b.pav;
            });
    }
    else if(pasirinkimas == 3){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.gal_vid < b.gal_vid;
            });
    }
    else if(pasirinkimas == 4){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.gal_med < b.gal_med;
            });
    }
}

void rusiavimas_strat1(list <studentas> & studentai, list <studentas> & vargsai, list <studentas> & kieti, int & pasirinkimas){
    if(pasirinkimas == 1){
        for(const auto& s:studentai){
            if(s.gal_vid < 5.0){
                vargsai.push_back(s);
            }
            else{
                kieti.push_back(s);
            }
        }
    }
    else if(pasirinkimas == 2){
        for(const auto& s:studentai){
            if(s.gal_med < 5.0){
                vargsai.push_back(s);
            }
            else{
                kieti.push_back(s);
            }
        }
    }
}

void rusiavimas_strat2(list <studentas> & studentai, list <studentas> & vargsai, int & pasirinkimas){
    if(pasirinkimas == 1){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.gal_vid > b.gal_vid;
        });
        while(true){
            studentas s = studentai.back();
            if(s.gal_vid < 5.0){
                vargsai.push_back(s);
                studentai.pop_back();
            }
            else break;
        }
    }
    else if(pasirinkimas == 2){
        studentai.sort([](const studentas &a, const studentas &b){
                return a.gal_med > b.gal_med;
            });
        while(true){
            studentas s = studentai.back();
            if(s.gal_med < 5.0){
                vargsai.push_back(s);
                studentai.pop_back();
            }
            else break;
        }
        
    }
}
