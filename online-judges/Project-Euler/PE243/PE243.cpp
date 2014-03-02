#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd (int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % t;
    a = t;
  }
  return a;
}

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

vector<pair<int,int>> factor_decomp (int X, vector<int>& primes) {
  vector<pair<int,int>> pv;
  for(auto& p : primes) {
    if (X == 1)
      return pv;
    int exp = 0;
    while (X % p == 0) {
      X /= p;
      exp++;
    }
    if (exp > 0)
      pv.push_back(make_pair(p, exp));
  }
  return pv;
}

void display_decomp (int X, vector<pair<int,int>>& decomp) {
  cout << X << " = ";
  bool f = false;
  for(auto &p : decomp) {
    if (!f) {
      f = true;
    }
    else {
      cout << " + ";
    }
    cout << p.first << "^" << p.second;
  }
  cout << endl;
}

int euler_phi (int X, vector<int>& primes) {
  auto factors = factor_decomp(X, primes);
  int ans = X;
  for(auto& p : factors) {
    ans /= p.first;
    ans *= (p.first-1);
  }
  return ans;
}

pair<int,int> R (int X, vector<int>& primes) {
  int phi = euler_phi(X, primes);
  int g = gcd(phi, X-1);
  return make_pair(phi/g, (X-1)/g);
}

bool comp_fraction (pair<int,int> &A, pair<int,int> &B) {
  return (unsigned long long)A.first * B.second < (unsigned long long)B.first * A.second;
}


int main ()
{
  int LIMIT = 10000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  vector<int> P;
  P.push_back(2);
  for (int i = 3; i < LIMIT; i += 2) {
    if (primes[i])
      P.push_back(i);
  }

  pair<int,int> d = {15499, 94744};
  for(int i = 1; i <= 10000000; i++) {
    auto res = R(i, P);
    cout << i << " => " << res.first << "/" << res.second << endl;
    if (comp_fraction(res, d)) {
      cout << "Answer is: " << i << endl;
      break;
    }
  }
}
