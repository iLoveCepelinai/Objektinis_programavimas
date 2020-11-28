/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include "v1.0_bib.h";

int main()
{
    string pasirinkimas;

    list <studentas> grupe, dundukai;   //<----- cia butina pakeisti i vector vietoje list jei norite pabandyti daryti su vector

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


    //sis (default) variantas yra daromas su mano skirstymo budu (3 strategija) listams (pagal v0.5)

    //1000 eiluciu

    failuKurimas(5, 1000);

    skaitymasList(1000, grupe, pasirinkimas);//

    skirstymasManoList(grupe, dundukai);//

    surasymasList(dundukai, grupe, "dundukai1000.txt", "sukciukai1000.txt");//
    grupe.clear();
    dundukai.clear();//

    system("pause");



    //10000 eiluciu

    failuKurimas(5, 10000);

    skaitymasList(10000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai10000.txt", "sukciukai10000.txt");
    grupe.clear();
    dundukai.clear();

    system("pause");


    //100000 eiluciu
    failuKurimas(5, 100000);

    skaitymasList(100000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai100000.txt", "sukciukai100000.txt");
    grupe.clear();
    dundukai.clear();

    system("pause");


    //1000000 eiluciu
    failuKurimas(5, 1000000);

    skaitymasList(1000000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai1000000.txt", "sukciukai1000000.txt");
    grupe.clear();
    dundukai.clear();

    system("pause");

    //10 000 000 eiluciu
    failuKurimas(5, 10000000);

    skaitymasList(10000000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai10000000.txt", "sukciukai10000000.txt");
    grupe.clear();
    dundukai.clear();

    system("pause");
    return 0;
}