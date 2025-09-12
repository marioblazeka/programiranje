#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream datoteka("ocjeneRead.txt");
    if (!datoteka.is_open()) {
        cout << "Greška pri otvaranju datoteke!" << endl;
        return 1;
    }

    string ime, prezime, predmet;
    char crta;
    int ocjena;

    while (datoteka >> ime >>crta>> prezime >>crta>> predmet >>crta>> ocjena) {
        if (ocjena < 4 ) {
            cout << ime << "  "<<crta << prezime << crta<<"  (" <<crta<< ocjena << " manja  od 4)"
                 << " - Predmet: " << crta<<predmet << endl;
        }else{
        	if (ocjena > 4){
        		cout << ime << "  "<<crta << prezime << crta<<"  (" <<crta<< ocjena << " vece  od 4)"
                 << " - Predmet: " << crta<<predmet << endl;
			}
		}
    }

    datoteka.close();
    return 0;
}

