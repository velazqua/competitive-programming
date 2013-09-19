/* Alex Velazquez
 * Start: Mon Oct 29 14:28:36 EDT 2012
 * End  : Mon Oct 29 14:35:04 EDT 2012
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
   int T;
   cin >> T;
   REP( t, T ) {
      int N;
      cin >> N;
      vector<int> nums(N);
      REP( i, N ) {
         cin >> nums[i];
      }
      int minn = nums[N-1];
      int maxx = -2000000000;
      if (N == 1) {
      }
      for( int i=N-2; i >= 0; --i) {
         maxx = max(maxx, nums[i]-minn);
         minn = min(minn, nums[i]);
      }
      cout << maxx << endl;
   }
}
