#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct popravci{
	int rbr = 0;
	string odrzavanje;
	string racunalo;
	int vrijemePopravka;
};

popravci komada[100];
int brojUnosa = 0;

bool popunjeno = false;

void unos(){
	cout<<"Do sadaje uneseno: "<< brojUnosa <<" popravaka/odrzavanja \n";
	int rbr = brojUnosa;
	cin>>rbr;
	cout<<"Upisi naziv popravka \n";
	//cin >> odrzavanje;
	
	
	cout<<"Upisi naziv racunala \n";
	//cin >> racunalo;
	
	//rbr++;
	return;
/*
Omogućiti unos podataka o održavanju/popravku u odgovarajuće polje veličine 
100 elemenata. Svaki element polja treba biti tipa strukture s podacima o
 jednom održavanju/popravku.

Odabirom mogućnosti 1., prije samog unosa program treba ispisati 
koliko je održavanja/popravaka dosad unešeno
Ukoliko je polje popunjeno ispisati poruku „Polje je popunjeno!“
Ukoliko polje nije popunjeno, podaci o novom održavanju/popravku se 
upisuju na prvo slobodno mjesto (korisnik upisuje vrstu održavanja/
popravke i naziv računala). Broj održavanja/popravke se ne upisuje 
već je program automatski dodaje (tako da prvo održavanje/popravka
 ima broj 1, slijedeće 2 itd.).
Nakon svakog unesenog održavanja/popravke izvođenje programa se 
vraća u glavni izbornik.
Mogućnost 1. treba funkcionirati tako da se svakim njenim pozivom 
unos u polje nastavlja od prvog slobodnog mjesta u polju.
*/
}

void izmjena(){
	cout<<"Upisi broj odrzavanja za izmjenu \n";
	// cin>>rbr;
	//if(rbr==0){
	cout<<"Održavanje/popravka s tim brojem ne postoji' i vratiti se u glavni izbornik \n";
	return;	
//	}else{
/*
Nakon odabira ove opcije program:

Korisnika traži broj održavanja/popravka koje treba izmijeniti
Ako upisani broj ne postoji program treba ispisati poruku 'Održavanje/
popravka s tim brojem ne postoji' i vratiti se u glavni izbornik
Ako upisani broj postoji program treba ispisati sve podatke za navedenu 
održavanje/popravku i zatražiti unos novih podataka
Nakon unosa novih podataka program se automatski vraća na izbornik
*/
	}
	

void brisanje(){
	cout<<"Upisi broj odrzavanja za brisanje \n";
	
/*Nakon odabira ove opcije program traži da korisnik upiše broj održavanja/
popravka koje treba izbrisati. Ako korisnik upiše nepostojeći broj program 
se vraća na glavni izbornik. Ako korisnik upiše ispravan broj, program najprije 
korisniku na ekran ispiše podatke vezane za navedeno održavanje/popravku te potom 
od korisnika traži da potvrdi da želi obrisati navedeno održavanje/popravku. Ako 
korisnik potvrdi brisanje, podaci o održavanju/popravci se obrišu iz polja. 
Nakon toga program se vraća na glavni izbornik.
*/
}

void pretrazivanje(){

/*
Nakon odabira ove opcije program:

Korisnika traži da upiše pojam koji želi pretražiti u polju održavanja/popravki
Program treba ispisati sve održavanja/popravke u polju koje sadrže navedeni pojam
 (npr. ako korisnik upiše "servis", program bi trebao ispisati sve održavanja/
 popravke koje sadrže riječ "servis" u svojem opisu)
Ako ne postoji niti jedno održavanje/popravak s navedenim pojmom, program 
treba ispisati poruku 'Nema održavanja/popravki s tim pojmom'
Nakon što se završi pretraživanje program se vraća na glavni izbornik
*/
}

void spremanje(){
	
/*
Nakon odabira ove opcije program treba ispisati sve održavanja/popravke
 koje su trenutno unesene u polje u datoteku baza.txt na način da se pojedini
  zapis održavanja/popravka nalazi u zasebnom retku, a zasebni podaci su 
  odvojeni vertikalnom crtom (|). U zadnjem retku datoteku treba pisati 
  tekst "–kraj zapisa–".
*/
}

void izbornik(){
	int izbor;

cout<<"-----IZBORNIK-----\n";
cout<<"0.-----IZBORNIK-----\n";
cout<<"1.-----IZBORNIK-----\n";
cout<<"2.-----IZBORNIK-----\n";
cout<<"3.-----IZBORNIK-----\n";
cout<<"4.-----IZBORNIK-----\n";
cout<<"5.-----IZBORNIK-----\n";

cin>>izbor;

do{
	switch(izbor){
		case 1: unos() ; break;
				case 2: ; break;
						case 3: ; break;
								case 4: ; break;
										case 5: ; break;
												case 0: ; break;
		default: 
		cout<<"Izlaz iz programa!\n";
	}
}while(izbor !=0);
}

int main(){
	izbornik();
	
	system("pause");
	return 0;
}