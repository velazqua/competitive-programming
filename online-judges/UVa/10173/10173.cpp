/* Alex Velazquez
 * Start: Tue Jul  3 21:20:26 EDT 2012
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

int main ()
{
	int N;
	while( cin >> N )
	{
		if( !N )
			break;
		double xlow;
		double xhigh;
		double ylow;
		double yhigh;
		double x, y;
		REP( i, N )
		{
			cin >> x >> y;
			if( i == 0 )
				xlow = x, xhigh = x, ylow = y, yhigh = y;
			else
			{
				xlow = min( xlow, x );
				xhigh = max( xhigh, x );
				ylow = min( ylow, y );
				yhigh = max( yhigh, y );
			} 
		}
		printf( "%.4f\n", (xhigh-xlow)*(yhigh-ylow) );
	}
}
