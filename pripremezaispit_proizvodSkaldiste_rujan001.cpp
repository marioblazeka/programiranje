#include <iostream>   // Za cout, cin
#include <string>     // Za std::string
#include <fstream>    // Za rad s datotekama (ifstream)

using namespace std;

// Struktura koja opisuje jedan proizvod u skladištu
struct proizvod {
    int sifra;       // Jedinstvena šifra proizvoda
    string naziv;    // Naziv proizvoda
    float cijena;    // Cijena proizvoda
    int kolicina;    // Količina proizvoda na zalihi
};

// Deklaracije funkcija (prototipovi)
void unos(proizvod skladiste[], int &novi);
bool nepostoji(proizvod skladiste[], int novi, int sifra);
void ispis(proizvod skladiste[], int novi);
void sortiranje(proizvod skladiste[], int novi);
void ispis2(proizvod skladiste[], int novi);
void ucitavanje(proizvod skladiste[], int &novi);

int main() {
    proizvod podaci[100]; // Polje od maksimalno 100 proizvoda
    int novi = 0;         // Broj unesenih proizvoda (indeks sljedećeg slobodnog mjesta)
    int izbor;            // Izbor korisnika iz menija

    do {
        // Ispis glavnog menija
        cout << "1. Dodavanje novog proizvoda" << endl;
        cout << "2. Trazenje proizvoda" << endl;
        cout << "3. Sortiranje proizvoda" << endl;
        cout << "4. Ispis proizvoda" << endl;
        cout << "5. Statistika (ukupna kolicina i prosjek cijena)" << endl;
        cout << "6. Ucitavanje iz datoteke" << endl;
        cout << "0. Izlaz" << endl << endl;

        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(podaci, novi);
                break;
            case 2:
                // Funkcija za pretragu nije implementirana
                cout << "Pretraga nije implementirana." << endl;
                break;
            case 3:
                if (novi > 1)
                    sortiranje(podaci, novi);
                else
                    cout << "Nema dovoljno proizvoda za sortiranje." << endl;
                break;
            case 4:
                if (novi > 0)
                    ispis(podaci, novi);
                else
                    cout << "Nije unesen niti jedan proizvod." << endl;
                break;
            case 5:
                if (novi > 0)
                    ispis2(podaci, novi);
                else
                    cout << "Nema proizvoda za statistiku." << endl;
                break;
            case 6:
                ucitavanje(podaci, novi);
                break;
            case 0:
                cout << "Izlaz iz programa." << endl;
                break;
            default:
                cout << "Krivi unos." << endl;
        }

    } while (izbor != 0);

    return 0;
}

// Funkcija za unos novog proizvoda
void unos(proizvod skladiste[], int &novi) {
    if (novi >= 100) {
        cout << "Skladiste je puno!" << endl;
        return;
    }

    proizvod temp;

    cout << "Upisi sifru: ";
    cin >> temp.sifra;
    cout << "Upisi naziv: ";
    cin >> temp.naziv;
    cout << "Upisi cijenu: ";
    cin >> temp.cijena;
    cout << "Upisi kolicinu: ";
    cin >> temp.kolicina;

    // Provjera postoji li već ta šifra
    if (nepostoji(skladiste, novi, temp.sifra)) {
        skladiste[novi] = temp; // Direktno spremanje strukture
        novi++; // Pomak indeksa na sljedeće prazno mjesto
    } else {
        cout << "Taj proizvod vec postoji!" << endl;
    }
}

// Provjerava postoji li proizvod s određenom šifrom
bool nepostoji(proizvod skladiste[], int novi, int sifra) {
    for (int i = 0; i < novi; i++) {
        if (skladiste[i].sifra == sifra)
            return false; // Već postoji
    }
    return true; // Ne postoji
}

// Ispis svih proizvoda
void ispis(proizvod skladiste[], int novi) {
    cout << "Lista proizvoda:" << endl;
    for (int i = 0; i < novi; i++) {
        cout << i + 1 << ". "
             << "Sifra: " << skladiste[i].sifra << ", "
             << "Naziv: " << skladiste[i].naziv << ", "
             << "Cijena: " << skladiste[i].cijena << ", "
             << "Kolicina: " << skladiste[i].kolicina << endl;
    }
}

// Sortiranje po šifri silazno (najveća šifra prva)
void sortiranje(proizvod skladiste[], int novi) {
    for (int n = novi; n > 1; n--) {
        int maxIndex = 0;
        for (int j = 1; j < n; j++) {
            if (skladiste[j].sifra > skladiste[maxIndex].sifra)
                maxIndex = j;
        }
        // Zamjena najvećeg s posljednjim u trenutnom nesortiranom dijelu
        proizvod temp = skladiste[n - 1];
        skladiste[n - 1] = skladiste[maxIndex];
        skladiste[maxIndex] = temp;
    }
}

// Ispis statistike: ukupna količina i prosječna cijena
void ispis2(proizvod skladiste[], int novi) {
    int ukupnaKolicina = 0;
    float sumaCijena = 0.0f;

    for (int i = 0; i < novi; i++) {
        ukupnaKolicina += skladiste[i].kolicina;
        sumaCijena += skladiste[i].cijena;
    }

    cout << "Ukupna kolicina proizvoda: " << ukupnaKolicina << endl;
    cout << "Prosjecna cijena proizvoda: " << (sumaCijena / novi) << endl;
}

// Učitavanje proizvoda iz datoteke
void ucitavanje(proizvod skladiste[], int &novi) {
    ifstream fajl("podaci.txt");

    if (!fajl.is_open()) {
        cout << "Greska u otvaranju datoteke!" << endl;
        return;
    }

    proizvod temp;
    while (fajl >> temp.sifra >> temp.naziv >> temp.cijena >> temp.kolicina) {
        if (novi < 100) {
            skladiste[novi] = temp;
            novi++;
        } else {
            cout << "Skladiste je puno, ne mogu ucitati vise." << endl;
            break;
        }
    }

    fajl.close();
}
