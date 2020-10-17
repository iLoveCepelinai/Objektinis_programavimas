#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::to_string;
using std::setw;
using std::vector;
using std::ifstream;


struct studentas {
    string vardas, pavard;
    vector <double> nd;
    double egz, galut;
};

void failuKurimas(int, int);

void skaitymas(string, vector <studentas>&, string);

void skirstymas(vector <studentas>, vector <studentas>&, vector <studentas>&);

void surasymas(vector <studentas>, vector <studentas>, string, string);
