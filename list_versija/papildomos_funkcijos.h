#pragma once
#include <iostream>
#include <string>
#include <list>

#include "studentai.h"

bool arskaicius(string i);
void rikiavimas(list <studentas> & studentai, int pasirinkimas);
void rusiavimas_strat1(list <studentas> & studentai, list <studentas> & vargsai, list <studentas> & kieti, int & pasirinkimas);
void rusiavimas_strat2(list <studentas> & studentai, list <studentas> & vargsai, int & pasirinkimas);

