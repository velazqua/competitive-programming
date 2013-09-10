#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ulld;

ulld countWays (int N, vector<ulld>& dp) {
  if (N < -2)
    return 0;
  else if (N == -1)
    return 1;
  else if (dp[N] != 1)
    return dp[N];
  else {
    ulld temp = 0;
    for (int i = 0; i <= N; i++) {
      for (int b = 3; b <= N; b++) {
        temp += countWays(N-b-i-1, dp);
      }
    }
    dp[N] = temp+1;
    return dp[N];
  }
}

int main ()
{
  vector<ulld> dp(51, 1);
  dp[0]=1; dp[1]=1; dp[2]=1; dp[3]=2; dp[4]=4;
  for (int i = 0; i < 51; i++) {
    cout << "i: " << i << " -> " << countWays(i, dp) << endl;
  }
}
