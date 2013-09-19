/* Alex Velazquez
 * Start: Mon Oct 22 23:13:58 EDT 2012
 * End  : Mon Oct 22 23:57:09 EDT 2012
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

void search (vector<vi> &G, vector<bool> &visited, int i, int color, vector<int> &colored, bool &contradiction) {
   if (!visited[i]) {
      visited[i] = true;
      colored[i] = color;
      if (color == 1)
         color = 2;
      else
         color = 1;
      REP( k, SZ(G[i]) ) {
         search(G, visited, G[i][k], color, colored, contradiction);
      }
   }
   else {
      if (color != colored[i])
         contradiction = true;
   }
}

int main ()
{
   int numNodes;
   while (cin >> numNodes) {
      if (!numNodes) {
         break;
      }
      int numEdges;
      cin >> numEdges;
      vector<vi> G( numNodes );
      REP( i, numEdges ) {
         int i, j;
         cin >> i >> j;
         G[i].PB(j);
         G[j].PB(i);
      }
      vector<bool> visited( numNodes, false );
      vector<int> colored( numNodes, 0 );
      int color = 1;
      bool contradiction = false;
      REP( i, numNodes ) {
         if (!visited[i]) {
            search(G, visited, i, color, colored, contradiction);
         }
      }
      cout << (contradiction ? "NOT " : "") << "BICOLORABLE." << endl;
   }
}
