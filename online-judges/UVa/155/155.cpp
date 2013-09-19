/* Alex Velazquez
 * Start: Sun Feb 26 00:13:35 EST 2012
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
#define DEBUG 1

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPointInSquare( double x, double y, double cx, double cy, double s )
{
	return ( x>=cx-s/2 && x<=cx+s/2 && y>=cy-s/2 && y<=cy+s/2 ) ? true : false;
}

int find( int k, int x, int y, int cx, int cy )
{
	#if DEBUG
		cout << "Called: " << k << " " << x << " " << y << " " << cx << " " << cy << endl;
	#endif
	if( k == 0 ) 
		return 0;
	int side = 2*k+1;
	int add = 0;
	if( isPointInSquare( x, y, cx, cy, side ) )
		++add;
	#if DEBUG
		cout << "add: " << add << endl;
	#endif
	if( isPointInSquare( x, y, cx-side/2, cy-side/2, 2*(k/2)+1 ) )
		return add + find( k/2, x, y, cx-side/2, cy-side/2 );
	else if( isPointInSquare( x, y, cx-side/2, cy+side/2, 2*(k/2)+1  ) ) 
		return add + find( k/2, x, y, cx-side/2, cy+side/2 );
	else if( isPointInSquare( x, y, cx+side/2, cy-side/2, 2*(k/2)+1  ) ) 
		return add + find( k/2, x, y, cx+side/2, cy-side/2 );
	else
		return add + find( k/2, x, y, cx+side/2, cy+side/2 );
}

int main ()
{
	int k, x, y;
	while( cin >> k >> x >> y )
	{
		int answer = find( k, x, y, 1024, 1024 );
		cout << answer << endl;
	}
}
