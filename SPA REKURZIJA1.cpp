#include<iostream>
 using namespace std;
  int suma(int a){ 
  if(a<3) return 0;
  	 else if(a%3==0) 
	   return a+suma(a-3);
  	 
  	  
  	 	   
			   else
  	 	    	return suma(a-1);
		cout<<"Suma : "<< a+suma <<endl; 
		
		return suma(a-1);
	}
			 
	int main(){
	 int a;
	  cout<<"Upisi broj:";
	   cin>>a; 
	   cout<<"Suma brojeva djeljivih sa 3 do upisanog broja je:"<<suma(a)<<endl; 
	   return 0; } 