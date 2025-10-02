#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

#include "studentai.h"
#include "galutinis_balas.h"
#include "balu_vardu_meniu_ivestys.h"

studentas ivest_su_n();
studentas ivest_be_n();
studentas rando();
void ivest_f(vector <studentas> & studentai, int & stud_n, string & pav);
void stud_iv(vector <studentas> & studentai, int & n, studentas (*funkc)());

