/* Alex Velazquez
 * Start: Sun Sep 29 21:19:39 EDT 2013
 * End  : Sun Sep 29 21:26:18 EDT 2013
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
  int n;
  while (cin >> n) {
    if (!n)
      break;
    int a = 0, b = 0;
    int turn = 0;
    while (n) {
      // get least significant bit that is set
      int x = n & ~(n-1);

      // set this bit on appropriate number (a or b)
      ((turn++ % 2) ? b : a) |= x;

      // clear bit on n
      n &= (n-1);
    }
    cout << a << " " << b << endl;
  }
}
