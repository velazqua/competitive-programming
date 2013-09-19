#include <iostream>
#include <list>

using namespace std;

int main ()
{
   int N;
   cin >> N;
   for (int i=0;i<N;++i)
   {
      string URL;
      int val;
      int highest=0;
      list<string> websites;
      for (int j=0;j<10;++j)
      {
         cin >> URL >> val;
         if (val == highest)
         {
            websites.push_back(URL);        
         }     
         else if (val > highest)
         {
            highest = val;
            websites.clear();
            websites.push_back(URL);     
         }
      }
      cout << "Case #" << i+1 << ":" << endl;
      for (list<string>::iterator it = websites.begin();it!=websites.end();++it)
          cout << *it << endl;
   }
  
}
