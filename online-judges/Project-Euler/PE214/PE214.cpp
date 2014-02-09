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

int calc_chain_length(int num, vector<int>& phi, vector<bool>& primes, vector<int>& P) {
  if (num == 1) return 1;
  if (phi[num] != -1) return phi[num];
  if (primes[num]) {
    phi[num] = 1 + calc_chain_length(num-1, phi, primes, P);
    return phi[num];
  }
  else {
    int eu = euler_phi(num, P);
    phi[num] = 1 + calc_chain_length(eu, phi, primes, P);
    return phi[num];
  }
}

int main ()
{
  int LIMIT = 40000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  vector<int> P;
  P.push_back(2);
  for (int i = 3; i < LIMIT; i += 2) {
    if (primes[i])
      P.push_back(i);
  }

  vector<int> phi(LIMIT+1, -1);
  unsigned long long ans = 0;
  for(auto& p : P) {
    phi[p] = calc_chain_length(p, phi, primes, P);
    if (phi[p] == 25)
      ans += p;
  }
  cout << ans << endl;
}
