/* Alex Velazquez
 * Start: Sun Sep  1 19:33:10 EDT 2013
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

ulld nCr (ulld n, ulld r) {
  ulld ans = 1;
  r = min(r, n-r);
  for(ulld c = 0; c < r; c++) {
    ans *= n - c;
    ans /= c + 1;
  }
  return ans;
}

int main ()
{
  int n, r;
  while (cin >> n >> r) {
    if (!n && !r)
      break;
    cout << n << " things taken " << r << " at a time is " << nCr(n, r) << " exactly." << endl;
  }
}
