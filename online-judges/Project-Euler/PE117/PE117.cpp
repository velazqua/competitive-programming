#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ulld;

ulld countWays (int N, vector<ulld>& dp) {
  if (dp[N] != 0)
    return dp[N];
  else {
    dp[N] = countWays(N-1, dp) + 
            countWays(N-2, dp) + 
            countWays(N-3, dp) + 
            countWays(N-4, dp);
    return dp[N];
  }
}

int main ()
{
  vector<ulld> dp(51, 0);
  dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4; dp[4] = 8;
  for (int i = 0; i <= 50; i++) {
    cout << "i: " << i << " -> " << countWays(i, dp) << endl;
  }
}
