/* Alex Velazquez
 * Start: Tue May  7 21:57:04 EDT 2013
 * End  : Tue May  7 23:56:24 EDT 2013
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
  int B, N;
  while (cin >> B >> N) {
    if (!B && !N)
      break;
    vector<int> P(N+1, 0), F(N+1, 0);
    REP(i, N) {
      cin >> P[i+1] >> F[i+1];
    }
    vector< vector<int> > dp(N+2, vector<int>(B+2, 0));
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= B; j++) {
        int X = (j-P[i] >= 0) ? dp[i-1][j-P[i]] : -100000;
        dp[i][j] = max(dp[i-1][j], X+F[i]);
      }
    }
    int weight = B;
    int ans = dp[N][B];
    for ( ; weight; weight--) {
      if (dp[N][weight] < ans)
        break;
    }
    cout << weight+1 << " " << dp[N][B] << " " << endl;
  }
}
