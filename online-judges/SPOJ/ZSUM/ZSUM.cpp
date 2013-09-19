/* Alex Velazquez
 * Start: Fri Aug 24 22:32:37 EDT 2012
 * End  : Fri Aug 24 22:40:56 EDT 2012
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
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

LL square( LL x )
{
	return x*x;
}

LL bigMod( LL B, LL P, LL M )
{
	if( P == 0 )
		return 1;
	else if( P == 1 )
		return B%M;
	else
	{
		if( P%2 == 0 )
			return square( bigMod( B, P/2, M )%M )%M;
		else
			return ((square( bigMod( B, P/2, M )%M )%M)*(B%M))%M;
	}
}

int main ()
{
	LL MOD = 10000007;
	LL n, k;
	while( cin >> n >> k )
	{
		if( !n && !k )
			break;
		cout << ( ( 2LL*bigMod( n-1, k, MOD )) % MOD + ( 2LL*bigMod( n-1, n-1, MOD )) % MOD + bigMod( n, k, MOD ) + bigMod( n, n, MOD ) ) % MOD << endl;
	}
}
