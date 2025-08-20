#include <iostream>
#include <fstream>

using namespace std;

struct Kamp {
    int idMjesta;
    int brDana;
    int brKorisnika;
    int brLjubimaca;
    int prekrsaji;
};

bool postoji(Kamp polje[], int l, int id_kamp) {
    for (int i = 0; i < l; i++) {
        if (polje[i].idMjesta == id_kamp) return true;
    }
    return false;
}

void unos(Kamp polje[], int &l) {
    cout << "Uneseno je: " << l << " polja" << endl;
    if (l >= 70) {
        cout << "Unesen je maksimalan broj polja" << endl;
        return;
    }
    cout << "Upisi ID kampa" << endl;
    int id_kampa;
    cin >> id_kampa;
    if (postoji(polje, l, id_kampa)) {
        cout << "Kamp mjesto je zauzeto" << endl;
        return;
    }
    polje[l].idMjesta = id_kampa;
    cout << "Unesite broj korisnika" << endl;
    cin >> polje[l].brKorisnika;
    cout << "Unesite broj dana" << endl;
    cin >> polje[l].brDana;
    cout << "Broj ljubimaca" << endl;
    cin >> polje[l].brLjubimaca;
    polje[l].prekrsaji = 0;
    l++;
}

void info(Kamp kamp) {
    cout << " ID kampa: " << kamp.idMjesta << endl;
    cout << " Broj korisnika: " << kamp.brKorisnika << endl;
    cout << " Broj dana: " << kamp.brDana << endl;
    cout << " Broj ljubimaca: " << kamp.brLjubimaca << endl;
    cout << " Prekrsaji: " << kamp.prekrsaji << endl;
}

void izvjesce(Kamp polje[], int l) {
    int suma_dana = 0, brojac = 0, zarada = 0, br_osoba = 0, br_ljubimaca = 0;
    for (int i = 0; i < l; i++) {
        info(polje[i]);
        cout << endl;
        suma_dana += polje[i].brDana;
        br_osoba += polje[i].brKorisnika;
        br_ljubimaca += polje[i].brLjubimaca;
        zarada += polje[i].brDana * polje[i].brKorisnika + polje[i].brDana * polje[i].brLjubimaca + polje[i].prekrsaji;
        brojac++;
    }
    if (brojac > 0) {
        cout << "Prosjek dana: " << (suma_dana * 1.0 / brojac) << endl;
    }
    cout << "Zarada: " << zarada << endl;
    cout << "Broj osoba: " << br_osoba << endl;
    cout << "Broj ljubimaca: " << br_ljubimaca << endl;
}

void datoteka(Kamp polje[], int l) {
    ofstream file("kamp.txt");
    if (!file) {
        cout << "Greska pri kreiranju datoteke" << endl;
        return;
    }
    file << l << endl;
    for (int i = 0; i < l; i++) {
        file << polje[i].idMjesta << " "
             << polje[i].brDana << " "
             << polje[i].brKorisnika << " "
             << polje[i].brLjubimaca << " "
             << polje[i].prekrsaji << endl;
    }
    file.close();
    cout << "Podaci su upisani u kamp.txt" << endl;
}

int main() {
    int index_zadnjeg = 0;
    Kamp polje[70];
    int opcija;
    do {
        cout << "1. Unos kamp mjesta.\n";
        cout << "2. Ispis izvjesca.\n";
        cout << "3. Unos podataka u datoteku.\n";
        cout << "0. Izlaz iz programa.\n";
        cout << "Unesi opciju: ";
        cin >> opcija;
        switch (opcija) {
            case 1:
                unos(polje, index_zadnjeg);
                break;
            case 2:
                izvjesce(polje, index_zadnjeg);
                break;
            case 3:
                datoteka(polje, index_zadnjeg);
                break;
            case 0:
                cout << "Izlaz iz programa..." << endl;
                break;
            default:
                cout << "Pogresan unos! Pokusajte ponovo." << endl;
        }
    } while (opcija != 0);
    return 0;
}
