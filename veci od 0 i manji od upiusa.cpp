#include <iostream>
using namespace std;

int main() {
   int broj, brojac=1;
   cout<<"Upisi broj:";
   cin>>broj;
   cout<<"While petlja:"<<endl;
   while(brojac<broj){
       cout<<brojac<<endl; brojac++;
   }
   cout<<"Do-while petlja:"<<endl;
   brojac=1;
   do{
       cout<< brojac<<endl;
       brojac++;
   }while(brojac<broj);

   system("pause");
   return 0;
}
