#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct proizvod {
    int sifra;
    string naziv;
    float cijena;
    int kolicina;
};

void unos(proizvod skladiste[], int &novi);
bool nepostoji(proizvod skladiste[], int novi, int sifra);
void ispis(proizvod skladiste[], int novi);
void sortiranje(proizvod skladiste[], int novi);
void ispis2(proizvod skladiste[], int novi);
void ucitavanje(proizvod skladiste[], int &novi);
void trazenje(proizvod skladiste[], int novi) {
    int sifra;
    bool pronadjen = false;

    cout << "Unesite sifru proizvoda: ";
    cin >> sifra;

    for (int i = 0; i < novi; i++) {
        if (skladiste[i].sifra == sifra) {
            cout << "Proizvod pronadjen: " << skladiste[i].naziv << endl;
            cout << "Cijena: " << skladiste[i].cijena << " Kolicina: " << skladiste[i].kolicina << endl;
            pronadjen = true;
            break;
        }
    }

    if (!pronadjen) {
        cout << "Proizvod sa ovom sifrom nije pronadjen." << endl;
    }
}

int main() {
    proizvod podaci[1000]; //polje
    int novi = 0; //prvi prazni clan
    int izbor; // izbor funkcije
    do {
        cout << "1. Dodavanje novog proizvoda" << endl;
        cout << "2. Trazenje proizvoda" << endl;
        cout << "3. Sortiranje proizvoda" << endl;
        cout << "4. Ispis proizvoda" << endl;
  cout << "5. Ucitavanje proizvoda iz datoteke" << endl; // NOVA OPCIJA
        cout << "0. Izlaz" << endl << endl;
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(podaci, novi);
                break;
            case 2:
                trazenje(podaci, novi); // Pozivanje funkcije za traženje proizvoda
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
                ucitavanje(podaci, novi); // POZIVAMO FUNKCIJU ZA UČITAVANJE
                break;
            case 0:
                cout << "Izlaz iz programa..." << endl; // Ovo je sada izlaz
                break;
            default:
                cout << "Krivi unos" << endl; // Ako korisnik unese bilo koji drugi broj, tretiraj kao krivi unos
                break;
        }
    } while (izbor != 0); // Petlja se nastavlja dok korisnik ne unese 0

    return 0;
}

void unos(proizvod skladiste[], int &novi) {
    if (novi < 100) {
        proizvod temp;
        cout << "Upisi sifru:";
        cin >> temp.sifra;
        cout << "Upisi naziv:";
        cin >> temp.naziv;
        cout << "Upisi cijenu:";
        cin >> temp.cijena;
        cout << "Upisi kolicinu:";
        cin >> temp.kolicina;
        if (nepostoji(skladiste, novi, temp.sifra)) {
            skladiste[novi].sifra = temp.sifra;
            skladiste[novi].naziv = temp.naziv;
            skladiste[novi].cijena = temp.cijena;
            skladiste[novi].kolicina = temp.kolicina;
            novi++; // slijedeće prazno polje
        } else {
            cout << "Taj proizvod već postoji" << endl;
        }
    }
}

bool nepostoji(proizvod skladiste[], int novi, int sifra) {
    for (int i = 0; i < novi; i++) {
        if (sifra == skladiste[i].sifra) {
            return false; // Proizvod sa tom šifrom već postoji
        }
    }
    return true; // Proizvod sa tom šifrom ne postoji
}

void ispis(proizvod skladiste[], int novi) {
    for (int i = 0; i < novi; i++) {
        cout << i + 1 << " - " << skladiste[i].sifra;
        cout << " " << skladiste[i].naziv;
        cout << " " << skladiste[i].cijena;
        cout << " " << skladiste[i].kolicina << endl;
    }
}

void sortiranje(proizvod skladiste[], int novi) {
    for (int n = novi; n > 1; n--) {
        int max = 0;
        for (int j = 1; j < n; j++) {
            if (skladiste[j].sifra > skladiste[max].sifra) {
                max = j;
            }
        }
        proizvod temp;
        temp = skladiste[n - 1];
        skladiste[n - 1] = skladiste[max];
        skladiste[max] = temp;
    }
}

void ispis2(proizvod skladiste[], int novi) {
    int broj = 0;
    float prosjek = 0;
    for (int i = 0; i < novi; i++) {
        broj += skladiste[i].kolicina;
        prosjek += skladiste[i].cijena;
    }
    cout << "Ukupna kolicina proizvoda u skladistu: " << broj << endl;
    cout << "Prosjecna cijena proizvoda u skladistu: " << prosjek / novi << endl;
}

void ucitavanje(proizvod skladiste[], int &novi) {
    ifstream fajl("podaci.txt");
    if (fajl.is_open()) {
        fajl >> skladiste[novi].sifra;
        while (!fajl.eof()) {
            fajl >> skladiste[novi].naziv;
            fajl >> skladiste[novi].cijena;
            fajl >> skladiste[novi].kolicina;
            novi++;
            fajl >> skladiste[novi].sifra;
        }
        fajl.close();
    } else {
        cout << "Greska u otvaranju datoteke" << endl;
        system("pause");
    }
}

