/* Alex Velazquez
 * Start: Tue May  7 20:09:06 EDT 2013
 * End  : Tue May  7 20:53:52 EDT 2013
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
  int u = 1000000000;
  int T;
  cin >> T;
  REP(t, T) {
    int E, F, N;
    cin >> E >> F >> N;
    vector<int> V(N, 0), W(N, 0);
    REP(i, N) {
      int a, b;
      cin >> a >> b;
      V[i] = a;
      W[i] = b;
    }
    vector<int> dp(F-E+1, u);
    dp[0] = 0;
    for (int i = 1; i <= F-E; i++) {
      for (int j = 0; j < N; j++) {
        if (i-W[j] >= 0)
          dp[i] = min(dp[i], dp[i-W[j]]+V[j]);
      }
    }
    if (dp[F-E] != u)
      cout << "The minimum amount of money in the piggy-bank is " << dp[F-E] << "." << endl;
    else
      cout << "This is impossible." << endl;
  }
}
