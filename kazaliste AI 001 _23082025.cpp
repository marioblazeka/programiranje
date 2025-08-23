#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struktura za evidenciju ulaznica
struct EvidProdUlaz {
    int brUlaz;       // broj ulaznice (raèun)
    int brSjed;       // broj sjedala
    bool rezSjed;     // true = rezervirano, false = prodano
    float cijenaUlaz; // cijena ulaznice
    string oibGle;    // OIB gledatelja (string da ne izgubimo vodeæe nule)
};

// Polje od max 150 ulaznica
EvidProdUlaz evidencija[150];
int unos = 0;     // broj evidentiranih ulaznica
int BrRac = 0;    // broj raèuna
float suma = 0;   // ukupna zarada

// Funkcija za odreðivanje cijene po sjedalu
float cijenaPoSjedalu(int brSjed) {
    if (brSjed >= 1 && brSjed <= 100) return 15.0;   // Parter
    else if (brSjed >= 101 && brSjed <= 140) return 17.5; // Terasa
    else if (brSjed >= 141 && brSjed <= 150) return 20.0; // VIP
    else return 0; // Greška
}

// -------------------- 1. Prodaja ulaznice --------------------
void prodajaUlaznica() {
    if (unos >= 150) { // provjera rasprodanosti
        cout << "Predstava je rasprodana!\n";
        return;
    }

    int brSjed;
    cout << "Unesite broj sjedala (1-150): ";
    cin >> brSjed;

    if (brSjed < 1 || brSjed > 150) {
        cout << "Nepostojeci broj sjedala!\n";
        return;
    }

    // Provjera je li sjedalo veæ zauzeto
    for (int i = 0; i < unos; i++) {
        if (evidencija[i].brSjed == brSjed) {
            cout << "Sjedalo " << brSjed << " je vec zauzeto!\n";
            return;
        }
    }

    // Upis podataka
    BrRac++;
    evidencija[unos].brUlaz = BrRac;
    evidencija[unos].brSjed = brSjed;
    evidencija[unos].rezSjed = false; // direktna prodaja
    evidencija[unos].cijenaUlaz = cijenaPoSjedalu(brSjed);

    cout << "Unesite OIB: ";
    cin >> evidencija[unos].oibGle;

    suma += evidencija[unos].cijenaUlaz;
    cout << "Prodana je ulaznica " << BrRac << " sa sjedalom " << brSjed << ".\n";

    unos++;
}

// -------------------- 2. Rezervacija ulaznice --------------------
void rezervacijaUlaznica() {
    if (unos >= 150) {
        cout << "Predstava je rasprodana!\n";
        return;
    }

    int izbor;
    cout << "1. Rezervacija numeriranog sjedala\n";
    cout << "2. Izmjena podataka o rezervaciji\n";
    cin >> izbor;

    int brSjed;
    cout << "Unesite broj sjedala (1-150): ";
    cin >> brSjed;

    if (brSjed < 1 || brSjed > 150) {
        cout << "Nepostojeci broj sjedala!\n";
        return;
    }

    if (izbor == 1) {
        // provjera zauzetosti
        for (int i = 0; i < unos; i++) {
            if (evidencija[i].brSjed == brSjed) {
                cout << "Sjedalo " << brSjed << " je vec zauzeto!\n";
                return;
            }
        }

        BrRac++;
        evidencija[unos].brUlaz = BrRac;
        evidencija[unos].brSjed = brSjed;
        evidencija[unos].rezSjed = true;
        evidencija[unos].cijenaUlaz = cijenaPoSjedalu(brSjed);

        cout << "Unesite OIB: ";
        cin >> evidencija[unos].oibGle;

        cout << "Rezervacija realizirana!\n";
        unos++;
    }
    else if (izbor == 2) {
        bool found = false;
        for (int i = 0; i < unos; i++) {
            if (evidencija[i].brSjed == brSjed && evidencija[i].rezSjed == true) {
                cout << "Unesite novi OIB: ";
                cin >> evidencija[i].oibGle;
                cout << "Izmjena rezervacije realizirana!\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Nema rezervacije za sjedalo " << brSjed << "!\n";
        }
    }
}

// -------------------- 3. Prodaja rezervirane ulaznice --------------------
void prodajaRezUlaznica() {
    int brSjed;
    cout << "Unesite broj sjedala: ";
    cin >> brSjed;

    bool found = false;
    for (int i = 0; i < unos; i++) {
        if (evidencija[i].brSjed == brSjed && evidencija[i].rezSjed == true) {
            evidencija[i].rezSjed = false; // postaje prodano
            suma += evidencija[i].cijenaUlaz;
            cout << "Prodana je ulaznica " << evidencija[i].brUlaz
                 << " sa sjedalom " << evidencija[i].brSjed << ".\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Rezervacija ne postoji za sjedalo " << brSjed << "!\n";
    }
}

// -------------------- 4. Ispis podataka --------------------
void ispisPodoUlaznicama() {
    if (unos == 0) {
        cout << "Nema podataka!\n";
        return;
    }

    cout << "Prodano je " << unos << " ulaznica.\n";
    cout << "Inkasirano je " << suma << " eura.\n";

    int countP = 0, countT = 0, countV = 0;
    for (int i = 0; i < unos; i++) {
        if (!evidencija[i].rezSjed) { // samo prodane
            if (evidencija[i].brSjed <= 100) countP++;
            else if (evidencija[i].brSjed <= 140) countT++;
            else countV++;
        }
    }

    cout << "Postotak rasprodanog partera: " << (countP / 100.0) * 100 << "%\n";
    cout << "Postotak rasprodanih terasa: " << (countT / 40.0) * 100 << "%\n";
    cout << "Postotak rasprodanog VIP-a: " << (countV / 10.0) * 100 << "%\n";
}

// -------------------- 5. Izvoz u datoteku --------------------
void izvozPodoUlaznicama() {
    if (unos == 0) {
        cout << "Nema podataka za izvoz!\n";
        return;
    }

    ofstream datoteka("Izvoz.txt");
    if (!datoteka) {
        cout << "Greska pri otvaranju datoteke!\n";
        return;
    }

    datoteka << "Br.ulaznice\tSjedalo\tCijena\tOIB\n";
    for (int i = 0; i < unos; i++) {
        datoteka << evidencija[i].brUlaz << "\t"
                 << evidencija[i].brSjed << "\t"
                 << evidencija[i].cijenaUlaz << "\t"
                 << evidencija[i].oibGle << "\n";
    }

    datoteka.close();
    cout << "Izvoz podataka realiziran!\n";
}

// -------------------- Glavni izbornik --------------------
void glavniIzbornik() {
    int izbor;
    do {
        cout << "\n----- IZBORNIK -----\n";
        cout << "1. Prodaja ulaznice\n";
        cout << "2. Rezervacija ulaznice\n";
        cout << "3. Prodaja rezervirane ulaznice\n";
        cout << "4. Ispis podataka\n";
        cout << "5. Izvoz podataka\n";
        cout << "0. Izlaz\n";
        cout << "Unos: ";
        cin >> izbor;

        switch (izbor) {
        case 1: prodajaUlaznica(); break;
        case 2: rezervacijaUlaznica(); break;
        case 3: prodajaRezUlaznica(); break;
        case 4: ispisPodoUlaznicama(); break;
        case 5: izvozPodoUlaznicama(); break;
        case 0: cout << "Izlaz iz programa.\n"; break;
        default: cout << "Pogresan unos!\n"; break;
        }
    } while (izbor != 0);
}

// -------------------- main --------------------
int main() {
    glavniIzbornik();
    return 0;
}

