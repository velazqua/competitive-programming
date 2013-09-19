#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
   typedef string::iterator STR_ITER;
   string word;
   int N;
   cin >> N;
   string vowels="aeiou";
   string consonants="bcdfghjklmnpqrstvwxyz";
   map<char,int> occur;
   map<char,int> vI;
   map<char,int> cI;
   STR_ITER vit=vowels.begin();
   STR_ITER vitEnd=vowels.end();
   STR_ITER cit=consonants.begin();
   STR_ITER citEnd=consonants.end();
   int counter=0;
   for ( ; vit != vitEnd; ++vit){
      occur[*vit]=0;
      vI[*vit]=counter;
      ++counter;
   }
   counter=0;
   for (; cit != citEnd; ++cit){
      occur[*cit]=0;
      cI[*cit]=counter;
      ++counter;
   }
   bool isVowel=false;
   for (int i=0;i<N;++i)
   {
      vit=vowels.begin(); 
      for ( ; vit != vitEnd; ++vit){
         occur[*vit]=0;
      }
      cit=consonants.begin();
      for (; cit != citEnd; ++cit){
         occur[*cit]=0;
      }
      
      cin >> word;
      STR_ITER it=word.begin();
      STR_ITER itEnd=word.end();
      for ( ; it != itEnd; ++it)
      {
         // check if consonant or vowel
         if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
            isVowel=true;
         else
            isVowel=false;
         
         if (isVowel)
         {
            cout << consonants[((vI[*it]+occur[*it]*5)%21)];            
         }
         else
         {
            cout << vowels[((cI[*it]+occur[*it]*21)%5)];     
         }
         ++occur[*it];        
      }
      cout << endl;
                
   }   
   int i;
   cin >> i;
}
