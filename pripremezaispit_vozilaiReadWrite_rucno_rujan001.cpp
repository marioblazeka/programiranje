#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream datoteka("vozila.txt");
		if(!datoteka){
			cout<<"Greska u otvaranju datoteke\n";
		}
	string marka, tip;
	int godiste;
	
	bool pronadjen=false;
	
	while(datoteka>>marka>>tip>>godiste){
		if(godiste < 2010){
			pronadjen=true;
			cout<<marka<<tip<<godiste<<endl;
	ofstream izvjestaj("izvjestaj.txt");
	if(!izvjestaj){
			cout<<"Greska u kreiranju datoteke\n";
		}
		for(int i=0; i<pronadjen;i++){
	
	izvjestaj<<marka<<tip<<godiste<<endl;
		izvjestaj.close();
	return 0;
			}
		}
	}
	
}
