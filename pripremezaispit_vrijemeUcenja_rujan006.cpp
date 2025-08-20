#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct vrijemeUcenja{
	string danUcenja;	//u formatu dd-mm-yyyy
	int satUcenja;
	int ocjenaUcenja;
};

vrijemeUcenja vrijeme[10]; //niz od 10 elemenata
int brojUnosa = 0;


void unosPodataka(){
	if (brojUnosa>=10){
	cout<<"Unesen je maksimalni broj unosa!!! \n";
	// return ;
	}	
	
	cout<<"Do sada je uneseno: " << brojUnosa << " dana. \n";
		cin.ignore();	// čišćenje
		
	cout<<"Upisi podatke  o datumu (u formatu dd-mm-yyyy)\n";
	getline(cin, vrijeme[brojUnosa].danUcenja);
	if(vrijeme[brojUnosa].danUcenja.length() !=10 || 
	   vrijeme[brojUnosa].danUcenja[2]!='-'||
	   vrijeme[brojUnosa].danUcenja[5]!='-'){
			cout<<"Upisali ste krivi format za datum ! \n";
			return;
		}else
		cout<<"Upisali ste datum! \n";
	
	cout<<"Upisi podatke o broju sati ucenja: \n";
	cin>> vrijeme[brojUnosa].satUcenja;
		if(vrijeme[brojUnosa].satUcenja<0||vrijeme[brojUnosa].satUcenja>24){
			cout<<"Upisi sate ucenja u rasponu od 0 do 24 ! \n";
			return;
		}else
		cout<<"Vrijeme je uredno zabiljezeno! \n";
	
	cout<<"Upisi ocjenu za danas (od 1 do 5): \n";
	cin>>vrijeme[brojUnosa].ocjenaUcenja;
		if(vrijeme[brojUnosa].ocjenaUcenja<1||vrijeme[brojUnosa].ocjenaUcenja>5){
			cout<<"Upisi sate ucenja u rasponu od 0 do 24 ! \n";
			return;
		}else
		cout<<"Ocjena je uredno zabiljezena! \n";
		
		brojUnosa++;
}

void ispisPodataka(){
	if(brojUnosa==0){
		cout<<"Nema upisanih podataka o ucenju! \n";
		return;
	}
	//ispis zaglavlja
	cout<<"Do sada je upisano: \n"<<
	"Broj unosa \t |	\t Broj dana	|	\t Broj sati	|\t	Ocijena	|\n"<<
	brojUnosa 	<<"	\t|	"<<	"\t	"<<vrijeme[brojUnosa].danUcenja<< "	|	"<<	"\t	"<<vrijeme[brojUnosa].satUcenja<<"	|	"<<
	"\t 	"<<vrijeme[brojUnosa].ocjenaUcenja<<"|	\n";
	
		int sumaDana=0;
		int sumaSati=0;
	
	cout << "\n--- PODACI O UCENJU ---\n";
    cout << "Datum\t\tSati\tOcjena\n";
    cout << "-------------------------------\n";
    
	for(int i=0; i<brojUnosa; i++){
	//cout<<"Do sada je upisano: \t"<<vrijeme[i].brojDana+=sumaDana;
	//cout<<"Do sada je upisanon broj sati: \t"<<vrijeme[brojUnosa].satUcenja == sumaSati<<endl;
	//cout<<"Prosjecna ocjena: \t"<<vrijeme[brojUnosa].ocjenaUcenja /danaUcenja= prosjekOcjena<<endl;
	//sumaDana += vrijeme[brojUnosa].danUcenja;
	//sumaSati += vrijeme[brojUnosa].satUcenja;
	}
/*	float prosjekOcjena=(float)sumaOcjena/brojUnosa;
	    cout << "-------------------------------\n";
    cout << "Ukupno dana: " << brojUnosa << "\n";
    cout << "Ukupno sati: " << sumaSati << "\n";
    cout << "Prosjecna ocjena: " << prosjekOcjena << "\n";
    */
	}

void ispravakPodataka(){
   if (brojUnosa == 0) {
        cout << "Nema podataka za ispraviti.\n";
        return;
    }

	cout<< "Do sada je uneseno "<<brojUnosa<< " dana ucenja. \n";
	cout<<"Upisi datum koji zelis ispraviti \n";
	cin.ignore();
	string trazeniDatum;
	getline(cin, trazeniDatum);
	
	bool pronadjen=false;
	
	for(int i=0; i<brojUnosa; i++){
		if(vrijeme[i].danUcenja==trazeniDatum){
			pronadjen =true;
			
		cout<< "Pronaasao sam datum datum"<<trazeniDatum<<endl;
		cout<< "Upisi broj sati - novi"<<endl;
		cin>>vrijeme[i].satUcenja;
		
		while (vrijeme[i].satUcenja < 0 || vrijeme[i].satUcenja > 24) {
                cout << "Greska! Unesite broj sati od 0 do 24: ";
                cin >> vrijeme[i].satUcenja;
            }

            cout << "Upisi novu ocjenu (1-5): ";
            cin >> vrijeme[i].ocjenaUcenja;

            while (vrijeme[i].ocjenaUcenja < 1 || vrijeme[i].ocjenaUcenja > 5) {
                cout << "Greska! Unesite ocjenu od 1 do 5: ";
                cin >> vrijeme[i].ocjenaUcenja;
            }

            cout << "Podaci su uspjesno ispravljeni!\n";
            break;
	}
	
}
}

void brisanjePodataka(){
	if(brojUnosa!=0){
	cout<<"Do sada je uneseno "<< brojUnosa <<endl;
}else{
	cout<<"Nema podataka za unos " <<endl;
	return;
}

	cin.ignore();
	string trazeniDatum;
	getline(cin, trazeniDatum);
	
bool pronadjen = false;

for(int i=0;i<brojUnosa;i++){
		if(vrijeme[i].danUcenja == trazeniDatum){
			pronadjen =true;
	cout<<"Upisi trazeni datum za brisanje " <<endl;
	
	for (int j = i; j < brojUnosa - 1; j++) {
                vrijeme[j] = vrijeme[j + 1];
            }
            brojUnosa--; // smanji broj unosa
            cout << "Podatak za datum " << trazeniDatum << " je uspjesno obrisan.\n";
            break; // ako ima više istih datuma, briše samo prvi
}

	    if (!pronadjen) {
        cout << "Datum nije pronadjen!\n";
}
}
}

spremanjePodataka(){
	if(brojUnosa!=0){
	cout<<"Sveukupno je upisano: "<< brojUnosa<< " koji su spremni za spremanje u datoteku podaci.txt \n";
}else{
cout<<"Nazalost broj upisanih podataka je: "<< brojUnosa<< " pa nemapodataka za spremanje u datoteku. \n";
}

ofstream datoteka("podaci.txt");
	if(!datoteka){
		cout<<"Greska pri otvaranju datoteke!!!"<<endl;
		//return;
	}	
	// Ispis zaglavlja
    datoteka << "Datum \t \t Sati \t Ocjena\t \n";

    for (int i = 0; i < brojUnosa; i++) {
        datoteka << vrijeme[i].danUcenja <<"\t" << " " << vrijeme[i].satUcenja <<"\t" << " " << vrijeme[i].ocjenaUcenja <<"\t"<< endl;
    }
    
	datoteka.close();
    if(brojUnosa=0){
	cout<<"Nema podataka za unos, uneseno  "<< brojUnosa <<endl;
}else{
	cout<<" Izvoz podataka u datoteku realiziran!" <<endl;
	return 0;
}
return 0;
}

void citanjePodataka() {
    ifstream datoteka("podaci.txt");
    if (!datoteka) {
        cout << "Ne mogu otvoriti datoteku za citanje!\n";
        return;
    }

    string linija;
    cout << "\n--- SADRZAJ DATOTEKE ---\n";
    while (getline(datoteka, linija)) {
        cout << linija << endl;
    }

    datoteka.close();
}

void izmijeniTreciRed() {
   const int MAX_LINIJA = 100;
    string linije[MAX_LINIJA];
    int brojLinija = 0;

    // Otvori datoteku za čitanje
    ifstream datotekaIn("podaci.txt");
    if (!datotekaIn) {
        cout << "Ne mogu otvoriti datoteku za citanje!\n";
        return;
    }

    // Učitaj sve linije u niz
    while (getline(datotekaIn, linije[brojLinija]) && brojLinija < MAX_LINIJA) {
        brojLinija++;
    }
    datotekaIn.close();

    // Provjera postoji li treći red
    if (brojLinija < 3) {
        cout << "Datoteka nema treći red za izmjenu!\n";
        return;
    }

    // Traži novi sadržaj
    cout << "Unesi novi sadrzaj za treći red (npr. 03-08-2025\t4\t5):\n";
    string noviRed;
    cin.ignore(); // očisti ulazni buffer
    getline(cin, noviRed);

    // Zamijeni treći red
    linije[2] = noviRed;

    // Otvori datoteku za pisanje i prepiši sve linije
    ofstream datotekaOut("podaci.txt");
    for (int i = 0; i < brojLinija; i++) {
        datotekaOut << linije[i] << "\n";
    }
    datotekaOut.close();

    cout << "Treci red je uspjesno izmijenjen!\n";
    return;
}


void izbornik(){
	int izbornik;
	do{
	
	cout<<"---IZBORNIK---\n";
	cout<<"0. Izlaz iz programa! \n";
	cout<<"1. Unos podataka \n";
	cout<<"2. Ispis unesenih podataka \n";
	cout<<"3. Ispravak unesenih podataka \n";
	cout<<"4. Brisanje unesenih podataka \n";
	cout<<"5. Spremanje unesenih podataka u datoteku (podaci.txt) \n";
	cout<<"Unesite izbor od 1 do 5!";
	
	cin>> izbornik;
		
	switch(izbornik){
		case 1: unosPodataka(); break;
		case 2: ispisPodataka(); break;
		case 3: ispravakPodataka(); break;
		case 4: brisanjePodataka(); break;
		case 5: spremanjePodataka(); break;
		default:
			cout<<"Pogresan unos!!! \n";
			}
		
	}while(izbornik !=0||izbornik<0||izbornik>>5);
	cout<<"Izlazite iz programa..."<<endl;
}


int main(){
	
	izbornik();
	
	//unosPodataka();
	
	system("pause");
	return 0;
}