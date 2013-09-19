/* Alex Velazquez
 * Start: Fri Feb 17 21:55:25 EST 2012
 * End  : Fri Feb 17 22:37:05 EST 2012
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

long long  F( long long  x, vector<long long > &M )
{
	//cout << "F( " << x << ") " << endl;
	if( x == 1 )
		return 0;
	if( x<=100000 && M[x] != -1 )
		return M[x];
	else
	{
		if( x <= 100000 )
		{
			if( x%2 == 0 )
			{
				M[x] = 1 + F( x/2, M );
				return M[x];
			}
			else
			{
				M[x] = 1 + F( 3*x+1, M );
				return M[x];
			}
		}
		else
		{
			if( x%2 == 0 )
				return 1 + F( x/2, M );
			else
				return 1 + F( 3*x+1, M );
		}
	}
}

int main ()
{
	// precalculate from 1 to 100,000
	vector<long long > M( 100001, -1 );
	M[1] = 3;
	for( long long  i=2; i<=100000; ++i )
	{
		//cout << "Calculating " << i << ": " << endl;
		M[i] = F( i, M );
	}
	
	long long  L, H, V;
	while( cin >> L >> H )
	{
		if( L == 0 && H == 0 ) break;
		long long  maxx = 0;
		long long  l = L, h = H;
		L = min( l, h );
		H = max( l, h );
		for( long long  i=L; i<=H; ++i )
		{
			long long  f = F( i, M );
			if( i == 1 ) f = 3;
			if( f > maxx ) 
			{
				maxx = f;
				V = i;
			}
		}
		cout << "Between " << L << " and " << H << ", " << V;
		cout << " generates the longest sequence of " << maxx << " values." << endl; 
	}
}
