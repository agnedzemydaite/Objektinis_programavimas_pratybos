#include "generavimas.h"

using std::string;
using std::to_string;
using std:: ofstream;
using std::ios;
using std::ostringstream;
using std::setw;
using std::left;

void failu_gener(int k) {
    int paz_n = rand() % 16 + 5, n = 0, laik_k = k;
    while (laik_k != 0) {
        laik_k /= 10;
        n++;
    }
    string tarpai = "";
    for (int i = 0; i < n; i++){
        tarpai+= " ";
    }
    string pav = to_string(k) + ".txt";
    ofstream fout(pav, ios::out | ios::binary);

    ostringstream antraste;
    antraste << setw(n + 8) << left << "Vardas"
             << setw(n + 8) << left << "Pavarde";
    for (int i = 0; i < paz_n; i++) {
        antraste << setw(5) << left << ("ND" + to_string(i + 1));
    }
    antraste << "Egz.\n";

    string buffer = antraste.str();
    buffer.reserve(10000000);

    string tarpai2;
    int prait_dyd = 1;
    for (int i = 0; i < k; i++) {
        int dyd = static_cast<int>(to_string(i+1).size());
            if (dyd > prait_dyd) {
                tarpai.pop_back();
                prait_dyd = dyd;
            }
        buffer += ("Vardas" + to_string(i + 1)) + tarpai+" ";
        buffer += ("Pavarde" + to_string(i + 1)) + tarpai;

        for (int j = 0; j < paz_n; j++) {
            int r = rand() % 10 + 1;
            if(r == 10) tarpai2 = "   ";
            else tarpai2 = "    ";
            buffer += to_string(r) + tarpai2;
        }

        buffer += to_string(rand() % 10 + 1) + "\n";

        if (buffer.size() > 10'000'000) {
            fout.write(buffer.data(), buffer.size());
            buffer.clear();
        }
    }

    if (!buffer.empty()) {
        fout.write(buffer.data(), buffer.size());
    }
}
