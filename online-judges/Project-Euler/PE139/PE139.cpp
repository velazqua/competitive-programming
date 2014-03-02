#include <iostream>

using namespace std;

int gcd (int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main ()
{
  // generate all pythagorean triples
  int upper_bound = 7071;
  int limit = 100000000;
  int small_bound = 10;
  int small_limit = 100;
  unsigned long long answer = 0;
  for (int m = 2; m <= upper_bound; m++) {
    for (int n = m-1; n >= 1; n -= 2) {
      if (gcd(m, n) == 1) {
        int a = m*m-n*n;
        int b = 2*m*n;
        int c = m*m+n*n;
        if (c*c % abs(a-b) == 0) {
          answer += limit/(2*m*(m+n));
          if (limit % (2*m*(m+n)) == 0)
            answer--;
          /*
          for(int k = 1; ; k++) {
            if (k*(a+b+c) > small_limit) {
              break;
            }
            cout << k*a << " " << k*b << " " << k*c << " = " << k*(a+b+c) << endl;
          }
          */
        }
      }
    }
  }
  cout << answer << endl;
}
