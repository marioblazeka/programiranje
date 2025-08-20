#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct kampEvid {
    int IDbroj;
    int brojKoris;
    int brojDana;
    int brojLjubim;
    int cijenaPrekr; // ovdje spremamo cijenu prekršaja
};

kampEvid evidencija[70]; 
int unos = 0;

void unosNovZap() {
    if (unos >= 70) {
        cout << "Kamp je popunjen\n";
        return;
    }

    cout << "Upisite ID kamp mjesta: ";
    cin >> evidencija[unos].IDbroj;

    // provjera zauzeæa ID-a
    for (int i = 0; i < unos; i++) {
        if (evidencija[i].IDbroj == evidencija[unos].IDbroj) {
            cout << "Mjesto je zauzeto\n";
            return;
        }
    }

    cout << "Upisite broj korisnika: ";
    cin >> evidencija[unos].brojKoris;

    cout << "Upisite broj dana: ";
    cin >> evidencija[unos].brojDana;

    cout << "Upisite broj ljubimaca: ";
    cin >> evidencija[unos].brojLjubim;

    evidencija[unos].cijenaPrekr = 0; // poèetno nema prekršaja

    unos++;
}

void cijenePrekrsaja(int index) {
    int ljubimci = 0, smece = 0, granica = 0;

    cout << "Unesite broj prekršaja s ljubimcima: ";
    cin >> ljubimci;

    cout << "Unesite broj prekršaja bacanja smeæa: ";
    cin >> smece;

    cout << "Unesite broj prekršaja prelaska granice: ";
    cin >> granica;

    int trosak = (ljubimci * 10) + (smece * 20) + (granica * 50);

    evidencija[index].cijenaPrekr += trosak;

    cout << "Ukupni trosak za ovo mjesto sada iznosi: " 
         << evidencija[index].cijenaPrekr << " eura\n";
}

void IzmjenaZapisa() {
    cout << "Upisi trazeni ID kamp mjesta: ";
    int trazeniID;
    cin >> trazeniID;

    for (int i = 0; i < unos; i++) {
        if (trazeniID == evidencija[i].IDbroj) {
            cout << "Trazeni zapis je pronadjen:\n";
            cout << "ID: " << evidencija[i].IDbroj 
                 << ", Korisnici: " << evidencija[i].brojKoris
                 << ", Dana: " << evidencija[i].brojDana
                 << ", Ljubimci: " << evidencija[i].brojLjubim
                 << ", Prekršaji: " << evidencija[i].cijenaPrekr << " EUR\n";

            int izaberi;
            do {
                cout << "\nOpcije:\n";
                cout << "1. Dodaj cijene prekršaja\n";
                cout << "0. Povratak\n";
                cin >> izaberi;

                switch (izaberi) {
                    case 1: cijenePrekrsaja(i); break;
                    case 0: break;
                    default: cout << "Krivi unos\n";
                }
            } while (izaberi != 0);

            return;
        }
    }

    cout << "Nema unosa pod tim brojem\n";
}

void pregledUpisa() {
    cout << "Do sada imamo sveukupno " << unos << " evidencija:\n";
    for (int i = 0; i < unos; i++) {
        cout << i+1 << ". ID: " << evidencija[i].IDbroj
             << ", Korisnici: " << evidencija[i].brojKoris
             << ", Dana: " << evidencija[i].brojDana
             << ", Ljubimci: " << evidencija[i].brojLjubim
             << ", Prekršaji: " << evidencija[i].cijenaPrekr << " EUR\n";
    }
}

void glavniIzbornik() {
    int izbor;
    do {
        cout << "\n------IZBORNIK-----\n";
        cout << "1. Unos novog zapisa\n";
        cout << "2. Izmjena zapisa\n";
        cout << "3. Pregled svih zapisa\n";
        cout << "0. Izlaz\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: unosNovZap(); break;
            case 2: IzmjenaZapisa(); break;
            case 3: pregledUpisa(); break;
            case 0: cout << "Izlaz iz programa.\n"; break;
            default: cout << "Pogresan unos\n";
        }
    } while (izbor != 0);
}

int main() {
    glavniIzbornik();
    return 0;
}

