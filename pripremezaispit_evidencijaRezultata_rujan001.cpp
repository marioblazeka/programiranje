#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct evidencijaRez{
	int sifraUtak;
	string ekipa1;
	string ekipa2;
	int golEkp1;
	int golEkp2;	
};

evidencijaRez evidencija[100];
int unos = 0;
int sifraUtak =0;

void unosRezultata(){
	if(unos==0){
		cout<<"Nema evidentiranog unosan \n";		
	}	
	
	sifraUtak++;
	evidencija[unos].sifraUtak = sifraUtak;

		
	cout<<"Upisi ime prve ekipe \n";
	cin>>evidencija[unos].ekipa1;
	
	cout<<"Upisi ime druge ekipe \n";
	cin>>evidencija[unos].ekipa2;
	
	cout<<"Upisi broj golova prve ekipe \n";
	cin>>evidencija[unos].golEkp1;
	
	cout<<"Upisi broj golova druge ekipe \n";
	cin>>evidencija[unos].golEkp2;
	

	unos++;
	cout << "Rezultat je uspjesno dodan!\n";
}

void ispravakRezultata(){
	
	int trazenaSifra =0;
	
	if(unos==0){
		cout<<"Nema evidentiranog unosan \n";	
		return;	
	}
		for(int i=0;i<unos;i++){
		cout<<evidencija[i].sifraUtak<<". "<<evidencija[i].ekipa1<<" - "<<evidencija[i].ekipa2<<" "<<evidencija[i].golEkp1<<" : "<<evidencija[i].golEkp2<<endl;
		}
	cout<<"Upisi sifru utakmice za ispravak \n";
	
	cin>>trazenaSifra;
		

		
	for(int i=0;i<unos;i++){
	if(trazenaSifra==evidencija[i].sifraUtak){
	cout<<"Upisi podatke za ispravak \n";
	
			trazenaSifra=evidencija[i].sifraUtak;
	
	cout<<"Domacini \n";
	cin>>evidencija[i].ekipa1;
	cout<<"Gosti \n";
	cin>>evidencija[i].ekipa2;
	cout<<"Golovi donacina \n";
	cin>>evidencija[i].golEkp1;
	cout<<"Golovi gosta \n";
	cin>>evidencija[i].golEkp2;
	
	//unos++;

	
		cout << "Rezultat je uspjesno izmjenjen!\n";

}//else{
//	cout<<"Nema te sifre \n";
//	return;
}
}


void pregledRezultata(){
	if(unos==0){
		cout<<"Nema evidentiranog unosan \n";	
		return;	
	}
	for(int i=0;i<unos;i++){
	
	int domaci=evidencija[i].golEkp1;
	int gosti=evidencija[i].golEkp2;
	
	cout<<"Svi uneseni rezultati iz evidencije su: \n";
	
	for(int i=0;i<unos;i++){
			if(domaci < gosti){
				cout<<"Domacini su izgubili "<<gosti<<endl;
				gosti++;
			}else{
				cout<<"Domacini su pogjedili "<<domaci<<endl;
				domaci++;
			}
	cout<<evidencija[i].sifraUtak<<". "<<evidencija[i].ekipa1<<" - "<<evidencija[i].ekipa2<<" "<<evidencija[i].golEkp1<<" : "<<evidencija[i].golEkp2<<endl;
		if(evidencija[i].golEkp1>evidencija[i].golEkp2){
			cout <<"Pobjednik: "<< evidencija[i].ekipa1<<endl;
		}
		else if (evidencija[i].golEkp1 < evidencija[i].golEkp2) {
            cout << "Pobjednik: " << evidencija[i].ekipa2 << endl;
        } 
        else {
            cout << "Utakmica zavrsila nerijeseno.\n";
        }
        cout << "-----------------------\n";
		}
		}
}
void spremanjeRezultata(){
	if(unos==0){
		cout<<"Nema podataka za spremanje \n";
			return;
	}	
	ofstream datoteka("rez_rujan.txt");

	if(!datoteka){
		cout<<"greska pri upisu u datoteku \n";
	
	}
	for(int i=0;i<unos;i++){
		datoteka<<evidencija[i].sifraUtak<<". "<<evidencija[i].ekipa1<<" - "<<evidencija[i].ekipa2<<" "<<evidencija[i].golEkp1<<" : "<<evidencija[i].golEkp2<<endl;
	//unos++;
	
	}
	datoteka.close();
	cout<<"Podaci su uspjesno spremljeni u datoteku \n";
}

void pretrazivanjeRezultata(){
	if(unos==0){
		cout<<"Nema podataka za pretrazivanje \n";
		return;
	}
	string pretrazi;
	bool nadjen = false;
	cout<<"Upisi trazeni naziv tima \n";
	cin>>pretrazi;
	for(int i=0;i<unos;i++){
		if(evidencija[i].ekipa1==pretrazi || evidencija[i].ekipa2==pretrazi){
			cout<<"Pronasao sam ekipu: "<<pretrazi<<endl;
			cout<<"Ovo su podaci od ekipe: "<<pretrazi<<endl;
			cout<<evidencija[i].ekipa1<< evidencija[i].ekipa1 << " - " << evidencija[i].ekipa2
                 << " " << evidencija[i].golEkp1 << " : " << evidencija[i].golEkp2
                 << endl;
			nadjen=true;
		}//else{
		//	cout<<"Unos te ekipe ne postoji \n";
		}
		 if (!nadjen) {
        cout << "Unos te ekipe ne postoji \n";
	}

}

void glavniIzbornik(){
	int izbornik;
	do{
		cout<<"-----IZBORNIK-----\n";
		cout<<"1.Unos podataka o rezultatima	\n";
		cout<<"2.Ispravak podataka o rezultatima	\n";
		cout<<"3.Pregled rezultata	\n";
		cout<<"4.Spremanje rezultata	\n";
		cout<<"5.Pretrazivanje rezultata	\n";
		cout<<"6.Izlaz	\n";
		
		cin>>izbornik;
		
	switch(izbornik){
		case 1: unosRezultata(); break;
		case 2: ispravakRezultata(); break;
		case 3: pregledRezultata(); break;
		case 4: spremanjeRezultata(); break;
		case 5: pretrazivanjeRezultata(); break;
		
		
		default:
		if(izbornik <1|| izbornik >5){
			cout<<"Unjeli ste izbor 6. za izlaz iz programa! \n";
		}
	}
	}while(izbornik !=6);

	
}


int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}

