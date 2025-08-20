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

int main(){
	
	int unos[70];
	int izbor;
	
	cout<<"1. Unos parkirnog mjesta.\n";
	cout<<"2. Izmjena unesenog parkirnog mjesta.\n";
	cout<<"3. Naplata parkirnog mjesta/kampiranja.\n";
	cout<<"4. Ispis podataka o parkirnom mjestu.\n";
	cout<<"5. Unos podataka parkirnog mjesta u datoteku parkiranje.txt\n";
	cout<<"0. Izaz iz izbornika.\n";
	
	cout<<"Unesi izbor\n";
	cin>>izbor;
	
	switch(izbor){
				case 1
				cout<<"Popunjenost kampa je "<< unos <<" parkirnih mjesta od 70 sveukupno"endl;
				if(unos<1){
					cout<<"Kamp je prazan\n";
				}
				if(unos=70){
					cout<<"Sva kamp mjesta su zauzeta\n";
				}else{
					cout<<"Unesite zeljeno parkirno mjesto\n"; 
				}else if{
					cout<<"Zeljeno parkirno mjesto je zauzeto\n"; 
				}
				}
			}
		
		break;
		
				case 1
		
		break;
		
				case 1
		
		break;
		
				case 1
		
		break;
		
				case 1
		
		break;
		
				case 0
				break;
		return;
		}
	
	
	
	
	system("pause");
	return 0,
}