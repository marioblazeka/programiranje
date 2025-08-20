#include<iostream>
using namespace std;

int suma_iterativno(int n) {
    int suma = 0;
    for(int i = 1; i <= n; i++) {
           cout << "Suma  " << i<< endl;
	   suma += i;
    }
    return suma;
}

int suma_rekurzivno(int n) {
    if (n == 1)
        return 1;
    else
        return n + suma_rekurzivno(n - 1);
    
}

int main() {
    int n;
    cout << "Unesi broj: ";
    cin >> n;

    cout << "Suma (iterativno) od 1 do " << n << " je: " << suma_iterativno(n) << endl;
    cout << "Suma (rekurzivno) od 1 do " << n << " je: " << suma_rekurzivno(n) << endl;

    system("pause");
    return 0;
}
