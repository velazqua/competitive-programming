#include <iostream>
#include <list>

using namespace std;

int main ()
{
   int a1, b1, c1;
   list<int> l;
   string p;
   int next;
   while (1)
   {
      cin >> a1 >> b1 >> c1;
      l.push_back(a1); l.push_back(b1); l.push_back(c1);
      l.sort();
      if (a1==0 && b1==0 && c1==0)
          break;
      list<int>::iterator it=l.begin();
      a1 = *it; ++it; b1=*it; ++it; c1=*it;
      if (b1-a1 == c1-b1){
         p = "AP";
         next = 2*c1-b1;
      }
      else
      {
         p = "GP";
         next = c1*c1/b1;    
      }
      cout << p << " " << next << endl;
      
      l.clear();      
   }  
}
