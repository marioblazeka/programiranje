#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct kampEvid{
	int IDbroj;
	int brojKoris;
	int brojDana;
	int brojLjubim;
	int cijenaPrekr;
};

kampEvid evidencija[70]; 
int unos = 0;

bool nePostoji = true;

void unosNovZap(){
	if (unos<1){
		cout<<"Jos nema unosa\n";
		}else{
		cout<<"Do sad je upisano "<<unos<<" evidencija \n";
}
	if(unos>70){
		cout<<"Kamp je popunjen\n";
		}else{
		cout<<"Do sad je upisano "<<unos<<" evidencija \n";
		}
	cout<<"Upisite ID kamp mjesta\n";
	//int trazeniBroj;	
	//	cin.ignore();
		cin>> evidencija[unos].IDbroj;
		
		if(!nePostoji){
			cout<<"Trazeno kamp mjesto ne postoji!\n";
		}
		
for(int i=0;i<unos;i++){
	if(unos==evidencija[unos].IDbroj){
		cout<<"Mjesto je zauzeto\n";
		return;
	}else{
		cout<<"Upisano je ID kamp mjesta\n";
	}
}
cout<<"Upisite broj korisnika\n";
		cin>> evidencija[unos].brojKoris;

cout<<"Upisite broj dana\n";
		cin>> evidencija[unos].brojDana;
cout<<"Upisite broj ljubimaca\n";
		cin>> evidencija[unos].brojLjubim;
		
		unos++;
		
		return;
	}

void cijenePrekrsaja(){
	int ljubimci=0;
	int smece =0;
	int granica =0;
	int trosak=0;
	
cout<<"1 ljubimci \n";
cin>>ljubimci;
ljubimci ++;

trosak=ljubimci+smece+granica;

cout<<"Ukupni trosak iznosi: "<<trosak<<" eura \n";
	
}

void IzmjenaZapisa(){
cout<<"Upisi trazeni ID kamp mjesta \n";

int trazeniID;
cin>> trazeniID;
for(int i=0;i<unos;i++){
if (trazeniID == evidencija[i].IDbroj){
	cout<<"Trazeni zapis je pronadjen \n";
	cout<< evidencija[unos].IDbroj<< evidencija[unos].brojKoris<< evidencija[unos].brojDana<<evidencija[unos].brojLjubim<<endl;
}else{
	cout<<"Nema unosa pod tim brojem \n";
	return;
}

int cijena;

do{

int izaberi;

cout<<"Cijene prekrsaja: \n";
cout<<"1\n";
cout<<"2\n";
cout<<"3\n";

cin>>izaberi;

switch(izaberi){
	case 1: cijenePrekrsaja(); break;
	
	default:
		cout<<"Krivi unos\n";
}
}while(cijena!=0);
return;
//	cijenaPrekr;
}
}

void pregledUpisa(){
cout<<"Do sada imamo sveukupno "<<unos<< " evidencija.\n";	
}

void naplataKampiranja(){
	if(nePostoji=1){
		cout<<"Trazeno mjesto ne postoji\n";
	//	return;
	}else
	int dnevnaCijena = 0;
	int dnevnoLjubim = 0;
	int suma=unos * 100 + unos * 15;
	suma++;
	
	cout<<	evidencija[unos].IDbroj<<evidencija[unos].brojDana<<evidencija[unos].brojKoris<<evidencija[unos].brojLjubim<<evidencija[unos].cijenaPrekr<<endl;
cout<<suma<<endl;

}

void spremanjeUdat(){
if(unos=0){
	cout<<"nema podataka o unosu za spremanje";
	return;
}else{
	cout<<"Podaci: "<<evidencija[unos].IDbroj<<evidencija[unos].brojDana<<evidencija[unos].brojKoris<<evidencija[unos].brojLjubim<<evidencija[unos].cijenaPrekr<<" su spremljeni u vanjsku datoteku kamp.txt"<<endl;
	}
	ofstream datoteka("kamp.txt");
		if(!datoteka){
			cout<<"greska\n";
			return;
		}
	datoteka.close();
	
}

void glavniIzbornik(){
	
	int izbor;
	
	do{
		cout<<"------IZBORNIK-----\n";
		cout<<"1. Unos novog zapisa u evidenciju\n";
		cout<<"2. Izmjena zapisa iz evidencije\n";
		cout<<"3. Cijene prekrsaja iz evidencije\n";
		cout<<"4. Naplata kampiranja\n";
		cout<<"5. Pregled svih zapisa u evidenciju\n";
		cout<<"6. Spremanje u datoteku kamp.txt\n";
		cout<<"0. izlaz iz programa\n";
		
		cout<<"Izbor: \n";
		cin>> izbor;
		
		switch(izbor){
			case 1:	unosNovZap(); break;
			case 2: IzmjenaZapisa(); break;
			case 3: cijenePrekrsaja(); break;
			case 4: naplataKampiranja(); break;
			case 5: pregledUpisa(); break;
			case 6: spremanjeUdat(); break;
			case 0:  break;
			
			default: 
			cout<<"Pogresan unos\n";
		}
						if(izbor >0 || izbor <6){
		cout<<"Odabrali ste opciju za ulazak u izbornik "<<izbor<<" ulazim u program\n";
		
	if(izbor == 0){
		cout<<"Odabrali ste opciju 0, izlazim iz programa\n";
			}
//	return;
	}


	}while( izbor!=0);
}


int main(){
	
	glavniIzbornik();
	
	system("pause");
	return 0;
	
}
