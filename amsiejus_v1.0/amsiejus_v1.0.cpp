/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include "v1.0_bib.h";

int main()
{
    string pasirinkimas;

    list <studentas> grupe, dundukai, sukciukai;

    vector <studentas> grupeV, dundukaiV, sukciukaiV;

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

    cout << "-------------1000-------------" << endl;

    failuKurimas(5, 1000);

    cout << "---------vector pirmas budas---------" << endl;

    skaitymasVec(1000, grupeV, pasirinkimas);//

    skirstymas1Vec(grupeV, dundukaiV, sukciukaiV);//

    surasymasVec(dundukaiV, sukciukaiV, "dundukai1000.txt", "sukciukai1000.txt");//
    sukciukaiV.clear();
    dundukaiV.clear();//

    cout << endl;

    cout << "---------vector antras budas---------" << endl;

    skaitymasVec(1000, grupeV, pasirinkimas);

    skirstymas2Vec(grupeV, dundukaiV);

    surasymasVec(dundukaiV, grupeV, "dundukai1000.txt", "sukciukai1000.txt");
    grupeV.clear();
    dundukaiV.clear();

    cout << endl;

    cout << "--------vector mano budas------------" << endl;

    skaitymasVec(1000, grupeV, pasirinkimas);//

    skirstymasManoVector(grupeV, sukciukaiV);//

    surasymasVec(grupeV, sukciukaiV, "dundukai1000.txt", "sukciukai1000.txt");//
    grupe.clear();
    sukciukai.clear();//

    cout << endl;

    cout << "--------list pirmas budas------------" << endl;

    skaitymasList(1000, grupe, pasirinkimas);//

    skirstymas1List(grupe, dundukai, sukciukai);//

    surasymasList(dundukai, sukciukai, "dundukai1000.txt", "sukciukai1000.txt");//
    sukciukai.clear();
    dundukai.clear();//

    cout << endl;

    cout << "--------list antras budas------------" << endl;

    skaitymasList(1000, grupe, pasirinkimas);

    skirstymas2List(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai1000.txt", "sukciukai1000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;

    cout << "----------list mano budas------------" << endl;

    skaitymasList(1000, grupe, pasirinkimas);//

    skirstymasManoList(grupe, dundukai);//

    surasymasList(dundukai, grupe, "dundukai1000.txt", "sukciukai1000.txt");//
    grupe.clear();
    dundukai.clear();//

    cout << endl;
    system("pause");


    //10 000 eiluciu

    cout << "-------------10 000-------------" << endl;

    failuKurimas(5, 10000);

    cout << "---------vector pirmas budas---------" << endl;

    skaitymasVec(10000, grupeV, pasirinkimas);//

    skirstymas1Vec(grupeV, dundukaiV, sukciukaiV);//

    surasymasVec(dundukaiV, sukciukaiV, "dundukai10000.txt", "sukciukai10000.txt");//
    sukciukaiV.clear();
    dundukaiV.clear();//

    cout << endl;

    cout << "---------vector antras budas---------" << endl;

    skaitymasVec(10000, grupeV, pasirinkimas);

    skirstymas2Vec(grupeV, dundukaiV);

    surasymasVec(dundukaiV, grupeV, "dundukai10000.txt", "sukciukai10000.txt");
    grupeV.clear();
    dundukaiV.clear();

    cout << endl;

    cout << "--------vector mano budas------------" << endl;

    skaitymasVec(10000, grupeV, pasirinkimas);

    skirstymasManoVector(grupeV, sukciukaiV);

    surasymasVec(grupeV, sukciukaiV, "dundukai10000.txt", "sukciukai10000.txt");
    grupe.clear();
    sukciukai.clear();

    cout << endl;

    cout << "--------list pirmas budas------------" << endl;

    skaitymasList(10000, grupe, pasirinkimas);//

    skirstymas1List(grupe, dundukai, sukciukai);//

    surasymasList(dundukai, sukciukai, "dundukai10000.txt", "sukciukai10000.txt");//
    sukciukai.clear();
    dundukai.clear();//

    cout << endl;

    cout << "--------list antras budas------------" << endl;

    skaitymasList(10000, grupe, pasirinkimas);

    skirstymas2List(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai10000.txt", "sukciukai10000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;

    cout << "----------list mano budas------------" << endl;

    skaitymasList(10000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai10000.txt", "sukciukai10000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;
    system("pause");


    //100 000 eiluciu

    cout << "-------------100 000-------------" << endl;

    failuKurimas(5, 100000);

    cout << "---------vector pirmas budas---------" << endl;

    skaitymasVec(100000, grupeV, pasirinkimas);//

    skirstymas1Vec(grupeV, dundukaiV, sukciukaiV);//

    surasymasVec(dundukaiV, sukciukaiV, "dundukai100000.txt", "sukciukai100000.txt");//
    sukciukaiV.clear();
    dundukaiV.clear();//

    cout << endl;

    cout << "---------vector antras budas---------" << endl;

    skaitymasVec(100000, grupeV, pasirinkimas);

    skirstymas2Vec(grupeV, dundukaiV);

    surasymasVec(dundukaiV, grupeV, "dundukai100000.txt", "sukciukai100000.txt");
    grupeV.clear();
    dundukaiV.clear();

    cout << endl;

    cout << "--------vector mano budas------------" << endl;

    skaitymasVec(100000, grupeV, pasirinkimas);

    skirstymasManoVector(grupeV, sukciukaiV);

    surasymasVec(grupeV, sukciukaiV, "dundukai100000.txt", "sukciukai100000.txt");
    grupe.clear();
    sukciukai.clear();

    cout << endl;

    cout << "--------list pirmas budas------------" << endl;

    skaitymasList(100000, grupe, pasirinkimas);//

    skirstymas1List(grupe, dundukai, sukciukai);//

    surasymasList(dundukai, sukciukai, "dundukai100000.txt", "sukciukai100000.txt");//
    sukciukai.clear();
    dundukai.clear();//

    cout << endl;

    cout << "--------list antras budas------------" << endl;

    skaitymasList(100000, grupe, pasirinkimas);

    skirstymas2List(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai100000.txt", "sukciukai100000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;

    cout << "----------list mano budas------------" << endl;

    skaitymasList(100000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai100000.txt", "sukciukai100000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;
    system("pause");


    //1 000 000 eiluciu

    cout << "-------------1 000 000-------------" << endl;

    failuKurimas(5, 1000000);

    cout << "---------vector pirmas budas---------" << endl;

    skaitymasVec(1000000, grupeV, pasirinkimas);//

    skirstymas1Vec(grupeV, dundukaiV, sukciukaiV);//

    surasymasVec(dundukaiV, sukciukaiV, "dundukai1000000.txt", "sukciukai1000000.txt");//
    sukciukaiV.clear();
    dundukaiV.clear();//

    cout << endl;

    cout << "---------vector antras budas---------" << endl;

    skaitymasVec(1000000, grupeV, pasirinkimas);

    skirstymas2Vec(grupeV, dundukaiV);

    surasymasVec(dundukaiV, grupeV, "dundukai1000000.txt", "sukciukai1000000.txt");
    grupeV.clear();
    dundukaiV.clear();

    cout << endl;

    cout << "--------vector mano budas------------" << endl;

    skaitymasVec(1000000, grupeV, pasirinkimas);

    skirstymasManoVector(grupeV, sukciukaiV);

    surasymasVec(grupeV, sukciukaiV, "dundukai1000000.txt", "sukciukai1000000.txt");
    grupe.clear();
    sukciukai.clear();

    cout << endl;

    cout << "--------list pirmas budas------------" << endl;

    skaitymasList(1000000, grupe, pasirinkimas);//

    skirstymas1List(grupe, dundukai, sukciukai);//

    surasymasList(dundukai, sukciukai, "dundukai1000000.txt", "sukciukai1000000.txt");//
    sukciukai.clear();
    dundukai.clear();//

    cout << endl;

    cout << "--------list antras budas------------" << endl;

    skaitymasList(1000000, grupe, pasirinkimas);

    skirstymas2List(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai1000000.txt", "sukciukai1000000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;

    cout << "----------list mano budas------------" << endl;

    skaitymasList(1000000, grupe, pasirinkimas);

    skirstymasManoList(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai1000000.txt", "sukciukai1000000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;
    system("pause");

    //10 000 000 eiluciu

    cout << "-------------10 000 000-------------" << endl;

    failuKurimas(5, 10000000);

    cout << "---------vector pirmas budas---------" << endl;

    skaitymasVec(10000000, grupeV, pasirinkimas);//

    skirstymas1Vec(grupeV, dundukaiV, sukciukaiV);//

    surasymasVec(dundukaiV, sukciukaiV, "dundukai10000000.txt", "sukciukai10000000.txt");//
    sukciukaiV.clear();
    dundukaiV.clear();//

    cout << endl;

    cout << "---------vector antras budas---------" << endl;

    skaitymasVec(10000000, grupeV, pasirinkimas);

    skirstymas2Vec(grupeV, dundukaiV);

    surasymasVec(dundukaiV, grupeV, "dundukai10000000.txt", "sukciukai10000000.txt");
    grupeV.clear();
    dundukaiV.clear();

    cout << endl;

    cout << "--------vector mano budas------------" << endl;

    skaitymasVec(10000000, grupeV, pasirinkimas);

    skirstymasManoVector(grupeV, sukciukaiV);

    surasymasVec(grupeV, sukciukaiV, "dundukai10000000.txt", "sukciukai10000000.txt");
    grupe.clear();
    sukciukai.clear();

    cout << endl;

    cout << "--------list pirmas budas------------" << endl;

    skaitymasList(10000000, grupe, pasirinkimas);//

    skirstymas1List(grupe, dundukai, sukciukai);//

    surasymasList(dundukai, sukciukai, "dundukai10000000.txt", "sukciukai10000000.txt");//
    sukciukai.clear();
    dundukai.clear();//

    cout << endl;

    cout << "--------list antras budas------------" << endl;

    skaitymasList(10000000, grupe, pasirinkimas);

    skirstymas2List(grupe, dundukai);

    surasymasList(dundukai, grupe, "dundukai10000000.txt", "sukciukai10000000.txt");
    grupe.clear();
    dundukai.clear();

    cout << endl;

    cout << "----------list mano budas------------" << endl;

    skaitymasList(10000000, grupe, pasirinkimas);//

    skirstymasManoList(grupe, dundukai);//

    surasymasList(dundukai, grupe, "dundukai10000000.txt", "sukciukai10000000.txt");//
    grupe.clear();
    dundukai.clear();//

    cout << endl;
    system("pause");
    return 0;
}