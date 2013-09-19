/* Alex Velazquez
 * Start: Thu Nov  1 12:40:06 EDT 2012
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
#define DEBUG        1

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
   int t = 1;
   int n, m;
   while (cin >> n >> m) {
      if (!n && !m)
         break;
      vector<string> names(n);
      REP( i, n ) {
         cin >> names[i];
      }
      vector< vi > AdjMatrix( n, vi( n, 0 ) );
      REP( i, m ) {
         int a, b, cost;
         cin >> a >> b >> cost;
         a--; b--;
         AdjMatrix[a][b] = cost;
         AdjMatrix[b][a] = cost;
      }
      
      REP( k, n )
         REP( i, n )
            REP( j, n )
               AdjMatrix[i][j] = min( AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j] );
      int minn = 2000000000;
      int indx;
      REP( i, n ) {
         int amount = 0;
         REP( j, n) {
            if (i != j) {
               amount += AdjMatrix[i][j];
            }
         }
         #if DEBUG
            cout << names[i] << " " << amount << endl;
         #endif
         if (amount < minn) {
            minn = amount;
            indx = i;
         }
      }
      cout << "Case #" << t++ << " : " << names[indx] << endl;
   }
}
