#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>

#include <list>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::to_string;
using std::setw;
using std::vector;
using std::ifstream;

using std::list;
using std::sort;


struct studentas {
    string vardas, pavard;
    vector <float> nd;
    float egz, galut;
};

void failuKurimas(int, int);

void skaitymas(int, list <studentas>&, string);

void skirstymasManoVector(vector <studentas>&, vector <studentas>&, int);
void skirstymasManoList(list <studentas>&, list <studentas>&);

void surasymas(list <studentas>, list <studentas>, string, string);


bool ar_5(studentas);
bool compareByGalut(const studentas&, const studentas&);
