#include <fstream>
#include <iostream>
using namespace std;

struct Kamp {
  int id = 0;
  int br_korisnika = 0;
  int br_dana = 0;
  int br_ljubimaca = 0;
  int prekrsaji = 0;
};

bool postoji(Kamp *polje, int l, int id_kampa) {
  for (int i = 0; i < l; i++) {
    if (polje[i].id == id_kampa) {
      return true;
    }
  }
  return false;
}

void ispisi_info(Kamp kamp) {
  cout << "- ID: " << kamp.id << endl;
  cout << "- Dani: " << kamp.br_dana << endl;
  cout << "- Korisnici: " << kamp.br_korisnika << endl;
  cout << "- Ljubimci: " << kamp.br_ljubimaca << endl;
  cout << "- Prekrsaji: " << kamp.prekrsaji << endl;
}

void unos(Kamp *polje, int &l) {
  // ispisati broj zauzetih mjesta
  cout << "Zauzetih ima " << l << endl;

  // ako su sva mjesta zauzeta ispisi poruku i vrati u izbornik
  if (l >= 70) {
    cout << "Sva kamp mjesta su zauzeta" << endl;
    return;
  }

  int id_kampa;
  cout << "Upisite ID kampa za kojeg se unose podaci: ";
  cin >> id_kampa;
  // provjera da li mjesto već postoji u polju
  if (postoji(polje, l, id_kampa)) {
    cout << "Kamp mjesto je već rezervirano" << endl;
    // povratak u izbornik (main)
    return;
  }

  // upis u prvo slobodno mjesto
  polje[l].id = id_kampa;
  cout << "Upisite broj dana ";
  cin >> polje[l].br_dana;
  cout << "Upisite broj korisnika ";
  cin >> polje[l].br_korisnika;
  cout << "Upisite broj ljubimaca ";
  cin >> polje[l].br_ljubimaca;
  // premjesti brojac na sljedeće prazno mjesto za sljedeći upis
  l++;
}

void izmjena(Kamp *polje, int l) {
  int id_kampa;
  cout << "Upisite ID kampa ";
  cin >> id_kampa;
  // ako ne postoji vrati u izbornik
  if (!postoji(polje, l, id_kampa)) {
    cout << "Kamp mjesto nije evidentirano kao zauzeto" << endl;
    // povratak u izbornik (main)
    return;
  }

  // trazenje prema id-u
  for (int i = 0; i < l; i++) {
    if (polje[i].id == id_kampa) {
      cout << "Pronadjeno, ovo su podaci za taj kamp:" << endl;
      ispisi_info(polje[i]);

      int odabir;
      cout << "Odaberi jednu od opcija: ";
      cout << "1. Ne prijavljeni ljubimci: 200 kn" << endl;
      cout << "2. Razbacivanje smeća: 400 kn" << endl;
      cout << "3. Ne poštivanje granica: 100 kn" << endl;
      cin >> odabir;
      switch (odabir) {
      case 1:
        polje[i].prekrsaji += 200;
        break;
      case 2:
        polje[i].prekrsaji += 400;
        break;
      case 3:
        polje[i].prekrsaji += 100;
        break;
      default:
        cout << "Neispravan unos" << endl;
      }

      // pronasli smo podatak i ne treba traziti dalje
      // pa se vrati u izbornik
      return;
    }
  }
}

void naplata(Kamp *polje, int &l) {
  int id_kampa;
  cout << "Upisite ID kampa ";
  cin >> id_kampa;
  // ako ne postoji vrati u izbornik
  if (!postoji(polje, l, id_kampa)) {
    cout << "Kamp mjesto nije evidentirano kao zauzeto" << endl;
    // povratak u izbornik (main)
    return;
  }
  for (int i = 0; i < l; i++) {
    if (polje[i].id == id_kampa) {
      ispisi_info(polje[i]);

      int cijena = polje[i].br_dana * polje[i].br_korisnika +
                   polje[i].br_dana * polje[i].br_ljubimaca +
                   polje[i].prekrsaji;
      cout << "Cijena: " << cijena << endl;

      // oznaci element kao slobodan
      polje[i].id = 0;
      polje[i].br_dana = 0;
      polje[i].br_korisnika = 0;
      polje[i].br_ljubimaca = 0;
      polje[i].prekrsaji = 0;
      polje[i] = polje[l - 1];
      // sveukupno je sada jedan manje element, pa smanji brojač
      l--;

      // prekini trazenje i vrati se u glavni izbornik
      return;
    }
  }
}

void izvjesce(Kamp *polje, int l) {
  int suma_dana = 0, brojac = 0, zarada = 0, br_osoba = 0, br_ljubimaca = 0;
  for (int i = 0; i < l; i++) {
    ispisi_info(polje[i]);
    cout << endl;

    suma_dana += polje[i].br_dana;
    br_osoba += polje[i].br_korisnika;
    br_ljubimaca += polje[i].br_ljubimaca;
    zarada += polje[i].br_dana * polje[i].br_korisnika +
              polje[i].br_dana * polje[i].br_ljubimaca + polje[i].prekrsaji;
    brojac++;
  }
  cout << "Prosjek dana: " << suma_dana * 1.0 / brojac << endl;
  cout << "Zarada: " << zarada << endl;
  cout << "Broj osoba: " << br_osoba << endl;
  cout << "Broj ljubimaca: " << br_ljubimaca << endl;
}

void datoteka(Kamp *polje, int l) {
  ofstream file("kamp.txt");
  if (!file) {
    cout << "Greska pri kreiranju datoteke" << endl;
    return;
  }

  // u prvom retku je samo broj zauzetih kampova
  file << l << endl;

  for (int i = 0; i < l; i++) {
    // u datoteku ispisi samo zauzete elemente
    file << polje[i].id << " ";
    file << polje[i].br_dana << " ";
    file << polje[i].br_korisnika << " ";
    file << polje[i].br_ljubimaca << " ";
    file << polje[i].prekrsaji << endl; // zavrsi redak
  }
  file.close();
}

int main() {
  int index_zadnjeg = 0;
  Kamp polje[70];
  
  cout<<"1. Unos parkirnog mjesta.\n";
	cout<<"2. Izmjena unesenog parkirnog mjesta.\n";
	cout<<"3. Naplata parkirnog mjesta/kampiranja.\n";
	cout<<"4. Ispis podataka o parkirnom mjestu.\n";
	cout<<"5. Unos podataka parkirnog mjesta u datoteku (kamp.txt) parkiranje.txt\n";
	cout<<"0. Izaz iz izbornika.\n";


  int opcija;
  do {
    cout << "Odaberi opciju od 1 do 5 ili 0 za izlaz. ";
    cin >> opcija;
    switch (opcija) {
    case 1:
      unos(polje, index_zadnjeg);
      break;
    case 2:
      izmjena(polje, index_zadnjeg);
      break;
    case 3:
      naplata(polje, index_zadnjeg);
      break;
    case 4:
      izvjesce(polje, index_zadnjeg);
      break;
    case 5:
      datoteka(polje, index_zadnjeg);
      break;
    default:
      cout << "Odabeti jedan od ponudjenih izbora/opcija: " << endl;
    }

  } while (opcija != 0);
  {
    	cout << "Odabrali ste 0 i izlazim iz programa" << endl;
  };
	system("pause");
  return 0;
}

