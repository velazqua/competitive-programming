#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ulld;

ulld countWays (int N, vector<ulld>& dp, int blocks) {
  if (N < -2)
    return 0;
  else if (N == -1)
    return 1;
  else if (dp[N] != 1)
    return dp[N];
  else {
    ulld temp = 0;
    for (int i = 0; i <= N; i++) {
      for (int b = blocks; b <= N; b++) {
        temp += countWays(N-b-i-1, dp, blocks);
      }
    }
    dp[N] = temp+1;
    return dp[N];
  }
}

int main ()
{
  int NUM = 50;
  vector<ulld> dp(1000, 1);
  dp[NUM] = 2;
  for (int i = 0; i < 1000; i++) {
    cout << "i: " << i << " -> " << countWays(i, dp, NUM) << endl;
  }
}
