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
    proizvod skladiste[100]; // polje
    int novi = 0;            // prvi prazni clan
    int izbor;               // izbor funkcije
    do {
        system("cls"); // brisanje ekrana
        cout << "1. Dodavanje novog proizvoda" << endl;
        cout << "2. Statistika proizvoda" << endl;
        cout << "3. Sortiranje proizvoda" << endl;
        cout << "4. Ispis proizvoda" << endl;
        cout << "5. Ucitavanje iz datoteke" << endl;
        cout << "0. Izlaz" << endl
             << endl;
        cout << "Izbor: ";

        cin >> izbor;
        switch (izbor) {
        case 1:
            unos(skladiste, novi);
            break;

        case 2:
            ispis2(skladiste, novi);
            break;

        case 3:
            sortiranje(skladiste, novi);
            break;

        case 4:
            ispis(skladiste, novi);
            break;

        case 5:
            ucitavanje(skladiste, novi);
            break;

        case 0:
            cout << "Izlaz iz programa\n";
            break;

        default:
            cout << "Krivi unos" << endl;
        }

        system("pause");
    } while (izbor != 0);

    return 0;
}

void unos(proizvod skladiste[], int &novi) {
    if (novi < 100) {
        proizvod temp;
        cout << "Upisi sifru: ";
        cin >> temp.sifra;
        cin.ignore(); // da pokupi enter
        cout << "Upisi naziv: ";
        getline(cin, temp.naziv); // da dozvoli naziv sa razmacima
        cout << "Upisi cijenu: ";
        cin >> temp.cijena;
        cout << "Upisi kolicinu: ";
        cin >> temp.kolicina;
        if (nepostoji(skladiste, novi, temp.sifra)) {
            skladiste[novi] = temp;
            novi++;
        } else
            cout << "Taj proizvod vec postoji" << endl;
    }
}

bool nepostoji(proizvod skladiste[], int novi, int sifra) {
    for (int i = 0; i < novi; i++) {
        if (sifra == skladiste[i].sifra)
            return false;
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
            if (skladiste[j].sifra > skladiste[max].sifra)
                max = j;
        }
        proizvod temp = skladiste[n - 1];
        skladiste[n - 1] = skladiste[max];
        skladiste[max] = temp;
    }
    cout << "Sortiranje zavrseno." << endl;
}

void ispis2(proizvod skladiste[], int novi) {
    int broj = 0;
    float prosjek = 0;
    for (int i = 0; i < novi; i++) {
        broj += skladiste[i].kolicina;
        prosjek += skladiste[i].cijena;
    }
    if (novi > 0) {
        cout << "Ukupna kolicina proizvoda u skladistu: " << broj << endl;
        cout << "Prosjecna cijena proizvoda u skladistu: " << prosjek / novi << endl;
    } else {
        cout << "Skladiste je prazno." << endl;
    }
}

void ucitavanje(proizvod skladiste[], int &novi) {
    ifstream fajl("podaci.txt");
    if (fajl.is_open()) {
        while (fajl >> skladiste[novi].sifra) {
            fajl >> skladiste[novi].naziv;
            fajl >> skladiste[novi].cijena;
            fajl >> skladiste[novi].kolicina;
            novi++;
        }
        fajl.close();
        cout << "Podaci ucitani." << endl;
    } else {
        cout << "Greska u otvaranju datoteke" << endl;
    }
}

