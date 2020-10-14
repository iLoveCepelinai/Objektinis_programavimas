/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include "v04_bib.h";

int main()
{
    string pasirinkimas;

    vector <studentas> grupe, dundukai, sukciukai;

    cout << "Iveskite pagal ka skaiciuosite vidurki (vid/med)" << endl;
    cin >> pasirinkimas;

    //darbas su 1000
    /*failuKurimas(10, 1000);

    skaitymas("1000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai1000.txt", "sukciukai1000.txt");
    dundukai.clear();
    sukciukai.clear();
    */


    
    failuKurimas(10, 1000000);
    
    skaitymas("1000000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai1000000.txt", "sukciukai1000000.txt");
    dundukai.clear();
    sukciukai.clear();
    
    /*
    failuKurimas(10, 100000);

    failuKurimas(10, 1000000);

    failuKurimas(10, 10000000);
    */
    return 0;
}