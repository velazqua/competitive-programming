#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
   string word;
   int c=0;
   for (int i=0;i<5;++i)
   {
      cin >> word;
      //transform(word.begin(),word.end(),word.begin(),::tolower);
      if (word.find("FBI") != string::npos) 
      {
         ++c; 
         cout << i+1 << ((i==4)?"":" ");  
      } 
   }    
   if (!c)
      cout << "HE GOT AWAY!" << endl;
      
   int i;
   cin >> i;
}
