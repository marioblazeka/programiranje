#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Odrzavanje {
    int redni_broj;
    string vrsta;
    string naziv_racunala;
    int trajanje;  // Trajanje u satima
};

// Maksimalan broj unosa
const int MAX_ODRZAVANJA = 100;

// Funkcije
void unos_odrzavanja(vector<Odrzavanje> &odrzavanja);
void izmjena_odrzavanja(vector<Odrzavanje> &odrzavanja);
void brisanje_odrzavanja(vector<Odrzavanje> &odrzavanja);
void pretraga_odrzavanja(const vector<Odrzavanje> &odrzavanja);
void spremi_u_datoteku(const vector<Odrzavanje> &odrzavanja);

int main() {
    vector<Odrzavanje> odrzavanja;
    int izbor;

    do {
        cout << "\n--- IZBORNIK ---\n";
        cout << "1. Unos novog održavanja/popravka\n";
        cout << "2. Izmjena održavanja/popravka\n";
        cout << "3. Brisanje održavanja/popravka\n";
        cout << "4. Pretraga održavanja/popravki\n";
        cout << "5. Spremanje podataka u datoteku\n";
        cout << "0. Izlaz\n";
        cout << "Unesite izbor: ";
        cin >> izbor;
        cin.ignore();  // Čišćenje buffera

        switch (izbor) {
            case 1: unos_odrzavanja(odrzavanja); break;
            case 2: izmjena_odrzavanja(odrzavanja); break;
            case 3: brisanje_odrzavanja(odrzavanja); break;
            case 4: pretraga_odrzavanja(odrzavanja); break;
            case 5: spremi_u_datoteku(odrzavanja); break;
            case 0: cout << "Izlaz iz programa...\n"; break;
            default: cout << "Pogrešan unos! Pokušajte ponovo.\n";
        }
    } while (izbor != 0);

    return 0;
}

// 📌 Unos novog održavanja/popravka
void unos_odrzavanja(vector<Odrzavanje> &odrzavanja) {
    if (odrzavanja.size() >= MAX_ODRZAVANJA) {
        cout << "Polje je popunjeno!\n";
        return;
    }

    Odrzavanje novo;
    novo.redni_broj = odrzavanja.size() + 1;

    cout << "Trenutno unešenih održavanja/popravaka: " << odrzavanja.size() << "\n";
    cout << "Unesite vrstu održavanja/popravka: ";
    getline(cin, novo.vrsta);

    cout << "Unesite naziv računala: ";
    getline(cin, novo.naziv_racunala);

    cout << "Unesite trajanje (u satima): ";
    cin >> novo.trajanje;
    cin.ignore();

    odrzavanja.push_back(novo);
    cout << "Održavanje/popravak uspješno dodan!\n";
}

// 📌 Izmjena održavanja/popravka
void izmjena_odrzavanja(vector<Odrzavanje> &odrzavanja) {
    if (odrzavanja.empty()) {
        cout << "Nema unesenih održavanja/popravaka.\n";
        return;
    }

    int broj;
    cout << "Unesite redni broj održavanja/popravka za izmjenu: ";
    cin >> broj;
    cin.ignore();

    for (auto &o : odrzavanja) {
        if (o.redni_broj == broj) {
            cout << "Podaci o održavanju/popravku: " << o.vrsta << " - " << o.naziv_racunala << " (" << o.trajanje << " sati)\n";
            cout << "Unesite nove podatke: \n";

            cout << "Vrsta održavanja/popravka: ";
            getline(cin, o.vrsta);

            cout << "Naziv računala: ";
            getline(cin, o.naziv_racunala);

            cout << "Trajanje (u satima): ";
            cin >> o.trajanje;
            cin.ignore();

            cout << "Podaci uspješno izmijenjeni!\n";
            return;
        }
    }

    cout << "Održavanje/popravak s tim brojem ne postoji.\n";
}

// 📌 Brisanje održavanja/popravka
void brisanje_odrzavanja(vector<Odrzavanje> &odrzavanja) {
    if (odrzavanja.empty()) {
        cout << "Nema unesenih održavanja/popravaka.\n";
        return;
    }

    int broj;
    cout << "Unesite redni broj održavanja/popravka za brisanje: ";
    cin >> broj;
    cin.ignore();

    for (size_t i = 0; i < odrzavanja.size(); i++) {
        if (odrzavanja[i].redni_broj == broj) {
            cout << "Podaci o održavanju/popravku: " << odrzavanja[i].vrsta << " - " << odrzavanja[i].naziv_racunala << " (" << odrzavanja[i].trajanje << " sati)\n";
            cout << "Jeste li sigurni da želite obrisati? (da/ne): ";
            string potvrda;
            getline(cin, potvrda);

            if (potvrda == "da") {
                odrzavanja.erase(odrzavanja.begin() + i);
                cout << "Održavanje/popravak obrisan.\n";
            } else {
                cout << "Brisanje otkazano.\n";
            }
            return;
        }
    }

    cout << "Održavanje/popravak s tim brojem ne postoji.\n";
}

// 📌 Pretraživanje održavanja/popravki
void pretraga_odrzavanja(const vector<Odrzavanje> &odrzavanja) {
    if (odrzavanja.empty()) {
        cout << "Nema unesenih održavanja/popravaka.\n";
        return;
    }

    string pojam;
    cout << "Unesite pojam za pretragu: ";
    getline(cin, pojam);

    bool nadjeno = false;
    cout << "\n--- REZULTATI PRETRAGE ---\n";
    for (const auto &o : odrzavanja) {
        if (o.vrsta.find(pojam) != string::npos || o.naziv_racunala.find(pojam) != string::npos) {
            cout << "Redni broj: " << o.redni_broj << ", Vrsta: " << o.vrsta << ", Računalo: " << o.naziv_racunala << ", Trajanje: " << o.trajanje << " sati\n";
            nadjeno = true;
        }
    }

    if (!nadjeno) {
        cout << "Nema održavanja/popravki s tim pojmom.\n";
    }
}

// 📌 Spremanje podataka u datoteku
void spremi_u_datoteku(const vector<Odrzavanje> &odrzavanja) {
    ofstream fajl("baza.txt");
    if (!fajl) {
        cout << "Greška pri otvaranju datoteke!\n";
        return;
    }

    for (const auto &o : odrzavanja) {
        fajl << o.redni_broj << "|" << o.vrsta << "|" << o.naziv_racunala << "|" << o.trajanje << "\n";
    }

    fajl << "–kraj zapisa–\n";
    fajl.close();
    cout << "Podaci su uspješno spremljeni u datoteku.\n";
}
