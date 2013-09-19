/* Alex Velazquez
 * Start: Sun Sep  1 19:22:25 EDT 2013
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

int toDecimal (string S) {
  int size = S.size();
  int poww = size;
  int res = 0;
  for(int i = 0; i < size; i++) {
    res += (S[i]-48) * ((1 << (poww)) -1);
    poww--;
  }
  return res;
}

int main ()
{
  string S;
  while (cin >> S) {
    if (!S.compare("0"))
      break;
    int ans = toDecimal(S);
    cout << ans << endl;
  }
}
