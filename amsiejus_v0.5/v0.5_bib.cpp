#include "v0.5_bib.h";

void failuKurimas(int, int);
void skaitymas(int, list <studentas>&, string);
void skirstymas(list <studentas>&, list <studentas>&);
void surasymas(list <studentas>, list <studentas>, string, string);

bool ar_5(studentas);

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



void skaitymas(int studkiekis, list <studentas>& grupele, string pasirinkimas) {
    auto start = std::chrono::high_resolution_clock::now();
    ifstream failas;
    string sVardai, sPavardes, sTemp, egzaminas;
    list <string> ndMasyv;
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
        float mediana;
        float suma;
        for (auto& studenciokas : grupele) {
            studenciokas.nd.sort();
            if (m % 2 == 0) {
                std::list<float>::iterator it = std::next(studenciokas.nd.begin(), m / 2 - 1); //gauname didesniji medianos skaiciu
                suma = *it; //suma - dvieju viduriniu skaiciu vidurkis (cia pirmas)
                it = ++it;
                suma += *it;    //pridedame antra vidurini skaiciuka
                mediana = suma / 2; //galiausiai gauname mediana
            }
            else {
                int index = (m * 1.0 - 1) / 2 + 0.5;
                std::list<float>::iterator it = std::next(studenciokas.nd.begin(), index); //vaziuojame su iteratoriumi iki index
                mediana = *it;  //cia mediana tik vidurinis skaiciukas
            }
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * mediana;
        }
    }
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Skaitymas nuo failo uztruko: " << diff.count() << "s" << endl;
}


void skirstymas(list <studentas>& grupele, list <studentas>& dundukai) {
    auto start = std::chrono::high_resolution_clock::now();

        grupele.sort([](studentas const& l, studentas const& r) {
            return l.galut < r.galut; });

        list<studentas>::iterator it = std::find_if(grupele.begin(), grupele.end(), ar_5);//randame pirmaji studenta galutiniu >=5
        dundukai.splice(dundukai.begin(), grupele, grupele.begin(), it);    //sudarome mokiniu su <=5 galutiniu sarasa
        //splice jau iskerpa musu dunduku pradzia, todel grupele lieka tik sukciukai (>=5)
        
    std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas i 2 sarasus uztruko: " << diff.count() << "s" << endl;
}


void surasymas(list <studentas> dundukai, list <studentas> sukciukai, string pavDundukai, string pavSukciukai) {
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