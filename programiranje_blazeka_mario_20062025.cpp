#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct kazaliste{
	int racun;
	int brsjedala;
	bool rezervacija;
	float cijenaulaz;
	int oib;
};

//void prodaja

//void rezervacija //ulaznice i sjedala

//prodaja ulaznice //rezervirane

//ispis //podataka o ulaznicama

//datoteka

//izlaz

int main(){
	int movi[150];
	int izbor;
	int novi = 0;
	do{
		cout << endl;
		cout << "\nUnesite izbor 1-5 ili 0 za izlazak iz programa\n";
		cout << "***** I Z B O R N I K *****\n";
		cout << "1. Prodaja ulaznica\n";
		cout << "2. Rezervacija\n";;
		cout << "3. Prodaja rezervirane ulaznice\n";
		cout << "4. Ispis podataka o prodanim ulaznicama\n";
		cout << "5. Spremanje podataka u datoteku Izvoz.txt\n";
		cout << "0. Izlaz iz programa\n";
		cin >> izbor;
		switch(izbor){
			case 1: prodaja(polje, novi); break;
			case 2: rezervacija(polje, novi); break;
			case 3: prodrez(polje, novi); break;
			case 4: ispis(polje, novi); break;
			case 5: spremanje(polje, novi); break;
			case 0: cout << "Izlaz iz programa..." << endl; break;
			default: cout << "Pogresan unos!" << endl;
		}
	} while(izbor != 0);
	
	system("pause");
	return 0;
}	
	
	



/*
Napi�ite program kojim �ete evidentirati prodaju ulaznica kazali�ta sukladno kapacitetu i cjeniku:

Parter � 15 �, 100 ulaznica (sjedala 1-100)
Terasa � 17.50 �, 40 ulaznica (sjedala 101-140)
VIP lo�a � 20 �, 10 ulaznica (sjedala 141-150)
Svaka ulaznica u va�em programu treba sadr�avati barem sljede�e podatke:

Br. ulaznice / Ra�un (cijeli broj)
Br. sjedala (cijeli broj)
Rezervacija (logi�ka vrijednost)
Cijena ulaznice (decimalan broj)
OIB gledatelja (cijeli broj)
Program mora sadr�avati glavni izbornik sa mogu�nostima:

Prodaja ulaznice
Rezervacija ulaznice (sjedala)
Prodaja rezervirane ulaznice
Ispis podataka o prodanim ulaznicama
Izvoz podataka u datoteku
Izlaz iz programa
Napomena: Pojedine mogu�nosti obavezno realizirati pomo�u funkcija s argumentima!

Svaka, u potpunosti, realizirana mogu�nost programa donosi 20 bodova.

 

Mogu�nost 1: Prodaja ulaznice

Napi�ite funkciju koja omogu�ava upis podataka o prodanoj ulaznici u odgovaraju�e polje.

Program najprije provjeri ima li slobodnih mjesta, te ukoliko nema korisniku vrati info �Predstava je rasprodana!�
Ukoliko slobodno mjesto postoji, program pita za unos OIB-a kupca te prodaje prvo dostupno mjesto
Broj prodane ulaznice (Ra�un) program automatizmom, za svaku prodanu ulaznicu, uve�ava za 1 po�ev�i od 1 (1, 2, 3, � do 150)
Nakon svake prodane ulaznice program korisniku u konzolu ispi�e obavijest �Prodana je ulaznica xxx sa sjedalom xxx.�
Nakon toga izvo�enje programa se vra�a u glavni izbornik.
 

Mogu�nost 2: Rezervacija ulaznice

Kreirajte funkciju koja omogu�ava rezervaciju ulaznice i (ukoliko kupac �eli) odabir odre�enog numeriranog sjedala.

Program najprije ponudi podizbornik s 2 opcije:

Rezervacija numeriranog sjedala
Izmjena podataka o rezervaciji

Ukoliko se odabere Rezervacija numeriranog sjedala
Program najprije provjeri ima li slobodnih mjesta, te ukoliko nema korisniku vrati info �Predstava je rasprodana!� ina�e ispi�e sva slobodna mjesta
Nakon toga korisnika tra�i da upi�e mjesto koje �eli rezervirati
Nakon toga korisnika tra�i da upi�e OIB gledatelja
Zastavicu Rezervacija za doti�no mjesto program treba automatski zapisati i korisniku u konzolu vratiti poruku �Rezervacija realizirana!�
Nakon izvr�avanja program se vra�a u glavni izbornik
 

Ukoliko se odabere Izmjena podataka o rezervaciji

Program korisnika pita unos numeracije sjedala
Potom provjerava je li za doti�no sjedalo ve� ispostavljen Ra�un. Ukoliko je ra�un napravljen (postoji zapis �Br. ulaznice/Ra�un�) korisniku vra�a poruku �Ulaznica za doticno sjedalo je prodana, izmjena nije moguca!� ina�e za odabrano sjedalo program automatski adekvatno promijeni zastavicu Rezervacija i korisniku vrati info �Izmjena rezervacije realizirana!�.
Nakon izvr�avanja program se vra�a u glavni izbornik
 

Mogu�nost 3: Prodaja rezervirane ulaznice

Odabirom ove opcije program korisnika pita da unese sjedalo za koje postoji rezervacija
Nakon unosa, program provjerava vrijednost zastavice tj. postoji li rezervacija. Ukoliko rezervacija ne postoji program obavje�tava korisnika porukom �Rezervacija ne postoji za sjedalo xxx!� ina�e automatizmom prodaje ulaznicu vode�i ra�una o numeraciji prodane ulaznice/ra�una (opisano u Mogu�nost 1)
Program korisniku ispi�e obavijest �Prodana je ulaznica xxx sa sjedalom xxx.�
Nakon toga izvo�enje programa se vra�a u glavni izbornik.
 

Mogu�nost 4: Ispis podataka o prodanim ulaznicama

Kreirajte funkciju koja �e u konzolnom ispisu dati informaciju o:

Koli�ina prodanih karata:
Ukupno inkasirana sredstva:
Postotak rasprodanog Partera, Terase i VIP lo�e
Nakon izvr�avanja Mogu�nosti 4 izvo�enje programa se vra�a u glavni izbornik.

 

Mogu�nost 5: Izvoz podataka u datoteku

Kreirajte funkciju koja omogu�ava upis (izvoz) svih podataka o prodanim ulaznicama u tekstualnu datoteku imena �Izvoz.txt�.

Pojedini red datoteke sadr�i podatke o pojedinoj ulaznici
Pojedini red datoteke sadr�i najmanje 4 stupca (Br. ulaznice, sjedalo, cijena ulaznice, OIB gledatelja)
U prvi red datoteke program treba upisati oznake stupaca me�usobno odvojene razmakom (Br. ulaznice, sjedalo, cijena ulaznice, OIB gledatelja)
U ostalim redovima datoteke podaci o pojedinoj ulaznici
Nakon izvr�avanja Mogu�nosti 5 program u konzolu korisniku vra�a info �Izvoz podataka u datoteku realiziran!� te se izvo�enje programa vra�a u glavni izbornik.

 

Mogu�nost 0: Izlaz iz programa
*/




































/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct kuhari{
	int sifra;
	long long oib; // 11 znamenki
	string imeiprez;
	int bodovi;
	bool IIkrug;
};

bool validanOIB(long long oib) {
	int brojZnamenki = 0;
	while(oib > 0) {
		oib /= 10;
		brojZnamenki++;
	}
	return brojZnamenki == 11;
}
/*
bool postoji(Kamp polje[], int l, int id_kamp) {
    for (int i = 0; i < l; i++) {
        if (polje[i].idMjesta == id_kamp) return true;
    }
    return false;
}bool postoji(Kamp polje[], int l, int id_kamp) {
    for (int i = 0; i < l; i++) {
        if (polje[i].idMjesta == id_kamp) return true;
    }
    return false;
}

int id_kampa;
cin >> id_kampa;
if (postoji(polje, l, id_kampa)) {
        cout << "Kamp mjesto je zauzeto" << endl;
        return;
    }


void prijava(kuhari polje[], int &l) {
    cout << "Do sada je prijavljeno: " << l << " natjecatelja." << endl;
    if(l >= 50) {
        cout << "Dosegnut je maksimalni broj unosa" << endl;
        return;
    }

    polje[l].sifra = l + 1;

    string oib;
    cout << "Unesite OIB (11 znamenki): ";
    cin >> oib;
    while(!validanOIB(oib)) {
        cout << "Neispravan OIB. Pokusajte ponovno: ";
        cin >> oib;
    }
    polje[l].oib = oib;

    cin.ignore();
    cout << "Unesite ime i prezime: ";
    getline(cin, polje[l].imeiprez);

    polje[l].bodovi = 0;
    polje[l].IIkrug = false;
    l++;
}
void izmjena(kuhari polje[], int l) {
	int sifra;
	cout << "Unesite sifru natjecatelja za izmjenu: ";
	cin >> sifra;
	if(sifra < 1 || sifra > l) {
		cout << "Nepostojeca sifra!" << endl;
		return;
	}
	sifra--; // index u polju

	cout << "Trenutni podaci:\nOIB: " << polje[sifra].oib << "\nIme i prezime: " << polje[sifra].imeiprez << "\nBodovi: " << polje[sifra].bodovi << endl;

	long long oib;
	cout << "Unesite novi OIB: ";
	cin >> oib;
	while(!validanOIB(oib)){
		cout << "Neispravan OIB. Pokusajte ponovno: ";
		cin >> oib;
	}
	polje[sifra].oib = oib;

	cin.ignore();
	cout << "Unesite novo ime i prezime: ";
	getline(cin, polje[sifra].imeiprez);

	cout << "Unesite nove bodove: ";
	cin >> polje[sifra].bodovi;
	polje[sifra].IIkrug = false;
}
void izmjeni(odrzavanje polje[], int novi) {
    int redni;
    cout << "Unesi redni broj popravka/odrzavanja koji zelis izmijeniti: ";
    cin >> redni;

    for (int i = 0; i < novi; i++) {
        if (polje[i].rbr == redni) {
            cout << "Pronadjen popravak:\n";
            cout << "Vrsta: " << polje[i].vrstaPop << ", Racunalo: " << polje[i].naziv 
                 << ", Vrijeme: " << polje[i].vrijemePop << " min\n";
            cin.ignore();

            cout << "Unesi novu vrstu odrzavanja/popravka: ";
            getline(cin, polje[i].vrstaPop);
            cout << "Unesi novi naziv racunala: ";
            getline(cin, polje[i].naziv);
            cout << "Unesi novo vrijeme trajanja (u minutama): ";
            cin >> polje[i].vrijemePop;
            return;
        }
    }

    cout << "Odrzavanje/popravak s tim brojem ne postoji!\n";
}
void bodovi(kuhari polje[], int l){
	cout << "Do sada je prijavljeno: " << l << " natjecatelja." << endl;
	int opcija;
	do {
		cout << "\n1. Upis bodova\n2. Izmjena podataka\nOdaberi opciju: ";
		cin >> opcija;
		switch(opcija){
			case 1:
				for(int i = 0; i < l; i++){
					cout << "Sifra: " << polje[i].sifra << ", Ime i prezime: " << polje[i].imeiprez << "\nUnesite bodove: ";
					cin >> polje[i].bodovi;
					polje[i].IIkrug = false;
				}
				break;
			case 2:
				izmjena(polje, l);
				break;
			default:
				cout << "Krivi odabir" << endl;
		}
	} while(opcija != 1 && opcija != 2);
}
void ispravak(Ocjena polje[], int l) {
    string ime, prezime;
    cout << "Unesite ime i prezime studenta ciju ocjenu zelite ispraviti: ";
    cin >> ime >> prezime;
    
    for (int i = 0; i < l; i++) {
        if (polje[i].ime == ime && polje[i].prezime == prezime) {
            cout << "Trenutna ocjena: " << polje[i].ocjena << endl;
            cout << "Unesite novu ocjenu: ";
            cin >> polje[i].ocjena;
            cout << "Ocjena uspje�no a�urirana." << endl;
            return;
        }
    }
    
    cout << "Student nije prona�en!" << endl;
}
void izracun(kuhari polje[], int l){
	int maxBodovi = 0;
	for(int i = 0; i < l; i++){
		if(polje[i].bodovi > maxBodovi)
			maxBodovi = polje[i].bodovi;
	}
	float prag = maxBodovi * 0.8;
	for(int i = 0; i < l; i++){
		if(polje[i].bodovi > prag)
			polje[i].IIkrug = true;
	}
	cout << "Izracun zavrsen. Prag za 2. krug: " << prag << endl;
}

void ispis(kuhari polje[], int l){
	int odabir;
	cout << "1. Ispis svih natjecatelja\n2. Ispis natjecatelja u 2. krugu\nOdabir: ";
	cin >> odabir;
	for(int i = 0; i < l; i++){
		if(odabir == 2 && !polje[i].IIkrug) continue;
		cout << polje[i].sifra << " " << polje[i].oib << " " << polje[i].imeiprez << " " << polje[i].bodovi << " " << (polje[i].IIkrug ? "DA" : "NE") << endl;
	}
}

void ucitavanje(proizvod skladiste[], int &novi) {
    ifstream fajl("podaci.txt");
    if (fajl.is_open()) {
        while (!fajl.eof() && novi < 100) {
            fajl >> skladiste[novi].sifra;
            fajl >> skladiste[novi].naziv;
            fajl >> skladiste[novi].cijena;
            fajl >> skladiste[novi].kolicina;
            novi++;
        }
        fajl.close();
    } else {
        cout << "Greska pri otvaranju datoteke!" << endl;
    }
}

void pretraga(proizvod skladiste[], int novi, int trazenaSifra) {
    bool nadjen = false;
    for (int i = 0; i < novi; i++) {
        if (skladiste[i].sifra == trazenaSifra) {
            cout << "Pronadjen proizvod:" << endl;
            cout << "Sifra: " << skladiste[i].sifra << endl;
            cout << "Naziv: " << skladiste[i].naziv << endl;
            cout << "Cijena: " << skladiste[i].cijena << endl;
            cout << "Kolicina: " << skladiste[i].kolicina << endl;
            nadjen = true;
            break;
        }
    }
    if (!nadjen) {
        cout << "Proizvod sa sifrom " << trazenaSifra << " nije pronadjen." << endl;
    }
}
void pretrazi(odrzavanje polje[], int novi) {
    string pojam;
    cout << "Unesi pojam za pretragu: ";
    cin.ignore();
    getline(cin, pojam);
    
    bool found = false;
    for (int i = 0; i < novi; i++) {
        if (polje[i].vrstaPop.find(pojam) != string::npos || polje[i].naziv.find(pojam) != string::npos) {
            cout << "Pronadjeno: " << polje[i].rbr << ". " << polje[i].vrstaPop 
                 << " (" << polje[i].naziv << "), Vrijeme: " << polje[i].vrijemePop << " min\n";
            found = true;
        }
    }
    
    if (!found) cout << "Nema odrzavanja/popravki s tim pojmom!\n";
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

void spremanje(kuhari polje[], int l){
	ofstream dat("Izvoz.txt");
	dat << "sifra OIB ime_prezime bodovi 2KN" << endl;
	for(int i = 0; i < l; i++){
		dat << polje[i].sifra << " " << polje[i].oib << " " << polje[i].imeiprez << " " << polje[i].bodovi << " " << (polje[i].IIkrug ? 1 : 0) << endl;
	}
	dat.close();
	cout << "Podaci su uspjesno spremljeni u Izvoz.txt" << endl;
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
void brisi(odrzavanje polje[], int &novi) {
    int redni;
    cout << "Unesi redni broj popravka/odrzavanja koji zelis obrisati: ";
    cin >> redni;

    for (int i = 0; i < novi; i++) {
        if (polje[i].rbr == redni) {
            cout << "Brisem odrzavanje/popravak: " << polje[i].vrstaPop << " (" << polje[i].naziv << ")\n";
            for (int j = i; j < novi - 1; j++) {
                polje[j] = polje[j + 1];
            }
            novi--;
            cout << "Obrisano!\n";
            return;
        }
    }
    cout << "Odrzavanje/popravak s tim brojem ne postoji!\n";
}
int main(){
	kuhari polje[50];
	int izbor;
	int novi = 0;
	do{
		cout << endl;
		cout << "\nUnesite izbor 1-5 ili 0 za izlazak iz programa\n";
		cout << "***** I Z B O R N I K *****\n";
		cout << "1. Prijava novog natjecatelja\n";
		cout << "2. Upis bodova natjecatelja\n";
		cout << "3. Izracun/odabir ulaska u 2. krug\n";
		cout << "4. Ispis podataka o natjecateljima\n";
		cout << "5. Spremanje podataka u datoteku Izvoz.txt\n";
		cout << "0. Izlaz iz programa\n";
		cin >> izbor;
		switch(izbor){
			case 1: prijava(polje, novi); break;
			case 2: bodovi(polje, novi); break;
			case 3: izracun(polje, novi); break;
			case 4: ispis(polje, novi); break;
			case 5: spremanje(polje, novi); break;
			case 0: cout << "Izlaz iz programa..." << endl; break;
			default: cout << "Pogresan unos!" << endl;
		}
	} while(izbor != 0);
	
	system("pause");
	return 0;
}
*/
