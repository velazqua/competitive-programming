/* Alex Velazquez
 * Start: Mon Oct 29 15:44:48 EDT 2012
 * End  : Mon Oct 29 23:46:06 EDT 2012
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
      long long a, b, c;
      cin >> a >> b >> c;
      vector<long long> nums(3);
      nums[0] = a;
      nums[1] = b;
      nums[2] = c;
      cout << "Case " << t+1 << ": ";
      sort(nums.begin(), nums.end());
      if ( a <= 0 || b <= 0 || c <= 0 || nums[0]+nums[1] <= nums[2]) {
         cout << "Invalid" << endl;
      }
      else if (a == b && b == c) {
         cout << "Equilateral" << endl;
      }
      else if ((a == b && a != c) ||
               (a == c && a != b) ||
               (b == c && a != b) ) {
         cout << "Isosceles" << endl;
      }
      else {
         cout << "Scalene" << endl;
      }
   }
}
