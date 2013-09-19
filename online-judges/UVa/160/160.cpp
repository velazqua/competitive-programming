/* Alex Velazquez
 * Start: Sun Sep  8 17:01:10 EDT 2013
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

void factorIt(int X, vector<int>& ans, int* primes) {
  for(int i = 0; i < 25; i++) {
    while (X > 1 && X % primes[i] == 0) {
      ans[i]++;
      X /= primes[i];
    }
  }
}

void printIt(int N) {
  if (N == 100)
    cout << N;
  else if (N < 10)
    cout << "  " << N;
  else
    cout << " " << N;
}


int findFirstNonZero(vector<int> &ans) {
  for(int i = 24; i >= 0; i--) {
    if (ans[i] != 0)
      return i+1;
  }
}

int main ()
{
  int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  int N;
  while (cin >> N) {
    if (N == 0)
      break;
    vector<int> ans(25, 0);
    for(int i = N; i >= 2; i--) {
      factorIt(i, ans, primes);
    }
    printIt(N);
    cout << "! =";
    int s = findFirstNonZero(ans);
    for(int i = 0; i < s; i++) {
      if (i == 15)
        cout << endl << "      ";
      printIt(ans[i]);
    }
    cout << endl;
  }
}
