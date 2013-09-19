#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

void f (int cur, int A, int &B, int &counter)
{
   if (A == B)
      ++counter;
   else
   {
      ++A;
      for (int i=cur;i<10;++i)
         f(i,A,B,counter);   
   }
}   

int main ()
{
   int s=29;
   int counter=0;
   f(0,0,s,counter);
   cout << counter << endl;
   int i;
   cin >> i;
   
}
