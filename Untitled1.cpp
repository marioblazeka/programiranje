#include<iostream> // Ucitavanje biblioteke za ulaz/izlaz
#include<string>  // Ucitavanje biblioteke za rad sa stringovima
#include<fstream> // Ucitavanje biblioteke za rad sa fajlovima
#include<cstdlib> // Biblioteka za generisanje nasumičnih brojeva
#include<ctime>   // Biblioteka za rad sa vremenom

using namespace std; // Koriscenje standardnog C++ namespace-a

// Definicija strukture 'proizvod' koja cuva podatke o proizvodima u skladistu
struct proizvod{
    int sifra;      // Sifra proizvoda
    string naziv;   // Naziv proizvoda
    float cijena;   // Cijena proizvoda
    int kolicina;   // Kolicina proizvoda u skladistu
};

// Deklaracija funkcija
void generisiPodatke(proizvod skladiste[], int &novi, int brojProizvoda);
void ispis(proizvod skladiste[], int novi); // Ispis svih proizvoda

int main(){
    srand(time(0)); // Inicijalizacija generatora nasumičnih brojeva
    proizvod podaci[100]; // Niz za cuvanje podataka o proizvodima, maksimalno 100 proizvoda
    int novi = 0; // Brojac koji oznacava sledece prazno mesto u nizu
    
    generisiPodatke(podaci, novi, 95); // Generisanje 95 nasumičnih proizvoda
    ispis(podaci, novi); // Ispis generisanih podataka
    
    return 0;
}

// Funkcija koja generise nasumične podatke za proizvode
to
void generisiPodatke(proizvod skladiste[], int &novi, int brojProizvoda){
    const string nazivi[] = {"Jabuka", "Kruska", "Banana", "Narandza", "Breskva"};
    for(int i = 0; i < brojProizvoda; i++){
        skladiste[novi].sifra = rand() % 1000 + 1; // Nasumična šifra između 1 i 1000
        skladiste[novi].naziv = nazivi[rand() % 5]; // Nasumični naziv iz niza
        skladiste[novi].cijena = (rand() % 1000) / 10.0; // Nasumična cijena između 0 i 100
        skladiste[novi].kolicina = rand() % 50 + 1; // Nasumična količina između 1 i 50
        novi++;
    }
}

// Funkcija za ispis svih proizvoda
void ispis(proizvod skladiste[], int novi){
    cout << "Sifra\tNaziv\tCijena\tKolicina" << endl;
    for(int i = 0; i < novi; i++){
        cout << skladiste[i].sifra << "\t" << skladiste[i].naziv << "\t" << skladiste[i].cijena << "\t" << skladiste[i].kolicina << endl;
    }
}
