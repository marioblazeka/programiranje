#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct kuhari{
	int sifra;
	int oib;		//trebam dodati ogranicenje 11
	string imeiprez;
	int bodovi;
	bool IIkrug;	//ako ostvari bodove ulazi u drugi krug
};

void prijava(kuhari[], int &l){
	cout<<"Do sada je prijavljeno: "<<l<<" natjecatelja."<<endl;
	if(l>=50){
		cout<<"Dosegnut je maksimalni broj unosa"<<endl;
		return;
	}
for(int i=0; i>l; i++)
//kuhari[novi].sifra = novi +1;

cout<<"Unesite OiB"<<endl;
//cin.getline();

cout<<"Unesite ime i prezime"<<endl;
//cin.getline();

int bodovi=0;
l++;
}

void bodovi(kuhari[], int l){
	cout<<"Do sada je prijavljeno: "<<l<<" natjecatelja."<<endl;
int opcija;
	do{
		cout<<"Odaberi 1 ili 2"<<endl;
	
	cout<<"\n1. bodovi\n"<<endl;
	cout<<"2. izmjena"<<endl;
	switch(opcija){
		case 1: //bodovi(polje, novi);
			break;
			case 2: //izmjena(polje, novi);
				break;
				default:
					cout<<"Krivi odabir"<<endl;
	}
	}while(opcija>1||2);
return;
}
void izracun(kuhari[], int l){                       //prag za ulazak u drugi krug
                      
}		
void ispis(kuhari[], int l){
	
}
void spremanje(kuhari[], int l){
	
}

void izmjena(kuhari[], int l){						//dodati

}

int main(){
	kuhari polje[50];
	int izbor;
	int novi=0;
	
	do{
		cout<<endl;
		cout<<"\nUnesite izbor 1-5 ili 0 za izlazak iz programa\n";
		cout<<endl;
		cout<<"*****I Z B O R N I K *****\n";
		cout<<endl;
		cout<<"1. Prijava novog natjecatelja\n";
		cout<<"2. Upis bodova natjecatelja\n";
		cout<<"3. Izraèun/odabir ulaska u 2. krug\n";
		cout<<"4. Ispis podataka o natjecateljima\n";
		cout<<"5. Spremanje podataka u datoteku Izvoz.txt\n";
		cout<<"0. Izlaz iz programa\n";
		cin>>izbor;
		
		switch(izbor){
		case 1: prijava(polje, novi);
			break;
				case 2: bodovi(polje, novi);
					break;
						case 3: izracun(polje, novi);
							break;
								case 4: ispis(polje, novi);
									break;
										case 5: spremanje(polje, novi);
											break;
		default:
			cout<<"Pogresan unos unesite izbor 1-5 ili 0 za izlaz"<<endl;				
		}
	}while(!izbor>=0);
	
	system("pause");
	return 0;
}

/*
Programiranje 4.4.2025

Napišite program za potrebe 1. kruga kulinarskog natjecanja u kojem sudjeluje 50 natjecatelja. Program pohranjuje i prati podatke o pojedinom natjecatelju. Svaki se kandidat prijavljuje predstavniku organizatora koji u vaš program unosi barem sljedeæe podatke o natjecatelju:

Šifra natjecatelja (cijeli broj)
OIB natjecatelja (11-tero znamenkasti cijeli broj)
ime i prezime natjecatelja (tekst)
Osvojeni bodovi (cijeli broj)
2. krug natjecanja (logièka vrijednost)
Program treba sadržavati glavni izbornik sa sljedeæim moguænostima:

Prijava novog natjecatelja
Upis bodova / izmjena podataka o natjecatelju
Izraèun/odabir za ulazak u 2. krug natjecanja
Ispis podataka o natjecateljima
Izvoz podataka u datoteku
Napomena: Pojedine moguænosti obavezno realizirati pomoæu funkcija s argumentima!

Svaka, u potpunosti realizirana moguænost programa donosi vam 20 bodova.

 

Moguænost 1: Prijava natjecatelja

Kreirajte funkciju koja omoguæava upis podataka o novom natjecatelju u polje velièine 50 elemenata.

Moguænost programa najprije ispiše koliko je natjecatelja do sada prijavljeno (ukoliko je veæ prijavljeno 50 natjecatelja, program ispiše odgovarajuæu obavijest i vrati se u glavni izbornik).
Nakon toga program automatizmom novom natjecatelju dodjeljuje iduæu slobodnu šifru (prvi natjecatelj dobiva šifru 1, drugi 2, treæi 3 … itd. do posljednjeg 50)
Potom pita za unos njegovog OIB-a, imena i prezimena
Ostale vrijednosti automatizmom postavlja na nulu.
 

Moguænost 2: Upis bodova / izmjena podataka o natjecatelju

Kreirajte funkciju koja omoguæava upis bodova i izmjenu podataka za pojedinog natjecatelja.

Moguænost najprije ispiše koliko je natjecatelja prijavljeno
Nakon toga ponudi 2 opcije:
Upis bodova
Izmjena podataka natjecatelja
Ukoliko se odabere Upis bodova

Program redom (po šifri natjecatelja) nudi upis bodova
Prije samog upisa bodova program treba ispisati šifru te ime i prezime natjecatelja za kojeg se traži upis bodova
Labela „2. krug natjecanja“ program automatizmom dodjeljuje vrijednost 0 (nula)
Ukoliko se odabere Izmjena podataka natjecatelja

Program traži upis šifre natjecatelja za kojeg se želi napraviti izmjenu podataka
Potom program ispiše OIB, ime i prezime za dotiènu šifru natjecatelja za kojeg ponudi izmjenu vrijednosti za OIB-a, imena i prezimena, bodova
 

Moguænost 3: Izraèun/odabir za ulazak u 2. krug natjecanja

Kreirajte funkciju koja æe izraèunati i odabrati sve natjecatelje koji ulaze u 2. krug natjecanja.

U 2. krug natjecanja ulaze samo oni natjecatelji koji su prikupili više od 80% bodova najbolje ocijenjenog natjecatelja.

Funkcija svim natjecateljima koji udovoljavaju kriterija za ulazak u 2. krug natjecanja atribut „2. krug natjecanja – 2KN“ postavlja na logièku vrijednost 1.

 

Moguænost 4: Ispis podataka o natjecateljima

Kreirajte funkciju koja omoguæava ispis podataka u konzolu te ponudi odabir:

Ispis podataka svih natjecatelja
Ispis podataka natjecatelja koji su ušli u 2. krug natjecanja
U konzolnom ispisu pojedini red sadrži podatke o pojedinom natjecatelju. Podaci su meðusobno odvojeni razmakom

 

Moguænost 5: Izvoz podataka u datoteku

Kreirajte funkciju koja omoguæava upis (izvoz) svih podataka o natjecateljima u tekstualnu datoteku imena „Izvoz.txt“.

Pojedini red datoteke sadrži podatke o pojedinom natjecatelju
Pojedini red datoteke sadrži najmanje 5 stupaca (šifra, OIB, ime i prezime, bodovi, ulazak u drugi krug natjecanja)
U prvom redu datoteke trebaju pisati oznake stupaca meðusobno odvojene razmakom „šifra OIB ime_prezime bodovi 2KN“
U ostalim redovima datoteke trebaju pisati podaci o pojedinom natjecatelju
 

Moguænost 0: Izlaz iz programa
*/



































