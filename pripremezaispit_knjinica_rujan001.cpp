#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_SIFRA = 332;
const int MAX_POSUDBI = 130;

struct posudba {
    int rbr;
    int sifra;
    string ime;
    int brdanaposudbe;
    float zakasnina;
};

posudba knjige[MAX_POSUDBI];
int brojPosudbi = 0;

void unosPodataka() {
    cout << "Trenutno uneseno posudbi: " << brojPosudbi << endl;
    if (brojPosudbi >= MAX_POSUDBI) {
        cout << "Dosegnut maksimalan broj posudbi!" << endl;
        return;
    }

    int sifra;
    do {
        cout << "Unesi sifru knjige (1-" << MAX_SIFRA << "): ";
        cin >> sifra;
    } while (sifra < 1 || sifra > MAX_SIFRA);

    knjige[brojPosudbi].sifra = sifra;

    cout << "Unesi ime korisnika: ";
    cin.ignore();
    getline(cin, knjige[brojPosudbi].ime);

    cout << "Unesi broj dana posudbe: ";
    cin >> knjige[brojPosudbi].brdanaposudbe;

    knjige[brojPosudbi].zakasnina = 0.0;
    knjige[brojPosudbi].rbr = brojPosudbi + 1;
    brojPosudbi++;
}

void ispravakPodataka() {
    if (brojPosudbi == 0) {
        cout << "Nema unesenih posudbi!" << endl;
        return;
    }

    cout << "Postoje posudbe s rednim brojevima: ";
    for (int i = 0; i < brojPosudbi; i++)
        cout << knjige[i].rbr << " ";
    cout << endl;

    int rbrZaIspravak;
    cout << "Unesi redni broj posudbe za ispravak: ";
    cin >> rbrZaIspravak;

    if (rbrZaIspravak < 1 || rbrZaIspravak > brojPosudbi) {
        cout << "Neispravan redni broj!" << endl;
        return;
    }

    int index = rbrZaIspravak - 1;

    int novaSifra;
    do {
        cout << "Unesi novu sifru knjige (1-" << MAX_SIFRA << "): ";
        cin >> novaSifra;
    } while (novaSifra < 1 || novaSifra > MAX_SIFRA);

    knjige[index].sifra = novaSifra;

    cout << "Unesi novo ime korisnika: ";
    cin.ignore();
    getline(cin, knjige[index].ime);

    cout << "Unesi novi broj dana posudbe: ";
    cin >> knjige[index].brdanaposudbe;
}

void pregledPosKnji() {
    cout << "PREGLED POSUDBI:";
    cout << left << setw(8) << "RBR"
         << setw(10) << "SIFRA"
         << setw(20) << "IME"
         << setw(10) << "DANI"
         << setw(12) << "ZAKASNINA" << endl;

    cout << string(60, '-') << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < brojPosudbi; i++) {
        cout << left << setw(8) << knjige[i].rbr
             << setw(10) << knjige[i].sifra
             << setw(20) << knjige[i].ime
             << setw(10) << knjige[i].brdanaposudbe
             << setw(12) << knjige[i].zakasnina << endl;
    }
}

void vracanjeKnji() {
    int rbr;
    cout << "Unesi redni broj posudbe za povrat: ";
    cin >> rbr;

    if (rbr < 1 || rbr > brojPosudbi) {
        cout << "Neispravan redni broj!" << endl;
        return;
    }

    int stvarniDani;
    cout << "Unesi stvarni broj dana od posudbe: ";
    cin >> stvarniDani;

    int planirano = knjige[rbr - 1].brdanaposudbe;
    int zakasnjenje = stvarniDani - planirano;

    if (zakasnjenje <= 0) {
        knjige[rbr - 1].zakasnina = 0;
        cout << "Nema zakasnine." << endl;
    } else {
        knjige[rbr - 1].zakasnina = zakasnjenje * 0.1f;
        cout << "Zakasnina iznosi: " << fixed << setprecision(2)
             << knjige[rbr - 1].zakasnina << " €" << endl;
    }
}

void izvoz() {
    ofstream datoteka("knjiznica.txt");
    if (!datoteka) {
        cout << "Greška pri otvaranju datoteke!" << endl;
        return;
    }

    datoteka << brojPosudbi << endl;
    datoteka << "RBR SIFRA IME DANI ZAKASNINA" << endl;
    datoteka << fixed << setprecision(2);

    for (int i = 0; i < brojPosudbi; i++) {
        datoteka << knjige[i].rbr << " "
                 << knjige[i].sifra << " "
                 << knjige[i].ime << " "
                 << knjige[i].brdanaposudbe << " "
                 << knjige[i].zakasnina << endl;
    }

    datoteka.close();
    cout << "Podaci uspjesno izvezeni u knjiznica.txt" << endl;
}

void glavniIzbornik() {
    int izbor;
    do {
        cout << "\n***** G L A V N I   I Z B O R N I K *****\n";
        cout << "\n1. Unos podataka o posudbi\n";
        cout << "\n2. Ispravak podataka o posudbi\n";
        cout << "\n3. Pregled posudjenih knjiga\n";
        cout << "\n4. Vracanje knjige i naplata zakasnine\n";
        cout << "\n5. Izvoz podataka u datoteku\n";
        cout << "\n0. Izlaz iz programa\n";
        cout << "Odaberi opciju 0-5: ";
        cin >> izbor;

        switch (izbor) {
            case 1: unosPodataka(); break;
            case 2: ispravakPodataka(); break;
            case 3: pregledPosKnji(); break;
            case 4: vracanjeKnji(); break;
            case 5: izvoz(); break;
            case 0: cout << "Izlaz iz programa!" << endl; break;
            default: cout << "Nepoznat izbor!" << endl;
        }

    } while (izbor != 0);
}

int main() {
    glavniIzbornik();
    return 0;
}


/*Napi�ite program za pra�enje posudbe knjiga u knji�nici. Program pohranjuje i prati 
podatke o pojedinoj posudbi knjige. 
Svaku posudbu unosi djelatnik knji�nice u va� program koji pohranjuje 
sljede�e podatke o posudbi:

Redni broj posudbe (cijeli broj)
�ifra knjige (cijeli broj)
Ime korisnika (tekst)
Broj dana posudbe (cijeli broj)
Zakasnina (decimalni broj)
Program treba sadr�avati glavni izbornik sa sljede�im mogu�nostima:

Unos podataka o posudbi
Ispravak podataka o posudbi
Pregled posu�enih knjiga
Vra�anje knjige i Naplata zakasnine
Izvoz podataka u datoteku
     0. Izlaz iz programa

Napomena: Pojedine mogu�nosti obavezno realizirati pomo�u funkcija s argumentima!

Svaka, u potpunosti realizirana mogu�nost programa donosi 20 bodova.

 

Mogu�nost 1: Unos podataka o posudbi

Kreirajte funkciju koja omogu�ava upis podataka o posudbi u polje veli�ine 
130 elemenata (program mo�e pratiti do 130 posudbi).

Najprije program ispi�e podatak koliko je  posudbi do sada uneseno
Nakon toga knji�ni�ar treba upisati �ifru knjige. Dozvoljene �ifre knjiga su iz raspona 
[1, 332]. Ako knji�ni�ar upi�e nepostoje�u �ifru knjige, program treba zatra�iti 
ponovni upis sve dok �ifra nije ispravna
Nakon upisa �ifre, knji�ni�ar upisuje ime posuditelja i broj dana posudbe
Redni broj posudbe program automatski generira, po�ev�i od broja 1
 

Mogu�nost 2: Ispravak podataka o posudbi

Kreirajte funkciju koja omogu�ava ispravak podataka o posudbi.  Funkcija radi na sljede�i na�in:

Provjerava je su li upisani podaci o bar jednoj posudbi. Ako nisu, ispisuje odgovaraju�u poruku i vra�a se u glavni izbornik ina�e u konzolu ispi�e redne brojeve posudbi
Omogu�uje knji�ni�aru unos rednog broja posudbe koju treba ispraviti. Ako knji�ni�ar upi�e nepostoje�i redni broj, program treba ispisati odgovaraju�u poruku i vratiti se u glavni izbornik
Ako knji�ni�ar upi�e ispravni redni broj, program omogu�uje ispravak �ifre knjige, imena i broja dana posudbe. Kod ispravka �ifre potrebno je osigurati ispravnost �ifre kao i u mogu�nosti 1
 

Mogu�nost 3: Pregled posu�enih knjiga

Kreirajte funkciju ispisa koja �e na ekran ispisati statistike o unesenim posudbama. 
Program mora za svaku od knjiga u knji�nici (�ifre 1-332) zasebno ispisati koliko 
je kopija svake od knjige posu�eno, te koje je najkra�e i najdu�e vrijeme posudbe za 
svaku od tih kopija knjiga. Dakle, podaci moraju biti prikazani za odre�ene (�ifre) knjige. 
Ukoliko pojedina knjiga uop�e nije posu�ena, program ne ispisuje ni�ta za tu pojedinu knjigu.


 

Mogu�nost 4: Vra�anje knjige i Naplata zakasnine

Kreirajte funkciju koja slu�i za izra�unavanje zakasnine nakon �to se posudba knjige zavr�i. Knji�ni�ar unosi  redni broj posudbe.

Program knji�ni�aru omogu�ava upisati stvarni broj dana proteklih od posudbe knjige. Program izra�unava  razliku stvarnog broja dana i planiranog broja dana (unesenom u Mogu�nosti 1). Ukoliko posuditelj nije zakasnio s vra�anjem knjige, program pod Zakasnina upisuje 0, a u suprotnom upisuje cijenu zakasnine po tarifi od 0.1� po danu. Program mora knji�ni�ara obavijestiti da li knjiga kasni s povratom, te kolika je cijena zakasnine.

 

Mogu�nost 5: Izvoz podataka u datoteku

Kreirajte funkciju koja omogu�ava upis (izvoz) svih podataka o posudbama u tekstualnu
 datoteku imena �knjiznica.txt�.

Prvi red u datoteci sadr�i zapis o broju trenutno aktivnih posudbi
Drugi red u datoteci sadr�i nazive atributa/stupaca odvojene razmakom
Ostali redovi datoteke sadr�e  podatke o posudbama, podaci su me�usobno odvojeni razmakom
 

Mogu�nost 0: Izlaz iz programa*/
