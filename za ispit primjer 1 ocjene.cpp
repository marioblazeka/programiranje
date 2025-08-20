#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Struktura za cuvanje podataka o uceniku
struct ucenik {
    string ime;
    string prezime;
    string predmet;
    int ocjena;
};

// Deklaracija funkcije za unos ucenika
void unos(ucenik popis[], int &novi);
void trazi(ucenik popis[], int &podaci);
void sortiraj(ucenik popis[], int &novi);

int main() {
    ucenik podaci[10]; // Niz za cuvanje podataka o ucenicima
    int novi = 0; // Brojac ucenika
    int izbor;
    
    do {
        cout << "1. Novi ucenik" << endl;
        cout << "2. Trazi ucenika" << endl;
        cout << "3. Sortiraj ucenike" << endl;
        cout << "4. Ispisi ucenike" << endl;
        cout << "0. Izlaz" << endl;
        cout << "Izbor: ";
        cin >> izbor;
        
        switch (izbor) {
            case 1:
                unos(podaci, novi);
                break;
            case 2:
                unos(podaci, novi);
                break;
            case 3:
                unos(sortiraj, podaci)
                if(unos>2)
				cout<<"Sortiram"<<endl;
				{else
                cout<<"Nema dovoljno za sort"<<endl;
				}
                break;  
            case 4:
                unos(podaci, novi);
                break;
                
        case 0:
               // unos(podaci, novi);
                break;
                return 0;
                
            default:
                cout << "Krivi unos" << endl;
        }
        
    } while (izbor != 0);
    
    return 0;
}

// Funkcija za unos novog ucenika
void unos(ucenik popis[], int &novi) {
    if (novi < 10) {
        cout << "Unesi ime: ";
        cin >> popis[novi].ime;
        cout << "Unesi prezime: ";
        cin >> popis[novi].prezime;
        cout << "Unesi predmet: ";
        cin >> popis[novi].predmet;
        cout << "Unesi ocjenu: ";
        cin >> popis[novi].ocjena;
        novi++;
    } else {
        cout << "Nema vise mjesta za nove ucenike." << endl;
    }
}
