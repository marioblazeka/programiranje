#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct evidencijaRadnika{
	string imePrez;
	int brojRk;
	string datumRod;
	float placa;
	string odjel;
};

evidencijaRadnika evidencija[100];
int brojUnosa = 0;

void unosPodataka(){
	cout<<"Do sada je uneseno "<<brojUnosa<< " radnika \n";
	if (brojUnosa > 100){
		cout<<"Dosegnut je maksimalni broj unosa evidencije radnika od 100 radnika. Polje je popunjeno! \n";
		return;
	}else{
		cout<<"Unesite slijedeće podatke: \n";
	}
	cin.ignore();
	
	cout<<"Unesite ime i prezime: \n";
	getline(cin, evidencija[brojUnosa].imePrez);
	
	cout<<"Unesite broj radne knjizice: \n";
	cin>>evidencija[brojUnosa].brojRk;
	
	cin.ignore();
	cout<<"Unesite datum rodjenja (u formatu dd-mm-gggg): \n";
	getline(cin, evidencija[brojUnosa].datumRod);
		if(evidencija[brojUnosa].datumRod.length()!=10||
		evidencija[brojUnosa].datumRod[2]!='-'||
		evidencija[brojUnosa].datumRod[5]!='-'){
		cout<<"Unjeli ste krivi format datuma! \n";
		return;
			}else{
			cout<<"Upisali ste datum! \n";
	}
	
	cout<<"Unesite iznos place: \n";
	cin>>evidencija[brojUnosa].placa;
	
	cout<<"Unesite naziv odjela: \n";
	cin>> evidencija[brojUnosa].odjel;
	
	brojUnosa ++;
	
	return;
}

void izmjenaPodataka(){
	if(brojUnosa==0){
		cout<<"Nema podataka za izmjenu! \n";
		return;
}
		cout<<"Unesi podatke za izmjenu. Broj radne knjizice je: \n";
	int trazenaRk;
	
	cin>> trazenaRk;
	
	bool pronadjen=false;
	
	for(int i =0; i<brojUnosa; i++){
		if(evidencija[i].brojRk == trazenaRk){
			pronadjen = true;
			cout<<"Radna knjizica je pronadjena! \n"<<trazenaRk<< "\t"<<"|"<<evidencija[i].imePrez<<"\t"<<"|"<<evidencija[i].datumRod<<"\t"<<"|"<<evidencija[i].placa<<"\t"<<"|"<<evidencija[i].odjel<<"\t"<<"|"<<endl;	
		}else{
			cout<<"Nema radne knjizice pod tim brojem \n";
			return;
		}
		
	cin.ignore(); // očisti buffer
	
	cout<<"Stara radna knjizica broj: "<<trazenaRk<<" je pronadjena. Izmjeni podatke\n";
	
	cout<<"Unesi novo ime i prezime\n";
	cin>>evidencija[i].imePrez;	
	
	cin.ignore(); // očisti buffer
	
		cout<<"Unesi novi datum rodjenja\n";
	cin>>evidencija[i].datumRod;	
	
	cin.ignore(); // očisti buffer
	
		cout<<"Unesi novu palcu\n";
	cin>>evidencija[i].placa;	
	
	cin.ignore(); // očisti buffer
	
		cout<<"Unesi novi odjel\n";
	cin>>evidencija[i].odjel;	
return;
	}
}
void pregledPodataka(){
	if(brojUnosa<100){
	cout<<" Do sada je upisano: "<<brojUnosa<< " evidencija. \n";
	for(int i=0;i<brojUnosa;i++){
		if(evidencija[i].brojRk >0){
	cout<<"Radna knjizica je pronadjena! \n";
	cout<<evidencija[i].brojRk<< "\t"<<"|"<<evidencija[i].imePrez<<"\t"<<"|"<<evidencija[i].datumRod<<"\t"<<"|"<<evidencija[i].placa<<"\t"<<"|"<<evidencija[i].odjel<<"\t"<<"|"<<endl;	
}else{
	cout<<"Upisan je maksimalni broj evidencija! \n";
}
}
}
}

void pretragaPoGodRod(){
	if(brojUnosa <1){
		cout<<"Nema podataka za pretrazivanje. \n";
		return;
	}
	
	cout<<"Do sada je u evidenciji "<<brojUnosa<<" upisanih radnika. \n";
	cout<<"Upisi godinu rodjenja za pretragu \n";
	
	string trazenaGod;
		cin>>trazenaGod;
	
	bool pronadjen = false;
	
	for(int i=0;i<brojUnosa;i++){
		if(evidencija[i].datumRod.length() >=10){
		
	string godRod = evidencija[i].datumRod.substr(6, 4);
	for(int i=0;i<brojUnosa;i++){
		cout<<"Samo godine rodjenja "<<godRod<<endl;
	}
	

	
	for(int i=0;i<brojUnosa;i++){
		if(trazenaGod==evidencija[i].datumRod){
			pronadjen=true;
			cout<<"Pronadjen je radnik sa godinom rodjenja "<<trazenaGod<<endl;
	}else{
		cout<<"Nema radnika rodjenog "<<trazenaGod<<endl;
		
	}
	
}
}
}
}

void izbornik(){
	
	int izbornik;
	
	do{
	cout<<"-----IZBORNIK----- \n";
	cout<<"0. Izlaz iz programa! \n";
	cout<<"1. Unos podataka o evidenciji radnika \n";
	cout<<"2. Izmjena podataka o evidenciji radnika \n";
	cout<<"3. Pregled upisanih podataka o evidencijama rdnika. \n";
	cout<<"4. Pretraga po godini rodjenja radnika. \n";
	
	cin>>izbornik;
	
	switch(izbornik){
		case 1: unosPodataka();	break;
		case 2: izmjenaPodataka(); break;
		case 3: pregledPodataka(); break;
		case 4: pretragaPoGodRod(); break;
		
		default: cout<<"Unjeli ste krivi izbor! \n";
		}
	}while (izbornik !=0);
}

int main(){
	izbornik();
	
	system("pause");
	return 0;
}
