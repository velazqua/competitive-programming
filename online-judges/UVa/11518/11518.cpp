/* Alex Velazquez
 * Start: Thu Jan 24 18:23:02 EST 2013
 * End  : Thu Jan 24 18:46:57 EST 2013 Thu Jan 24 18:39:24 EST 2013
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

void knockIt (int d, vector< vector<int> > &G, vector<bool> &knockedOver) {
  if (!knockedOver[d]) {
    knockedOver[d] = true;
    REP(i, SZ(G[d])) {
      knockIt(G[d][i], G, knockedOver);
    }
  }
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    int n, m, l;
    cin >> n >> m >> l;
    vector< vector<int> > G(n+1, vector<int>());
    REP(i, m) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
    }
    vector<bool> knockedOver(n+1, false);
    REP(i, l) {
      // dominos knocked out
      int d; 
      cin >> d;
      knockIt(d, G, knockedOver);
    }
    int c = 0;
    FOR(i, 1, n+1) {
      if (knockedOver[i]) {
        c++;
      }
    }
    cout << c << endl;
  }
}
