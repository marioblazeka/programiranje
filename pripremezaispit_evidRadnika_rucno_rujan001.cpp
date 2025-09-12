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
int unos;
int brRadknji;

void unosRadnika(){
	if(unos>100){
		cout<<"Polje je popunjeno!\n";
	}else{
		cout<<"Do sada je uneseno "<< unos <<" radnika u evidenciju.\n";
	
	cout<<"Unesite ime i prezime radnika\n";
	cin>>evidencija[unos].imeIprezime;
		cout<<"Unesite broj radne knjizice radnika\n";
		cin>>evidencija[unos].brRadknji;
			cout<<"Unesite datum rodjenja radnika\n";
			cin>>evidencija[unos].datRodj;
				cout<<"Unesite placu radnika\n";
				cin>>evidencija[unos].palca;
					cout<<"Unesite odjel radnika\n";
					cin>>evidencija[unos].odjel;
		unos++;
		return;
		}
	}

void izmjenaPodataka(){
		cout<<"Upisi broj radne knjizice za izmjenu podataka: \n";
			int trazi;
		cin>>trazi;
		if(trazi==evidencija[unos].brRadknji){
			for(int i=0; i<unos;i++){
			cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<
			"Datum rodjenja: "<<evidencija[i].datRodj<<
			"Iznos place: "<<evidencija[i].palca<<
			"Radni odjel: "<<evidencija[i].odjel<<endl;
			
			cout<<"Unesite novo ime i prezime radnika\n";
			cin>>evidencija[unos].imeIprezime;
				cout<<"Unesite novi broj radne knjizice radnika\n";
				cin>>evidencija[unos].brRadknji;
					cout<<"Unesite datum rodjenja novog radnika\n";
					cin>>evidencija[unos].datRodj;
						cout<<"Unesite placu novog radnika\n";
						cin>>evidencija[unos].palca;
							cout<<"Unesite odjel novog radnika\n";
							cin>>evidencija[unos].odjel;
							return;				
				}
		}else{
			cout<<"Radnik s navedenim brojem radne knjižice ne postoji\n";
			return;
		}
}

void ispisPodataka(){
	cout<<"Ispis svih "<<unos<<" upisanih radnika: \n";
				for(int i=0; i<unos;i++){
			cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<
			"Datum rodjenja: "<<evidencija[i].datRodj<<
			"Iznos place: "<<evidencija[i].palca<<
			"Radni odjel: "<<evidencija[i].odjel<<endl;
			}
		}

void pretragaEvidencije(){
	cout<<"Upisi godinu rodjenja radnika za pretragu svih "<<unos<<" unesenih radnika: \n";
	string godina;
	cin>>godina;
	float placa;
	float star;
	if(godina==evidencija[unos].datRodj){
		for(int i=0;i<unos;i++){
			cout<<"Ime i prezime: "<<evidencija[i].imeIprezime<<
			"Datum rodjenja: "<<evidencija[i].datRodj<<
			"Iznos place: "<<evidencija[i].palca<<
			"Radni odjel: "<<evidencija[i].odjel<<endl;
	float prosjekP=evidencija[i].palca/unos;
//	float prosjekS=godina/unos;
		}
	}else{
		cout<<"Ne postoji niti jedan radnik s navedenom godinom roðenja\n";
	}
}

void spremanjeUdatoteku(){
	ofstream datoteka("evidRad.txt");
	if(!datoteka){
		cout<<"Greska u otvaranju datoteke\n";
	}
	datoteka<<"Broj radnika "<<unos<<endl;
	for(int i=0;i<unos;i++){
	datoteka<<"Ime i prezime: "<<evidencija[i].imeIprezime<<
			" Datum rodjenja: "<<evidencija[i].datRodj<<
			" Iznos place: "<<evidencija[i].palca<<
			" Radni odjel: "<<evidencija[i].odjel<<endl;
		
			datoteka.close();
}
}

void glavniIzbornik(){
	int izbor;
	
	do{
		cout<<"-----I Z B O R N I K -----\n";

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
		default: cout<<"Krivi odabir!\n";
		}
	}while(izbor!=0);
}

int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}
