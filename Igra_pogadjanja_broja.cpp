#include <iostream>
#include <cmath>  
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {
    string ime;
    int raspon;
	int broj;
    int sb;
    int brojcanik=0;
    srand(time(NULL));
    rand();
       sb=static_cast <float> (rand())/RAND_MAX*raspon;
        cout<<"Dobro dosli u igru pogadjanja brojeva!"<<endl;
         cout<<"Sami odabirete raspon u nastavku"<<endl;
          cout<<"Molim prvo unesite svoje ime"<<endl;
          cin>>ime;
           cout<<"Dobro dosao "<<ime<<"!"<<endl;
            cout<<"Zelim ti uspjesnu igru!!!"<<endl;
    
	    cout<<endl;
	   cout<<"U kojem rasponu brojeva zelis igrati"<<endl;
	    cout<<"Raspon moje igre je od 0 do ";
	    cin>>raspon;
	    
	    cout<<"Unesi raspon od 0 do "<<raspon<<endl;
	    cout<<"Zamislio sam jedan broj od 0 do 100!"<<endl;
	    
       cout<<"Lukas, ajde pogodi koji broj sam zamislio, brojim ti pokusaje"<<endl;
       
        do{
            cout<<"Unesi odgovor, koji broj sam zamislio"<<endl;
            cin>>broj;
            brojcanik=brojcanik+1;
            
                if(sb>broj){
                    cout<<"Zamislio sam veci broj"<<endl;
                }
                       if(sb<broj){
                    cout<<"Zamislio sam manji broj"<<endl;
                }
        }
                    while(sb!=broj);
                    cout<<"Pogodil si od "<<brojcanik<<" put, bravo Lukas!!!"<<endl;
        
        
   //system("pause");
    return 0;
}
