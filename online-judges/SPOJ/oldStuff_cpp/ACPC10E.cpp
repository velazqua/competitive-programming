#include <iostream>
#include <cmath>

typedef unsigned long long ull;

using namespace std;

bool powerOf2 (ull N)
{
   return !(N&(N-1));
}
int closestPower2 (int N)
{
   return (int)pow(2,(ceil(log2(N))));   
}
int knockout (int N)
{
   int x = int(log2(N));
   double summ=0;
   for (double i=x-1;i>=0;--i)
       summ += pow(2,i);
   return int(summ);
}

int main ()
{
   int G, T, A, D;
   int X, Y=0;
   int p2,cp2;
   while (1)
   {
      cin >> G >> T >> A >> D;
      if (G==-1 && T==-1 && A==-1 && D==-1)
         break;
      cout <<powerOf2(G)<<" "<<powerOf2(T)<<" "<<powerOf2(A)<<" "<<powerOf2(D)<<endl;
      /*  
      p2=G*A+D;
      cp2=p2;
      if (!powerOf2(p2))
      {
         cp2 = closestPower2(p2);                 
         Y=cp2-p2;
      }
      X=G*((T-1)*T/2)+knockout(cp2);
      
      cout << G << "*" << A << "/" << T << "+" << D << "=" << X << "+" << Y << endl;     
      */
   }   
   cin >> G;
}
