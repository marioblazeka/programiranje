#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_NATJECATELJA = 50;

struct Natjecatelj {
    int sifra;
    long long oib;
    string imePrezime;
    int bodovi;
    bool drugiKrug;
};

void prijavaNatjecatelja(Natjecatelj natjecatelji[], int &brojNatjecatelja) {
    if (brojNatjecatelja >= MAX_NATJECATELJA) {
        cout << "?? Dostignut maksimalan broj natjecatelja (" << MAX_NATJECATELJA << ")." << endl;
        return;
    }
    cout << "Prijavljeno natjecatelja: " << brojNatjecatelja << endl;
    Natjecatelj novi;
    novi.sifra = brojNatjecatelja + 1;
    cout << "Unesite OIB natjecatelja (11 znamenki): ";
    cin >> novi.oib;
    cin.ignore();
    cout << "Unesite ime i prezime: ";
    getline(cin, novi.imePrezime);
    novi.bodovi = 0;
    novi.drugiKrug = false;

    natjecatelji[brojNatjecatelja] = novi;
    brojNatjecatelja++;

    cout << "? Natjecatelj uspjesno prijavljen. Sifra: " << novi.sifra << endl;
}

void upisBodovaIzmjena(Natjecatelj natjecatelji[], int brojNatjecatelja) {
    if (brojNatjecatelja == 0) {
        cout << "?? Nema prijavljenih natjecatelja." << endl;
        return;
    }
    cout << "Prijavljeno natjecatelja: " << brojNatjecatelja << endl;
    cout << "1. Upis bodova\n2. Izmjena podataka\nOdabir: ";
    int izbor; cin >> izbor;

    if (izbor == 1) {
        for (int i = 0; i < brojNatjecatelja; i++) {
            cout << "Sifra: " << natjecatelji[i].sifra 
                 << " | " << natjecatelji[i].imePrezime 
                 << " | Bodovi: ";
            cin >> natjecatelji[i].bodovi;
            natjecatelji[i].drugiKrug = false;
        }
    } else if (izbor == 2) {
        int sifra;
        cout << "Unesite sifru natjecatelja za izmjenu: ";
        cin >> sifra;
        if (sifra < 1 || sifra > brojNatjecatelja) {
            cout << "?? Neispravna sifra." << endl;
            return;
        }
        Natjecatelj &n = natjecatelji[sifra - 1];
        cout << "Trenutni podaci: OIB: " << n.oib << ", Ime i prezime: " << n.imePrezime << ", Bodovi: " << n.bodovi << endl;
        cout << "Unesite novi OIB: ";
        cin >> n.oib;
        cin.ignore();
        cout << "Unesite novo ime i prezime: ";
        getline(cin, n.imePrezime);
        cout << "Unesite nove bodove: ";
        cin >> n.bodovi;
    }
}

void izracunDrugiKrug(Natjecatelj natjecatelji[], int brojNatjecatelja) {
    if (brojNatjecatelja == 0) {
        cout << "?? Nema natjecatelja." << endl;
        return;
    }
    int maxBodovi = 0;
    for (int i = 0; i < brojNatjecatelja; i++) {
        if (natjecatelji[i].bodovi > maxBodovi) {
            maxBodovi = natjecatelji[i].bodovi;
        }
    }
    double prag = maxBodovi * 0.8;
    for (int i = 0; i < brojNatjecatelja; i++) {
        natjecatelji[i].drugiKrug = (natjecatelji[i].bodovi >= prag);
    }
    cout << "? Izracun zavrsen. Prag za drugi krug: " << prag << " bodova." << endl;
}

void ispisNatjecatelja(Natjecatelj natjecatelji[], int brojNatjecatelja) {
    if (brojNatjecatelja == 0) {
        cout << "?? Nema natjecatelja za ispis." << endl;
        return;
    }
    cout << "1. Ispis svih natjecatelja\n2. Ispis onih u 2. krugu\nOdabir: ";
    int izbor; cin >> izbor;

    for (int i = 0; i < brojNatjecatelja; i++) {
        if (izbor == 1 || (izbor == 2 && natjecatelji[i].drugiKrug)) {
            cout << natjecatelji[i].sifra << " " 
                 << natjecatelji[i].oib << " " 
                 << natjecatelji[i].imePrezime << " " 
                 << natjecatelji[i].bodovi << " " 
                 << (natjecatelji[i].drugiKrug ? 1 : 0) << endl;
        }
    }
}

void izvozUDatoteku(Natjecatelj natjecatelji[], int brojNatjecatelja) {
    ofstream out("Izvoz.txt");
    out << "sifra OIB ime_prezime bodovi 2KN" << endl;
    for (int i = 0; i < brojNatjecatelja; i++) {
        out << natjecatelji[i].sifra << " " 
            << natjecatelji[i].oib << " " 
            << natjecatelji[i].imePrezime << " " 
            << natjecatelji[i].bodovi << " " 
            << (natjecatelji[i].drugiKrug ? 1 : 0) << endl;
    }
    out.close();
    cout << "? Podaci su uspjesno izvezeni u datoteku Izvoz.txt" << endl;
}

int main() {
    Natjecatelj natjecatelji[MAX_NATJECATELJA];
    int brojNatjecatelja = 0;
    int izbor;

    do {
        cout << "\n===== GLAVNI IZBORNIK =====" << endl;
        cout << "1. Prijava novog natjecatelja" << endl;
        cout << "2. Upis bodova / izmjena podataka" << endl;
        cout << "3. Izracun ulaska u 2. krug" << endl;
        cout << "4. Ispis podataka o natjecateljima" << endl;
        cout << "5. Izvoz podataka u datoteku" << endl;
        cout << "0. Izlaz iz programa" << endl;
        cout << "Odabir: ";
        cin >> izbor;

        switch (izbor) {
            case 1: prijavaNatjecatelja(natjecatelji, brojNatjecatelja); break;
            case 2: upisBodovaIzmjena(natjecatelji, brojNatjecatelja); break;
            case 3: izracunDrugiKrug(natjecatelji, brojNatjecatelja); break;
            case 4: ispisNatjecatelja(natjecatelji, brojNatjecatelja); break;
            case 5: izvozUDatoteku(natjecatelji, brojNatjecatelja); break;
            case 0: cout << "?? Kraj programa." << endl; break;
            default: cout << "?? Neispravan odabir." << endl;
        }
    } while (izbor != 0);

    return 0;
}

