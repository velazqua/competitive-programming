/* Alex Velazquez
 * Start: Wed Oct 31 14:57:15 EDT 2012
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

int side (int xa, int ya, int xb, int yb, int xc, int yc) 
{
	return (xb - xa) * (yc - ya) - (xc - xa) * (yb - ya);
}

int main ()
{
   int N;
   while (cin >> N) {
      if (!N)
         break;
      vector< pair<int,int> > points;
      REP( i, N ) {
         int x, y;
         cin >> x >> y;
         points.PB(make_pair(x, y));
      }
      
      bool good = true;
      int dir = 0;
      for( int i=0; i<N; ++i ) {
         int x1 = points[i].first, y1 = points[i].second;
         int x2 = points[(i+1+N)%N].first, y2 = points[(i+1+N)%N].second;
         int x3 = points[(i-1+N)%N].first, y3 = points[(i-1+N)%N].second;
         int x = side(x1, y1, x2, y2, x3, y3);
         if (dir != 0)
         {
            if (dir > 0 && x < 0 || dir < 0 && x > 0)
               good = false;
         }
         else {
            dir = x > 0 ? 1 : -1;
         }
      }
      if (good)
         cout << "No" << endl;
      else
         cout << "Yes" << endl;
   }
}
