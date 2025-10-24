#include "galutinis_balas.h"

double vidurkis(studentas s, int n, int sum){
    if( n == 0){
        return s.egz;
    }
    else{
        return double(sum)/double(n)*0.4 + s.egz*0.6;
    }
}
double mediana(studentas s, int n){
    if(n == 0){
        return s.egz;
    }
    else{
        list <int> isrikiuoti_paz = s.paz;
        isrikiuoti_paz.sort();
        auto it = isrikiuoti_paz.begin();
        advance(it, n/2);
        
        double med = 0;
        if (n % 2 == 0) {
            auto it2 = it; --it2;
            med = (*it + *it2)/2.0;
        }
        else {
            med = *it;
        }
        return med*0.4+s.egz*0.6;
    }
}
