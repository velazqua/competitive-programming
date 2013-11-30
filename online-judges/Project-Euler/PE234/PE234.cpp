#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ulld;

void sieve (vector<bool> &p) {
  int t = p.size();
  for (int i = 3; i < t; i += 2) {
    p[i] = true;
    p[i-1] = false;
  }
  p[0] = p[1] = false;
  p[2] = true;
  int r = ceil(sqrt(t));
  if ((t&1) == 1) p[t-1] = false;
  for (int i = 3; i < r; i += 2) {
    if (p[i]) {
      for (int j = 3; j*i < t; j += 2) {
        p[j*i] = false;
      }
    }
  }
}

ulld multiples (ulld a, ulld b, ulld LIMIT) {
  ulld first = a*a;
  ulld second = b*b;
  ulld summ = 0;
  for(ulld i = first/a; a * i <= second && a * i < LIMIT; i++) {
    if (a * i < first) continue;
    if (a * i == first) continue;
    if (a * i == a * b) continue;
    if (a * i == second) break;
    summ += a * i;
  }
  for(ulld i = first/b; b * i <= second && b * i < LIMIT; i++) {
    if (b * i < first) continue;
    if (b * i == first) continue;
    if (b * i == a * b) continue;
    if (b * i == second) break;
    summ += b * i;
  }
  return summ;
}

int main ()
{
  ulld LIMIT = 1000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  vector<int> P;
  P.push_back(2);
  for(int i = 3; i < LIMIT; i += 2) {
    if (primes[i]) P.push_back(i);
  }
  ulld answer = 0;
  for(int i = 0; i < P.size()-1; i++) {
    ulld a = P[i], b = P[i+1];
    ulld m = multiples(a, b, 999966663333);
    answer += m;
  }
  cout << answer << endl;
}
