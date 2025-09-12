#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct pracenjeOcjena{
string ime;
string prezime;
string nazivPred;
int ocjena;
};

pracenjeOcjena pracenje[100];
int unos =0;

void unosPodataka(){
	cout<<"Upisi ime ucenika\n";
		cin>>pracenje[unos].ime;
	cout<<"Upisi prezime ucenika\n";
		cin>>pracenje[unos].prezime;
	cout<<"Upisi naziv predmeta\n";
		cin>>pracenje[unos].nazivPred;
	cout<<"Upisi ocjenu za ucenika iz tog predmeta\n";
		cin>>pracenje[unos].ocjena;
		if(pracenje[unos].ocjena < 1 || pracenje[unos].ocjena > 5){
		cout<<"Upisi ocjenu u rasponu od 1 do 5!\n";
		//ocjena++;
		unos++;
		}else{
			cout<<"Ocjena je upisana!\n";
			return;
			}
}

void ispisPodataka(){
	if(unos==0){
		cout<<"Nema podataka za ispis\n";
		}
	int izbor;	
	
	cout<<"Zelis li ispisati ocjene po:\n";
cout<<" "<<endl;
	cout<<"1. Predmetima\n";
	cout<<"2. Ucenicima\n";
cout<<" "<<endl;
	cout<<"Unesi odabir:\n";

	cin>>izbor;
	
	if(izbor==1){
		for(int i=0;i<unos;i++){
					cout<<pracenje[i].nazivPred<<pracenje[i].prezime<<pracenje[unos].ocjena<<endl;
					}
	//	float prosPred=ocjena/unos;
	float prosPred=2;

		cout<<"Prosjecna ocjena za "<<pracenje[unos].nazivPred<<" iznosi "<<prosPred<<endl;

			}

	if(izbor==2){
		for(int i=0;i<unos;i++){
					cout<<pracenje[i].prezime<<pracenje[unos].ocjena<<endl;
					}
		//float prosUcen=ocjena/unos;
			float prosUcen=3;
		cout<<"Prosjecna ocjena za "<<pracenje[unos].nazivPred<<" iznosi "<<prosUcen<<endl;

			}

}

void ispravakPodataka(){
		if(unos==0){
		cout<<"Nema podataka za ispravak\n";
	
	string trazi;
		
cout<<"Unesi prezime ucenika\n";
cin>>pracenje[unos].prezime;
		for(int i=0;i<unos;i++){
		if(trazi==pracenje[i].prezime){
		cout<<"Unesi novu ocjenu!\n";
cin>>pracenje[unos].ocjena;
if(pracenje[unos].ocjena < 1 && pracenje[unos].ocjena > 5){
		cout<<"Upisi ocjenu u rasponu od 1 do 5!\n";
		//ocjena++;
		unos++;
		}else{
			cout<<"Ocjena je promjenjena\n";
			return;
			}
			}
			}
			}
			}
			

void brisanjePodataka(){
		if(unos==0){
		cout<<"Nema podataka za brisanje\n";

		for(int i=0;i<unos;i++){
					cout<<pracenje[i].ime<<pracenje[i].prezime<<pracenje[i].nazivPred<<pracenje[unos].ocjena<<endl;
					}
		cout<<"Unesi prezime ucenika i predmet za koji brises ocjenu: \n";
		cin>>pracenje[unos].prezime;
		cout<<"Izbrisi ocjenu: \n";

}
}

void citanjeIzDat(){
		if(unos==0){
		cout<<"Nema podataka za citanje\n";

    ifstream datoteka("ocjene.txt");
    if (!datoteka) {
        cout << "Datoteka ocjene.txt ne postoji ili se ne moze otvoriti.\n";
        return;
    }

    unos = 0; // reset polja
    string linija;
    while (getline(datoteka, linija)) {
        stringstream ss(linija);
        string ime, prezime, predmet, ocjenaStr;

        getline(ss, ime, '|');
        getline(ss, prezime, '|');
        getline(ss, predmet, '|');
        getline(ss, ocjenaStr);

        // trim razmake
        auto trim = [](string &s) {
            while (!s.empty() && isspace(s.front())) s.erase(s.begin());
            while (!s.empty() && isspace(s.back())) s.pop_back();
        };
        trim(ime);
        trim(prezime);
        trim(predmet);
        trim(ocjenaStr);

        pracenje[unos].ime = ime;
        pracenje[unos].prezime = prezime;
        pracenje[unos].nazivPred = predmet;
        pracenje[unos].ocjena = stoi(ocjenaStr);
        unos++;
    }

    datoteka.close();
    cout << "Podaci su ucitani iz ocjene.txt\n";
/*	
	ofstream datoteka ("ocjeneMoje.txt");
		if(!datoteka){
			cout<<"Greska u datoteci\n";
				}
		for(int i=0;i<unos;i++)
		datoteka<<"IME\t"<<"PREZIME\t"<<"PREDMET\t"<<"OCJENA\t"<<endl;
		datoteka<<pracenje[unos].ime<<"\t"<<pracenje[unos].prezime<<"\t"<<pracenje[unos].nazivPred<<"\t"<<pracenje[unos].ocjena<<"\t"<<endl;
	
			datoteka.close();
	
		//ifstream datoteka("ocjene.txt");
		//read
		//datoteka.close;
*/
}
}

void glavniIzbornik(){
	int izbor;	
	
	do{
	cout<<"-----IZBORNIK-----\n";
		cout<<" "<<endl;
	cout<<"1. Unos podataka za ucenike i predmete\n";
	cout<<"2. Ispis podataka po predmetime ili ucenicima\n";
	cout<<"3. Ispravak podataka za ucenika ili predmet\n";
	cout<<"4. Brisanje podataka za ucenika\n";
	cout<<"5. Citanje iz datoteke ocjene.txt (u polje)\n";
	cout<<"-----IZBORNIK-----\n";

	cin>>izbor;

	switch(izbor){
			case 1:unosPodataka();		break;
			case 2:ispisPodataka();		break;
			case 3:ispravakPodataka(); 	break;
			case 4:brisanjePodataka(); 	break;
			case 5:citanjeIzDat(); 		break;

			default: cout<<"Krivi unos\n";
			}
	}while(izbor!=0);
		}

int main(){
	glavniIzbornik();

	system("pause");
	return 0;
	}


