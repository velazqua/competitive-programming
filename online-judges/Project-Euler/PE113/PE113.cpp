#include <iostream>
#include <vector>

using namespace std;

typedef long long int lld;

int main ()
{
  lld NUM_DIGITS = 100; // 10^100 has 101 digits
  vector<vector<lld>> incr(101, vector<lld>(10, 0));
  vector<vector<lld>> decr(101, vector<lld>(10, 0));
  for(int i = 0; i <= 9; i++) {
    incr[1][i] = 1;
    decr[1][i] = 1;
  }
  decr[1][0] = 0;

  // Increasing numbers DP
  for(int d = 2; d <= NUM_DIGITS; d++) {
    for(int lastDigit = 1; lastDigit <= 9; lastDigit++) {
      for(int k = 1; k <= lastDigit; k++) {
        incr[d][lastDigit] += incr[d-1][k];
      }
    }
  }

  // Decreasing numbers DP
  for(int d = 2; d <= NUM_DIGITS; d++) {
    for(int lastDigit = 0; lastDigit <= 9; lastDigit++) {
      for(int k = lastDigit; k <= 9; k++) {
        decr[d][lastDigit] += decr[d-1][k];
      }
    }
  }

  decr[1][0] = 1;
  
  // Remove increasing & decreasing numbers
  lld duplicates = NUM_DIGITS * 9 + 1;

  lld total = 0;
  for(int d = 1; d <= NUM_DIGITS; d++) {
    for(int i = 0; i <= 9; i++) {
      total += incr[d][i] + decr[d][i];
    }
  }

  total -= duplicates;
  cout << total-1 << endl;
}
