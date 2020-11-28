#include "v1.0_bib.h";

void failuKurimas(int, int);


void skaitymasVec(int, vector <studentas>&, string);
void skaitymasList(int, list <studentas>&, string);



void skirstymas1Vec(vector <studentas>&, vector <studentas>&, vector <studentas>&);
void skirstymasManoVector(vector <studentas>&, vector <studentas>&);
void skirstymasManoList(list <studentas>&, list <studentas>&);


void surasymasList(list <studentas>, list <studentas>, string, string);
void surasymasVec(vector <studentas>, vector <studentas>, string, string);

//papildomos funkcijos
bool ar_5(studentas);
bool compareByGalut(const studentas&, const studentas&);




//failu kurimas yra tokia pati visiems 6 variantams
void failuKurimas(int ndkiekis, int studkiekis) {
    auto start = std::chrono::high_resolution_clock::now();
    string tempVardas;
    string tempPavarde;

    string failopav = to_string(studkiekis);
    failopav += ".txt";

    ofstream failas(failopav);
    failas << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndkiekis; i++) {
        failas << "ND" << i << "\t";
    }

    failas << "Egz." << endl;

    //pradedame irasineti duomenis
    for (int j = 1; j <= studkiekis; j++) {
        failas << endl;

        tempVardas = "Vardas" + to_string(j);
        failas << setw(20) << tempVardas;

        tempPavarde = "Pavarde" + to_string(j);
        failas << setw(20) << tempPavarde << "\t";

        for (int i = 1; i <= ndkiekis; i++) {
            failas << std::rand() % 10 + 1 << "\t";
        }

        failas << std::rand() % 10 + 1;
    }
    failas.close();
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo sukurimas uztruko: " << diff.count() << "s" << endl;
}


//skaitymasList/skaitymasVec skiriasi tik jei naudojame skirtingà konteinerá (del to uztenka 2 funkciju)(pats kodas tas pats)
void skaitymasList(int studkiekis, list <studentas>& grupele, string pasirinkimas) {
    auto start = std::chrono::high_resolution_clock::now();
    ifstream failas;
    string sVardai, sPavardes, sTemp, egzaminas;
    vector <string> ndMasyv;
    int m;  //namu darbu kiekis

    string failoPav = to_string(studkiekis);
    failoPav += ".txt";


    try {
        failas.open(failoPav);
    }
    catch (std::exception& e) {
        cout << "Failas " << failoPav << " nebuvo rastas" << endl;
    }

    try {
        if (!failas.good()) {
            throw failoPav;
        }
        failas >> sVardai >> sPavardes >> sTemp;
        while (sTemp != "Egz.") {
            ndMasyv.push_back(sTemp);
            failas >> sTemp;
        }
        egzaminas = sTemp;  //sie nuskaitymai pades tureti stulpeliu vardus, bet svarbiausia: bus zinomas namu darbu kiekis

        m = ndMasyv.size();
        ndMasyv.clear();

        while (!failas.eof()) { //skaito iki kol atsimusa i failo pabaiga
            studentas laik;
            failas >> laik.vardas >> laik.pavard;

            float laikPaz;

            for (int i = 0; i < m; i++) {
                failas >> laikPaz;
                laik.nd.push_back(laikPaz);
            }

            failas >> laik.egz;

            grupele.push_back(laik);
        }
        failas.close();
    }
    catch (string pav) {
        cout << pav << " failas neegzistuoja arba jo nepavyko atidaryti\n";
    }


    //skaiciavimas pagal vidurki:
    if (pasirinkimas == "vid") {
        float suma;
        float vid = 0;
        for (auto& studenciokas : grupele) {
            suma = std::accumulate(std::begin(studenciokas.nd), std::end(studenciokas.nd), 0.0);
            vid = suma / m;
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * vid;
        }
    }

    //skaiciavimas pagal mediana:
    else {
        double mediana;
        for (auto& studenciokas : grupele) {
            std::sort(studenciokas.nd.begin(), studenciokas.nd.end());
            if (m % 2 == 0) {
                mediana = (studenciokas.nd.at((m * 1.0) / 2 - 1) + studenciokas.nd.at(m / 2)) / 2;
            }
            else {
                int index = (m * 1.0 - 1) / 2 + 0.5;
                mediana = studenciokas.nd.at(index);
            }
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * mediana;
        }
    }
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Skaitymas nuo failo uztruko: " << diff.count() << "s" << endl;
}

void skaitymasVec(int studkiekis, vector <studentas>& grupele, string pasirinkimas) {
    auto start = std::chrono::high_resolution_clock::now();
    ifstream failas;
    string sVardai, sPavardes, sTemp, egzaminas;
    vector <string> ndMasyv;
    int m;  //namu darbu kiekis

    string failoPav = to_string(studkiekis);
    failoPav += ".txt";


    try {
        failas.open(failoPav);
    }
    catch (std::exception& e) {
        cout << "Failas " << failoPav << " nebuvo rastas" << endl;
    }

    try {
        if (!failas.good()) {
            throw failoPav;
        }
        failas >> sVardai >> sPavardes >> sTemp;
        while (sTemp != "Egz.") {
            ndMasyv.push_back(sTemp);
            failas >> sTemp;
        }
        egzaminas = sTemp;  //sie nuskaitymai pades tureti stulpeliu vardus, bet svarbiausia: bus zinomas namu darbu kiekis

        m = ndMasyv.size();
        ndMasyv.clear();

        while (!failas.eof()) { //skaito iki kol atsimusa i failo pabaiga
            studentas laik;
            failas >> laik.vardas >> laik.pavard;

            float laikPaz;

            for (int i = 0; i < m; i++) {
                failas >> laikPaz;
                laik.nd.push_back(laikPaz);
            }

            failas >> laik.egz;

            grupele.push_back(laik);
        }
        failas.close();
    }
    catch (string pav) {
        cout << pav << " failas neegzistuoja arba jo nepavyko atidaryti\n";
    }


    //skaiciavimas pagal vidurki:
    if (pasirinkimas == "vid") {
        float suma;
        float vid = 0;
        for (auto& studenciokas : grupele) {
            suma = std::accumulate(std::begin(studenciokas.nd), std::end(studenciokas.nd), 0.0);
            vid = suma / m;
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * vid;
        }
    }

    //skaiciavimas pagal mediana:
    else {
        double mediana;
        for (auto& studenciokas : grupele) {
            std::sort(studenciokas.nd.begin(), studenciokas.nd.end());
            if (m % 2 == 0) {
                mediana = (studenciokas.nd.at((m * 1.0) / 2 - 1) + studenciokas.nd.at(m / 2)) / 2;
            }
            else {
                int index = (m * 1.0 - 1) / 2 + 0.5;
                mediana = studenciokas.nd.at(index);
            }
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * mediana;
        }
    }
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Skaitymas nuo failo uztruko: " << diff.count() << "s" << endl;
}


//skirstymas bus skirtingas listams ir vektoriams, bei bus skirtingi skirtymo budai:

//vector pirma strategija:
void skirstymas1Vec(vector <studentas>& grupele, vector <studentas>& dundukai, vector <studentas>& sukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int studKiekis = grupele.size();
    dundukai.reserve(studKiekis * 0.5);
    sukciukai.reserve(studKiekis * 0.6);
    for (auto& studenciokas : grupele) {
        if (studenciokas.galut < 5) {
            dundukai.push_back(studenciokas);
        }
        else {
            sukciukai.push_back(studenciokas);
        }
    }
    grupele.clear();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas i 2 vektorius uztruko: " << diff.count() << "s" << endl;
}

//list pirma strategija:


//vector antra startegija:


//list antra strategija:


//vector mano strategija:
void skirstymasManoVector(vector <studentas>& grupele, vector <studentas>& sukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
    sort(grupele.begin(), grupele.end(), compareByGalut);   //surusiuojame musu studentu vektoriu
    int studKiekis = grupele.size();

    sukciukai.reserve(studKiekis * 0.6);

    studentas temp = grupele.back();    //laikinas galinis grupele elementas
    while (temp.galut >= 5) {
        sukciukai.push_back(temp);      //galini elementa dedame i sukciukus tol, kol >= 5
        grupele.pop_back();             //naikiname galini elementa is grupele
        temp = grupele.back();          //naujas temp nes naujas galinis elementas
    }

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas i 2 vektorius uztruko: " << diff.count() << "s" << endl;
}

//list mano strategija:
void skirstymasManoList(list <studentas>& grupele, list <studentas>& dundukai) {
    auto start = std::chrono::high_resolution_clock::now();

    grupele.sort([](studentas const& l, studentas const& r) {
        return l.galut < r.galut; });

    list<studentas>::iterator it = std::find_if(grupele.begin(), grupele.end(), ar_5);//randame pirmaji studenta galutiniu >=5
    dundukai.splice(dundukai.begin(), grupele, grupele.begin(), it);    //sudarome mokiniu su <=5 galutiniu sarasa
    //splice jau iskerpa musu dunduku pradzia, todel grupele lieka tik sukciukai (>=5)

    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas i 2 sarasus uztruko: " << diff.count() << "s" << endl;
}


//surasymasList/surasymasVec skiriasi tik jei naudojame skirtingà konteinerá (del to uztenka 2 funkciju)(pats kodas tas pats)
void surasymasList(list <studentas> dundukai, list <studentas> sukciukai, string pavDundukai, string pavSukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
    ofstream failD(pavDundukai); // kuriame dunduku faila
    int ndKiekis = dundukai.front().nd.size();    //paimame belenkoki vektoriaus elementa (studenta) ir patikriname kiek jis turi nd

    failD << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndKiekis; i++) {
        failD << "ND" << i << "\t";
    }

    failD << "Egz." << "\t" << "Galut.";

    for (auto& dundukas : dundukai) {
        failD << endl;
        failD << setw(20) << dundukas.vardas << setw(20) << dundukas.pavard << "\t";
        for (auto& pazymys : dundukas.nd) failD << pazymys << "\t";
        failD << dundukas.egz << "\t" << dundukas.galut;
    }
    failD.close();

    ofstream failS(pavSukciukai); // kuriame sukciuku faila

    failS << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndKiekis; i++) {
        failS << "ND" << i << "\t";
    }

    failS << "Egz." << "\t" << "Galut.";

    for (auto& sukciukas : sukciukai) {
        failS << endl;
        failS << setw(20) << sukciukas.vardas << setw(20) << sukciukas.pavard << "\t";
        for (auto& pazymys : sukciukas.nd) failS << pazymys << "\t";
        failS << sukciukas.egz << "\t" << sukciukas.galut;
    }
    failS.close();
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "2 sarasu surasymas i 2 failus uztruko: " << diff.count() << "s" << endl;
}


void surasymasVec(vector <studentas> dundukai, vector <studentas> sukciukai, string pavDundukai, string pavSukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
    ofstream failD(pavDundukai); // kuriame dunduku faila
    int ndKiekis = dundukai.front().nd.size();    //paimame belenkoki vektoriaus elementa (studenta) ir patikriname kiek jis turi nd

    failD << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndKiekis; i++) {
        failD << "ND" << i << "\t";
    }

    failD << "Egz." << "\t" << "Galut.";

    for (auto& dundukas : dundukai) {
        failD << endl;
        failD << setw(20) << dundukas.vardas << setw(20) << dundukas.pavard << "\t";
        for (auto& pazymys : dundukas.nd) failD << pazymys << "\t";
        failD << dundukas.egz << "\t" << dundukas.galut;
    }
    failD.close();

    ofstream failS(pavSukciukai); // kuriame sukciuku faila

    failS << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndKiekis; i++) {
        failS << "ND" << i << "\t";
    }

    failS << "Egz." << "\t" << "Galut.";

    for (auto& sukciukas : sukciukai) {
        failS << endl;
        failS << setw(20) << sukciukas.vardas << setw(20) << sukciukas.pavard << "\t";
        for (auto& pazymys : sukciukas.nd) failS << pazymys << "\t";
        failS << sukciukas.egz << "\t" << sukciukas.galut;
    }
    failS.close();
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "2 sarasu surasymas i 2 failus uztruko: " << diff.count() << "s" << endl;
}

/*Pagalbines funkcijos:*/

bool ar_5(studentas i) {
    return (i.galut >= 5);
}

bool compareByGalut(const studentas& pirmas, const studentas& antras) {
    return pirmas.galut < antras.galut;
}