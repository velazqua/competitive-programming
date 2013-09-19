/* Alex Velazquez
 * Start: Sun Mar 11 20:54:39 EDT 2012
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
typedef unsigned long long ULL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ULL powerr( ULL x, int n )
{
	if( n == 0 )
		return 1ULL;
	ULL ans = 1ULL;
	for( int i=0; i<n; ++i )
		ans *= x;
	return ans;
}

int main ()
{
	set<ULL> SP;
	set<ULL> D;
	ULL MAXX = powerr( 2ULL, 64 )-1;
	for( int i=0; i<64; ++i )
	{
		ULL x = powerr( 2ULL, i );
		cout << x << endl;
		D.insert( x );
	}
	
}
