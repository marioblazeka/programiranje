#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int MAX = 100;

struct Ocjena{
string ime;
string prezime;
string predmet;
float ocjena;	//int ocjena
};

int brojOcjena =0;
Ocjena evidencija[MAX];

void unosPodataka(){
	if (brojOcjena >=MAX){
		cout<<"Dosegnut maksimalan broj unosa.\n";
		return;
	}
	
	Ocjena nova;
	cout<<"Unesite ime: \n";
	getline(cin, nova.ime);
	cout<<"Unesite prezime: \n";
	getline(cin, nova.prezime);
	cout<<"Unesite predmet: \n";
	getline(cin, nova.predmet);
	
	do{
		cout<<"Unesite ocjenu (1-5): \n";
		cin>>nova.ocjena;
		if(nova.ocjena < 1 || nova.ocjena > 5);
		cout<<"Ocjena mora biti u rasponu od 1 do 5!\n";
	}while(nova.ocjena < 1 || nova.ocjena > 5);
	cin.ignore(); // čišćenje
	evidencija[brojOcjena++] = nova;
	cout<<"Ocjena je uspjesno upisana.\n";
}

void ispisPoPredmetu(){
	string trazeniPredmet;
	cout<<"Unesite naziv predmeta: \n";
	getline(cin, trazeniPredmet);
	int suma = 0, broj = 0;
	
	for (int i=0;i<brojOcjena;i++){
		if(evidencija[i].predmet ==trazeniPredmet){
			cout<<evidencija[i].ime<<" "<<evidencija[i].prezime<<" - Ocijena: "<<evidencija[i].ocjena<<"\n";
			suma += evidencija[i].ocjena;
			broj++;
		}
	}
	if (broj > 0)
	cout<<"Prosjek ocjena za predmet "<<trazeniPredmet<<"': "<<(float)suma/broj<<"\n";  //float ne treba jer je prije deklariran
	else
		cout<<"Nema ocjena za racunanje prosjeka. \n ";
}

void ispisPoUceniku(){
	string ime, prezime;
	cout<<"Unesi ime: ";
	getline(cin, ime);
	cout<<"Unesi prezime: ";
	getline(cin, prezime);
	int suma = 0, broj = 0;
		
	for(int i=0; i<brojOcjena;i++){
		if(evidencija[i].ime == ime && evidencija[i].prezime == prezime){
			cout<<evidencija[i].predmet << " - Ocjena: " <<evidencija[i].ocjena<<"\n";
			suma += evidencija[i].ocjena;
			broj++;
		}
	}
	if (broj>0)
	cout<<"Prosjek ocjena za učenika"<< ime <<" "<< prezime << " : " << (float)suma/broj<< "\n";  // ne treba float
 	else
	cout<<"Nema zapisa za unesenog ucenika!\n";
}

void ispravakOcjene(){
	string ime, prezime, predmet;
	cout<<"Unesite ime: \n";
	getline(cin, ime);
	cout<<"Unesite prezime: \n";
	getline(cin, prezime);
	cout<<"Unesite predmet: \n";
	getline(cin, predmet);
	
	for(int i=0; i<brojOcjena; i++){
		cout<<"Trenutna ocjena: "<< evidencija[i].ocjena<<"\n";
		int nova;
		do{
			cout<<"Unesite ocjenu od 1 do 5: \n";
			cin>>nova;
		}while(nova<1||nova>5);
		evidencija[i].ocjena = nova;
		cout<<"Ocjena je ispravljena!\n";
		cin.ignore();
		return;
	}
	cout<<"Zapis nije pronadjen!!!\n";
}


void brisanjeOcjene(){
	string ime, prezime, predmet;
	cout<<"Unesite ime: ";
	getline(cin, ime);
	cout<<"Unesite prezime: ";
	getline(cin, prezime);

bool nadjen = false;
	
	// cout<<"ocjena za ucenika "<<ime<<prezime<<; // provjeriti što se dobije  s tim
	cout<<"Ocjena za ucenika: \n";
	for(int i=0;i<brojOcjena;i++){
		if(evidencija[i].ime == ime && evidencija[i].prezime == prezime ){
			cout<<evidencija[i].predmet<<"  "<<evidencija[i].ocjena<<"\n";
			nadjen=true;
		}
		if(!nadjen){
			cout<<"Ucenika nema u evidenciji!!! ";
			return;
		}
		cout<<"Unesite predmet za koji zelite izbrisati ocjenu: ";
		getline(cin, predmet);
		
		for(int i=0;i>brojOcjena;i++){
			if(evidencija[i].ime==ime&&evidencija[i].prezime==prezime&&evidencija[i].predmet==predmet)
			for(int j=0;j<brojOcjena-1;j++){
				evidencija[j]=evidencija[j+1];
			}
			brojOcjena--;
			cout<<"Ocjena je izbrisana!!! \n";
			return;
		}
	}
	cout<<"Zapis nije pronadjen! \n";
}

void citanjeIzDatoteke(){
	ifstream dat("ocjene.txt");
	if(!dat){
		cout<<"Datoteka se ne moze otvoriti \n";
		return;
	}
	string linija;
	while(getline(dat, linija)){
		if(brojOcjena>=MAX) break;
		        size_t p1 = linija.find(" | ");
        size_t p2 = linija.find(" | ", p1 + 3);
        size_t p3 = linija.find(" | ", p2 + 3);

        if (p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;

        evidencija[brojOcjena].ime = linija.substr(0, p1);
        evidencija[brojOcjena].prezime = linija.substr(p1 + 3, p2 - p1 - 3);
        evidencija[brojOcjena].predmet = linija.substr(p2 + 3, p3 - p2 - 3);
        evidencija[brojOcjena].ocjena = stoi(linija.substr(p3 + 3));

        brojOcjena++;
    }
    cout << "Podaci su učitani iz datoteke.\n";
}
		

void Izbornik(){
		int izbor;
	
		do {
		cout<<"\n---   I Z B O R N I K ---\n";
		cout<<"\n0. Izlaz\n";
		cout<<"\n1. Unos podataka\n";
		cout<<"\n2. Ispis podataka\n";
		cout<<"\n3. Ispravak podataka\n";
		cout<<"\n4. Brisanje podataka\n";
		cout<<"\n5. Citanje iz datoteke\n";
		cout<<"\n Unesite izbor: \n";
		cin>>izbor;
		cin.ignore();  //čišćenje buffera
		
		switch(izbor){
				case 1: unosPodataka();
					break;
				case 2:{
					int podizbor;
					cout<<"1. Ispis po predmetima\n 2. Ispis po ocjenama\n Izbor: ";
					cin>>podizbor;
					cin.ignore(); //čišćenje buffera
					
					if (podizbor == 1) ispisPoPredmetu();
					else if (podizbor == 2) ispisPoUceniku();
					else cout<<"nevazeci izbor.\n";
					break;
				}
				case 3: ispravakOcjene();
					break;
				case 4: brisanjeOcjene();
					break;
				case 5: citanjeIzDatoteke();
					break;	
				case 0: cout <<"Izlaz iz programa.\n";
					break;
				default: cout <<"Nevazeci izbor!!!\n";
		}
	}while (izbor != 0);
}


int main(){

	Izbornik();
	
	system ("pause");
	return 0;
}