#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct evidRadnika{
	string imeIprezime;
	int brRadknji;
	string datRodj;
	float palca;
	string odjel;
};

evidRadnika evidencija[100];
int unos = 0; // <-- inicijalizacija, jer se koristi kao brojaè
int brRadknji;

void unosRadnika(){
	if(unos >= 100){ // <-- ispravka uvjeta
		cout<<"Polje je popunjeno!\n";
	}else{
		cout<<"Do sada je uneseno "<< unos <<" radnika u evidenciju.\n";
	
		cout<<"Unesite ime i prezime radnika\n";
		cin.ignore(); // <-- da bi ime i prezime moglo sadržavati razmak
		getline(cin, evidencija[unos].imeIprezime);

		cout<<"Unesite broj radne knjizice radnika\n";
		cin>>evidencija[unos].brRadknji;

		cout<<"Unesite datum rodjenja radnika (dd.mm.gggg)\n";
		cin>>evidencija[unos].datRodj;

		cout<<"Unesite placu radnika\n";
		cin>>evidencija[unos].palca;

		cout<<"Unesite odjel radnika\n";
		cin>>evidencija[unos].odjel;

		unos++;
	}
}

void izmjenaPodataka(){
	cout<<"Upisi broj radne knjizice za izmjenu podataka: \n";
	int trazi;
	cin>>trazi;

	// <-- pretraga po cijelom polju, ne samo zadnjem unesenom
	bool postoji = false;
	for(int i=0;i<unos;i++){
		if(evidencija[i].brRadknji == trazi){
			postoji = true;

			cout<<"Trenutni podaci:\n";
			cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<" | "
				<<"Datum rodjenja: "<<evidencija[i].datRodj<<" | "
				<<"Iznos place: "<<evidencija[i].palca<<" | "
				<<"Radni odjel: "<<evidencija[i].odjel<<endl;

			cout<<"Unesite novo ime i prezime radnika\n";
			cin.ignore();
			getline(cin, evidencija[i].imeIprezime);

			cout<<"Unesite novi broj radne knjizice radnika\n";
			cin>>evidencija[i].brRadknji;

			cout<<"Unesite novi datum rodjenja radnika\n";
			cin>>evidencija[i].datRodj;

			cout<<"Unesite novu placu radnika\n";
			cin>>evidencija[i].palca;

			cout<<"Unesite novi odjel radnika\n";
			cin>>evidencija[i].odjel;

			break;
		}
	}

	if(!postoji){
		cout<<"Radnik s navedenim brojem radne knjižice ne postoji\n";
	}
}

void ispisPodataka(){
	cout<<"Ispis svih "<<unos<<" upisanih radnika: \n";
	for(int i=0; i<unos;i++){
		cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<" | "
			<<"Datum rodjenja: "<<evidencija[i].datRodj<<" | "
			<<"Iznos place: "<<evidencija[i].palca<<" | "
			<<"Radni odjel: "<<evidencija[i].odjel<<endl;
	}
}

void pretragaEvidencije(){
	cout<<"Upisi godinu rodjenja radnika za pretragu: \n";
	string godina;
	cin>>godina;

	bool pronadjen = false;
	float sumaPlaca = 0;
	int brojPronadjenih = 0;

	for(int i=0;i<unos;i++){
		// <-- izdvajamo zadnje 4 znamenke iz datuma rodjenja
		if(evidencija[i].datRodj.size() >= 4){
			string godinaRodj = evidencija[i].datRodj.substr(evidencija[i].datRodj.size()-4);
			if(godinaRodj == godina){
				pronadjen = true;
				cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<" | "
					<<"Datum rodjenja: "<<evidencija[i].datRodj<<" | "
					<<"Iznos place: "<<evidencija[i].palca<<" | "
					<<"Radni odjel: "<<evidencija[i].odjel<<endl;

				sumaPlaca += evidencija[i].palca;
				brojPronadjenih++;
			}
		}
	}

	if(!pronadjen){
		cout<<"Ne postoji niti jedan radnik s navedenom godinom roðenja\n";
	}else{
		cout<<"Prosjecna placa radnika roðenih "<<godina<<" je: "<<sumaPlaca/brojPronadjenih<<endl;

		// <-- prosjeèna starost: 2025 - godina
		int g = stoi(godina);
		cout<<"Prosjecna starost radnika roðenih "<<godina<<" je: "<<2025-g<<endl;
	}
}

void spremanjeUdatoteku(){
	ofstream datoteka("podaci.txt"); // <-- prema zadatku "podaci.txt"
	if(!datoteka){
		cout<<"Greska u otvaranju datoteke\n";
		return;
	}
	datoteka<<unos<<endl; // <-- prvi red samo broj radnika
	for(int i=0;i<unos;i++){
		// <-- sve u jednom redu odvojeno razmakom
		datoteka<<evidencija[i].imeIprezime<<" "
				<<evidencija[i].brRadknji<<" "
				<<evidencija[i].datRodj<<" "
				<<evidencija[i].palca<<" "
				<<evidencija[i].odjel<<endl;
	}
	datoteka.close();
}

void glavniIzbornik(){
	int izbor;
	
	do{
		cout<<"\n----- I Z B O R N I K -----\n";
		cout<<"1. Unos novog radnika\n";
		cout<<"2. Izmjena podataka o radniku\n";
		cout<<"3. Ispis svih radnika\n";
		cout<<"4. Pretraga radnika po godini roðenja\n";
		cout<<"5. Spremanje podataka u datoteku\n";
		cout<<"0. Izlaz iz programa\n";
		
		cin>>izbor;
		
		switch(izbor){
			case 1: unosRadnika(); break;
			case 2: izmjenaPodataka(); break;
			case 3: ispisPodataka(); break;
			case 4: pretragaEvidencije(); break;
			case 5: spremanjeUdatoteku(); break;
			case 0: cout<<"Izlaz...\n"; break;
			default: cout<<"Krivi odabir!\n";
		}
	}while(izbor!=0);
}

int main(){
	glavniIzbornik();
	return 0;
}

