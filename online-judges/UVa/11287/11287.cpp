/* Alex Velazquez
 * Start: Sat Sep 22 20:26:33 EDT 2012
 * End  : Sat Sep 22 20:42:12 EDT 2012
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

LL square( LL x )
{
	return x*x;
}

LL bigMod( LL B, LL P, LL M )
{
	if( P == 0LL )
		return 1LL;
	else if( P == 1LL )
		return B%M;
	else
	{
		if( P%2 == 0LL )
			return square( bigMod( B, P/2LL, M )%M )%M;
		else
			return ((square( bigMod( B, P/2LL, M )%M )%M)*(B%M))%M;
	}
}

bool isPrime( LL N, vector<bool>& primes, vector<int> &P, int size )
{
	if( N < 1000000LL )
		return !primes[N];
	else
	{
		for( int i=0; i<size; ++i )
		{
			if( P[i]*P[i] > N )
				return true;
			if( N % P[i] == 0LL )
				return false;
		}
		return true;
	}
}

int main ()
{
	unsigned int lim = 1000000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
	primes[0] = true;
	primes[1] = true;
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> P;
    for (i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
	int size = SZ(P);

	LL p, a;
	while( cin >> p >> a )
	{
		if( !p && !a )
			break;
		if( isPrime( p, primes, P, size ) )
			cout << "no" << endl;
		else if( bigMod( a, p, p ) == a )
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
