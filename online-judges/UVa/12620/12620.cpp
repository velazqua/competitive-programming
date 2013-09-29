/* Alex Velazquez
 * Start: Sun Sep 29 17:52:00 EDT 2013
 * End  : Sun Sep 29 18:22:20 EDT 2013
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

int main ()
{
  int a = 1, b = 1, c = 2;
  vector<ulld> sumsToN(310);
  sumsToN[0] = 0;
  sumsToN[1] = 1;
  sumsToN[2] = 2;
  int counter = 3;
  ulld summ = 2;
  for(int i = 0; ; i++) {
    c = (a + b)%100;
    summ += c;
    sumsToN[counter++] = summ;
    a = b;
    b = c;
    if (a == 1 && b == 1)
      break;
  }
  int T;
  cin >> T;
  REP(t, T) {
    ulld N, M;
    cin >> N >> M;
    N--;
    cout << (M/300)*sumsToN[300]+sumsToN[M%300]-((N/300)*sumsToN[300]+sumsToN[N%300]) << endl;
  }
}
