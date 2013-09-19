#include <iostream>

using namespace std;


void calcStuff (string row, int ways[8])
{
     int c=0;
     for (int i=0;i<38;++i)
     {
         if (row[i]=='H')   c+=4;
         if (row[i+1]=='H') c+=2;
         if (row[i+2]=='H') c+=1;
         ++ways[c];
         c=0;
     }
}


int main ()
{
   int N;
   cin >> N;
   string row;
   int n;
   int ways[8];
   for (int i=0;i<N;++i)
   {
      for (int i=0;i<8;++i)
         ways[i] = 0; 
      cin >> n;
      cin >> row;
      calcStuff(row,ways);
      cout << i+1 << " ";
      for (int j=0;j<8;++j)
      {
         cout << ways[j] << ((j==7)? "":" ");    
      }
      cout << endl;
   }   
}
