#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long int ulld;

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

vector<ulld> factor(ulld x, vector<int>& P, vector<bool>& primes) {
  if (x <= 20000000 && primes[x])
    return vector<ulld>(1, x);
  vector<ulld> facts;
  for(vector<int>::iterator p = P.begin();
      p != P.end();
      p++) {
    if(x == 1)
      return facts;
    if (*p * *p > x || (x <= 20000000 && primes[x])) {
      facts.push_back(x);
      return facts;
    }
    while (x % *p == 0) {
      x /= *p;
      facts.push_back(*p);
    }
  }
  return facts;
}

void printFactors (vector<ulld>& factors) {
  cout << "{";
  for(vector<ulld>::iterator it = factors.begin();
      it != factors.end();
      it++) {
    cout << ((it != factors.begin()) ? ", " : "") << *it;
  }
  cout << "}" << endl;
}

int main ()
{
  int LIMIT = 20000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  vector<int> P;
  P.push_back(2);
  for (int i = 3; i < LIMIT; i += 2) {
    if (primes[i])
      P.push_back(i);
  }

  ulld fibs1 = 1, fibs2 = 1, fibs3 = 1, num;
  for(int i = 0; i < 71; i++) {
    num = fibs3 + fibs2 + fibs1;
    cout << num << ": ";
    vector<ulld> f = factor(num, P, primes);
    printFactors(f);
    fibs1 = fibs2;
    fibs2 = fibs3;
    fibs3 = num;
  }
}
