#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct kuhari {
    int sifra;
    long long oib; // 11-znamenkasti OIB
    string imeiprez;
    int bodovi;
    bool IIkrug;
};

// Funkcija za unos novog natjecatelja
void prijava(kuhari natjecatelji[], int &l) {
    cout << "Do sada je prijavljeno: " << l << " natjecatelja." << endl;
    if (l >= 50) {
        cout << "Dosegnut je maksimalni broj unosa." << endl;
        return;
    }

    kuhari novi;
    novi.sifra = l + 1;

    do {
        cout << "Unesite OIB (11 znamenki): ";
        cin >> novi.oib;
    } while (novi.oib < 10000000000 || novi.oib > 99999999999); // Validacija OIB-a

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Unesite ime i prezime: ";
    getline(cin, novi.imeiprez);

    novi.bodovi = 0;
    novi.IIkrug = false;

    natjecatelji[l] = novi;
    l++;
}

// Funkcija za upis bodova ili izmjenu
void izmjena(kuhari natjecatelji[], int l) {
    int sifra;
    cout << "Unesite šifru natjecatelja za izmjenu: ";
    cin >> sifra;
    if (sifra < 1 || sifra > l) {
        cout << "Nepostojeća šifra." << endl;
        return;
    }
    kuhari &n = natjecatelji[sifra - 1];
    cout << "Trenutni OIB: " << n.oib << ", ime: " << n.imeiprez << ", bodovi: " << n.bodovi << endl;

    cout << "Unesite novi OIB: ";
    cin >> n.oib;
    cin.ignore();
    cout << "Unesite novo ime i prezime: ";
    getline(cin, n.imeiprez);
    cout << "Unesite nove bodove: ";
    cin >> n.bodovi;
    n.IIkrug = false;
}

// Funkcija za upis bodova
void bodovi(kuhari natjecatelji[], int l) {
    if (l == 0) {
        cout << "Nema prijavljenih natjecatelja." << endl;
        return;
    }

    int opcija;
    do {
        cout << "\n1. Upis bodova\n2. Izmjena podataka\nIzbor: ";
        cin >> opcija;

        switch (opcija) {
        case 1:
            for (int i = 0; i < l; i++) {
                cout << "Natjecatelj #" << natjecatelji[i].sifra << " - " << natjecatelji[i].imeiprez << endl;
                cout << "Unesite bodove: ";
                cin >> natjecatelji[i].bodovi;
                natjecatelji[i].IIkrug = false;
            }
            break;
        case 2:
            izmjena(natjecatelji, l);
            break;
        default:
            cout << "Pogrešan izbor." << endl;
        }
    } while (opcija != 1 && opcija != 2);
}

// Izračun tko ulazi u drugi krug
void izracun(kuhari natjecatelji[], int l) {
    if (l == 0) return;

    int max_bodovi = 0;
    for (int i = 0; i < l; i++) {
        if (natjecatelji[i].bodovi > max_bodovi) {
            max_bodovi = natjecatelji[i].bodovi;
        }
    }

    double prag = max_bodovi * 0.8;
    for (int i = 0; i < l; i++) {
        if (natjecatelji[i].bodovi >= prag) {
            natjecatelji[i].IIkrug = true;
        }
    }

    cout << "Izračun završen. Prag za drugi krug: " << prag << " bodova." << endl;
}

// Ispis natjecatelja
void ispis(kuhari natjecatelji[], int l) {
    int izbor;
    cout << "\n1. Ispis svih\n2. Ispis natjecatelja u 2. krugu\nIzbor: ";
    cin >> izbor;

    for (int i = 0; i < l; i++) {
        if (izbor == 2 && !natjecatelji[i].IIkrug) continue;
        cout << natjecatelji[i].sifra << " " << natjecatelji[i].oib << " " 
             << natjecatelji[i].imeiprez << " " << natjecatelji[i].bodovi 
             << " " << (natjecatelji[i].IIkrug ? "DA" : "NE") << endl;
    }
}

// Spremanje u datoteku
void spremanje(kuhari natjecatelji[], int l) {
    ofstream out("Izvoz.txt");
    if (!out) {
        cout << "Greška pri otvaranju datoteke!" << endl;
        return;
    }

    out << "sifra OIB ime_prezime bodovi 2KN\n";
    for (int i = 0; i < l; i++) {
        out << natjecatelji[i].sifra << " " << natjecatelji[i].oib << " " 
            << natjecatelji[i].imeiprez << " " << natjecatelji[i].bodovi << " " 
            << (natjecatelji[i].IIkrug ? 1 : 0) << "\n";
    }

    out.close();
    cout << "Podaci su spremljeni u 'Izvoz.txt'." << endl;
}

// Glavna funkcija
int main() {
    kuhari natjecatelji[50];
    int izbor;
    int broj_natjecatelja = 0;

    do {
        cout << "\n***** I Z B O R N I K *****\n";
        cout << "1. Prijava novog natjecatelja\n";
        cout << "2. Upis bodova natjecatelja\n";
        cout << "3. Izračun/odabir ulaska u 2. krug\n";
        cout << "4. Ispis podataka o natjecateljima\n";
        cout << "5. Spremanje podataka u datoteku Izvoz.txt\n";
        cout << "0. Izlaz iz programa\n";
        cout << "Unesite izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: prijava(natjecatelji, broj_natjecatelja); break;
            case 2: bodovi(natjecatelji, broj_natjecatelja); break;
            case 3: izracun(natjecatelji, broj_natjecatelja); break;
            case 4: ispis(natjecatelji, broj_natjecatelja); break;
            case 5: spremanje(natjecatelji, broj_natjecatelja); break;
            case 0: cout << "Izlaz iz programa..." << endl; break;
            default: cout << "Pogrešan unos, pokušajte ponovno!" << endl;
        }
    } while (izbor != 0);

    return 0;
}
