/* Alex Velazquez
 * Start: Sat Mar 24 22:28:41 EDT 2012
 * End  : Sat Mar 24 22:57:39 EDT 2012
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

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main ()
{
	// 1D DP solution
	vector<int> G( 501, 0 );
	G[2] = 1;
	FOR( i, 3, 501 )
	{
		G[i] = G[i-1];
		FOR( j, 1, i )
			G[i] += GCD( i, j );
	}
			
	int N;
	while( scanf( "%d", &N ) )
	{
		if( !N ) break;
		printf( "%d\n", G[N] );
	}
}
