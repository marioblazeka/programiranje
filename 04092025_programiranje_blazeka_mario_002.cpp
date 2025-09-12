#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct evidPoslovanja{
	string oib;  //mora biti string
	int serBrUre;
	string nazivUred;
	bool ispravan;
	float cijUred;
	bool isporucen;
	int tjedan; //u formatu tt broj tjedna u godini za tjedni izracun
};

evidPoslovanja evidencija[500];
int unos=0;
bool ispravan=false;
bool isporucen=false;

void zaprimanjeUredaja(){
	cout<<"Do sada je zaprimljeno "<<unos<<" uredaja na popravak!\n";
	if(unos>500){
		cout<<"Popunjeno je svih 500 mjesta za evidenciju! \n";
		return;
	}
	string trazi;
	bool postoji=false;
	
	cout<<"Upisi OIB-a vlasnika uredaja: \n";
	cin>>evidencija[unos].oib;
	if(trazi==evidencija[unos].oib){
	postoji=true;
	cout<<"Vlasnik je vec upisan: OiB "<<evidencija[unos].oib<<
	"Serijski broj uredaja "<<evidencija[unos].serBrUre<<
	"Naziv uredaja "<<evidencija[unos].nazivUred<<
	"Status popravka"<<evidencija[unos].ispravan<<
	"Stanje isporuke "<<evidencija[unos].isporucen<<endl;
		}else{
		cout<<"Upisi serijski broj uredaja: \n";
		cin>>evidencija[unos].serBrUre;
			cout<<"Upisi naziv uredaja: \n";
			cin>>evidencija[unos].nazivUred;
			
			cout<<"Upisi broj tjedna upisa uredaja u godini(u formatu tt): \n";
			cin>>evidencija[unos].tjedan;
			
			cout<<evidencija[unos].ispravan;
			cout<<evidencija[unos].isporucen;
	
	unos++;	
	}	
	return;
}

void upisCijeneUred(){
	int izbor;
	int trazi;
	
	cout<<"Odaberi opciju 1: Upisivanje cijene servisiranja ureðaja ili 2: Tjedno ažuriranje zapisa neisporuèenih ureðaja\n";
	cin>>izbor;
	
	if(izbor==1){
		cout<<"Upisi serijski broj uredaja za azuriranje podataka \n";
		cin>>trazi;
		
		 bool nadjen = false;


    cout << "\nserijski broj uredaja za azuriranje podataka " << trazi << ":\n";

    for (int i = 0; i < unos; i++) {
        if (evidencija[i].serBrUre == trazi) {
            nadjen = true;
            cout << "Serijski broj: " << evidencija[i].oib << " | "
                 << "Naziv uredaja: " << evidencija[i].nazivUred << " | "
                 << "Tjedan prijema: " << evidencija[i].tjedan << " | "
                 << "Ispravan: " << (evidencija[i].ispravan ? "DA" : "NE") << " | "
                 << "Isporucen: " << (evidencija[i].isporucen ? "DA" : "NE")
                 << endl;
        
        cout << "Upisi cijenu popravka: \n ";
        cin>>evidencija[i].cijUred; 
        cout<<"Ureðaj je popravljen: (1 -Da 0 -Ne) \n ";
        cin>>evidencija[i].ispravan;
               cout<<"Ureðaj je isporuèen: (1 -Da 0 -Ne) \n ";
        cin>>evidencija[i].isporucen;
        return;
    }
}

    if (!nadjen) {
        cout << "Nema uredaja s tim OIB-om u servisu.\n";
    }
}
		

	
	if(izbor==2){
		int neisporuceni=0;
		int trazi;
		bool nadjen=false;
		cout<<"Unesi broj tjedna za pregled statusa uredaja\n";
		cin>>trazi;
	//	if(trazi==evidencija[i].tjedan){
	//		nadjen=true;
	//	for (int i=0;i<unos;i++){
	//		if(evidencija[i].isporucen==0){
		cout<<"Popis neisporucenih uredaja \n"<<trazi<<endl;
	//	neisporuceni++;
	for (int i = 0; i < unos; i++) {
        if (evidencija[i].tjedan == trazi && evidencija[i].isporucen == 0) {
            nadjen = true;
            neisporuceni++;
            cout << evidencija[i].serBrUre << " | "
                 << evidencija[i].oib << " | "
                 << evidencija[i].nazivUred << endl;
		}
		}

	
 if (!nadjen) {
        cout << "Nema uredaja u tom tjednu u servisu.\n";
}
}
}

/*	Opcija 1: Upisivanje cijene servisiranja ureðaja -> Program najprije od servisera
 traži da upiše serijski broj ureðaja za kojeg želi ažurirati podatke,
  potom za dotièni serijski broj ureðaja serviseru omoguæuje unos cijene 
  servisiranja (trošak ugraðenih dijelova + sati rada), 
  te je li ureðaj servisiran ili nije.

Opcija 2: Tjedno ažuriranje zapisa neisporuèenih ureðaja -> 
Program ažurira zapise u polju tako da zapise o neisporuèenim 
ureðajima poslaže na poèetak polja, time u polju 
struktura ostanu samo aktualni zapisi neisporuèenih ureðaja. 
(Zapisi o isporuèenim ureðajima „nestaju“).

Program nastavlja s radom vraæajuæi se u glavni Menu.*/

void pretrazivanjePodataka() {
    string trazi;       // OIB vlasnika
    bool nadjen = false;

    cout << "Upisi OIB vlasnika uredaja: ";
    cin >> trazi;

    cout << "\nUredaji vlasnika s OIB-om " << trazi << ":\n";

    for (int i = 0; i < unos; i++) {
        if (evidencija[i].oib == trazi) {
            nadjen = true;
            cout << "Serijski broj: " << evidencija[i].serBrUre << " | "
                 << "Naziv uredaja: " << evidencija[i].nazivUred << " | "
                 << "Tjedan prijema: " << evidencija[i].tjedan << " | "
                 << "Ispravan: " << (evidencija[i].ispravan ? "DA" : "NE") << " | "
                 << "Isporucen: " << (evidencija[i].isporucen ? "DA" : "NE")
                 << endl;
        }
    }

    if (!nadjen) {
        cout << "Nema uredaja s tim OIB-om u servisu.\n";
    }
}
	
/*	Pretraživanje po OIB-u vlasnika -> Program od korisnika traži da upiše 
OIB vlasnika ureðaja, a potom u svakom redu ispisuje podatke o pojedinim 
ureðajima koje vlasnik ima u servisu (serijski broj, naziv, cijenu servisiranja, 
je li ureðaj popravljen ili ne, te je li vraæen vlasniku).

Program nastavlja s radom vraæajuæi se u glavni Menu.*/
	

void tjedniIzvjestaj(){
	int trazi;
	int nadjeno=0;
	float prosCje=0;
	double sumaCijena=0;
	bool nadjen=false;
	cout<<"Upisi tjedan prijema uredaja\n";
	cin>>trazi;
	for(int i=0;i<unos;i++){
		if(trazi==evidencija[i].tjedan){
				nadjen=true;
				nadjeno++;
				sumaCijena += evidencija[i].cijUred;
		prosCje=sumaCijena/nadjeno;
cout<<"U servisu se u "<<trazi<<" tjednu nalazilo "<<nadjeno<<" uredaja po prosjecnoj cjeni popravka od "<< prosCje <<" \n";
	
		
			
	}
}
}
	
/*
	Program treba izraèunati sažetak tjednog poslovanja:

Kolièinu ureðaja u servisu
Ukupnu naplaæenu vrijednost servisiranja (dakle samo za isporuèene ureðaje u 
tekuæem tjednu)
Vrijednost najskupljeg popravka
Prosjeènu cijenu servisiranja ureðaja u tekuæem tjednu*/


void ispisUdatoteku() {
    ofstream datoteka("Servis.txt");
    if (!datoteka) {
        cout << "Greska u otvaranju datoteke!\n";
        return;
    }

    // Jedan ureðaj = jedan red u datoteci
    for (int i = 0; i < unos; i++) {
        datoteka 
            << "OiB vasnika "<<evidencija[i].oib << " "
            << "Serijski broj uredaja "<<evidencija[i].serBrUre << " "
            << "Naziv uredaja "<<evidencija[i].nazivUred << " "
            << "Tjedan prijema "<<evidencija[i].tjedan << " "
            << "Cijena servisa "<<evidencija[i].cijUred << " "
            << "Ispravan "<<evidencija[i].ispravan << " "
            << "Isporucen "<<evidencija[i].isporucen 
            << "\n";
    }

    datoteka.close();
    cout << "Podaci uspjesno spremljeni u Servis.txt\n";
}

void glavniIzbornik(){
	int izbor;
	
	do{
		
		cout<<"-----I Z B O R N I K -----\n";
		cout<<"\n";
		cout<<"1. Zaprimanje neispravnog uredaja u servis\n";
		cout<<"2. Upisivanje cijene servisiranja uredaja / Tjedno azuriranje zapisa\n";
		cout<<"3. Pretrazivanje podataka\n";
		cout<<"4. Tjedni izvjestaj rada servisa\n";
		cout<<"5. Ispis u datoteku trenutnog statusa uredaja servisa\n";
		cout<<"0. Izlaz\n";
		cout<<"\n";
		cout<<"Odaberi opciju od 1 do 5 ili 0 za izlaz\n";
		
		cin>>izbor;
	
	switch(izbor){
		case 1: zaprimanjeUredaja();		break;
		case 2: upisCijeneUred();			break;
		case 3: pretrazivanjePodataka();	break;
		case 4: tjedniIzvjestaj();			break;
		case 5: ispisUdatoteku(); 			break;
		
		default: cout<<"Pogresan izbor!\n";
		return;
			}
	}while(izbor!=0);
}

int main(){
	glavniIzbornik();
	
	system("pause");
	return 0;
}
/*Izradite program za tjedno voðenje evidencije poslovanja servisa raèunalne opreme. 
Program uèitava podatke o zaprimljenim ureðajima u servis, troškovima servisiranja te 
ih pohranjuje u polje zadane strukture.

Ulazni podaci o pojedinom zaprimljenom ureðaju u servis su sljedeæi:

OIB u ulozi šifre vlasnika (cijeli broj)
Serijski broj ureðaja (cijeli broj)
Naziv ureðaja (string ili polje znakova)
Ispravnost ureðaja (logièka vrijednost)
Cijena servisiranja ureðaja (decimalan broj)
Ureðaj isporuèen vlasniku (logièka vrijednost)
Program treba sadržavati izbornik sa sljedeæim moguænostima:

1. Zaprimanje neispravnog ureðaja u servis
2. Upisivanje cijene servisiranja ureðaja / Tjedno ažuriranje zapisa
3. Pretraživanje podataka
4. Tjedni izvještaj rada servisa
5. Ispis u datoteku trenutnog statusa ureðaja servisa
0. Izlaz

Napomene:

Pojedine moguænosti programa treba realizirati pomoæu odgovarajuæih funkcija s argumentima.
Pomoæu statusa ispravnosti ureðaja korisnik programa ima uvid je li ureðaj popravljen ili ne.


Moguænost 1. -> Zaprimanje neispravnog ureðaja u servis

Program djelatniku servisa omoguæuje unos podataka tijekom zaprimanja ureðaja u servis. Podaci se
 spremaju u odgovarajuæe polje velièine 500 elemenata. Svaki element polja treba biti tipa 
 strukture i sadržavati barem navedene obvezne podatke.

Potrebno je sljedeæe:

Prije unosa, program treba ispisati kolièinu do tada zaprimljenih ureðaja te ukoliko u polju nema mjesta 
za upisati novi podatak program treba ispisati poruku i vratiti se u glavni izbornik.
Ukoliko ima mjesta za upis novog podatka o ureðaju koji se zaprima, program najprije traži upis 
OIB-a vlasnika ureðaja. Nakon što djelatnik servisa upiše OIB vlasnika, program treba provjeriti 
postoji li veæ neki ureðaj dotiènog vlasnika u servisu
a) Ukoliko veæ postoji zapis sa istom šifrom vlasnika, program treba ispisati serijski broj, 
naziv ureðaja i ispravnost ureðaja koji je veæ u servisu, te za dodatni ureðaj koji se zaprima 
ponuditi upis serijskog broja i naziv ureðaja. Program automatski upisuje (maloèas upisani) OIB 
vlasnika, te logièku vrijednost „0“ za ispravnost ureðaja i za ureðaj isporuèen vlasniku.
b) Ako ne postoji zapis sa upisanom šifrom vlasnika, program korisniku treba ponuditi upis serijskog 
broja i naziv ureðaja. Program automatski upisuje (maloèas upisani) OIB vlasnika, te logièku vrijednost „0“
 za ispravnost ureðaja i za ureðaj isporuèen vlasniku.
Program nastavlja s radom vraæajuæi se u glavni Menu.

 

Moguænost 2. -> Upisivanje cijene servisiranja ureðaja / Tjedno ažuriranje zapisa

Moguænost 2 treba ponudi 2 opcije:

Opcija 1: Upisivanje cijene servisiranja ureðaja

Opcija 2: Tjedno ažuriranje zapisa neisporuèenih ureðaja

Opcija 1: Upisivanje cijene servisiranja ureðaja -> Program najprije od servisera
 traži da upiše serijski broj ureðaja za kojeg želi ažurirati podatke, potom za dotièni
  serijski broj ureðaja serviseru omoguæuje unos cijene servisiranja (trošak ugraðenih dijelova + sati rada), 
  te je li ureðaj servisiran ili nije.

Opcija 2: Tjedno ažuriranje zapisa neisporuèenih ureðaja -> Program ažurira zapise 
u polju tako da zapise o neisporuèenim ureðajima poslaže na poèetak polja, time u polju 
struktura ostanu samo aktualni zapisi neisporuèenih ureðaja. (Zapisi o isporuèenim ureðajima „nestaju“).

Program nastavlja s radom vraæajuæi se u glavni Menu.

 

Moguænost 3. -> Pretraživanje podataka

Pretraživanje po OIB-u vlasnika -> Program od korisnika traži da upiše 
OIB vlasnika ureðaja, a potom u svakom redu ispisuje podatke o pojedinim 
ureðajima koje vlasnik ima u servisu (serijski broj, naziv, cijenu servisiranja, 
je li ureðaj popravljen ili ne, te je li vraæen vlasniku).

Program nastavlja s radom vraæajuæi se u glavni Menu.

 

Moguænost 4. -> Tjedni izvještaj rada servisa

Program treba izraèunati sažetak tjednog poslovanja:

Kolièinu ureðaja u servisu
Ukupnu naplaæenu vrijednost servisiranja (dakle samo za isporuèene ureðaje u tekuæem tjednu)
Vrijednost najskupljeg popravka
Prosjeènu cijenu servisiranja ureðaja u tekuæem tjednu
 

Moguænost 5. -> Ispis trenutnog stanja skladišta servisa u datoteku

Odabirom ove opcije podaci o ureðajima u servisu spremaju se u datoteku Servis.txt 
tako da podaci o pojedinom ureðaju budu zapisani u pojedinom retku datoteke 
meðusobno odvojeni razmakom.

 

Moguænost 0. -> Izlaz

Program završava sa radom.*/
