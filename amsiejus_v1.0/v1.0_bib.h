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

void skaitymasVec(int, vector <studentas>&, string);
void skaitymasList(int, list <studentas>&, string);

void skirstymas1Vec(vector <studentas>&, vector <studentas>&, vector <studentas>&);
void skirstymas1List(list <studentas>&, list <studentas>&, list <studentas>&);
void skirstymas2Vec(vector <studentas>&, vector <studentas>&);
void skirstymas2List(list <studentas>&, list <studentas>&);
void skirstymasManoVector(vector <studentas>&, vector <studentas>&);
void skirstymasManoList(list <studentas>&, list <studentas>&);

void surasymasList(list <studentas>, list <studentas>, string, string);
void surasymasVec(vector <studentas>, vector <studentas>, string, string);


bool ar_5(studentas);
bool compareByGalut(const studentas&, const studentas&);
