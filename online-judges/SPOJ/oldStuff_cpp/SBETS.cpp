#include <iostream>
#include <map>

using namespace std;

int main ()
{
   int N;
   cin >> N;
   
   for (int i=0;i<N;++i)
   {
      map<string,int> teams;
      string T1, T2;
      int S1, S2; 
      for (int j=0;j<16;++j)
      {
          cin >> T1 >> T2 >> S1 >> S2;
          if (S1 > S2)
             ++teams[T1];
          else
             ++teams[T2];
      }     
      for (map<string,int>::iterator it=teams.begin();it!=teams.end();++it)
      {
          if (it->second == 4)
          {
             cout << it->first << endl;
             break;               
          }
      }
      
   }    
}
