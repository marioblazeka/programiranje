#include <iostream>  // Omogućava rad sa unosom/izlazom (cin, cout)
#include <string>    // Omogućava rad sa stringovima
#include <fstream>   // Omogućava rad sa fajlovima

using namespace std; // Koristimo standardni C++ namespace, da ne pišemo std::

// ----------------------
// Definicija strukture "proizvod"
// ----------------------
struct proizvod {
    int sifra;      // Jedinstvena šifra proizvoda
    string naziv;   // Naziv proizvoda
    float cijena;   // Cena proizvoda
    int kolicina;   // Dostupna količina proizvoda
};

// ----------------------
// Deklaracije funkcija
// ----------------------
void unos(proizvod skladiste[], int &novi);
bool nepostoji(proizvod skladiste[], int novi, int sifra);
void ispis(proizvod skladiste[], int novi);
void sortiranje(proizvod skladiste[], int novi);
void ispis2(proizvod skladiste[], int novi);
void ucitavanje(proizvod skladiste[], int &novi);
void trazenje(proizvod skladiste[], int novi);

// ----------------------
// Funkcija "trazenje" - Pretraga proizvoda po šifri
// ----------------------
void trazenje(proizvod skladiste[], int novi) {
    int sifra;
    bool pronadjen = false; // Promenljiva koja označava da li je proizvod pronađen

    cout << "Unesite sifru proizvoda: ";
    cin >> sifra;

    for (int i = 0; i < novi; i++) {
        if (skladiste[i].sifra == sifra) { // Ako pronađe proizvod sa istom šifrom
            cout << "Proizvod pronadjen: " << skladiste[i].naziv << endl;
            cout << "Cijena: " << skladiste[i].cijena << " Kolicina: " << skladiste[i].kolicina << endl;
            pronadjen = true;
            break; // Prekidamo pretragu jer smo našli proizvod
        }
    }

    if (!pronadjen) {
        cout << "Proizvod sa ovom sifrom nije pronadjen." << endl;
    }
}

// ----------------------
// Glavna funkcija - "main"
// ----------------------
int main() {
    proizvod podaci[100]; // Polje proizvoda, kapaciteta 100
    int novi = 0;         // Broj trenutno unetih proizvoda
    int izbor;            // Varijabla za unos korisničkog izbora

    do {
        // Ispis menija korisniku
        cout << "1. Dodavanje novog proizvoda" << endl;
        cout << "2. Trazenje proizvoda" << endl;
        cout << "3. Sortiranje proizvoda" << endl;
        cout << "4. Ispis proizvoda" << endl;
        cout << "5. Ucitavanje proizvoda iz datoteke" << endl;
        cout << "0. Izlaz" << endl << endl;
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(podaci, novi);
                break;
            case 2:
                trazenje(podaci, novi);
                break;
            case 3:
                if (novi > 1)
                    sortiranje(podaci, novi);
                else
                    cout << "Nema dovoljno proizvoda za sort" << endl;
                break;
            case 4:
                if (novi > 0)
                    ispis(podaci, novi);
                else
                    cout << "Nije unešen niti 1 proizvod" << endl;
                break;
            case 5:
                ucitavanje(podaci, novi);
                break;
            case 0:
                cout << "Izlaz iz programa..." << endl;
                break;
            default:
                cout << "Krivi unos" << endl;
                break;
        }
    } while (izbor != 0);

    return 0;
}

// ----------------------
// Funkcija "unos" - Unos novog proizvoda
// ----------------------
void unos(proizvod skladiste[], int &novi) {
    if (novi < 100) { // Provera da li ima mesta za novi unos
        proizvod temp;
        cout << "Upisi sifru: ";
        cin >> temp.sifra;
        cout << "Upisi naziv: ";
        cin >> temp.naziv;
        cout << "Upisi cijenu: ";
        cin >> temp.cijena;
        cout << "Upisi kolicinu: ";
        cin >> temp.kolicina;

        if (nepostoji(skladiste, novi, temp.sifra)) {
            skladiste[novi] = temp;
            novi++; // Povećavamo broj proizvoda
        } else {
            cout << "Taj proizvod već postoji" << endl;
        }
    }
}

// ----------------------
// Funkcija "nepostoji" - Proverava da li proizvod sa šifrom već postoji
// ----------------------
bool nepostoji(proizvod skladiste[], int novi, int sifra) {
    for (int i = 0; i < novi; i++) {
        if (sifra == skladiste[i].sifra) {
            return false;
        }
    }
    return true;
}

// ----------------------
// Funkcija "ispis" - Ispisuje listu proizvoda
// ----------------------
void ispis(proizvod skladiste[], int novi) {
    for (int i = 0; i < novi; i++) {
        cout << i + 1 << " - " << skladiste[i].sifra << " "
             << skladiste[i].naziv << " "
             << skladiste[i].cijena << " "
             << skladiste[i].kolicina << endl;
    }
}

// ----------------------
// Funkcija "sortiranje" - Sortira proizvode po šifri (Selection Sort)
// ----------------------
void sortiranje(proizvod skladiste[], int novi) {
    for (int n = novi; n > 1; n--) {
        int max = 0;
        for (int j = 1; j < n; j++) {
            if (skladiste[j].sifra > skladiste[max].sifra) {
                max = j;
            }
        }
        swap(skladiste[n - 1], skladiste[max]);
    }
}

// ----------------------
// Funkcija "ucitavanje" - Učitava proizvode iz fajla
// ----------------------
void ucitavanje(proizvod skladiste[], int &novi) {
    ifstream fajl("podaci.txt");
    if (!fajl) {
        cout << "Greska pri otvaranju datoteke" << endl;
        return;
    }
    while (fajl >> skladiste[novi].sifra) {
        fajl >> skladiste[novi].naziv;
        fajl >> skladiste[novi].cijena;
        fajl >> skladiste[novi].kolicina;
        novi++;
    }
    fajl.close();
}
