/* Alex Velazquez
 * Start: Sun Oct 21 02:29:17 EDT 2012
 * End  : Sun Oct 21 02:53:23 EDT 2012
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

void search( vector<vi> &G, vector<vb> &visited, int i, int j, int N, int &size) {
   ++size;
   visited[i][j] = true;
   int arrx[] = {-1,1,0,0};
   int arry[] = {0,0,-1,1};
   REP( k, 4) {
      int x = i+arrx[k];
      int y = j+arry[k]; 
      if (isOk(x,y,N) && !visited[x][y] && G[x][y] == G[i][j] )
         search( G, visited, x, y, N, size);
   }
}
               
int main ()
{
   int N;
   while (cin >> N) {
      if (!N)
         break;
      vector< vi > G( N, vi( N, N ) );
      REP( i, N-1 ) {
         string line;
         if (i == 0)
            cin.ignore();
         getline (cin, line);
         stringstream newLine (line);
         int token;
         while (newLine >> token) {
            int x, y;
            x = token;
            newLine >> token;
            y = token;
            G[x-1][y-1] = i+1;
         }
      }
      
      vector< vb > visited ( N, vb( N, false ) );
      bool bad = false;
      REP( i, N ) {
         REP( j, N ) {
            if (!visited[i][j]) {
               int size = 0;
               search(G, visited, i, j, N, size);
               if (size != N) {
                  bad = true;
               }
            }
         }
      }
      if (bad) {
         cout << "wrong" << endl;
      }
      else {
         cout << "good" << endl;
      }
   }
}
