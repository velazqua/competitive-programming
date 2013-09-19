/* Alex Velazquez
 * Start: Thu Nov  1 20:59:44 EDT 2012
 * End  : Thu Nov  1 21:02:38 EDT 2012
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
   int N;
   cin >> N;
   REP( i, N ) {
      vector<int> nums(3);
      REP( j, 3 ) {
         cin >> nums[j];
      }
      sort(ALL(nums));
      if (nums[0]+nums[1]<=nums[2])
         cout << "Wrong!!" << endl;
      else
         cout << "OK" << endl;
   }
}
