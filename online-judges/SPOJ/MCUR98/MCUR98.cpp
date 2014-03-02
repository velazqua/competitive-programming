/* Alex Velazquez
 * Start: Sun Sep 29 22:05:12 EDT 2013
 * End  :
*/
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int sumDigits (int N) {
  int summ = 0;
  while (N) {
    summ += N % 10;
    N /= 10;
  }
  return summ;
}

int d (int N) {
  return N + sumDigits(N);
}

int main ()
{
  // prime sieve approach: start at 1, generate all of its
  // d(n) until we reach a million.
  vector<bool> selfNumbers(1000001, true);
  int prev = 0;
  set<int> diff;
  for(int i = 1; i < 1000000; i++) {
    if (selfNumbers[i]) {
      printf("%d %d\n", i, i-prev);
      diff.insert(i-prev);
      prev = i;
      // generate i's sequence
      int x = d(i);
      while (x <= 1000000 && selfNumbers[x] == true) {
        selfNumbers[x] = false;
        x = d(x);
      }
    }
  }
  for(set<int>::iterator it = diff.begin();
      it != diff.end();
      it++) {
    printf("%d\n", *it);
  }
}
