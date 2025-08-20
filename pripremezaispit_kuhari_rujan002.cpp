#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct kulinarNatje{
	int sifraNatje;
	int oibNatje;
	string imeiPrez;
	int osvoBod;
	bool IIkrug;
};

kulinarNatje kulinar[50];
bool IIkrug=false;
int unos = 0;

void prijavaNovog(){
	int sifraNatje=unos;
	int osvoBod=0;
	cout<<"Koliko je natjecatelja do sada prijavljeno? "<<unos<< " je odgovor! \n";
	if(unos>=50){
		cout<<"Prijavljen je maksimalan broj sudionika \n";
		return;
	}
	unos++;
	cout<<"Unesi Oib\n";
	cin>>kulinar[unos].oibNatje;
	if(kulinar[unos].oibNatje<00000000001||kulinar[unos].oibNatje>99999999999){
		cout<<"Oib mora imati 11 znamenki!";
		return;
	}else{
		cout<<"unesli ste dobar format oib-a \n";
	}
	cin.ignore();
	cout<<"Unesi Ime i prezime\n";
	getline(cin, kulinar[unos].imeiPrez);
		return;	
}

void upisBodova(){
	
}

void izracunBodova(){
	
}

void ispisPodataka(){
	if(unos !=0){
		cout<<"Do sada je upisano " <<unos<<" natjecatelja \n";
	}else
	cout<<"Nema natjecatelja za ispis!!! \n";
	
int izbor;

do{
	cout<<"*****IZBORNIK***** \n";
	cout<<"1. Ispis podataka svih natjecatelja \n";
		for(int i=0;i<unos;i++){
	cout<<kulinar[i].sifraNatje<<"| \t"<<kulinar[i].oibNatje<<"| t"<<kulinar[i].imeiPrez<<"| \t"<<kulinar[i].osvoBod<<"| \t"<<kulinar[i].IIkrug<<endl;
	}
	cout<<"2. Ispis podataka natjecatelja koji su ušli u 2. krug natjecanja \n";
		for(int i=0;i<unos;i++){
	cout<<kulinar[i].sifraNatje<<"| \t"<<kulinar[i].oibNatje<<"| t"<<kulinar[i].imeiPrez<<"| \t"<<kulinar[i].osvoBod<<"| \t"<<kulinar[i].IIkrug<<endl;
	}
	cout<<"0. Izlaz iz izbirnika \n";

cin>>izbor;

switch(izbor){
	case 1: break;
	case 2: break;
	
	default: cout<<"Izlaz!!! \n";
}	
}while(izbor!=0);
}

void izvozuDat(){
	if(unos!=0){
	cout<<"Do sada je upisano "<<unos<<" podataka o batjeceteljima \n";
}
	ofstream datoteka("izvozPodataka.txt");
		for(int i=0;i<unos;i++){
			if(unos>=1)
	cout<<"šifra\t OIB\t ime i prezime\t bodovi\t ulazak u drugi krug natjecanja"<<endl;
	cout<<kulinar[i].sifraNatje<<"\t"<<kulinar[i].oibNatje<<"\t"<<kulinar[i].imeiPrez<<"\t"<<kulinar[i].osvoBod<<"\t"<<kulinar[i].IIkrug<<endl;
	}
}

void glavniIzbornik(){
	int izbor;
	
	do{
		cout<<"-----IZBORNIK----- \n";
		cout<<"1. Prijava natjecatelja \n";
		cout<<"2. Upis bodova / izmjena podataka o natjecatelju \n";
		cout<<"3. Izraèun/odabir za ulazak u 2. krug natjecanja \n";
		cout<<"4. Ispis podataka o natjecateljima \n";
		cout<<"5. Izvoz podataka u datoteku \n";
		cout<<"0. Izlaz iz programa \n";
		cin>>izbor;
		
		switch(izbor){
			case 1: prijavaNovog(); break;
			case 2: upisBodova(); break;
			case 3: izracunBodova(); break;
			case 4: ispisPodataka(); break;
			case 5: izvozuDat(); break;
			case 0: break;
			
			default:cout<<"Odaberite opcije 1 do 5 ili 0 za izlaz \n"; 
			}
		if(izbor > 0 || izbor < 6){
				cout<<"Odabrali ste opciju: "<<izbor<<" za ulaz u izbornik \n";
			}else if(izbor ==0){
				cout<<"Odabrali ste opciju: "<<izbor<<" za izlaz iz programa \n";
			}else{
				cout<<"Krivi unos!!! \n";
			return;
			}
			
	}while(izbor!=0);
	
}

int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}
