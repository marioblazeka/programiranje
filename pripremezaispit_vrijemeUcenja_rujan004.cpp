#include <iostream>     // Za unos i ispis
#include <fstream>      // Za rad s datotekama
#include <string>       // Za rad s tekstom

using namespace std;

// Definicija strukture koja sadrži podatke o jednom danu učenja
struct DanUcenja {
    string datum;      // Dan kao riječ (npr. "Ponedjeljak", "2025-07-31")
    int sati;          // Broj sati učenja
    int ocjena;        // Ocjena efikasnosti (1-5)
};

// Maksimalni broj dana koji se mogu unijeti
const int MAX_DANA = 10;

// Polje struktura u kojem se spremaju podaci o učenju
DanUcenja podaci[MAX_DANA];
int brojDana = 0; // Trenutni broj unesenih dana

// Funkcija za unos novih podataka
void unosPodataka() {
    cout << "Trenutno uneseno dana: " << brojDana << "/" << MAX_DANA << endl;

    if (brojDana >= MAX_DANA) {
        cout << "Dostignut maksimalan broj dana.\n";
        return;
    }

    // Unos novog dana
    cout << "Unesite datum (npr. 2025-07-31): ";
    cin >> podaci[brojDana].datum;

    // Unos i validacija broja sati
    do {
        cout << "Unesite broj sati učenja (0 - 24): ";
        cin >> podaci[brojDana].sati;
    } while (podaci[brojDana].sati < 0 || podaci[brojDana].sati > 24);

    // Unos i validacija ocjene
    do {
        cout << "Unesite ocjenu efikasnosti (1 - 5): ";
        cin >> podaci[brojDana].ocjena;
    } while (podaci[brojDana].ocjena < 1 || podaci[brojDana].ocjena > 5);

    brojDana++; // Povećaj broj unesenih dana
}

// Funkcija za ispis svih podataka
void ispisPodataka() {
    if (brojDana == 0) {
        cout << "Nema unesenih podataka.\n";
        return;
    }

    // Ispis zaglavlja
    cout << "Datum\t\tSati\tOcjena\n";
    cout << "-----------------------------\n";

    int ukupnoSati = 0;
    int sumaOcjena = 0;

    // Ispis svakog dana i izračun zbirnih podataka
    for (int i = 0; i < brojDana; i++) {
        cout << podaci[i].datum << "\t" << podaci[i].sati << "\t" << podaci[i].ocjena << endl;
        ukupnoSati += podaci[i].sati;
        sumaOcjena += podaci[i].ocjena;
    }

    // Ispis zbirnih podataka
    cout << "\nUkupan broj dana učenja: " << brojDana << endl;
    cout << "Ukupno sati učenja: " << ukupnoSati << endl;
    cout << "Prosječna ocjena: " << (float)sumaOcjena / brojDana << endl;
}

// Funkcija za ispravak podataka prema datumu
void ispravakPodataka() {
    cout << "Broj unesenih dana: " << brojDana << endl;
    string trazeniDatum;
    cout << "Unesite datum za ispravak: ";
    cin >> trazeniDatum;

    // Pronađi dan
    for (int i = 0; i < brojDana; i++) {
        if (podaci[i].datum == trazeniDatum) {
            // Pronađen dan, ispravljamo
            do {
                cout << "Novi broj sati (0 - 24): ";
                cin >> podaci[i].sati;
            } while (podaci[i].sati < 0 || podaci[i].sati > 24);

            do {
                cout << "Nova ocjena (1 - 5): ";
                cin >> podaci[i].ocjena;
            } while (podaci[i].ocjena < 1 || podaci[i].ocjena > 5);

            cout << "Podaci su ažurirani.\n";
            return;
        }
    }

    // Ako dan nije pronađen
    cout << "Ne postoje podaci za odabrani dan.\n";
}

// Funkcija za brisanje podataka za određeni dan
void brisanjePodataka() {
    cout << "Broj unesenih dana: " << brojDana << endl;
    string trazeniDatum;
    cout << "Unesite datum za brisanje podataka: ";
    cin >> trazeniDatum;

    for (int i = 0; i < brojDana; i++) {
        if (podaci[i].datum == trazeniDatum) {
            // Postavimo sate i ocjenu na 0 (ostaje datum)
            podaci[i].sati = 0;
            podaci[i].ocjena = 0;
            cout << "Podaci su obrisani (osim datuma).\n";
            return;
        }
    }

    cout << "Ne postoje podaci za odabrani dan.\n";
}

// Funkcija za spremanje podataka u datoteku
void spremanjePodataka() {
    ofstream datoteka("podaci.txt"); // Otvaranje datoteke za pisanje

    // Ispis zaglavlja
    datoteka << "Datum Sati Ocjena\n";

    for (int i = 0; i < brojDana; i++) {
        datoteka << podaci[i].datum << " " << podaci[i].sati << " " << podaci[i].ocjena << endl;
    }

    datoteka.close(); // Zatvori datoteku
    cout << "Podaci su uspješno spremljeni u podaci.txt\n";
}

// Glavni program s izbornikom
int main() {
    int izbor;

    do {
        // Prikaz izbornika
        cout << "\n--- Izbornik ---\n";
        cout << "1. Unos podataka\n";
        cout << "2. Ispis podataka\n";
        cout << "3. Ispravak podataka\n";
        cout << "4. Brisanje podataka\n";
        cout << "5. Spremanje podataka\n";
        cout << "0. Izlaz\n";
        cout << "Odaberite opciju (0-5): ";
        cin >> izbor;

        switch (izbor) {
            case 1: unosPodataka(); break;
            case 2: ispisPodataka(); break;
            case 3: ispravakPodataka(); break;
            case 4: brisanjePodataka(); break;
            case 5: spremanjePodataka(); break;
            case 0: cout << "Izlaz iz programa.\n"; break;
            default: cout << "Nepoznata opcija. Pokusajte ponovno.\n";
        }

    } while (izbor != 0);

    return 0;
}
