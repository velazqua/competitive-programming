/* Alex Velazquez
 * Start: Sun Sep 29 17:45:41 EDT 2013
 * End  : Sun Sep 29 17:48:23 EDT 2013
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
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case " << t+1 << ": ";
    int N;
    cin >> N;
    int maxx = 0;
    REP(i, N) {
      int num;
      cin >> num;
      maxx = max(maxx, num);
    }
    cout << maxx << endl;
  }
}
