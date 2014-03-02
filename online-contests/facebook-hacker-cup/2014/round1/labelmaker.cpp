#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ulld;

char nextLetter (ulld jump, ulld N, string const& L, ulld size, ulld currSum) {
  if (N <= currSum) {
    return ' ';
  }
  else {
    return L[(N-1-currSum)/(jump) % size];
  }
}

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    string L;
    ulld N;
    cin >> L >> N;
    string ans;
    int size = L.size();
    ulld currPower = 1;
    ulld currSum = 0;
    for(int i = 0; ; i++) {
      char nextChar = nextLetter(currPower, N, L, size, currSum);
      if (nextChar != ' ') {
        ans += nextChar;
      }
      else {
        break;
      }
      currPower *= size;
      currSum += currPower;
    }
    reverse(ans.begin(), ans.end());
    cout << "Case #" << t+1 << ": " << ans << endl;
  }
}
