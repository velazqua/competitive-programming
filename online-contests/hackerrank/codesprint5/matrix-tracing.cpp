#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define DEBUG 1
typedef unsigned long long ulld;

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

void prime_factorize(int N, vector<int> &V, vector<int> &P, int size) {
  if (N <= 1)
    return;
  for(int n = N; n >= 2; n--) {
    int num = n;
    for(int i = 0; i < size; i++) {
      if (num == 1)
        break;
      while (num % P[i] == 0) {
        num /= P[i];
        V[i]++;
      }
    }
  }
}

void calc_stuff(int N, vector< vector<int> > &mp, vector<int> &P, int size, vector<bool>& primes) {
  if (N <= 1)
    return;
  vector<int> prev(size+1, 0);
  mp.push_back(prev);
  mp.push_back(prev);
  prev[0]++;
  mp.push_back(prev);
  for(int n = 3; n <= N; n++) {
    int num = n;
    for(int i = 0; i < size; i++) {
      if (num == 1)
        break;
      //if (primes[num]) {
      //  prev[num]++;
      //  break;
      //}
      while (num % P[i] == 0) {
        num /= P[i];
        prev[i]++;
      }
    }
    mp.push_back(prev);
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
  int size = P.size();

  vector< vector<int> > mp;
  int S = 1000;
  calc_stuff(S, mp, P, size, primes);
#if DEBUG
    cout << S << "!: " << endl;
    for(int i = 0; i < size; i++) {
      if (mp[S][i] > 0) {
        cout << P[i] << "^" << mp[S][i] << " * ";
      }
    }
    cout << endl;
#endif
 
  cout << "done" << endl;
  return 0;
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int m, n;
    cin >> m >> n;
    vector<int> primesMN, primesM, primesN;
    primesMN = mp[m+n-2]; //prime_factorize(m+n-2, primesMN, P, size);
    primesM  = mp[m-1]; //prime_factorize(m-1, primesM,  P, size);
    primesN  = mp[n-1]; //prime_factorize(n-1, primesN,  P, size);
#if DEBUG
    cout << m-1 << "!: " << endl;
    for(int i = 0; i < size; i++) {
      if (primesM[i] > 0) {
        cout << P[i] << "^" << primesM[i] << " * ";
      }
    }
    cout << endl;
#endif
    for(int i = 0; i < size; i++) {
      primesMN[i] -= primesM[i];
      primesMN[i] -= primesN[i];
    }
    ulld ans = 1;
    for(int i = 0; i < size; i++) {
      for(int j = 0; j < primesMN[i]; j++) {
        ans *= P[i];
        ans %= 1000000007;
      }
    }
    cout << ans << endl;
  }
}
