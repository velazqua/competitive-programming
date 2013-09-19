/* Alex Velazquez
 * Start: Fri May  4 23:36:14 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int x1line, x2line, y1line, y2line, x1rect, x2rect, y1rect, y2rect;
		cin >> x1line >> y1line >> x2line >> y2line >> x1rect >> y1rect >> x2rect >> y2rect;
		int maxXline = max( x1line, x2line );
		int minXline = min( x1line, x2line );
		int maxYline = max( y1line, y2line );
		int minYline = min( y1line, y2line );
		int maxXrect = max( x1rect, x2rect );
		int minXrect = min( x1rect, x2rect );
		int maxYrect = max( y1rect, y2rect );
		int minYrect = min( y1rect, y2rect );
		if ( ( maxXline < minXrect ) || 
			 ( minXline > maxXrect ) || 
			 ( minYline > maxYrect ) ||
			 ( maxYline < minYrect )
		   )
			cout << "F" << endl;
		else
			cout << "T" << endl;
	}
}
