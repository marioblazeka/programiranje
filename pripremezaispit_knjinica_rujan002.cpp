#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct posudbaKnjiga{
	int redBr;
	int sifraKnji;
	string imeKoris;
	int brojDanPos;
	float zakasnina;
};

posudbaKnjiga posudba[323];
int unos = 0;

void unosPodataka(){

		}

void ispravakPodataka(){
		}

void pregledPodataka(){
		}

void vracanjeIzakasnina(){
		}

void izvozPodataka(){
		}

void glavniIzbornik(){

int izbornik;
do{
	cout<<"-----I Z B O R N I K-----\n";
	cout<<"1. Unos podataka o posudbi\n";
	cout<<"2. Ispravak podataka o posudbi\n";
	cout<<"3. Pregled posuđenih knjiga\n";
	cout<<"4. Vraćanje knjige i Naplata zakasnine\n";
	cout<<"5. Izvoz podataka u datoteku\n";

	cout<<"0. Izlaz iz programa\n";

	cout<<"Odaberi izbor 1 do 5 ili 0 za izlaz iz programa\n";

	cin>>izbornik;
		if(izbor >0||izbor<6){
		cout<<"Unjeli ste "<<izbornik<<" za ulaz u izbornik\n";
		}else{
			cout<<"Unjeli ste 0 za izlaz iz programa\n";
			cout<<"*********************************\n";
			return;
			}
	switch(izbornik){
	case 1:unosPodataka(); break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 0: break;
	default:cout<<"Krivi unos\n";
	}		
}while(izbornik!=0);
return;
}

int main(){
	glavniIzbornik();

	system("pause");
	return 0;
	}

 
