#include <iostream>
//#include <struct>
#include <fstream>

using namespace std;

/*Izradite program namijenjen vođenju evidencije zauzetih kamp mjesta u kampu kapaciteta 70 kamp mjesta. 
U programu voditelj kampa unosi sljedeće podatke o korisnicima koji zauzimaju određeno mjesto u kampu.*/

struct kamp{
	int idMjesta;
	int rBr;
	int brDana;
	int brLjub;	
	int cjnPre;
	
};

bool postoji(Kamp polje[], int l, int id_kamp){
	for(int i=0; i<l; i++){
		if(polje[i].id ==id_kamp) return true;
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
	
	void ispis(Kamp polje[], int l){
	cout<<"Upisi ID kampa"<<endl;
	int id_kampa;
	cin>>id_kampa;
	if(postoji (polje, l, int id_kamp)){
			cout<<"Kamp mjesto je zauzeto"<<endl;
			return;
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