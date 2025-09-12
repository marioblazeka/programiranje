#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct vrijemeUcenja{
		string danUcenja;
		int brSati;
		int ocjena;
};

vrijemeUcenja vrijeme[10];
int unos=0;

void unosPodataka(){
	cout<<"Do sada je uneseno "<<unos<<" dana ucenja studenta\n";
		cout<<""<<endl;
	cout<<"Unesite dan ucenja: \n";

	cin>>vrijeme[unos].danUcenja;
	
		cout<<"Unesi broj sati u rasponu od 0 do 24. \n";
		cin>>vrijeme[unos].brSati;
			if(vrijeme[unos].brSati<0||vrijeme[unos].brSati>24){
			cout<<"Unesen je krivi raspon!";
			}else{
			
					cout<<""<<endl;
				cout<<"Unesi broj sati u rasponu od 0 do 24. \n";
				cin>>vrijeme[unos].brSati;
		}
	
				cout<<"Unesi ocjenu - osobna evaluacija efikasnost uèenja\n";
				cin>>vrijeme[unos].ocjena;
					if(vrijeme[unos].ocjena<0||vrijeme[unos].ocjena>5){
					cout<<"Unesen je krivi raspon!";
						cin>>vrijeme[unos].ocjena;
					}
					
			unos++;
}

void ispisPodataka(){
	cout<<"Podaci o danima ucenja \n";
	
	int danUcenja=0;
	float ocjenaPros=0;
	int ukuSati=0;
	
	cout<<"datum\t"<<"broj sati\t"<<"ocjena\n";
	for(int i=0;i<unos;i++){
	cout<<vrijeme[i].danUcenja<<"\t"<<vrijeme[i].brSati<<"\t"<<vrijeme[i].ocjena<<"\n";
	}
	// ukupan broj dana uèenja, ukupan broj sati uèenja i prosjeènu ocjenu
	ocjenaPros=vrijeme[unos].ocjena/unos;
}

void ispravakPodatak(){
		cout<<"Do sada je uneseno "<<unos<<" dana ucenja studenta\n";
		cout<<""<<endl;
	int datum=0;
	
	
bool trazi=false;

	cout<<"Unesite datum dana za ispravak: \n";
	cin>>datum;
		if(!datum){
			cout<<"Ne postoje podaci za odabrani dan\n";
		}
//	if(datum==){
//			cout<<"Ne postoje podaci za odabrani dan\n";
//		}

	cout<<"Unesi broj sati za ispravak u rasponu od 0 do 24. \n";
		cin>>vrijeme[unos].brSati;
			if(vrijeme[unos].brSati<0||vrijeme[unos].brSati>24){
			cout<<"Unesen je krivi raspon!\n";
			return;
			}else{
				cout<<"Unesi ocjenu za ispravak - osobna evaluacija efikasnost uèenja\n";
				cin>>vrijeme[unos].ocjena;
					if(vrijeme[unos].ocjena<0||vrijeme[unos].ocjena>5){
					cout<<"Unesen je krivi raspon!";
						return;	
						}else{
							
						}
		}
		
}


void brisanjePodataka(){
		cout<<"Do sada je uneseno "<<unos<<" dana ucenja studenta\n";
		cout<<""<<endl;
	cout<<"Unesite dan za brisanje: \n";
	
	int brisi =0;
	bool nadjen = true;
	int datum=0;
	
	cin>>datum;
		if(!datum){
			cout<<"Ne postoje podaci za odabrani dan\n";
		}
	if(datum==nadjen){
		for(int j=0;j<unos-1;j++){
	
		nadjen = true;	
		
			
		unos--;
		}
		
	}	
	
}

void spremanjePodataka(){
	ofstream datoteka("PodaciOcje.txt");
	if (!datoteka){
		cout<<"Greska u otvaranju datoteke\n";
	}
	
	datoteka<<"datum\t"<<"broj sati\t"<<"ocjena\n";
	for(int i=0;i<unos;i++){
	datoteka<<vrijeme[i].danUcenja<<"\t"<<vrijeme[i].brSati<<"\t"<<vrijeme[i].ocjena<<"\n";
	
	
	
	
}datoteka.close();
}

void glavniIzbornik(){

int izbor;

	do{
	cout<<"-----I Z B O R N I K-----\n";
	cout<<""<<endl;
	cout<<"1. Mogucnost (unos podataka)\n";
	cout<<"2. Mogucnost (ispis podataka)\n";
	cout<<"3. Mogucnost (ispravak podataka)\n";
	cout<<"4. Mogucnost (brisanje podataka)\n";
	cout<<"5. Mogucnost (spremanje podataka)\n";
	cout<<""<<endl;
	cout<<"0. Izlaz iz programa\n";
		cout<<""<<endl;
		cout<<"Odaberite mogucnost od 1 do 5 ili 0 za izlaz iz programa"<<endl;
	
			cin>>izbor;
			
	switch(izbor){
		case 1:  unosPodataka(); 		break;
		case 2:  ispisPodataka(); 		break;
		case 3:  ispravakPodatak();		break;
		case 4:  brisanjePodataka(); 	break;
		case 5:  spremanjePodataka();	break;
		
		default: cout<<"Izlaz iz programa\n";
		}
	}while(izbor!=0);
}

int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}
