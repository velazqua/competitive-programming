/* Alex Velazquez
 * Start: Sat Aug 24 12:38:50 EDT 2013
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

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  int N;
  cin >> N;
  vector< vector<int> > M(N, vector<int>(N, 0));
  vector< vector<int> > P(N, vector<int>(N, 0));
  REP(i, N) {
    REP(j, N) {
      cin >> M[i][j];
    }
  }
  REP(i, N) {
    REP(j, N) {
      P[i][j] += M[i][j];
      if (i-1 >= 0)
        P[i][j] += P[i-1][j];
      if (j-1 >= 0)
        P[i][j] += P[i][j-1];
      if (i-1 >= 0 && j-1 >= 0)
        P[i][j] -= P[i-1][j-1];
    }
  }
  int maxx = -2146000000;
  REP(x1, N) {
    REP(y1, N) {
      FOR(x2, x1, N) {
        FOR(y2, y1,  N) {
          int val = P[x2][y2];
          if (x1-1 >= 0)
            val -= P[x1-1][y2];
          if (y1-1 >= 0)
            val -= P[x2][y1-1];
          if (x1-1 >= 0 && y1-1 >= 0)
            val += P[x1-1][y1-1];
          /*
          cout << "x1: " << x1 << ". y1: " << y1;
          cout << ". x2: " << x2 << ". y2: " << y2;
          cout << ". val: " << val << endl;
          */
          maxx = max(maxx, val); 
        }
      }
    }
  }
  cout << maxx << endl;
}
