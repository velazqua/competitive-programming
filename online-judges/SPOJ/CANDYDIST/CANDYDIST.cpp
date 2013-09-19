/* Alex Velazquez
 * Start: Wed Feb 15 21:30:43 EST 2012
 * End  : Wed Feb 15 21:44:41 EST 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;


int main ()
{
	int N;
	while( scanf( "%d", &N ) )
	{
		if( N == 0 ) break;
		vector<LL> C( N ), P( N );
		REP( i, N ) scanf( "%lld", &C[i] );
		REP( i, N ) scanf( "%lld", &P[i] );
		sort( C.begin(), C.end() );
		sort( P.begin(), P.end(), greater<LL>() );
		LL result = 0LL;
		REP( i, N ) result += C[i]*P[i];
		printf( "%lld\n", result );
	}
}
