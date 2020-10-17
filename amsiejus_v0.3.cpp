/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include "03nd_bib.h"

int main()
{
    ifstream failas;
    string eilute;
    string sVardai, sPavardes, sTemp, egzaminas;
    vector <string> ndMasyv;
    int m;  //namu darbu kiekis

    const string failoPav = "Studentai10000.txt";

    bool spausdinimas = false;  //tikrinimui gale ar reikia spausdinti

    ndMasyv.reserve(1);

    vector <studentas> grupe;
    grupe.reserve(1);

    try {
        failas.open(failoPav);
    }
    catch (std::exception& e) {
        cout << "Failas "<< failoPav <<" nebuvo rastas" << endl;
    }
    

    try{
        if (!failas.good()) {
            throw failoPav;
        }
        spausdinimas = true;    //spausdins cout nes faila pavyko atidaryti

        failas >> sVardai >> sPavardes >> sTemp;
        while (sTemp != "Egz.") {
            ndMasyv.push_back(sTemp);
            failas >> sTemp;
        }
        egzaminas = sTemp;  //sie nuskaitymai pades tureti stulpeliu vardus, bet svarbiausia: bus zinomas namu darbu kiekis

        m = ndMasyv.size();

        while (!failas.eof()) { //skaito iki kol atsimusa i failo pabaiga
            studentas laik;
            failas >> laik.vardas >> laik.pavard;

            double laikPaz;

            for (int i = 0; i < m; i++) {
                failas >> laikPaz;
                laik.nd.push_back(laikPaz);
            }

            failas >> laik.egz;

            grupe.push_back(laik);
        }

        failas.close();
    }
    catch(string pav){
        cout << pav << " failas neegzistuoja arba jo nepavyko atidaryti\n";
    }

    //*********************************************************
    //dabar atliksime rusiavima pagal vardus

    sort(grupe.begin(), grupe.end(), compareByName);


    //*********************************************************
    //dabar atliksime skaiciavimus

    //skaiciavimas pagal vidurki:
    double suma;
    double vid = 0;
    for (auto& studenciokas : grupe) {
        suma = 0;
        int a = 0;
        for (auto& a : studenciokas.nd) {
            suma = suma + a;
        }
        vid = suma / m;
        studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * vid;
    }

    //skaiciavimas pagal mediana:
    double mediana;
    for (auto& studenciokas : grupe) {
        std::sort(studenciokas.nd.begin(), studenciokas.nd.end());
        if (m % 2 == 0) {
            mediana = (studenciokas.nd.at((m * 1.0) / 2 - 1) + studenciokas.nd.at(m / 2)) / 2;
        }
        else {
            int index = (m * 1.0 - 1) / 2 + 0.5;
            mediana = studenciokas.nd.at(index);
        }
        studenciokas.galutMed = 0.6 * studenciokas.egz + 0.4 * mediana;
    }

    //*********************************************************
    //spausdinimas rezultatu

    if (spausdinimas) {
        cout << "\tPavarde\t" << "\tVardas" << "\tGalutinis (vid.)" << "\tGalutinis (med.)" << endl;
        cout << "_____________________________________________" << endl;
    }

    for (auto& studenciokas : grupe) {
        cout << std::fixed;
        cout << std::setprecision(2);
        cout << setw(15) << studenciokas.pavard << " " << setw(15) << studenciokas.vardas << "\t" << setw(16) << studenciokas.galut <<
            "\t" << setw(16) << studenciokas.galutMed << endl;
    }

    grupe.clear();

    int pab;
    cin >> pab;
}