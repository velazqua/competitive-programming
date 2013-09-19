/* Alex Velazquez
 * Start: Thu Nov  1 12:19:25 EDT 2012
 * End  : Thu Nov  1 12:29:31 EDT 2012
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

double area (double a, double b, double c) {
   double p = (a+b+c)/2.0;
   return sqrt(p)*sqrt(p-a)*sqrt(p-b)*sqrt(p-c);
}

int main ()
{
   int T;
   scanf("%d", &T);
   REP( t, T ) {
      int N;
      scanf("%d", &N);
      vector<double> nums(N);
      REP( i, N ) {
         scanf( "%lf", &nums[i]);
      }
      sort(nums.begin(), nums.end());
      double maxx = 0.00;
      for( int i=0; i<=N-3; ++i ) {
         if (nums[i]+nums[i+1]>nums[i+2])
            maxx = max(maxx, area(nums[i], nums[i+1], nums[i+2]));
      }
      printf( "%.2f\n", maxx );
   }
}
