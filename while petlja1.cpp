#include<iostream>

using namespace std;

int main(){
	
	int unos;
	int paran=2;
	int broji;
	int sumiraj;
	
	cout<<"Upisuj brojeve"<<endl;
	
		cin>>unos;
	
	if(unos%paran==0){
		cout<<"Broj <<unos <<" je paran broj."<<endl;
	}   else{
		cout<<"Nastavljamo!"<<endl;
	}                            

	while (unos%paran==0){
	
	if(broj%i==0){		
		cout<<i<<" "<<endl;
	}
	i++;
}
	
	system("pause");
	return 0;
	}
/* Napišite program koji poziva korisnika na unos brojeva sve dok ne upiše paran broj. 
Nakon unosa parnog broja program zaustavlja poziv unosa i ispisuje sumu upisanih (neparnih) brojeva.

Primjer:
ulaz:
1
3
2

izlaz: 
4*/