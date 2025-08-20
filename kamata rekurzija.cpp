#include <iostream>
using namespace std;

// Rekurzivna funkcija
double izracunaj_ustedu(int godine, double kamata, double pocetni_iznos) {
    if (godine == 0)
        return pocetni_iznos; // bazni slučaj: početna godina
    else
        return izracunaj_ustedu(godine - 1, kamata, pocetni_iznos) * (1 + kamata);
}

int main() {
    int godine;
    double kamata, pocetni_iznos;

    cout << "Unesi broj godina: ";
    cin >> godine;

    cout << "Unesi godisnju kamatu (npr. 0.05 za 5%): ";
    cin >> kamata;

    cout << "Unesi pocetni iznos: ";
    cin >> pocetni_iznos;

    double konacni_iznos = izracunaj_ustedu(godine, kamata, pocetni_iznos);

    cout << "Ukupno ustedjeni iznos nakon " << godine << " godina je: " 
         << konacni_iznos << endl;

    return 0;
}
