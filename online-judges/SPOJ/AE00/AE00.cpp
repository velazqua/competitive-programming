/* Alex Velazquez
 * Start: Thu Apr 25 22:53:12 EDT 2013
 * End  : Thu Apr 25 23:10:44 EDT 2013
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int findWays (int start, int end, int num) {
  if (start * start > num)
    return 0;
  int p = start;
  int mid;
  while (1) {
    mid = (start+end)/2;
    if (p*mid <= num && p*(mid+1) > num) {
      return mid;
    }
    if (p*mid <= num) {
      start = mid+1;
    }
    else {
      end = mid-1;
    }
  }
}

int main ()
{
  int N;
  cin >> N;
  int ways = 0;
  for (int i = 1; i <= N; i++) {
    int w = findWays(i, N, N);
    if (!w)
      break;
    ways += w - (i-1);
  }
  cout << ways << endl;
}
