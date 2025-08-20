#include <iostream>
#include <fstream>

using namespace std;

/*Izradite program namijenjen vođenju evidencije zauzetih kamp mjesta u kampu kapaciteta 70 kamp mjesta. 
U programu voditelj kampa unosi sljedeće podatke o korisnicima koji zauzimaju određeno mjesto u kampu.*/

struct Kamp{
	int idMjesta;
	int rBr;
	int brDana;
	int brLjub;	
	int cjnPre;
	
};

bool postoji(Kamp polje[], int l, int id_kamp){
	for(int i=0; i<l; i++){
		if(polje[i].id == id_kamp) return true;
	}
	return false;
	}

void unos(Kamp polje[], int &l){
	cout<<"Uneseno je: "<<l<<" polja"<<endl;
	if(l>=70){
	cout<<"Unesen je maksimalan broj polja"<<endl;
	return;
	}
	cout<<"Upisi ID kampa"<<endl;
	int id_kampa;
	cin>>id_kampa;
	if(postoji (polje, l, int id_kamp)){
			cout<<"Kamp mjesto je zauzeto"<<endl;
			return;
	}
	polje[l].id=id_kampa;
		cout<<"Unesite broj korisnika"<<endl;
		cin>>polje[l].br_korisnika;
		cout<<"KUpisite broj dana"<<endl;
		cin>>polje[l].br_dana;
		cout<<"Broj lkjubimaca"<<endl;
		cin>>polje[l].br_ljubinaca;
		polje[l].prekrsaji=0;
		l++;
	}

	void info(Kamp kamp){
		cout<<" ID kampa: "<<kamp.id<<endl;
		cout<<" Broj korisnika: "<<kamp.br_korisnika<<endl;
		cout<<" Broj dana: "<<kamp.br_dana<<endl;
		cout<<" Broj ljubimaca: "<<kamp.br_ljubimaca<<endl;
		cout<<" Prekrsaji: "<<kamp.prekrsaji<<endl;		
	}
	
	void ispis(Kamp polje[], int l){
	cout<<"Upisi ID kampa"<<endl;
	int id_kampa;
	cin>>id_kampa;
	if(!postoji (polje, l, int id_kamp)){
			cout<<"Kamp mjesto je zauzeto"<<endl;
			return;
	}
	for(int i=0; i>l; i++ ){
		if(polje[i].id==id_kampa){
			info(polje[i]);
			
		int odabir;
		cout<<"cijena 200"<<endl;
		cout<<"cijena 400"<<endl;
		cout<<"cijena 100"<<endl;
		
		cin>>odabir;
		switch(odabir){
			case 1: polje[i].prekrsaji +=200;
				break;
			case 2: polje[i].prekrsaji +=400;
				break;
			case 3: polje[i].prekrsaji +=100;
				break;
		}
		return;		
		}
	}	
}
	
void izmjena(Kamp polje[], int &l){
	cout<<"Upisi ID kampa"<<endl;
	int id_kampa;
	cin>>id_kampa;
	if(!postoji (polje, l, int id_kamp)){
			cout<<"Kamp mjesto je zauzeto"<<endl;
			return;
	}
	for(int i=0; i>l; i++ ){
		if(polje[i].id==id_kampa){
			info(polje[i]);
		
		int suma = ()polje[i].br_korisnika*100+polje[i].br_kljubimaca*polje[i].br_dana+polje[i].prekrsaji;
		cout<<"Suma je " <<suma<<endl;
		polje[i].br_dana=0;
		polje[i].br_korisnika=0;
		polje[i].br_ljubimaca=0;
		polje[i].prekrsaji=0;
		polje[i] = polje[l-1];
		l--;		
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
  //file.close();
  dat.close();
}
	

int main(){
	
	int index_zadnjeg=0;
	Kamp polje[70];
	
	int opcija;
	
	cout<<"1. Unos parkirnog mjesta.\n";
	cout<<"2. Izmjena unesenog parkirnog mjesta.\n";
	cout<<"3. Naplata parkirnog mjesta/kampiranja.\n";
	cout<<"4. Ispis podataka o parkirnom mjestu.\n";
	cout<<"5. Unos podataka parkirnog mjesta u datoteku parkiranje.txt\n";
	cout<<"0. Izaz iz izbornika.\n";
	
	cout<<"Unesi opciju\n";
	cin>>opcija;
	
	do{
		switch(opcija){
				case 1:
				unos(polje,index_zadnjeg);		
		break;
				case 2:
				izmjena(polje,index_zadnjeg);
		break;
				case 3:
				naplata(polje,index_zadnjeg);
		break;
				case 4:
				izvjecse(polje,index_zadnjeg);
		break;
				case 5: 
				datoteka(polje,index_zadnjeg);
		break;
				default:
					cout<<"Trebas odabrati jednu od opcija!"<<endl;
		}
		
	}while (opcija!=0);
	
	system("pause");
	return 0,
}