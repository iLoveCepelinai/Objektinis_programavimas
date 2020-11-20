/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;


struct studentas {
    string vardas, pavard;
    double* nd; //double nes dirbant su int tipo duom ir gaunant ne sveikojo tipo atsakymus, galima sugadinti duomenis
    double egz, galut;
    double sumaND = 0;
    int ndKiekis = 0;
};

int main()
{
    int n = 0;//studentu skaicius
    int m = 0;//nd skaicius
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    while (!cin) {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
    }

    studentas* grupe = new studentas[n];    //pirmose versijose nenaudoti const, nes nekompiliuoja

    for (int i = 0; i < n; i++) {
        grupe[i].nd = new double[m];    //sukuriu dinaminius masyvus namu darbams
    }


    for (int i = 0; i < n; i++) {
        studentas* temp = new studentas[n]; //susikuriu laikina masyva perrasymui

        cout << "Iveskite " << i + 1 << "-ojo studento varda: "; cin >> grupe[i].vardas;

        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: "; cin >> grupe[i].pavard;

        string randEgz;
        cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): " << endl; cin >> randEgz;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): "; cin >> randEgz;
        }

        if (randEgz == "ne") {
            cout << "Iveskite studento egzamino pazimi: "; cin >> grupe[i].egz;
            while (!cin || grupe[i].egz < 1 || grupe[i].egz>10) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite studento egzamino pazimi: "; cin >> grupe[i].egz;
            }
        }
        else if (randEgz == "taip") {
            grupe[i].egz = std::rand() % 10 + 1;
            cout << grupe[i].egz << endl;
        }

        string randNd;  //nustato ar vartotojas nores atsitiktinai generuotu ar pacio rasytu pazymiu

        cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): " << endl; cin >> randNd;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): "; cin >> randNd;
        }


        if (randNd == "ne") {   //kelias jei zmogus pasirenka pats ivesti duomenis
            string ndStop = "ne";
            int ndDydis = 0;

            while (ndStop == "ne") {
                ndDydis++;  //didinu nd masyvo didi vienetu (jis bus uzpildomas namu darbu)

                for (int k = 0; k < n; k++) {   //i temp surasau turimus grupes duomenis
                    temp[k] = grupe[k];
                }
                delete[] grupe; //istrinu masyva grupe

                grupe = new studentas[n];               //sukuriu nauja masyva grupe 
                grupe[i].nd = new double[ndDydis];      //konkreciam studentui, kuriam dabar vedami random duomenys, didinu masyva, kad tilptu

                for (int k = 0; k < n; k++) {
                    grupe[k] = temp[k];     // atgal keliu duomenis ið temp i grupe
                }

                double ndPaz;

                cout << "Iveskite studento namu darbu pazymi: "; cin >> ndPaz;
                while (!cin || ndPaz < 1 || ndPaz > 10) {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Iveskite studento namu darbu pazymi: "; cin >> ndPaz;
                }

                grupe[i].nd[ndDydis - 1] = ndPaz;   //panaudojau ndDydis tam kad nekurti naujo kintamojo while cikle
                grupe[i].sumaND = grupe[i].sumaND + ndPaz;

                cout << "Ar norite baigti vesti pazymius? (taip/ne) " << endl; cin >> ndStop;
                while (ndStop != "ne" && ndStop != "taip") {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Ar norite baigti vesti pazymius? (taip/ne) "; cin >> ndStop;
                }
            }
            grupe[i].ndKiekis = ndDydis;    //iskart sau paruosiu namu darbu kieki kuri naudosiu medianai
            grupe[i].galut = grupe[i].sumaND / ndDydis; //velgi ndDydis tinka ir nenoriu kurti nauju kintamuju. 
        }

        else if (randNd == "taip") { //kelias jei zmogus pasirenka automatini pazymiu generavima
            cout << "Iveskite  studento namu darbu skaiciu: "; cin >> m;
            while (!cin || m <= 0) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite  studento namu darbu skaiciu: ";
                cin >> m;
            }

            grupe[i].ndKiekis = m;  //iskart sau paruosiu namu darbu kieki kuri naudosiu medianai

            for (int k = 0; k < n; k++) { //i temp surasau turimus grupes duomenis
                temp[k] = grupe[k];
            }

            delete[] grupe;	//istrinu masyva grupe

            grupe = new studentas[n];	//sukuriu nauja masyva grupe 
            grupe[i].nd = new double[m];   //konkreciam studentui, kuriam dabar vedami random duomenys, didinu masyva, kad tilptu

            for (int k = 0; k < n; k++) {	// atgal keliu duomenis ið temp i grupe
                grupe[k] = temp[k];
            }

            for (int j = 0; j < m; j++) {
                grupe[i].nd[j] = std::rand() % 10 + 1;  //generuojame nd pazymius studentui
                grupe[i].sumaND = grupe[i].sumaND + grupe[i].nd[j];
                cout << grupe[i].nd[j] << " ";
            }
            cout << endl;
            grupe[i].galut = grupe[i].sumaND / m;
        }
    }

    string klausimas;
    cout << "Pagal ka skaiciuoti galutini pazimi (vid - vidurki, med - mediana)" << endl;
    cin >> klausimas;
    while (klausimas != "med" && klausimas != "vid") {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Pagal ka skaiciuoti galutini pazimi (vid - vidurki, med - mediana): ";
        cin >> klausimas;
    }

    if (klausimas == "vid") {
        double vidurkis;
        for (int ii = 0; ii < n; ii++) {
            vidurkis = grupe[ii].galut; //anksciau galut buvo musu vidurkis, todel dabar perrasau, nes musu galut keisis
            grupe[ii].galut = 0.6 * grupe[ii].egz + 0.4 * vidurkis;  //skaiciuojame GP
        }

        cout << "\tPavarde\t" << "\tVardas\t" << "\tGalutinis (vid.)" << endl;
        cout << "_____________________________________________" << endl;

        for (int k = 0; k < n; k++) {   //spausdiname
            cout << std::fixed;
            cout << std::setprecision(2);
            cout << setw(15) << grupe[k].pavard << "\t" << setw(15) << grupe[k].vardas << "\t\t" << grupe[k].galut << endl;
        }
    }

    else if (klausimas == "med") {
        //skaiciavimas pagal mediana
        double mediana;
        for (int jj = 0; jj < n; jj++) {
            int aa = grupe[jj].ndKiekis;
            std::sort(grupe[jj].nd, grupe[jj].nd + aa);
            if (aa % 2 == 0) {
                mediana = (grupe[jj].nd[(aa / 2) - 1] + grupe[jj].nd[aa / 2]) / 2;
            }
            else {
                int index = (aa * 1.0 - 1) / 2 + 0.5;
                mediana = (grupe[jj].nd[index]);
            }
            grupe[jj].galut = 0.6 * grupe[jj].egz + 0.4 * mediana;
        }
        cout << "\tPavarde\t" << "\tVardas\t" << "\tGalutinis (med.)" << endl;
        cout << "_____________________________________________" << endl;

        for (int k = 0; k < n; k++) {
            cout << std::fixed;
            cout << std::setprecision(2);
            cout << setw(15) << grupe[k].pavard << "\t" << setw(15) << grupe[k].vardas << "\t\t" << grupe[k].galut << endl;
        }
    }
}