#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream datoteka("racuni.txt");
		if(!datoteka.is_open()){
			cout<<"Datoteka je vec otvorena\n";
		}
	string racunBr;
	int broj;
	char prvi;
	string naziv1;
	int cjena1;
	string naziv2;
	int cjena2;
	string naziv3;
	int cjena3;
	string valuta;
	char drugi;
	
	while(datoteka>>racunBr>>broj>>prvi>>naziv1>>cjena1>>valuta>>drugi>>naziv2>>cjena2>>valuta>>drugi>>naziv3>>cjena3>>valuta>>drugi)
	if(broj>0){
	cout<<racunBr<<broj<<prvi<<naziv1<<cjena1<<valuta<<naziv2<<cjena2<<valuta<<naziv3<<cjena3<<valuta<<endl;
	for(int i=0;i<broj;i++){
		cout<<broj<<endl;
	int ukupno=cjena1+cjena2+cjena3;
	cout<<ukupno;
//	int sveukupno=	
		}
	}
		datoteka.close();
	
	system("pause");
	return 0;
}
