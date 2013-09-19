/* Alex Velazquez
 * Start: Sun Oct  7 22:13:44 EDT 2012
 * End  : Sun Oct  7 22:29:01 EDT 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int isPalindrome( int X )
{
   vector<char> D;
   int mult = 1;
   while( X )
   {
      int d = X % 10;
      D.push_back( d );
      X /= 10;
      if( d )
         mult *= d;
   }
   int size = SZ(D);
   for( int i=0; i<size/2; ++i )
      if( D[i] != D[size-i-1] )
         return 0;
   return mult;
}

int main ()
{
   unsigned int lim = 1000000, i, j;
   lim += 1;
   vector<bool> primes( lim, false );
   for (i = 2; i*i <= lim-1; i++)
      if (!primes[i])
         for (j = i * i; j <= lim-1; j += i)
            primes[j] = true;
    
   vector<int> P;
   for (i = 2; i <= lim-1; i++)
      if (!primes[i])
         P.push_back( i );
   
   int sizePrimes = SZ(P);
   vector< pair<int,int> > palindromes;
   REP( i, sizePrimes )
   {
      int X = isPalindrome( P[i] ); 
      if( X )
      {
         palindromes.push_back( make_pair( P[i], P[X-1] ) );
      }
   }
   int Z;
   cin >> Z;
   REP( i, Z )
   {
      int V;
      cin >> V;
      cout << palindromes[V-1].first << " " << palindromes[V-1].second << endl;
   }
}
