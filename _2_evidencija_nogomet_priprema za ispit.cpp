#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Rez{
	int sifra;
	string domaci;
	string gosti;
	int golD;
	int golG;
};

// bool 

void ispis(Rez *polje, int u){
    if(u==0) {
        cout<<"Nije unesen niti jedan rezultat.\n";
        return;
    }
    int brojac_dom=0,brojac_gost=0,brojac_tie=0;
    for(int i=0;i<u;i++){
        cout<<endl<<polje[i].sifra<<". "
            <<polje[i].domaci<<" - "
            <<polje[i].gosti<<" "
            <<polje[i].golD
            <<":"<<polje[i].golG;

        if(polje[i].golD>polje[i].golG)
            brojac_dom++;
        else if(polje[i].golG>polje[i].golD)
            brojac_gost++;
        else if(polje[i].golD==polje[i].golG)
            brojac_tie++;
    }
    
    cout<<"Broj pobjeda domaćih timova: "<<brojac_dom<<endl;
    cout<<"Broj pobjeda gostujućih timova: "<<brojac_gost<<endl;
    cout<<"Broj neodlučenih utakmica: "<<brojac_tie<<endl;
}


void unos(Rez *polje, int &b){
	cout<<"Uneseno je: "<<b<<" rezultata."<<endl;
	if(b==100){
		cout<<"Popunjeno je\n";
		return;
	}
	cout<<"Unesite domacina\n";
	cin>>polje[b].domaci;
	cout<<"Unesite gosta\n";
	cin>>polje[b].gosti;
	cout<<"Unesite broj golova domacina\n";
	cin>>polje[b].golD;
	cout<<"Unesite broj golova gostiju\n";
	cin>>polje[b].golG;
	polje[b].sifra=b+1;							//pomičemo b za 1 unos
	b += 1;
}

void pregled(Rez *polje, int u){
	if(u==0){
		cout<<"Nema upisanih rezultata\n";
		return;
		
	int sifr=0;	
	
	cout<<polje[sifr].sifra<<". "
	<<polje[sifr].domaci<<" . "
	<<polje[sifr].gosti<<"    "
	<<polje[sifr].golD
	<<polje[sifr].golG
	<<" . "<<endl;
		}
}

void ispravak(Rez *polje, int u){
	if(u==0){
		cout<<"Nema upisanih rezultata\n";
		return ;
	int sifr=0;	
	ispis(polje, u);
	cout<<"Unesite sifru utakmica\n";
	cin>>sifr;
	if(sifr<1||sifr>u){
		cout<<"Krivi unos\n";
		return;
	}
	cout<<polje[sifr].sifra<<". "
	<<polje[sifr].domaci<<" . "
	<<polje[sifr].gosti<<"    "
	<<polje[sifr].golD
	<<polje[sifr].golG
	<<" . "<<endl;
	
	cout<<"Unesite domacina\n";
	cin>>polje[sifr].domaci;
	cout<<"Unesite gosta\n";
	cin>>polje[sifr].gosti;
	cout<<"Unesite broj golova domacina\n";
	cin>>polje[sifr].golD;
	cout<<"Unesite broj golova gostiju\n";
	}
}

void spremi(Rez *polje,int u){
	fstream izlaz("Rezultati_priprema_za_ispit.txt");				//kreiraj
    if(!izlaz){
        cout<<endl<<"Greska u otvaranju datoteke"<<endl;
        return;
    }
    for(int i=0;i<u;i++){
         izlaz<<polje[i].sifra
             <<" "<<polje[i].domaci
             <<" "<<polje[i].gosti
             <<" "<<polje[i].golD
             <<" "<<polje[i].golG<<endl;
    }
    izlaz.close();

} 

void pretrazi(Rez *polje, int u){
    string ekipa;
    cout<<endl<<"Pretrazivanje rezultata"<<endl;
    cout<<endl<<"Unesite ime ekipe: ";
    cin>>ekipa;
    for(int i=0;i<u;i++){
        if(ekipa==polje[i].domaci || ekipa==polje[i].gosti)
            cout<<endl<<polje[i].sifra
                <<". "<<polje[i].domaci
                <<" - "<<polje[i].gosti
                <<" "<<polje[i].golD
                <<":"<<polje[i].golG;
     }
}

int main(){
	Rez *polje;
	polje=new Rez[100];
	
	int sum=0;
	int izbor;
	
	cout<<"1. Unos podataka\n";
	cout<<"2. Ispravak podataka\n";
	cout<<"3. Pregled podataka\n";
	cout<<"4. Spremanje podataka\n";
	cout<<"5. Pretrazivanje podataka\n";
	cout<<"0. Izlaz iz programa\n";
		
	cout<<"Unesite opciju 1 - 5 ili 0 za izlaz"<<endl;
		cin>>izbor;
	
	do{
		switch(izbor){
			case 1: unos(polje, sum);
				break;
			case 2: ispravak(polje, sum);
				break;
			case 3: pregled(polje, sum);
				break;
			case 4: spremi(polje, sum);
				break;
			case 5: pretrazi(polje, sum);
				break;
			defrault:
			cout<<"Unesite opciju 1 - 5 ili 0 za izlaz"<<endl;
		}
		
	}while(izbor!=0);
	
	system("pause");
	return 0;
}