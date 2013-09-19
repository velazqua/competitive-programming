/* Alex Velazquez
 * Start: Sun Apr 22 14:38:01 EDT 2012
 * End  : Sun Apr 22 14:57:13 EDT 2012
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

void rotate90( vector<string> &V, int n )
{
	vector<string> T( V.begin(), V.end() );
	REP( i, n )
		REP( j, n )
			V[j][n-i-1] = T[i][j];
}

bool areEqual( vector<string> &bigSquare, vector<string> &lilSquare, int x, int y, int n )
{
	REP( i, n )
		REP( j, n )
			if( bigSquare[x+i][y+j] != lilSquare[i][j] )
				return false;
	return true;
}

int countAppearances( vector<string> &bigSquare, vector<string> &lilSquare, int const& N, int const& n )
{
	int counter = 0;
	FOR( i, 0, N-n+1 )
		FOR( j, 0, N-n+1 )
			if( areEqual( bigSquare, lilSquare, i, j, n ) )
				++counter;
	return counter;
}

int main ()
{
	int N, n;
	while( cin >> N >> n )
	{
		if( N == 0 && n == 0 ) break;
		vector<string> bigSquare( N ), lilSquare( n );
		REP( i, N )
			cin >> bigSquare[i];
		REP( i, n )
			cin >> lilSquare[i];
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
		// no rotation
		a1 = countAppearances( bigSquare, lilSquare, N, n );
		
		// rotate 90 degrees
		rotate90( lilSquare, n );
		a2 = countAppearances( bigSquare, lilSquare, N, n );
		
		// rotate 180 degrees
		rotate90( lilSquare, n );
		a3 = countAppearances( bigSquare, lilSquare, N, n );
		
		// rotate 270 degrees
		rotate90( lilSquare, n );
		a4 = countAppearances( bigSquare, lilSquare, N, n );
		
		cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
	}
}
