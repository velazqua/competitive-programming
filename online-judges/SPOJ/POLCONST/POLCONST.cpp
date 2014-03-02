/* Alex Velazquez
 * Start: Mon Jan  6 06:57:15 EST 2014
 * End  :
*/
#include <iostream>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)

using namespace std;

bool f (int n, int* factors) {
  while (n % 2 == 0) n /= 2;
  REP(i, 5) {
    if (n % factors[i] == 0)
      n /= factors[i];
  }
  return n == 1;
}

int main ()
{
  int fermatPrimes[5] = {3, 5, 17, 257, 65537};
  int T;
  cin >> T;
  REP(t, T) {
    int n;
    cin >> n;
    cout << (f(n, fermatPrimes) ? "Yes" : "No") << endl;
  }
}
