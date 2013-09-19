#include <iostream>
#include <map>

using namespace std;

int sumNum (int N)
{
   if (N/10==0)
      return N*N;
   else
      return (N%10)*(N%10) + sumNum(N/10);   
}

int main ()
{
   int N;
   map<int,int> numbers;
   cin >> N;
   int steps=0;
   while (1)
   {
      //cout << "num: " << N << ". sumNum(num): "<< sumNum(N) << endl;
      
      if (sumNum(N) == 1)
      {
         cout << ++steps << endl;
         break;
      }
      else
      {
         if (numbers[N] > 0)
         {
            cout << "-1" << endl;
            break;            
         }
            
         ++numbers[N];
         N = sumNum(N);
         ++steps;
      }
   }
   int i;
   cin >> i;
      
}
