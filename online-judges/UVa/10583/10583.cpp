/* Alex Velazquez
 * Start: Wed Oct 31 20:22:03 EDT 2012
 * End  : Wed Oct 31 20:31:34 EDT 2012
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

void search (vector<vi> &G, vector<bool> &R, int i) {
   R[i] = true;
   REP( j, SZ(G[i]) ) {
      if (!R[G[i][j]])
         search(G, R, G[i][j]);
   }
}

int main ()
{
   int n, m;
   int cs = 1;
   while (cin >> n >> m) {
      if (!n && !m)
         break;
      vector<bool> R( n+1, false );
      vector< vi > G( n+1 );
      REP( i, m ) {
         int a, b;
         cin >> a >> b;
         G[a].PB(b);
         G[b].PB(a);
      }
      int c = 0;
      FOR( i, 1, n+1 ) {
         if (!R[i]) {
            search (G, R, i);
            c++;
         }
      }
      cout << "Case " << cs++ << ": " << c << endl;
   }
}
