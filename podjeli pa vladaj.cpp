#include <iostream>
using namespace std;

int Fniz_naivni(int n){
	cout<<n<<" ";
  if (n==1)
    return 1;
  if (n==2)
    return 1;
  else
  return Fniz_naivni(n-1)+Fniz_naivni(n-2);
}

int Fniz_memoizacija_pom(int Fib[],int n){
	cout<<n<<" ";
	if (Fib[n]==-1)
    	Fib[n]=Fniz_memoizacija_pom(Fib, n-1)+Fniz_memoizacija_pom(Fib, n-2);
    return Fib[n];
}

int Fniz_memoizacija(int n){
  int Fib[n];
  cout<<n<<" ";
  for (int i=0;i<=n;i++){
    Fib[i]=-1;
  }
  Fib[1]=1;
  Fib[2]=1;
  if (Fib[n]==-1)
    Fib[n]=Fniz_memoizacija_pom(Fib, n-1)+Fniz_memoizacija_pom(Fib, n-2);
  return Fib[n];
};

int Fniz_BottomUp(int n){
  cout<<n<<" ";
  int Fib[n+1];
  Fib[1]=1;
  Fib[2]=1;
  for (int i=3; i<=n; i++)
    Fib[i]=Fib[i-1]+Fib[i-2];
  return Fib[n];
};

int main() {
  int x;
  cout<<"Upisi broj: ";
  cin >> x;
  cout<<Fniz_naivni(x)<<endl;
  cout<<Fniz_memoizacija(x)<<endl;
  cout<<Fniz_BottomUp(x)<<endl;
  return 0;
}