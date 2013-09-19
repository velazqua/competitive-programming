#include <iostream>
#include <map>

using namespace std;

int main ()
{
   int N;
   cin >> N;
   int q=0, h=0, t=0;
   string temp;
   int minPizza=0;
   for (int i=0;i<N;++i)
   {
      cin >> temp;
      if (temp == "1/2")
         ++h;
      else if (temp == "3/4")
         ++t;
      else
         ++q;
   }
   //cout << q << " " << h << " " << t << endl;
   int mini;
   // 3/4s with 1/4s
   if (q && t)
   {
      mini=(q<t)?q:t;
      q -= mini;
      t -= mini;
      minPizza += mini;
   }
   
   // 1/4 with 1/4s
   if (q>1)
   {
      h += q/2;
      q %= 2;   
   }

   // 1/2s with 1/2s
   if (h>1)
   {
     minPizza += h/2;
     h %= 2;       
   }
   
   // 1/2s with 1/4s
   if (h || q)
   {
     minPizza++;       
   }
   cout << t+minPizza+1 << endl;
}
