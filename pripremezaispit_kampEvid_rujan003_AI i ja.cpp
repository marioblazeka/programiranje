#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct kampEvid {
    int IDbroj;
    int brojKoris;
    int brojDana;
    int brojLjubim;
    int cijenaPrekr;
};

kampEvid evidencija[70];
int unos = 0;

//bool nePostoji = true; // STARI KOD
bool nePostoji = false; // Novi kod – početno pretpostavljamo da kamp mjesto postoji tek kad ga unesemo

// ----------------------- FUNKCIJA ZA UNOS NOVOG ZAPISA -----------------------
void unosNovZap() {
    if (unos < 1) {
        cout << "Jos nema unosa\n";
    } else {
        cout << "Do sad je upisano " << unos << " evidencija \n";
    }

    if (unos >= 70) { // STARI KOD: if(unos>70) { ... } › Ispravljeno jer 70 mjesta max
        cout << "Kamp je popunjen\n";
        return;
    }

    cout << "Upisite ID kamp mjesta: ";
    cin >> evidencija[unos].IDbroj;

    // Provjera da li ID već postoji
    for (int i = 0; i < unos; i++) {
        if (evidencija[i].IDbroj == evidencija[unos].IDbroj) { // STARI KOD: if(unos==evidencija[unos].IDbroj) › greška, uspoređivao unos s ID
            cout << "Mjesto je zauzeto!\n";
            return;
        }
    }

    cout << "Upisite broj korisnika: ";
    cin >> evidencija[unos].brojKoris;

    cout << "Upisite broj dana: ";
    cin >> evidencija[unos].brojDana;

    cout << "Upisite broj ljubimaca: ";
    cin >> evidencija[unos].brojLjubim;

    evidencija[unos].cijenaPrekr = 0; // Inicijalno nema prekrsaja

    unos++;
    cout << "Zapis uspjesno dodan!\n";
}

// ----------------------- FUNKCIJA ZA CIJENE PREKRŠAJA -----------------------
void cijenePrekrsaja() {
    int ljubimci = 0, smece = 0, granica = 0;
    
    cout << "Unesite cijenu prekrsaja za ljubimce: ";
    cin >> ljubimci;
    
    cout << "Unesite cijenu prekrsaja za smece: ";
    cin >> smece;
    
    cout << "Unesite cijenu prekrsaja za prekrsaj granice: ";
    cin >> granica;

    int trosak = ljubimci + smece + granica;

    cout << "Ukupni trosak iznosi: " << trosak << " eura\n";
}

// ----------------------- FUNKCIJA ZA IZMJENU ZAPISA -----------------------
void IzmjenaZapisa() {
    cout << "Upisi trazeni ID kamp mjesta: ";
    int trazeniID;
    cin >> trazeniID;

    for (int i = 0; i < unos; i++) {
        if (trazeniID == evidencija[i].IDbroj) {
            cout << "Trazeni zapis je pronadjen:\n";
            cout << "ID: " << evidencija[i].IDbroj
                 << " Korisnika: " << evidencija[i].brojKoris
                 << " Dana: " << evidencija[i].brojDana
                 << " Ljubimaca: " << evidencija[i].brojLjubim
                 << " Prekrsaj: " << evidencija[i].cijenaPrekr << endl;

            int izbor;
            cout << "1. Promjena broja korisnika\n";
            cout << "2. Promjena broja dana\n";
            cout << "3. Promjena broja ljubimaca\n";
            cout << "4. Dodavanje cijene prekrsaja\n";
            cout << "0. Izlaz\n";
            cin >> izbor;

            switch (izbor) {
                case 1: cout << "Novi broj korisnika: "; cin >> evidencija[i].brojKoris; break;
                case 2: cout << "Novi broj dana: "; cin >> evidencija[i].brojDana; break;
                case 3: cout << "Novi broj ljubimaca: "; cin >> evidencija[i].brojLjubim; break;
                case 4: cout << "Unesite cijenu prekrsaja: "; cin >> evidencija[i].cijenaPrekr; break;
                case 0: return;
                default: cout << "Nepostojeca opcija!\n";
            }
            return;
        }
    }
    cout << "Nema unosa pod tim brojem!\n";
}

// ----------------------- FUNKCIJA ZA PREGLED UPISA -----------------------
void pregledUpisa() {
    cout << "Do sada imamo sveukupno " << unos << " evidencija.\n";
    for (int i = 0; i < unos; i++) {
        cout << "ID: " << evidencija[i].IDbroj
             << " Korisnika: " << evidencija[i].brojKoris
             << " Dana: " << evidencija[i].brojDana
             << " Ljubimaca: " << evidencija[i].brojLjubim
             << " Prekrsaj: " << evidencija[i].cijenaPrekr << endl;
    }
}

// ----------------------- FUNKCIJA ZA NAPLATU -----------------------
void naplataKampiranja() {
    int trazeniID;
    cout << "Unesite ID kamp mjesta za naplatu: ";
    cin >> trazeniID;

    for (int i = 0; i < unos; i++) {
        if (trazeniID == evidencija[i].IDbroj) {
            int dnevnaCijena = 100; // cijena po danu
            int cijenaLjubimca = 15; // cijena po ljubimcu
            int suma = evidencija[i].brojDana * dnevnaCijena +
                       evidencija[i].brojLjubim * cijenaLjubimca +
                       evidencija[i].cijenaPrekr;
            cout << "Ukupna naplata za ID " << trazeniID << " iznosi: " << suma << " eura\n";
            return;
        }
    }
    cout << "Trazeno mjesto ne postoji!\n";
}

// ----------------------- FUNKCIJA ZA SPREMANJE -----------------------
void spremanjeUdat() {
    if (unos == 0) {
        cout << "Nema podataka za spremanje.\n";
        return;
    }

    ofstream datoteka("kamp.txt");
    if (!datoteka) {
        cout << "Greska pri otvaranju datoteke!\n";
        return;
    }

    for (int i = 0; i < unos; i++) {
        datoteka << evidencija[i].IDbroj << " "
                 << evidencija[i].brojKoris << " "
                 << evidencija[i].brojDana << " "
                 << evidencija[i].brojLjubim << " "
                 << evidencija[i].cijenaPrekr << endl;
    }
    datoteka.close();
    cout << "Podaci su spremljeni u kamp.txt\n";
}

// ----------------------- GLAVNI IZBORNIK -----------------------
void glavniIzbornik() {
    int izbor;
    do {
        cout << "------ IZBORNIK ------\n";
        cout << "1. Unos novog zapisa\n";
        cout << "2. Izmjena zapisa\n";
        cout << "3. Cijene prekrsaja\n";
        cout << "4. Naplata kampiranja\n";
        cout << "5. Pregled svih zapisa\n";
        cout << "6. Spremanje u datoteku\n";
        cout << "0. Izlaz\n";
        cout << "----------------------\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: unosNovZap(); break;
            case 2: IzmjenaZapisa(); break;
            case 3: cijenePrekrsaja(); break;
            case 4: naplataKampiranja(); break;
            case 5: pregledUpisa(); break;
            case 6: spremanjeUdat(); break;
            case 0: cout << "Izlaz iz programa.\n"; break;
            default: cout << "Pogresan unos! Pokusajte ponovo.\n";
        }

        cout << "\n"; // razmak između prikaza menija
    } while (izbor != 0);
}


int main() {
    glavniIzbornik();
    return 0;
}
