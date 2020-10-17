#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;
using std::size;
using std::ifstream;
using std::getline;


struct studentas {
    string vardas, pavard;
    vector <double> nd;
    double egz, galut, galutMed;
};

bool compareByName(const studentas& pirmas, const studentas& antras);