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
bool sifraPostoji(proizvod skladiste[], int novi, int sifra); // Provera da li sifra vec postoji
void ucitajIzFajla(proizvod skladiste[], int &novi, const string& filename); // Ucitavanje podataka iz fajla

int main(){
    srand(time(0)); // Inicijalizacija generatora nasumičnih brojeva
    proizvod podaci[100]; // Niz za cuvanje podataka o proizvodima, maksimalno 100 proizvoda
    int novi = 0; // Brojac koji oznacava sledece prazno mesto u nizu
    
    ucitajIzFajla(podaci, novi, "podaci.txt"); // Ucitavanje podataka iz fajla
    ispis(podaci, novi); // Ispis ucitanih podataka
    
    return 0;
}

// Funkcija koja proverava da li sifra vec postoji u nizu
bool sifraPostoji(proizvod skladiste[], int novi, int sifra){
    for(int i = 0; i < novi; i++){
        if(skladiste[i].sifra == sifra) return true;
    }
    return false;
}

// Funkcija za ucitavanje podataka iz fajla
void ucitajIzFajla(proizvod skladiste[], int &novi, const string& filename){
    ifstream fajl(filename); // Otvaranje fajla
    if (!fajl) {
        cout << "Greska pri otvaranju fajla: " << filename << endl;
        return;
    }
    
    while (fajl >> skladiste[novi].sifra >> skladiste[novi].naziv >> skladiste[novi].cijena >> skladiste[novi].kolicina) {
        novi++;
        if (novi >= 100) break; // Ogranicenje na maksimalnih 100 proizvoda
    }
    fajl.close(); // Zatvaranje fajla
}

// Funkcija za ispis svih proizvoda
void ispis(proizvod skladiste[], int novi){
    cout << "Sifra\tNaziv\t\tCijena\tKolicina" << endl;
    cout << "--------------------------------------" << endl;
    for(int i = 0; i < novi; i++){
        cout << skladiste[i].sifra << "\t" 
             << skladiste[i].naziv << "\t\t" 
             << skladiste[i].cijena << "\t" 
             << skladiste[i].kolicina << endl;
    }
}
