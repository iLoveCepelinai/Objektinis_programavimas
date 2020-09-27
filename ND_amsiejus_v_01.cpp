#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;


struct studentas{
    string vardas, pavard;
    double nd[10]; //double nes dirbant su int tipo duom ir gaunant ne sveikojo tipo atsakymus, galima sugadinti duomenis
    double egz, galut;
};

int main()
{
    int n = 0;
    int m = 0;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    while (!cin) {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
    }

    studentas *grupe = new studentas[n];//pirmose versijose nenaudoti const, nes nekompiliuoja

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i+1 << "-ojo studento varda: "; cin >> grupe[i].vardas;
        
        cout << "Iveskite " << i+1 << "-ojo studento pavarde: "; cin >> grupe[i].pavard;
        
        cout << "Iveskite studento egzamino pazimi: "; cin >> grupe[i].egz;
        while (!cin || grupe[i].egz<1 || grupe[i].egz>10) {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite studento egzamino pazimi: ";
            cin >> grupe[i].egz;
        }
        cout << "Iveskite  studento namu darbu skaiciu: "; cin >> m;
        while (!cin || m <=0) {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite  studento namu darbu skaiciu: ";
            cin >> m;
        }
        for (int j = 0; j < m; j++) {
            cout << "Iveskite " << j+1 << "-aji namu darbu pazimi: "; cin >> grupe[i].nd[j];
            while (!cin || grupe[i].nd[j] < 1 || grupe[i].nd[j]>10) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite " << j + 1 << "-aji namu darbu pazimi: ";
                cin >> grupe[i].nd[j];
            }
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
        //skaiciavimas pagal vidurki
        double suma;
        double vid = 0;
        for (int ii = 0; ii < n; ii++) {
            suma = 0;
            int a = 0;
            for (a = 0; a < sizeof(grupe[ii].nd) / sizeof(grupe[ii].nd[0]) && grupe[ii].nd[a] <= 10 && grupe[ii].nd[a] >= 1;
                a++) {
                suma = suma + grupe[ii].nd[a];
            }
            vid = suma / a * 1.0;
            grupe[ii].galut = 0.6 * grupe[ii].egz + 0.4 * vid;
        }
        
        cout << "\tPavarde\t" << "\tVardas\t" << "\tGalutinis (vid.)" << endl;
        cout << "_____________________________________________" << endl;

        for (int k = 0; k < n; k++) {
            cout << std::fixed;
            cout << std::setprecision(2);
            cout << setw(15) << grupe[k].pavard << "\t" << setw(15) << grupe[k].vardas << "\t\t" << grupe[k].galut << endl;
        }
    }
    
    else if (klausimas == "med") {
        //skaiciavimas pagal mediana
        double mediana;
        for (int jj = 0; jj < n; jj++) {
            int aa;
            for (aa = 0; aa < sizeof(grupe[jj].nd) / sizeof(grupe[jj].nd[0]) && grupe[jj].nd[aa] <= 10 && grupe[jj].nd[aa] >= 1; aa++) {}
                //cia suskaiciuoja aa - mano uzpildyto pazymiais masyvo ilgi
            std::sort(grupe[jj].nd, grupe[jj].nd+aa);
            if (aa % 2 == 0) {
                mediana = (grupe[jj].nd[(aa / 2)-1] + grupe[jj].nd[aa / 2]) / 2;
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
    
    return 0;
}
