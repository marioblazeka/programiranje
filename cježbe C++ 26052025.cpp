#include <iostream>
using namespace std;

// Funkcija izvan main()
int provjeriUnos(int broj) {
    if (broj < 0) {
        return 1; // greška
    }
    return 0; // sve ok
}

int main() {
    int broj;

    cout << "Unesi broj: ";
    cin >> broj;

    // Pozivamo funkciju i pohranjujemo rezultat
    int rezultat = provjeriUnos(broj);

    if (rezultat == 0) {
        cout << "Broj je ispravan.\n";
    } else {
        cout << "Broj nije ispravan (negativan).\n";
    }

    system("pause");
    return 0;
}
