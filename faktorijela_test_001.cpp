// primjer za izraèun faktorijela
#include <iostream>
using namespace std;
int main (){
	
int n;
int i =1;
int k=1;

cout<< "unesi prirodni broj n"<<endl;
cin >>n;
do{ k=k*i; i++; } while (i<=n);
cout << "n!= "<<k<<endl;

return 0;
}
