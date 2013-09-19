/* Alex Velazquez
 * Start: Sun Oct 21 16:55:55 EDT 2012
 * End  : Sun Oct 21 17:16:43 EDT 2012
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

bool isOk (int i, int j, int M, int N) {
   return i >= 0 && i < M && j >= 0 && j < N;
}

void search( vector<string> &G, vector<vb> &visited, int i, int j, int M, int N, int &size, bool &ownLand, int x, int y, char c) {
   visited[i][j] = true;
   ++size;
   if (i == x && j == y) {
      ownLand = true;
   }
   int arrx[] = {0,0,-1,1};
   int arry[] = {1,-1,0,0};
   REP(k, 4) {
      int X = i+arrx[k];
      int Y = (j+arry[k]+N)%N;
      if (isOk(X,Y,M,N) && !visited[X][Y] && G[X][Y] == c) {
         search(G, visited, X, Y, M, N, size, ownLand, x, y, c);
      }
   }
}
            
int main ()
{
   int M, N;
   while (cin >> M >> N) {
      vector<string> G;
      REP( i, M ) {
         string S;
         cin >> S;
         G.PB(S);
      }
      int x, y;
      cin >> x >> y;
      vector<vb> visited (M, vb(N, false));
      int maxx = 0;
      char c = G[x][y];
      REP( i, M ) {
         REP( j, N ) {
            if (!visited[i][j] && G[i][j] == c) {
               int size = 0;
               bool ownLand = false;
               search(G, visited, i, j, M, N, size, ownLand, x, y, c);
               if (!ownLand) {
                  maxx = max(maxx, size);
               }
            }
         }
      }
      cout << maxx << endl;
   }   
}
