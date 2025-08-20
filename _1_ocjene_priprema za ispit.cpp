#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Ocjena {
    string ime;
    string prezime;
    string predmet;
    int ocjena;
};

// Funkcije
void unos(vector<Ocjena> &ocene);
void ispis_po_predmetu(const vector<Ocjena> &ocene);
void ispis_po_uceniku(const vector<Ocjena> &ocene);
void ispravak(vector<Ocjena> &ocene);
void brisanje(vector<Ocjena> &ocene);
void citanje_iz_datoteke(vector<Ocjena> &ocene);

int main() {
    vector<Ocjena> ocene;
    int izbor;

    do {
        cout << "\n--- Izbornik ---\n";
        cout << "1. Unos podataka\n";
        cout << "2. Ispis ocjena po predmetima\n";
        cout << "3. Ispis ocjena po ucenicima\n";
        cout << "4. Ispravak ocjene\n";
        cout << "5. Brisanje ocjene\n";
        cout << "6. Ucitavanje podataka iz datoteke\n";
        cout << "0. Izlaz\n";
        cout << "Unesite izbor: ";
        cin >> izbor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Čišćenje buffera

        switch (izbor) {
            case 1: unos(ocene); break;
            case 2: ispis_po_predmetu(ocene); break;
            case 3: ispis_po_uceniku(ocene); break;
            case 4: ispravak(ocene); break;
            case 5: brisanje(ocene); break;
            case 6: citanje_iz_datoteke(ocene); break;
            case 0: cout << "Izlaz iz programa...\n"; break;
            default: cout << "Pogresan unos! Pokusajte ponovo.\n";
        }
    } while (izbor != 0);

    return 0;
}

// 📌 Unos podataka
void unos(vector<Ocjena> &ocene) {
    Ocjena nova;
    
    cout << "Unesite ime: ";
    getline(cin, nova.ime);
    
    cout << "Unesite prezime: ";
    getline(cin, nova.prezime);

    cout << "Unesite naziv predmeta: ";
    getline(cin, nova.predmet);

    do {
        cout << "Unesite ocjenu (1-5): ";
        cin >> nova.ocjena;
        if (nova.ocjena < 1 || nova.ocjena > 5)
            cout << "Ocjena mora biti izmedu 1 i 5! Pokusajte ponovo.\n";
    } while (nova.ocjena < 1 || nova.ocjena > 5);
    
    ocene.push_back(nova);
    cout << "Ocjena uspjesno unesena!\n";
}

// 📌 Ispis ocjena po predmetu
void ispis_po_predmetu(const vector<Ocjena> &ocene) {
    if (ocene.empty()) {
        cout << "Nema upisanih ocjena.\n";
        return;
    }

    string trazeni_predmet;
    cout << "Unesite naziv predmeta: ";
    getline(cin, trazeni_predmet);

    int suma = 0, broj = 0;
    cout << "\nOcjene za predmet: " << trazeni_predmet << "\n";
    for (const auto &o : ocene) {
        if (o.predmet == trazeni_predmet) {
            cout << o.ime << " " << o.prezime << ": " << o.ocjena << endl;
            suma += o.ocjena;
            broj++;
        }
    }
    if (broj > 0)
        cout << "Prosjecna ocjena: " << (float)suma / broj << endl;
    else
        cout << "Nema ocjena za ovaj predmet.\n";
}

// 📌 Ispis ocjena po učeniku
void ispis_po_uceniku(const vector<Ocjena> &ocene) {
    if (ocene.empty()) {
        cout << "Nema upisanih ocjena.\n";
        return;
    }

    string ime, prezime;
    cout << "Unesite ime ucenika: ";
    getline(cin, ime);
    cout << "Unesite prezime ucenika: ";
    getline(cin, prezime);

    int suma = 0, broj = 0;
    cout << "\nOcjene za ucenika: " << ime << " " << prezime << "\n";
    for (const auto &o : ocene) {
        if (o.ime == ime && o.prezime == prezime) {
            cout << o.predmet << ": " << o.ocjena << endl;
            suma += o.ocjena;
            broj++;
        }
    }
    if (broj > 0)
        cout << "Prosjecna ocjena: " << (float)suma / broj << endl;
    else
        cout << "Ucenik nema evidentirane ocjene.\n";
}

// 📌 Ispravak ocjene
void ispravak(vector<Ocjena> &ocene) {
    if (ocene.empty()) {
        cout << "Nema upisanih ocjena.\n";
        return;
    }

    string ime, prezime, predmet;
    cout << "Unesite ime ucenika: ";
    getline(cin, ime);
    cout << "Unesite prezime ucenika: ";
    getline(cin, prezime);
    cout << "Unesite predmet: ";
    getline(cin, predmet);

    for (auto &o : ocene) {
        if (o.ime == ime && o.prezime == prezime && o.predmet == predmet) {
            cout << "Trenutna ocjena: " << o.ocjena << "\n";
            do {
                cout << "Unesite novu ocjenu (1-5): ";
                cin >> o.ocjena;
            } while (o.ocjena < 1 || o.ocjena > 5);
            cout << "Ocjena uspjesno izmijenjena!\n";
            return;
        }
    }
    cout << "Podatak nije pronaden!\n";
}

// 📌 Brisanje ocjene
void brisanje(vector<Ocjena> &ocene) {
    if (ocene.empty()) {
        cout << "Nema upisanih ocjena.\n";
        return;
    }

    string ime, prezime, predmet;
    cout << "Unesite ime ucenika: ";
    getline(cin, ime);
    cout << "Unesite prezime ucenika: ";
    getline(cin, prezime);
    cout << "Unesite predmet: ";
    getline(cin, predmet);

    for (auto it = ocene.begin(); it != ocene.end(); ++it) {
        if (it->ime == ime && it->prezime == prezime && it->predmet == predmet) {
            ocene.erase(it);
            cout << "Ocjena uspjesno obrisana!\n";
            return;
        }
    }
    cout << "Podatak nije pronaden!\n";
}

// 📌 Čitanje iz datoteke
void citanje_iz_datoteke(vector<Ocjena> &ocene) {
    ifstream fajl("ocjene.txt");
    if (!fajl) {
        cout << "Greska u otvaranju datoteke!\n";
        return;
    }

    Ocjena temp;
    while (fajl >> temp.ime >> temp.prezime >> temp.predmet >> temp.ocjena) {
        if (temp.ocjena >= 1 && temp.ocjena <= 5)
            ocene.push_back(temp);
    }

    fajl.close();
    cout << "Podaci su uspjesno ucitani!\n";
}
