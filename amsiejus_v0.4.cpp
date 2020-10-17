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

    do {
        cout << "Iveskite pagal ka skaiciuosite vidurki (vid/med)" << endl;
        cin >> pasirinkimas;
        try {
            if (pasirinkimas != "vid" && pasirinkimas != "med") {
                throw pasirinkimas;
            }
        }
        catch (string pas) {
            cout << "Jusu ivestas pasirinkimas " << pas << " neatitinka reikalavimu. Kartokite:\n";
        }
    } while (pasirinkimas != "vid" && pasirinkimas != "med");

    //1000 eiluciu
    
    failuKurimas(5, 1000);
    
    skaitymas("1000.txt", grupe, pasirinkimas);
    
    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai1000.txt", "sukciukai1000.txt");
    dundukai.clear();
    sukciukai.clear();

    system("pause");
    //10000 eiluciu

    failuKurimas(5, 10000);

    skaitymas("10000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai10000.txt", "sukciukai10000.txt");
    dundukai.clear();
    sukciukai.clear();

    system("pause");

    //100000 eiluciu
    failuKurimas(5, 100000);

    skaitymas("100000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai100000.txt", "sukciukai100000.txt");
    dundukai.clear();
    sukciukai.clear();

    system("pause");

    //1000000 eiluciu
    failuKurimas(5, 1000000);
    
    skaitymas("1000000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai1000000.txt", "sukciukai1000000.txt");
    dundukai.clear();
    sukciukai.clear();

    system("pause");

    //10 000 000 eiluciu
    failuKurimas(5, 10000000);
    
    skaitymas("10000000.txt", grupe, pasirinkimas);

    skirstymas(grupe, dundukai, sukciukai);
    grupe.clear();

    surasymas(dundukai, sukciukai, "dundukai10000000.txt", "sukciukai10000000.txt");
    dundukai.clear();
    sukciukai.clear();

    system("pause");
    return 0;
}
