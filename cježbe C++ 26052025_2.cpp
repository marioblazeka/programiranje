#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Upisi a: ";
    cin >> a;

    cout << "Upisi b: ";
    cin >> b;

    // Euclidean Algorithm
    int temp;
    while (b != 0) {
        temp = b;
            cout << b <<" ";
        b = a % b;
        cout << b << endl;
        a = temp;
    }

    cout << "Najveci zajednicki delilac je: " << a << endl;

    return 0;
}
