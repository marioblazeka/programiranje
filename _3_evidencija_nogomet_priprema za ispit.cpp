#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Rez {
    int sifra;
    string domaci;
    string gosti;
    int golD;
    int golG;
};

void ispis(Rez *polje, int u) {
    if (u == 0) {
        cout << "Nije unesen niti jedan rezultat.\n";
        return;
    }
    int brojac_dom = 0, brojac_gost = 0, brojac_tie = 0;
    for (int i = 0; i < u; i++) {
        cout << endl << polje[i].sifra << ". "
             << polje[i].domaci << " - "
             << polje[i].gosti << " "
             << polje[i].golD << ":"
             << polje[i].golG;

        if (polje[i].golD > polje[i].golG)
            brojac_dom++;
        else if (polje[i].golG > polje[i].golD)
            brojac_gost++;
        else
            brojac_tie++;
    }

    cout << "\nBroj pobjeda domaćih timova: " << brojac_dom << endl;
    cout << "Broj pobjeda gostujućih timova: " << brojac_gost << endl;
    cout << "Broj neodlučenih utakmica: " << brojac_tie << endl;
}

void unos(Rez *polje, int &b) {
    cout << "Uneseno je: " << b << " rezultata." << endl;
    if (b == 100) {
        cout << "Popunjeno je\n";
        return;
    }
    cout << "Unesite domacina: ";
    cin >> polje[b].domaci;
    cout << "Unesite gosta: ";
    cin >> polje[b].gosti;
    cout << "Unesite broj golova domacina: ";
    cin >> polje[b].golD;
    cout << "Unesite broj golova gostiju: ";
    cin >> polje[b].golG;
    polje[b].sifra = b + 1;
    b += 1;
}

void pregled(Rez *polje, int u) {
    if (u == 0) {
        cout << "Nema upisanih rezultata\n";
        return;
    }

    for (int i = 0; i < u; i++) {
        cout << polje[i].sifra << ". "
             << polje[i].domaci << " - "
             << polje[i].gosti << " "
             << polje[i].golD << ":"
             << polje[i].golG << endl;
    }
}

void ispravak(Rez *polje, int u) {
    if (u == 0) {
        cout << "Nema upisanih rezultata\n";
        return;
    }
    
    int sifr;
    ispis(polje, u);
    cout << "Unesite sifru utakmice: ";
    cin >> sifr;

    if (sifr < 1 || sifr > u) {
        cout << "Krivi unos\n";
        return;
    }

    sifr--; // Da indeks odgovara nizu

    cout << "Unesite novi domacin: ";
    cin >> polje[sifr].domaci;
    cout << "Unesite novog gosta: ";
    cin >> polje[sifr].gosti;
    cout << "Unesite novi broj golova domacina: ";
    cin >> polje[sifr].golD;
    cout << "Unesite novi broj golova gostiju: ";
    cin >> polje[sifr].golG;
}

void spremi(Rez *polje, int u) {
    ofstream izlaz("Rezultati_priprema_za_ispit.txt");
    if (!izlaz) {
        cout << endl << "Greska u otvaranju datoteke" << endl;
        return;
    }
    for (int i = 0; i < u; i++) {
        izlaz << polje[i].sifra << " "
              << polje[i].domaci << " "
              << polje[i].gosti << " "
              << polje[i].golD << " "
              << polje[i].golG << endl;
    }
    izlaz.close();
    cout << "Podaci su spremljeni.\n";
}

void pretrazi(Rez *polje, int u) {
    if (u == 0) {
        cout << "Nema upisanih rezultata\n";
        return;
    }

    string ekipa;
    cout << endl << "Pretrazivanje rezultata" << endl;
    cout << "Unesite ime ekipe: ";
    cin >> ekipa;
    
    bool found = false;
    for (int i = 0; i < u; i++) {
        if (ekipa == polje[i].domaci || ekipa == polje[i].gosti) {
            cout << endl << polje[i].sifra << ". "
                 << polje[i].domaci << " - "
                 << polje[i].gosti << " "
                 << polje[i].golD << ":"
                 << polje[i].golG;
            found = true;
        }
    }

    if (!found) cout << "Nema rezultata za ovu ekipu.\n";
}

int main() {
    Rez *polje = new Rez[100];
    int sum = 0;
    int izbor;

    do {
        cout << "\n1. Unos podataka\n";
        cout << "2. Ispravak podataka\n";
        cout << "3. Pregled podataka\n";
        cout << "4. Spremanje podataka\n";
        cout << "5. Pretrazivanje podataka\n";
        cout << "0. Izlaz iz programa\n";
        cout << "Unesite opciju 1 - 5 ili 0 za izlaz: ";
        cin >> izbor;

        switch (izbor) {
            case 1: unos(polje, sum); break;
            case 2: ispravak(polje, sum); break;
            case 3: pregled(polje, sum); break;
            case 4: spremi(polje, sum); break;
            case 5: pretrazi(polje, sum); break;
            case 0: cout << "Izlaz iz programa...\n"; break;
            default: cout << "Nepostojeca opcija! Pokusajte ponovo.\n";
        }
    } while (izbor != 0);

    delete[] polje;
    return 0;
}
