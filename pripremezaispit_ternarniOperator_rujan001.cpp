#include <iostream>
using namespace std;

int main() {
    int a, n;
    cout << "Provjera da li je a djeljiv sa n\n";
    cout << "Upisi a: ";
    cin >> a;
    cout << "Upisi n: ";
    cin >> n;
    
for(int a=2;a<100;a++){

for(int n=2;n<a;n++){

    bool djeljiv = (a % n == 0);

    // Ternarni operator za ispis
    cout << a << (djeljiv ? " je djeljiv sa " : " nije djeljiv sa ") << n << endl;//ternarni operator
}
}
    return 0;
}

