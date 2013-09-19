#include <iostream>
#include <list>
#include <map>

using namespace std;

int main ()
{
   typedef unsigned long long ull;
   map<int,ull> fib;
   fib[0]=0L; fib[1]=1L;
   for (int i=2;i<10000000;++i){
      fib[i]=fib[i-1]+fib[i-2];
      //cout << fib[i] << endl;
   }
   cout << "done" << endl;
   int i;
   cin >> i;
}
