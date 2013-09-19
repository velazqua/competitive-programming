/* Alex Velazquez
 * Start: Wed Oct 24 15:04:04 EDT 2012
 * End  : Wed Oct 24 15:15:36 EDT 2012
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
   // generate all numbers x = 2^i * 3^j
   vector<LL> power2(33,1LL), power3(33,1LL);
   FOR( i, 1, 32 ) {
      power2[i] = power2[i-1]*2LL;
      power3[i] = power3[i-1]*3LL;
   }
   set<LL> nums;
   REP( i, 32 ) {
      REP( j, 32 ) {
         LL N = power2[i] * power3[j];
         if (N > (1LL << 35)) 
            break;
         nums.insert( N );
      }
   }
   LL m;
   while (cin >> m) {
      if (!m)
         break;
      set<LL>::iterator it = nums.lower_bound(m);
      cout << *it << endl;
   }
}
