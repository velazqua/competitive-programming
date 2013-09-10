#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

bool property (int n)
{
   int k;
   int sq;
   bool S1=false, S2=false, S3=false, S4=false;
   for (int i = sqrt(n)-1; i>= 1; --i)
   {
         k = n - i*i;
         //cout << "k: " << k << endl;
         
         sq = int(sqrt(k));
         if (!S1 && sq*sq == k){
            //cout << i << "^2 + " << sq << "^2" << endl;
            S1 = true;
         }
         
         if (!S2 && !(k%2)){
         k /= 2;
         sq = int(sqrt(k));
   
         if (sq*sq == k){
            //cout << i << "^2 + 2*" << sq << "^2" << endl;
            S2 = true;
         }
         k *= 2;
         }
         
         if (!S3 && !(k%3)){
         k /= 3;
         sq = int(sqrt(k));
         if (sq*sq == k){
            //cout << i << "^2 + 3*" << sq << "^2" << endl;
            S3 = true;}
         k*=3;   
         }
         if (!S4 && !(k%7)){   
         //cout << "k: " << k << endl;
         k /= 7;   
         sq = int(sqrt(k));
         if (sq*sq == k){
            //cout << i << "^2 + 7*" << sq << "^2" << endl;
            S4 = true;}
         k*=7;
         }
            //return make_pair(i,sq);  
         if (S1 && S2 && S3 && S4)
            return true;
   }
   return false;
}

int main ()
{
    int count = 0;
    int LIMIT = 1000000;
    for (int i=1;i<LIMIT;++i)
        if (property(i))
           ++count;
    cout << count << "/" << LIMIT << endl;
    cin >> count;
}
