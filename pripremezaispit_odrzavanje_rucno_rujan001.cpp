#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct pojedOdrzava{
	int redBr;
	string vrstOdrza;
	string nazRac;
	int vrijOdrz;
};

pojedOdrzava odrzavanje[100];
int unos=0;
int redBr=1;

void unosOdrzavanja(){
	if(unos<101){
		cout<<"Do sada je uneseno "<<unos<<" odrzanvanja/popravaka\n";
	}else{
		cout<<" Polje je popunjeno! \n";
	}
	//cin.ignore();
	cout<<"Upisi vrstu odrzavanja: \n";
	cin>>odrzavanje[unos].vrstOdrza;
	cout<<"Upisi naziv racunala: \n";
	cin>>odrzavanje[unos].nazRac;
	cout<<"Upisi vrijeme popravka: \n";
	cin>>odrzavanje[unos].vrijOdrz;

	redBr++;
	
	return;
}

void izmjenaOdrzavanja(){
	cout<<"Upisi broj odrzavanja za izmjenu: \n";
	int trazi;
	cin>>trazi;
	
	if(trazi=odrzavanje[unos].redBr){
		cout<<odrzavanje[unos].redBr<<odrzavanje[unos].vrstOdrza<<odrzavanje[unos].nazRac<<odrzavanje[unos].vrijOdrz<<endl;
		cout<<"Unesi podatke za promjenu zapisa odrzavanja: \n";
		
		cout<<"Upisi ponovno redni broj: \n";
		cin>>odrzavanje[unos].redBr;
		cout<<"Upisi izmjenu vrstu odrzavanja: \n";
		cin>>odrzavanje[unos].vrstOdrza;
		cout<<"Upisi izmjenu naziv racunala: \n";
		cin>>odrzavanje[unos].nazRac;
		cout<<"Upisi izmjenu vrijeme popravka: \n";
		cin>>odrzavanje[unos].vrijOdrz;
		return;		
	}else{
		cout<<"Održavanje/popravka s tim brojem ne postoji \n";
		return;
	}
	
}

void brisOdrzavanja(){
		cout<<"Upisi broj odrzavanja za brisanje: \n";
	int brisi;
	cin>>brisi;
	
	if(brisi=odrzavanje[unos].redBr){
		cout<<odrzavanje[unos].redBr<<odrzavanje[unos].vrstOdrza<<odrzavanje[unos].nazRac<<odrzavanje[unos].vrijOdrz<<endl;
		cout<<"Unesi podatke za brisanje zapisa odrzavanja: \n";
		
		cout<<"Upisi ponovno redni broj za brisanje :\n";
		cin>>odrzavanje[unos].redBr;
		cout<<"Upisi  vrstu odrzavanja za brisanje: \n";
		cin>>odrzavanje[unos].vrstOdrza;
		cout<<"Upisi  naziv racunala  za brisanje: \n";
		cin>>odrzavanje[unos].nazRac;
		cout<<"Upisi  vrijeme popravka  za brisanje: \n";
		cin>>odrzavanje[unos].vrijOdrz;
	//for(int i=0; i<unos;i++;)
	
		return;		
	}else{
		cout<<"Održavanje/popravka s tim brojem ne postoji \n";
		return;
	}
	
}

void pretrOdrzavanja(){
	cout<<"Upisi pojam odrzavanja popravka za pretrasgu: \n";
	string pretrazi;
	cin>>pretrazi;
	if(pretrazi == odrzavanje[unos].vrstOdrza){
			cout<<odrzavanje[unos].redBr<<odrzavanje[unos].vrstOdrza<<odrzavanje[unos].nazRac<<odrzavanje[unos].vrijOdrz<<endl;
		}else{
		cout<<"Nema održavanja/popravki s tim pojmom \n";
	}
}

void spremanjeuDatoteku(){
	ofstream datoteka("baza.txt");
	if(!datoteka){
		cout<<"Greska u otvaranju dat\n";
	}else{
		for(int i=0; i<unos; i++){
		datoteka<<"REDNI BROJ\t"<<"VRSTA ODRZAVANJA\t"<<"NAZIV RACUNALA\t"<<"VRIJEME ODRZAVANJA\t"<<endl;
		datoteka<<odrzavanje[i].redBr<<"|\t"<<odrzavanje[i].vrstOdrza<<"|\t"<<odrzavanje[i].nazRac<<"|\t"<<odrzavanje[i].vrijOdrz<<"|"<<endl;
		datoteka<<"–kraj zapisa–\n";
	datoteka.close();
	return;
}
	}
}

void glavniIzbornik(){
	int izbor;
	
	do{
	cout<<"\n";
		cout<<"1. Unos novog održavanja/popravka\n";
		cout<<"2. Izmjena održavanja/popravka\n";
		cout<<"3. Brisanje održavanja/popravka\n";
		cout<<"4. Pretraživanje održavanja/popravki\n";
		cout<<"5. Spremanje u datoteku\n";
			cout<<"0.\n";
	cin>>izbor;
	
	switch(izbor){
		case 1: unosOdrzavanja(); break;
			case 2: izmjenaOdrzavanja(); break;
				case 3: brisOdrzavanja(); break;
					case 4: pretrOdrzavanja(); break;
						case 5: spremanjeuDatoteku(); break;
		default: cout<<"Greska u unosu\n";
		}
	}while(unos!=0);
}

int main(){
	glavniIzbornik();
	
	system ("pause");
	return 0;
	}
