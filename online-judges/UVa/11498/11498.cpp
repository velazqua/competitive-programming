/* Alex Velazquez
 * Start: Sat Jun 29 23:10:48 PDT 2013
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  int K;
  while (cin >> K) {
    if (!K)
      break;
    int ox, oy;
    cin >> ox >> oy;
    REP(t, K) {
      int x, y;
      cin >> x >> y;
      if (x == ox || y == oy)
        cout << "divisa" << endl;
      else if (x > ox) {
        if (y > oy)
          cout << "NE" << endl;
        else
          cout << "SE" << endl;
      }
      else {
        if (y > oy)
          cout << "NO" << endl;
        else
          cout << "SO" << endl;
      }
    }
  }
}
