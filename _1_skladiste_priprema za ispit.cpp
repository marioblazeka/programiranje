#include <iostream>
#include <string>
#include <fstream>

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

int main() {
    proizvod podaci[100]; // polje
    int novi = 0; // prvi prazni član
    int izbor; // izbor funkcije
    
    do {
        cout << "1. Dodavanje novog proizvoda" << endl;
        cout << "2. Trazenje proizvoda" << endl;
        cout << "3. Sortiranje proizvoda" << endl;
        cout << "4. Ispis proizvoda" << endl;
        cout << "0. Izlaz" << endl << endl;
        cout << "Izbor: ";
        cin >> izbor;
        
        switch (izbor) {
            case 1:
                unos(podaci, novi);
                break;
            case 2:
                // funkcija za traženje nije implementirana
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
                    cout << "Nije unesen niti 1 proizvod" << endl;
                break;
            case 0:
                cout << "Izlaz iz programa." << endl;
                break;
            default:
                cout << "Krivi unos" << endl;
        }
    } while (izbor != 0);

    return 0;
}

void unos(proizvod skladiste[], int &novi) {
    if (novi < 100) {
        proizvod temp;
        cout << "Upisi sifru: ";
        cin >> temp.sifra;
        cout << "Upisi naziv: ";
        cin.ignore();
        getline(cin, temp.naziv);
        cout << "Upisi cijenu: ";
        cin >> temp.cijena;
        cout << "Upisi kolicinu: ";
        cin >> temp.kolicina;
        
        if (nepostoji(skladiste, novi, temp.sifra)) {
            skladiste[novi] = temp;
            novi++;
        } else {
            cout << "Taj proizvod vec postoji" << endl;
        }
    }
}

bool nepostoji(proizvod skladiste[], int novi, int sifra) {
    for (int i = 0; i < novi; i++) {
        if (sifra == skladiste[i].sifra) return false;
    }
    return true;
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
        swap(skladiste[n - 1], skladiste[max]);
    }
}

void ispis2(proizvod skladiste[], int novi) {
    int broj = 0;
    float prosjek = 0.0;
    
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
        while (fajl >> skladiste[novi].sifra 
                    >> skladiste[novi].naziv 
                    >> skladiste[novi].cijena 
                    >> skladiste[novi].kolicina) {
            novi++;
        }
        fajl.close();
    } else {
        cout << "Greska u otvaranju datoteke" << endl;
    }
}
