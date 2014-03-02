#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int N, K, C;
    cin >> N >> K >> C;
    cout << "Case #" << t+1 << ": ";
    if (K >= N) {
      int coinsPerJar = K / N;
      int leftOvers = K % N;
      int steps = 0;
      if (C <= coinsPerJar * N) {
        cout << C << endl;
      }
      else {
        steps += coinsPerJar * N;
        steps += C - steps;
        steps += N - 1;
        cout << steps << endl;
      }
    }
    else {
      int steps = 0;
      steps += N - K;
      steps += C;
      cout << steps << endl;
    }
  }
}
