/* Alex Velazquez
 * Start: Tue Jul  3 20:18:00 EDT 2012
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
#define DEBUG        1

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPrime( int X, vector<bool>& primes, vector<int> &P, int size )
{
	if( X <= 1 )
		return false;
	if( X <= 31623 )
		return !primes[X];
	else
	{
		for( int i=0; i<size; ++i )
			if( X % P[i] == 0 )
				return false;
		return true;
	}
}

int gcd( int a, int b )
{
	while( b != 0 )
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void calcPhi( map<int,int> &M, int N, vector<bool> &primes, vector<int> &P, int size )
{
	#if DEBUG
		cout << " => " << N << endl;
	#endif
	if( M[N] == 0 )
		M[N] = 1;
	else
		return;
	if( N%2 == 0 )
	{
		int m = N/2;
		if( m%2 == 0 )
			M[N] *= 2;
		calcPhi( M, m, primes, P, size );
		M[N] *= M[m];
	}
	else if( isPrime( N, primes, P, size ) )
		M[N] *= N-1;
	else
	{
		// find pair of factors x,y of N such that x*y = N
		for( int i=0; i<size; ++i )
		{
			if( N%P[i] == 0 )
			{
				int m = P[i];
				int n = N/P[i];
				if( m == n )
				{
					calcPhi( M, m, primes, P, size );
					M[N] *= m;
					M[N] *= M[m];
				}
				else
				{
					int d = gcd( m, n );
					calcPhi( M, m, primes, P, size );
					calcPhi( M, n, primes, P, size );
					calcPhi( M, d, primes, P, size );
					M[N] = M[m]*M[n]*(d/M[d]);
				}
			}
		}
	}
}

int main ()
{
    unsigned int lim = 31623, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> P;
    for (i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
	int size = P.size();
	int N;
	map<int,int> M;
	while( cin >> N )
	{
		if( !N )
			break;
		calcPhi( M, N, primes, P, size );
		cout << M[N] << endl;
	}
}
