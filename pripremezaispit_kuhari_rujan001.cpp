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
		cout<<"3. Izra�un/odabir ulaska u 2. krug\n";
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

Napi�ite program za potrebe 1. kruga kulinarskog natjecanja u kojem sudjeluje 50 natjecatelja. Program pohranjuje i prati podatke o pojedinom natjecatelju. Svaki se kandidat prijavljuje predstavniku organizatora koji u va� program unosi barem sljede�e podatke o natjecatelju:

�ifra natjecatelja (cijeli broj)
OIB natjecatelja (11-tero znamenkasti cijeli broj)
ime i prezime natjecatelja (tekst)
Osvojeni bodovi (cijeli broj)
2. krug natjecanja (logi�ka vrijednost)
Program treba sadr�avati glavni izbornik sa sljede�im mogu�nostima:

Prijava novog natjecatelja
Upis bodova / izmjena podataka o natjecatelju
Izra�un/odabir za ulazak u 2. krug natjecanja
Ispis podataka o natjecateljima
Izvoz podataka u datoteku
Napomena: Pojedine mogu�nosti obavezno realizirati pomo�u funkcija s argumentima!

Svaka, u potpunosti realizirana mogu�nost programa donosi vam 20 bodova.

 

Mogu�nost 1: Prijava natjecatelja

Kreirajte funkciju koja omogu�ava upis podataka o novom natjecatelju u polje veli�ine 50 elemenata.

Mogu�nost programa najprije ispi�e koliko je natjecatelja do sada prijavljeno (ukoliko je ve� prijavljeno 50 natjecatelja, program ispi�e odgovaraju�u obavijest i vrati se u glavni izbornik).
Nakon toga program automatizmom novom natjecatelju dodjeljuje idu�u slobodnu �ifru (prvi natjecatelj dobiva �ifru 1, drugi 2, tre�i 3 � itd. do posljednjeg 50)
Potom pita za unos njegovog OIB-a, imena i prezimena
Ostale vrijednosti automatizmom postavlja na nulu.
 

Mogu�nost 2: Upis bodova / izmjena podataka o natjecatelju

Kreirajte funkciju koja omogu�ava upis bodova i izmjenu podataka za pojedinog natjecatelja.

Mogu�nost najprije ispi�e koliko je natjecatelja prijavljeno
Nakon toga ponudi 2 opcije:
Upis bodova
Izmjena podataka natjecatelja
Ukoliko se odabere Upis bodova

Program redom (po �ifri natjecatelja) nudi upis bodova
Prije samog upisa bodova program treba ispisati �ifru te ime i prezime natjecatelja za kojeg se tra�i upis bodova
Labela �2. krug natjecanja� program automatizmom dodjeljuje vrijednost 0 (nula)
Ukoliko se odabere Izmjena podataka natjecatelja

Program tra�i upis �ifre natjecatelja za kojeg se �eli napraviti izmjenu podataka
Potom program ispi�e OIB, ime i prezime za doti�nu �ifru natjecatelja za kojeg ponudi izmjenu vrijednosti za OIB-a, imena i prezimena, bodova
 

Mogu�nost 3: Izra�un/odabir za ulazak u 2. krug natjecanja

Kreirajte funkciju koja �e izra�unati i odabrati sve natjecatelje koji ulaze u 2. krug natjecanja.

U 2. krug natjecanja ulaze samo oni natjecatelji koji su prikupili vi�e od 80% bodova najbolje ocijenjenog natjecatelja.

Funkcija svim natjecateljima koji udovoljavaju kriterija za ulazak u 2. krug natjecanja atribut �2. krug natjecanja � 2KN� postavlja na logi�ku vrijednost 1.

 

Mogu�nost 4: Ispis podataka o natjecateljima

Kreirajte funkciju koja omogu�ava ispis podataka u konzolu te ponudi odabir:

Ispis podataka svih natjecatelja
Ispis podataka natjecatelja koji su u�li u 2. krug natjecanja
U konzolnom ispisu pojedini red sadr�i podatke o pojedinom natjecatelju. Podaci su me�usobno odvojeni razmakom

 

Mogu�nost 5: Izvoz podataka u datoteku

Kreirajte funkciju koja omogu�ava upis (izvoz) svih podataka o natjecateljima u tekstualnu datoteku imena �Izvoz.txt�.

Pojedini red datoteke sadr�i podatke o pojedinom natjecatelju
Pojedini red datoteke sadr�i najmanje 5 stupaca (�ifra, OIB, ime i prezime, bodovi, ulazak u drugi krug natjecanja)
U prvom redu datoteke trebaju pisati oznake stupaca me�usobno odvojene razmakom ��ifra OIB ime_prezime bodovi 2KN�
U ostalim redovima datoteke trebaju pisati podaci o pojedinom natjecatelju
 

Mogu�nost 0: Izlaz iz programa
*/



































