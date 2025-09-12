#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Struktura za pohranu jednog održavanja/popravka
struct pojedOdrzava{
	int redBr;          // redni broj zapisa
	string vrstOdrza;   // vrsta održavanja/popravka
	string nazRac;      // naziv raèunala
	int vrijOdrz;       // vrijeme održavanja/popravka
};

// Polje struktura (maksimalno 100 zapisa)
pojedOdrzava odrzavanje[100];
int unos=0;   // broj unosa (trenutno stanje)
int redBr=1;  // redni broj (inkrementira se pri svakom unosu)

// Funkcija za unos novog zapisa održavanja/popravka
void unosOdrzavanja(){
	if(unos<100){ // <-- bilo je <101, ali polje je od 0 do 99 (dakle max 100 elemenata)
		cout<<"Do sada je uneseno "<<unos<<" odrzavanja/popravaka\n";
	}else{
		cout<<"Polje je popunjeno! \n";
		return; // odmah prekid ako je puno
	}
	//cin.ignore(); // nepotrebno za unos stringa jer koristis >> (uzima samo do prvog razmaka)
	cout<<"Upisi vrstu odrzavanja: \n";
	cin>>odrzavanje[unos].vrstOdrza;
	cout<<"Upisi naziv racunala: \n";
	cin>>odrzavanje[unos].nazRac;
	cout<<"Upisi vrijeme popravka: \n";
	cin>>odrzavanje[unos].vrijOdrz;

	odrzavanje[unos].redBr = redBr; // postavi redni broj za zapis
	unos++;     // poveæa broj unosa
	redBr++;    // poveæa redni broj

	return;
}

// Funkcija za izmjenu zapisa
void izmjenaOdrzavanja(){
	cout<<"Upisi broj odrzavanja za izmjenu: \n";
	int trazi;
	cin>>trazi;
	
	// Ovdje je bila greska: koristio si = umjesto == (dodjela umjesto usporedbe)
	// Takoðer, treba pretražiti SVE unose, a ne samo zadnji
	bool nadjen=false;
	for(int i=0;i<unos;i++){
		if(trazi == odrzavanje[i].redBr){  // <-- ispravno
			cout<<odrzavanje[i].redBr<<" "<<odrzavanje[i].vrstOdrza<<" "<<odrzavanje[i].nazRac<<" "<<odrzavanje[i].vrijOdrz<<endl;
			cout<<"Unesi podatke za promjenu zapisa odrzavanja: \n";
			
			cout<<"Upisi izmjenu vrste odrzavanja: \n";
			cin>>odrzavanje[i].vrstOdrza;
			cout<<"Upisi izmjenu naziva racunala: \n";
			cin>>odrzavanje[i].nazRac;
			cout<<"Upisi izmjenu vremena popravka: \n";
			cin>>odrzavanje[i].vrijOdrz;
			nadjen=true;
			break;
		}
	}
	if(!nadjen){
		cout<<"Odrzavanje/popravak s tim brojem ne postoji \n";
	}
}

// Funkcija za brisanje zapisa
void brisOdrzavanja(){
	cout<<"Upisi broj odrzavanja za brisanje: \n";
	int brisi;
	cin>>brisi;

	// Isto kao i kod izmjene: treba pretražiti sve unose
	bool nadjen=false;
	for(int i=0;i<unos;i++){
		if(brisi == odrzavanje[i].redBr){
			cout<<"Brisem: "<<odrzavanje[i].redBr<<" "<<odrzavanje[i].vrstOdrza<<" "<<odrzavanje[i].nazRac<<" "<<odrzavanje[i].vrijOdrz<<endl;
			// Brisanje – pomakni sve elemente iza ovog za jedno mjesto unazad
			for(int j=i;j<unos-1;j++){
				odrzavanje[j] = odrzavanje[j+1];
			}
			unos--; // smanji broj unosa
			nadjen=true;
			break;
		}
	}
	if(!nadjen){
		cout<<"Odrzavanje/popravak s tim brojem ne postoji \n";
	}
}

// Funkcija za pretrazivanje po vrsti odrzavanja
void pretrOdrzavanja(){
	cout<<"Upisi pojam odrzavanja/popravka za pretragu: \n";
	string pretrazi;
	cin>>pretrazi;

	bool nadjen=false;
	for(int i=0;i<unos;i++){
		if(pretrazi == odrzavanje[i].vrstOdrza){
			cout<<odrzavanje[i].redBr<<" "<<odrzavanje[i].vrstOdrza<<" "<<odrzavanje[i].nazRac<<" "<<odrzavanje[i].vrijOdrz<<endl;
			nadjen=true;
		}
	}
	if(!nadjen){
		cout<<"Nema odrzavanja/popravki s tim pojmom \n";
	}
}

// Funkcija za spremanje u datoteku
void spremanjeuDatoteku(){
	ofstream datoteka("baza.txt");
	if(!datoteka){
		cout<<"Greska u otvaranju datoteke\n";
	}else{
		// Header (samo jednom, ne u petlji!)
		datoteka<<"REDNI BROJ\tVRSTA ODRZAVANJA\tNAZIV RACUNALA\tVRIJEME ODRZAVANJA\n";
		for(int i=0; i<unos; i++){
			datoteka<<odrzavanje[i].redBr<<"\t"<<odrzavanje[i].vrstOdrza<<"\t"<<odrzavanje[i].nazRac<<"\t"<<odrzavanje[i].vrijOdrz<<"\n";
		}
		cout<<"Podaci su spremljeni u datoteku.\n";
	}
}

// Glavni izbornik
void glavniIzbornik(){
	int izbor;
	
	do{
		cout<<"\n";
		cout<<"1. Unos novog održavanja/popravka\n";
		cout<<"2. Izmjena održavanja/popravka\n";
		cout<<"3. Brisanje održavanja/popravka\n";
		cout<<"4. Pretraživanje održavanja/popravki\n";
		cout<<"5. Spremanje u datoteku\n";
		cout<<"0. Izlaz\n";
		cin>>izbor;
	
		switch(izbor){
			case 1: unosOdrzavanja(); break;
			case 2: izmjenaOdrzavanja(); break;
			case 3: brisOdrzavanja(); break;
			case 4: pretrOdrzavanja(); break;
			case 5: spremanjeuDatoteku(); break;
			case 0: cout<<"Izlaz iz programa.\n"; break;
			default: cout<<"Greska u unosu\n";
		}
	}while(izbor!=0); // <-- ispravka: prije si imao (unos!=0), to je bila greska
}

int main(){
	glavniIzbornik();
	return 0;
}

