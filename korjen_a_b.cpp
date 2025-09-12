#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;
// program koji provjerava da li je prvi broj korjen drugog
int main(){
	int a; 
	int b;
	
	cout<<"Upisi a: \n";
	cin>>a;
	
	cout<<"Upisi b: \n";
	cin>>b;
	
	if(sqrt(b)== a || sqrt(b)==-a){
		cout<<a<<" je korjen od " <<b<< "\n";
	}else {
		cout<<a<<" nije korjen od " <<b<< "\n";
	}
	system("pause");
	return 0;
}
