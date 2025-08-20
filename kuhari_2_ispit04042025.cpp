#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct kuhari {
    int sifra;
    int oib[11];         // OIB kao niz od 11 znamenki
    string imeiprez;
    int bodovi;
    bool IIkrug;
};

// Funkcija za prijavu natjecatelja
void prijava(kuhari natjecatelji[], int &l) {
    cout << "Do sada je prijavljeno: " << l << " natjecatelja." << endl;
    if (l >= 50) {
        cout << "Dosegnut je maksimalni broj unosa." << endl;
        return;
    }

    kuhari novi;
    novi.sifra = l + 1;

    cout << "Unesite OIB znamenku po znamenku (11 znamenki): ";
    for (int i = 0; i < 11; i++) {
        int znamenka;
        cin >> znamenka;
        if (znamenka < 0 || znamenka > 9) {
            cout << "Svaka znamenka mora biti između 0 i 9. Pokušajte ponovno.\n";
            i--;
            continue;
        }
        novi.oib[i] = znamenka;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Unesite ime i prezime: ";
    getline(cin, novi.imeiprez);

    novi.bodovi = 0;
    novi.IIkrug = false;

    natjecatelji[l] = novi;
    l++;
}

// Funkcija za upis bodova i izmjenu
void izmjena(kuhari natjecatelji[], int l) {
    int sifra;
    cout << "Unesite šifru natjecatelja za izmjenu: ";
    cin >> sifra;

    if (sifra < 1 || sifra > l) {
        cout << "Neispravna šifra." << endl;
        return;
    }

    kuhari &k = natjecatelji[sifra - 1];

    cout << "Trenutni OIB: ";
    for (int i = 0; i < 11; i++) cout << k.oib[i];
    cout << "\nUnesite novi OIB (znamenku po znamenku): ";
    for (int i = 0; i < 11; i++) {
        int znamenka;
        cin >> znamenka;
        if (znamenka < 0 || znamenka > 9) {
            cout << "Znamenka mora biti 0-9. Pokušajte ponovno." << endl;
            i--;
            continue;
        }
        k.oib[i] = znamenka;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Trenutno ime i prezime: " << k.imeiprez << endl;
    cout << "Unesite novo ime i prezime: ";
    getline(cin, k.imeiprez);

    cout << "Trenutni bodovi: " << k.bodovi << endl;
    cout << "Unesite nove bodove: ";
    cin >> k.bodovi;

    k.IIkrug = false; // reset
}

void bodovi(kuhari natjecatelji[], int l) {
    if (l == 0) {
        cout << "Nema prijavljenih natjecatelja." << endl;
        return;
    }

    cout << "Do sada je prijavljeno: " << l << " natjecatelja." << endl;
    int opcija;
    do {
        cout << "\n1. Upis bodova\n2. Izmjena podataka\nOdabir: ";
        cin >> opcija;

        switch (opcija) {
            case 1:
                for (int i = 0; i < l; i++) {
                    cout << "Šifra: " << natjecatelji[i].sifra << " - " << natjecatelji[i].imeiprez << endl;
                    cout << "Unesi bodove: ";
                    cin >> natjecatelji[i].bodovi;
                    natjecatelji[i].IIkrug = false;
                }
                break;
            case 2:
                izmjena(natjecatelji, l);
                break;
            default:
                cout << "Krivi odabir." << endl;
        }
    } while (opcija != 1 && opcija != 2);
}

// Izračun ulaska u 2. krug
void izracun(kuhari natjecatelji[], int l) {
    int max_bodovi = 0;

    for (int i = 0; i < l; i++) {
        if (natjecatelji[i].bodovi > max_bodovi)
            max_bodovi = natjecatelji[i].bodovi;
    }

    double prag = max_bodovi * 0.8;

    for (int i = 0; i < l; i++) {
        natjecatelji[i].IIkrug = natjecatelji[i].bodovi > prag;
    }

    cout << "Izračun završen. Prag za ulazak u 2. krug je: " << prag << " bodova." << endl;
}

// Ispis
void ispis(kuhari natjecatelji[], int l) {
    if (l == 0) {
        cout << "Nema podataka za ispis." << endl;
        return;
    }

    int opcija;
    cout << "1. Ispis svih natjecatelja\n2. Samo oni koji su prošli u 2. krug\nOdabir: ";
    cin >> opcija;

    for (int i = 0; i < l; i++) {
        if (opcija == 2 && !natjecatelji[i].IIkrug)
            continue;

        cout << "Šifra: " << natjecatelji[i].sifra << ", OIB: ";
        for (int j = 0; j < 11; j++) cout << natjecatelji[i].oib[j];
        cout << ", Ime i prezime: " << natjecatelji[i].imeiprez;
        cout << ", Bodovi: " << natjecatelji[i].bodovi;
        cout << ", 2. krug: " << (natjecatelji[i].IIkrug ? "DA" : "NE") << endl;
    }
}

// Spremanje u datoteku
void spremanje(kuhari natjecatelji[], int l) {
    ofstream datoteka("Izvoz.txt");

    if (!datoteka) {
        cout << "Greška pri otvaranju datoteke!" << endl;
        return;
    }

    datoteka << "sifra OIB ime_prezime bodovi 2KN" << endl;

    for (int i = 0; i < l; i++) {
        datoteka << natjecatelji[i].sifra << " ";
        for (int j = 0; j < 11; j++) datoteka << natjecatelji[i].oib[j];
        datoteka << " " << natjecatelji[i].imeiprez << " ";
        datoteka << natjecatelji[i].bodovi << " ";
        datoteka << (natjecatelji[i].IIkrug ? "DA" : "NE") << endl;
    }

    datoteka.close();
    cout << "Podaci spremljeni u Izvoz.txt." << endl;
}

// Glavni program
int main() {
    kuhari polje[50];
    int izbor;
    int novi = 0;

    do {
        cout << "\n***** I Z B O R N I K *****\n";
        cout << "1. Prijava novog natjecatelja\n";
        cout << "2. Upis bodova / Izmjena podataka\n";
        cout << "3. Izračun ulaska u 2. krug\n";
        cout << "4. Ispis podataka\n";
        cout << "5. Spremanje u datoteku\n";
        cout << "0. Izlaz iz programa\n";
        cout << "Odabir: ";
        cin >> izbor;

        switch (izbor) {
            case 1: prijava(polje, novi); break;
            case 2: bodovi(polje, novi); break;
            case 3: izracun(polje, novi); break;
            case 4: ispis(polje, novi); break;
            case 5: spremanje(polje, novi); break;
            case 0: cout << "Izlaz iz programa." << endl; break;
            default: cout << "Pogrešan unos!" << endl;
        }
    } while (izbor != 0);

    return 0;
}
