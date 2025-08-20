#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct prodajaUlaz{
	int brojUlaz;
	int brojSjeda;
	bool rezervacija;
	float cijena;
	string oib;	//ogranici unos na 11 znamenki
};

prodajaUlaz ulaznice[150];
int unos = 0;
int sjeda = 0;
bool rezervacija=false;

struct vrstaSjedala{
	int parter;
	float parterC;
	int terasa;
	float terasaC;
	int loza;
	float lozaC;
};

vrstaSjedala vrsta;
int parter[100];
int terasa[40];
int loza[10];


int brojUlaz=unos;
int brojSjeda=sjeda;


void prodajaUlaznica(){
	if(unos>150){
		cout<<"Predstava je rasprodana!\n";
		return;
	}
	cout<<"Unesi OiB kupca: \n";
	cin>>ulaznice[unos].oib;
	
	//	unos++;
	cout<<"Upisi vrstu ulaznice\n";
	
	cout<<"Ulaznice po vrsti su 1.parter, 2.terasa, 3.loza\n";
	
	int izbor;
	
	cin>>izbor;
	
	int parter=0;
	int terasa=0;
	int loza=0;
	sjeda=parter+terasa+loza;
	
	if(izbor==1){
		cout<<"Odabrana je ulaznica za parter\n";
		if(parter>100){
			cout<<"Nema vise ulaznica za parter\n";
		}
		parter++;
		return;
	}
			if(izbor==2){
				cout<<"Odabrana je ulaznica za terasu\n";
					if(terasa>40){
			cout<<"Nema vise ulaznica za terasu\n";
				terasa++;
						return;
			}
					if(izbor==3){
						cout<<"Odabrana je ulaznica za lozu\n";
							if(loza>10){
			cout<<"Nema vise ulaznica za lozu\n";
						 loza++;
						 		return;
}
}
	cout<<"Parter – 15 €, 100 ulaznica (sjedala 1-100)\nTerasa – 17.50 €, 40 ulaznica (sjedala 101-140)\nVIP loza – 20 €, 10 ulaznica (sjedala 141-150)\n";
	cout<<"Racun broj "<<unos<<" ulaznica broj "<<brojUlaz<<" sjedalo broj "<<sjeda<<endl;
	return;
}
}


void rezervacijaUlaznica(){
	cout<<"Upisi broj ulaznice za rezervaciju: \n";
	cout<<"1,2,ili 3\n";

	int izbor;
	cin>>izbor;
	if(izbor==1){
		cout<<"Odabralli ste ulaznicu "<<parter<<" za parter\n";
	}
		if(izbor==2){
		cout<<"Odabralli ste ulaznicu "<<terasa<<" za terasu\n";
	}
		if(izbor==3){
		cout<<"Odabralli ste ulaznicu "<<loza<<" za lozu\n";
	}
	bool trazeni=false;
	
	//if(vrsta[sjeda].parter==parter||vrsta[sjeda].terasa==terasa||vrsta[sjeda].loza==loza){
	//	cout<<"Ulaznica za doticno sjedalo je prodana, izmjena nije moguca! \n";
	//}else{
	//	cout<<"Izmjena rezervacije realizirana! \n";
	}
	//	return;


void prodRezUlaznica(){

//Rezervacija ne postoji za sjedalo xxx!

//Prodana je ulaznica xxx sa sjedalom xxx.
}

void ispisPodataka(){
	if(unos==0){
		cout<<"Nema podataka za unos\n";
	}
	float suma =0;
	float postotak=0;
	int postotakP=0;
		int postotakT=0;
			int postotakL=0;
	suma = (vrsta.parter*15)+(vrsta.terasa*17.5)+(vrsta.loza*20);
	postotakP =100/vrsta.parter;
	postotakT =40/vrsta.terasa;
	postotakL =10/vrsta.loza;
	cout<<"Do sada je prodano " <<unos<<parter<<terasa<<loza<<endl;
	cout<<"Inkasirano je "<<suma<<endl;
		cout<<"Postotak je "<<postotak<<endl;
//Kolicina prodanih karata:
//Ukupno inkasirana sredstva:
//Postotak rasprodanog Partera, Terase i VIP loze
}
void izvozPodataka(){
if(unos>0){
	cout<<"Do sada je uneseno " <<unos<<endl;
	}
	ofstream datoteka("kazaliste.txt");
	if(!datoteka){
		cout<<"Greska u spremanju\n";
	}else{
		cout<<"	Izvoz podataka u datoteku realiziran! \n";
	}
	for(int i=0;i<unos;i++){
		datoteka<<"do sada je prodano";
		datoteka<<ulaznice[i].brojUlaz<<endl;
	}
		datoteka.close();
	return;
}
	
void glavniIzbornik(){
	
	int izbor;
	
	do{
		cout<<"-----Izbornik-----\n";
		cout<<"1. Prodaja ulaznica\n";
		cout<<"2. Rezervacija ulaznice\n";
		cout<<"3. Prodaja rezervirane ulaznice\n";
		cout<<"4. Ispis podataka o prodanim ulaznicama\n";
		cout<<"5. Izvoz podataka u datoteku\n";
		
		cout<<"0. Izlaz iz programa\n";
		cin>>izbor;
	
	switch(izbor){
		case 1: prodajaUlaznica(); break;
		case 2: rezervacijaUlaznica(); break;
		case 3: prodRezUlaznica(); break;
		case 4: ispisPodataka(); break;
		case 5: izvozPodataka(); break;
		
		default: cout<<"Krivi unos\n";
	}
	}while(izbor!=0);
	
}

int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}
