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

int f (int x, int p) {
  return ((x*x-3*x)+p)%p;
}

int full_f (int x, int p) {
  return ((x*x-3*x-1)+p*p)%(p*p);
}

int f_prime (int x, int p) {
  return ((2*x-3)+p)%p;
}

vector<int> find_solutions (int p) {
  vector<int> sols;
  int num_sols = 0;
  for(int i = 1; i < p && num_sols < 2; i++) {
    if (f(i, p) == 1) {
      sols.push_back(i);
      num_sols++;
    }
  }
  return sols;
}

int lift (int xo, int p) {
  int f_xo = f_prime(xo, p);
  if (f_xo != 0) {
    int t = ((-1*f_xo*(full_f(xo, p)/p))+p)%p;
    cout << "full_f: " << full_f(xo, p) << ". p: " << p << endl;
    cout << "t: " << t << endl;
    return ((xo + t*p*p)+p*p)%(p*p);
  }
  else {
    if (full_f(xo, p) != 0) {
      return 0;
    }
    else {
      int minn = p*p+1;
      for(int t = 0; t < p; t++) {
        int new_sol = (xo + p*p*t)%(p*p);
        minn = min(minn, new_sol);
      }
      return minn;
    }
  }
}

int main ()
{
  int LIMIT = 1000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  vector<int> P;
  P.push_back(2);
  for (int i = 3; i < LIMIT; i += 2) {
    if (primes[i])
      P.push_back(i);
  }
  for(int i = 0; i < 10; i++) {
    cout << "p:" << P[i] << " has ";
    vector<int> sols_mod_p = find_solutions(P[i]);
    cout << sols_mod_p.size() << " solutions mod p. " << endl;
    for(int k = 0; k < int(sols_mod_p.size()); k++) {
      int try_lift = lift(sols_mod_p[k], P[i]);
      cout << "Solution " << sols_mod_p[k] << " mod p has " << try_lift;
      cout << " as a solution in mod p^2" << endl;
    }
  }
}
