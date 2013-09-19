#include <iostream>

using namespace std;

int main ()
{
   int s1, s2, s3, a1, a2, a3;
   int i=1;
   while (cin >> s1 >> s2 >> s3 >> a1 >> a2 >> a3)
   {
      int numSolved=0;
      int penalties=s1+s2+s3;
      if (s1) ++numSolved;
      if (s2) ++numSolved;
      if (s3) ++numSolved;
      if (s1 && a1) penalties+=60*20*(a1-1); 
      if (s2 && a2) penalties+=60*20*(a2-1);
      if (s2 && a3) penalties+=60*20*(a3-1);
      cout << "team " << i << ": " << numSolved << ", " << penalties << endl;
      ++i;
   }   
   int i2;
   cin >> i2;
}
