#include<iostream> 
using namespace std;
 int maxz(int a){ int temp;
 	 if(a<10) return a; 
	  else{ return a%10>maxz(a/10) ? a%10 : maxz(a/10) ; } }
	  
	   int main(){ 
	   int a; cout<<"Upisi broj:";
	    cin>>a; 
		cout<<"Najveca znamenka upisanog broja je: "<<maxz(a)<<endl; 
		
		return 0; }