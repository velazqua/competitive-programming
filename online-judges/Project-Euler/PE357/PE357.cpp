#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

bool satisfiesProperty (int num, vector<bool>& primes) {
  for(int a = 1; ; a++) {
    if (num % a == 0) {
      int b = num/a;
      if (!primes[a+num/a] || !primes[b+num/b])
        return false;
      if (a >= b)
        return true;
    }
  }
  return true;
}

int main ()
{
  int LIMIT = 100000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  unsigned long long summ = 1;
  for(int num = 2; num <= 100000000; num += 4) {
    if (satisfiesProperty(num, primes)) {
      cout << num << endl;
      summ += num;
    }
  }
  cout << summ << endl;
}
