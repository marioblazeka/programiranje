# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

using namespace std;

struct ucenik {
string ime;
string prezime;
string predmet;
int ocjena;	
};

void unos(ucenik popis[], int &novi );

int main(){
	
	ucenik podaci[10];
	int novi=0;
	int izbor;
	do{
		cout<<"Novi ucenik"<<endl;
		cout<<"trazi ucenika"<<endl;
		cout<<"Sortiraj ucenik"<<endl;
		cout<<"Ispisi ucenike"<<endl;
		cout<<"izlaz"<<endl;
			cout<<izbor<<endl;
			cin>>izbor;
			switch(izbor){
				case1:
					unos(podaci, novi);
					break;
					
					default:
					cout<<"Krivi unos"<<endl;
			}
	}while(izbor !=0);
	
	return 0;
	system("pause");
	return 0;
}
