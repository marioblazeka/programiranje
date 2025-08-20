// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;
struct studenti{
    int jmbag;
    char preime[25];
    short godina;
    short br_ocjena;
    short ocjene[100];
};
struct pom {
    short godina;
    float prosjek;
    int indeks;
};
bool usporedba(const short &a, const short &b) {
    return a > b; // Silazni redoslijed
}

int main() {
studenti S[5000];
pom P[5000];
short N;
    do{
        cout<<"N = ";
        cin>>N;
    }while (N<1 || N>5000);
    
for (int i=0;i<N;i++){
    cout<<"JMBAG: ";
    cin>> S[i].jmbag;
     cout<<"Prezime i ime: ";
     cin.ignore();
     cin.getline(S[i].preime,20);
     cout<<"Godina studija: ";
     cin>>S[i].godina;
      cout<<"Broj ocjena: ";
     cin>>(S[i].br_ocjena);
     
float PO=0;
for(int j=0;j<S[i].br_ocjena;j++){
    cout<<"Ocjena " << j+1 <<": ";
    cin>>S[i].ocjene[j];
    PO+=(float)S[i].ocjene[j];
   }
PO/=S[i].br_ocjena;
int j=i-1;
P[i].godina=S[i].godina;
P[i].prosjek=PO;
P[i].indeks=i;
}
for (int i = 0; i < N; i++) {
        cout << "Student: " << S[i].preime 
             << ", Godina: " << P[i].godina 
             << ", Prosjek: " <<(float) P[i].prosjek << endl;
}
    return 0;
}