#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Radnik {
    string ime_prezime;
    int radna_knjizica;
    string datum_rodjenja;
    float placa;
    string odjel;
};

// Maksimalan broj radnika
const int MAX_RADNIKA = 100;

// Funkcije
void unos_radnika(vector<Radnik> &radnici);
void izmjena_radnika(vector<Radnik> &radnici);
void ispis_svih_radnika(const vector<Radnik> &radnici);
void pretraga_po_godini(const vector<Radnik> &radnici);
void spremi_u_datoteku(const vector<Radnik> &radnici);

int main() {
    vector<Radnik> radnici;
    int izbor;

    do {
        cout << "\n--- IZBORNIK ---\n";
        cout << "1. Unos novog radnika\n";
        cout << "2. Izmjena podataka o radniku\n";
        cout << "3. Ispis svih radnika\n";
        cout << "4. Pretraga radnika po godini rođenja\n";
        cout << "5. Spremanje podataka u datoteku\n";
        cout << "0. Izlaz\n";
        cout << "Unesite izbor: ";
        cin >> izbor;
        cin.ignore();  // Čišćenje buffera

        switch (izbor) {
            case 1: unos_radnika(radnici); break;
            case 2: izmjena_radnika(radnici); break;
            case 3: ispis_svih_radnika(radnici); break;
            case 4: pretraga_po_godini(radnici); break;
            case 5: spremi_u_datoteku(radnici); break;
            case 0: cout << "Izlaz iz programa...\n"; break;
            default: cout << "Pogrešan unos! Pokušajte ponovo.\n";
        }
    } while (izbor != 0);

    return 0;
}

// 📌 Unos novog radnika
void unos_radnika(vector<Radnik> &radnici) {
    if (radnici.size() >= MAX_RADNIKA) {
        cout << "Polje je popunjeno!\n";
        return;
    }

    Radnik novi;
    cout << "Trenutno unešenih radnika: " << radnici.size() << "\n";
    cout << "Unesite ime i prezime: ";
    getline(cin, novi.ime_prezime);
    
    cout << "Unesite broj radne knjižice: ";
    cin >> novi.radna_knjizica;
    cin.ignore();

    cout << "Unesite datum rođenja (DD.MM.YYYY): ";
    getline(cin, novi.datum_rodjenja);

    cout << "Unesite plaću: ";
    cin >> novi.placa;
    cin.ignore();

    cout << "Unesite odjel: ";
    getline(cin, novi.odjel);

    radnici.push_back(novi);
    cout << "Radnik uspješno dodan!\n";
}

// 📌 Izmjena podataka radnika
void izmjena_radnika(vector<Radnik> &radnici) {
    if (radnici.empty()) {
        cout << "Nema unesenih radnika.\n";
        return;
    }

    int knjizica;
    cout << "Unesite broj radne knjižice radnika za izmjenu: ";
    cin >> knjizica;
    cin.ignore();

    for (auto &r : radnici) {
        if (r.radna_knjizica == knjizica) {
            cout << "Podaci o radniku: " << r.ime_prezime << " " << r.datum_rodjenja << ", Plaća: " << r.placa << ", Odjel: " << r.odjel << "\n";
            cout << "Unesite nove podatke: \n";

            cout << "Ime i prezime: ";
            getline(cin, r.ime_prezime);

            cout << "Datum rođenja: ";
            getline(cin, r.datum_rodjenja);

            cout << "Plaća: ";
            cin >> r.placa;
            cin.ignore();

            cout << "Odjel: ";
            getline(cin, r.odjel);

            cout << "Podaci uspješno izmijenjeni!\n";
            return;
        }
    }

    cout << "Radnik s navedenim brojem radne knjižice ne postoji.\n";
}

// 📌 Ispis svih radnika
void ispis_svih_radnika(const vector<Radnik> &radnici) {
    if (radnici.empty()) {
        cout << "Nema unesenih radnika.\n";
        return;
    }

    cout << "\n--- POPIS SVIH RADNIKA ---\n";
    for (const auto &r : radnici) {
        cout << "Ime i prezime: " << r.ime_prezime << ", Knjižica: " << r.radna_knjizica
             << ", Datum rođenja: " << r.datum_rodjenja << ", Plaća: " << r.placa
             << ", Odjel: " << r.odjel << endl;
    }
}

// 📌 Pretraga radnika po godini rođenja
void pretraga_po_godini(const vector<Radnik> &radnici) {
    if (radnici.empty()) {
        cout << "Nema unesenih radnika.\n";
        return;
    }

    string godina;
    cout << "Unesite godinu rođenja za pretragu: ";
    cin >> godina;

    int broj = 0;
    float ukupna_placa = 0;

    cout << "\n--- RADNICI ROĐENI " << godina << " ---\n";
    for (const auto &r : radnici) {
        if (r.datum_rodjenja.substr(6, 4) == godina) {
            cout << "Ime: " << r.ime_prezime << ", Plaća: " << r.placa << endl;
            ukupna_placa += r.placa;
            broj++;
        }
    }

    if (broj > 0) {
        cout << "Prosječna plaća: " << (ukupna_placa / broj) << endl;
        cout << "Prosječna starost: " << (2024 - stoi(godina)) << " godina\n";
    } else {
        cout << "Ne postoji niti jedan radnik s navedenom godinom rođenja.\n";
    }
}

// 📌 Spremanje podataka u datoteku
void spremi_u_datoteku(const vector<Radnik> &radnici) {
    ofstream fajl("podaci.txt");
    if (!fajl) {
        cout << "Greška pri otvaranju datoteke!\n";
        return;
    }

    fajl << radnici.size() << "\n";
    for (const auto &r : radnici) {
        fajl << r.ime_prezime << " " << r.radna_knjizica << " " << r.datum_rodjenja << " "
             << r.placa << " " << r.odjel << "\n";
    }

    fajl.close();
    cout << "Podaci su uspješno spremljeni u datoteku.\n";
}
