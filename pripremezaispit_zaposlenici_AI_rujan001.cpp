#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream datoteka("zaposlenici.txt");
    if (!datoteka.is_open()) {
        cout << "Greška pri otvaranju datoteke!" << endl;
        return 1;
    }

    string ime, prezime, radnoMjesto;
    int godine, placa;

    while (datoteka >> ime >> prezime >> godine >> radnoMjesto >> placa) {
        if (godine > 30) {
            cout << ime << " " << prezime << " (" << godine << " god.)"
                 << " - Radno mjesto: " << radnoMjesto
                 << ", Plaæa: " << placa << endl;
        }
    }

    datoteka.close();
    return 0;
}

