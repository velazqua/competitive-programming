/* Alex Velazquez
 * Start: Fri Jun 28 00:34:54 PDT 2013
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
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

typedef unsigned long long int ull;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  vector<int> dp(1000001);
  dp[1] = 1;
  int n1, k1;
  while (cin >> n1 >> k1) {
    int n = n1, k = k1;
    if (n > k)
      swap(n, k);
    int maxx = 0;
    for (int i = n; i <= k; i++) {
      if (dp[i] > 0) {
        maxx = max(maxx, dp[i]);
      }
      else {
        int n = i;
        vector<int> nums;
        int steps = 0;
        while (n != 1) {
          if (!(n >= 1 && n <= 100000 && dp[n] != 0)) {
            if (n%2 == 0)
              n = n/2;
            else
              n = 3*n + 1;
            nums.push_back(n);
            steps++;
          }
          else {
            break;
          }
        }
        dp[i] = steps + dp[n];
        maxx = max(maxx, dp[i]);
        for (int j = 0; j < int(nums.size()); j++) {
          if (nums[j] >= 1 && nums[j] <= 100000) {
            dp[nums[j]] = dp[i] - (j+1);
          }
        }
      }
    }
    cout << n1 << " " << k1 << " " << maxx << endl;
  }
}
