#include "03nd_bib.h"

bool compareByName(const studentas, const studentas);

bool compareByName(const studentas& pirmas, const studentas& antras) {
    if (pirmas.vardas != antras.vardas) {
        return pirmas.vardas < antras.vardas;
    }
    else return pirmas.pavard < antras.pavard;
}