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
        vector <int> isrikiuoti_paz = s.paz;
        sort(isrikiuoti_paz.begin(), isrikiuoti_paz.end());
        double med = 0;
        if (n % 2 == 0) {
            med = (isrikiuoti_paz[n/2 - 1] + isrikiuoti_paz[n/2]) / 2.0;
        }
        else {
            med = isrikiuoti_paz[n/2];
        }
        return med*0.4+s.egz*0.6;
    }
}
