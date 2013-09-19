/* Alex Velazquez
 * Start: Sun Oct 21 02:01:16 EDT 2012
 * End  : Sun Oct 21 02:25:35 EDT 2012
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

bool isOk (int i, int j, int N) {
   return i >= 0 && i < N && j >= 0 && j < N;
}

void search( vector<string> &G, vector< vb > &visited, int i, int j, int N, bool &isAlive) {
   if (G[i][j] == 'x')
      isAlive = true;
   visited[i][j] = true;
   if (isOk(i, j+1, N) && G[i][j+1] != '.' )
      search(G, visited, i, j+1, N, isAlive);
   if (isOk(i+1, j, N) && G[i+1][j] != '.' )
      search(G, visited, i+1, j, N, isAlive);
}

int main ()
{
   int T;
   cin >> T;
   REP( t, T ) {
      int N;
      cin >> N;
      vector<string> G;
      REP( k, N ) {
         string S;
         cin >> S;
         G.PB( S );
      }
      cout << "Case " << t+1 << ": ";
      vector< vb > visited( N, vector<bool>( N, false ));
      int ships = 0;
      REP( i, N ) {
         REP( j, N ) {
            bool isAlive = false;
            if (G[i][j] != '.' && !visited[i][j]) {
               search(G, visited, i, j, N, isAlive);
               if (isAlive)
                  ++ships;
            }
         }
      }
      cout << ships << endl;
   }
}
