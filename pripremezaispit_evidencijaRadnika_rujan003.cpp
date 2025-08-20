#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct evidencijaRadnika {
    string imePrez;
    int brojRk;
    string datumRod; // format: dd-mm-yyyy
    float placa;
    string odjel;
};

evidencijaRadnika evidencija[100];
int brojUnosa = 0;

void unosPodataka() {
    cout << "Do sada je uneseno " << brojUnosa << " radnika.\n";
    if (brojUnosa >= 100) {
        cout << "Polje je popunjeno! \n";
        return;
    }

    cin.ignore();
    cout << "Unesite ime i prezime: ";
    getline(cin, evidencija[brojUnosa].imePrez);

    cout << "Unesite broj radne knjizice: ";
    cin >> evidencija[brojUnosa].brojRk;

    cin.ignore();
    cout << "Unesite datum rodjenja (dd-mm-yyyy): ";
    getline(cin, evidencija[brojUnosa].datumRod);

    if (evidencija[brojUnosa].datumRod.length() != 10 ||
        evidencija[brojUnosa].datumRod[2] != '-' ||
        evidencija[brojUnosa].datumRod[5] != '-') {
        cout << "Krivi format datuma!\n";
        return;
    }

    cout << "Unesite iznos place: ";
    cin >> evidencija[brojUnosa].placa;

    cout << "Unesite odjel: ";
    cin >> evidencija[brojUnosa].odjel;

    brojUnosa++;
    cout << "Radnik unesen!\n";
}

void izmjenaPodataka() {
    if (brojUnosa == 0) {
        cout << "Nema podataka za izmjenu!\n";
        return;
    }

    cout << "Unesite broj radne knjizice za izmjenu: ";
    int trazenaRk;
    cin >> trazenaRk;

    bool pronadjen = false;
    for (int i = 0; i < brojUnosa; i++) {
        if (evidencija[i].brojRk == trazenaRk) {
            pronadjen = true;

            cout << "Radnik pronadjen: "
                 << evidencija[i].imePrez << " | "
                 << evidencija[i].datumRod << " | "
                 << evidencija[i].placa << " | "
                 << evidencija[i].odjel << endl;

            cin.ignore();
            cout << "Unesi novo ime i prezime: ";
            getline(cin, evidencija[i].imePrez);

            cout << "Unesi novi datum rodjenja (dd-mm-yyyy): ";
            getline(cin, evidencija[i].datumRod);

            cout << "Unesi novu placu: ";
            cin >> evidencija[i].placa;

            cout << "Unesi novi odjel: ";
            cin >> evidencija[i].odjel;

            cout << "Podaci izmijenjeni!\n";
            return;
        }
    }

    if (!pronadjen) {
        cout << "Radnik s navedenim brojem radne knjizice ne postoji.\n";
    }
}

void pregledPodataka() {
    if (brojUnosa == 0) {
        cout << "Nema upisanih radnika.\n";
        return;
    }

    cout << "Upisani radnici:\n";
    for (int i = 0; i < brojUnosa; i++) {
        cout << evidencija[i].brojRk << " | "
             << evidencija[i].imePrez << " | "
             << evidencija[i].datumRod << " | "
             << evidencija[i].placa << " | "
             << evidencija[i].odjel << endl;
    }
}

void pretragaPoGodRod() {
    if (brojUnosa == 0) {
        cout << "Nema podataka za pretrazivanje.\n";
        return;
    }

    cout << "Upisi godinu rodjenja za pretragu: ";
    string trazenaGod;
    cin >> trazenaGod;

    bool pronadjen = false;
    float sumaPlaca = 0;
    int brojPronadjenih = 0;

    for (int i = 0; i < brojUnosa; i++) {
        if (evidencija[i].datumRod.substr(6, 4) == trazenaGod) {
            pronadjen = true;
            brojPronadjenih++;
            sumaPlaca += evidencija[i].placa;

            cout << evidencija[i].brojRk << " | "
                 << evidencija[i].imePrez << " | "
                 << evidencija[i].datumRod << " | "
                 << evidencija[i].placa << " | "
                 << evidencija[i].odjel << endl;
        }
    }

    if (!pronadjen) {
        cout << "Ne postoji niti jedan radnik s navedenom godinom rodjenja.\n";
    } else {
        cout << "Prosjek placa tih radnika: " << sumaPlaca / brojPronadjenih << endl;
    }
}

void spremanje() {
    if (brojUnosa == 0) {
        cout << "Nema podataka za spremanje.\n";
        return;
    }

    ofstream datoteka("podaci.txt");
    if (!datoteka) {
        cout << "Greska pri otvaranju datoteke!\n";
        return;
    }

    datoteka << brojUnosa << endl; // prvi red broj radnika
    for (int i = 0; i < brojUnosa; i++) {
        datoteka << evidencija[i].imePrez << " "
                 << evidencija[i].brojRk << " "
                 << evidencija[i].datumRod << " "
                 << evidencija[i].placa << " "
                 << evidencija[i].odjel << endl;
    }

    datoteka.close();
    cout << "Podaci spremljeni u podaci.txt\n";
}

void izbornik() {
    int izbor;
    do {
        cout << "\n-----IZBORNIK-----\n";
        cout << "0. Izlaz\n";
        cout << "1. Unos radnika\n";
        cout << "2. Izmjena radnika\n";
        cout << "3. Pregled radnika\n";
        cout << "4. Pretraga po godini rodjenja\n";
        cout << "5. Spremanje u datoteku\n";
        cout << "------------------\n";
        cout << "Odabir: ";
        cin >> izbor;

        switch (izbor) {
        case 1: unosPodataka(); break;
        case 2: izmjenaPodataka(); break;
        case 3: pregledPodataka(); break;
        case 4: pretragaPoGodRod(); break;
        case 5: spremanje(); break;
        case 0: cout << "Izlaz iz programa.\n"; break;
        default: cout << "Pogresan izbor!\n"; break;
        }
    } while (izbor != 0);
}

int main() {
    izbornik();
    return 0;
}
