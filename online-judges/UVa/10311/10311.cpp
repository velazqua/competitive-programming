/* Alex Velazquez
 * Start: Wed Oct 31 13:04:24 EDT 2012
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
   int lim = 100000001, i, j;
   lim += 1;
   vector<bool> primes( lim, false );
   primes[0] = true;
   primes[1] = true;
   for (i = 2; i*i <= lim-1; i++)
      if (!primes[i])
         for (j = i * i; j <= lim-1; j += i)
            primes[j] = true;
	
   vector<int> P;
   for (i = 2; i <= lim/2+2; i++)
      if (!primes[i])
         P.push_back( i );
   int size = SZ(P);
   int N;
   while (cin >> N) {
      if (N < 5) {
         cout << N << " is not the sum of two primes!" << endl;
      }
      else if (N%2) {
         if (!primes[N-2]) {
            cout << N << " is the sum of " << 2 << " and ";
            cout << N-2 << "." << endl;
         }
         else {
            cout << N << " is not the sum of two primes!" << endl;
         }
      }
      else {
         int i = 0;
         bool found = false;
         while ( i < size && P[i] <= N/2 ) {
            if (!primes[N-P[i]] && N-P[i] != P[i]) {
               found = true;
               cout << N << " is the sum of " << P[i] << " and ";
               cout << N-P[i] << "." << endl;
               break;
            }
            ++i;
         }
         if (!found) {
            cout << N << " is not the sum of two primes!" << endl;
         }
      }
   }
}
