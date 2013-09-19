/* Alex Velazquez
 * Start: Sat Sep 15 16:22:36 EDT 2012
 * End  :
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
	int size = SZ( P );
	int T;
	scanf( "%d", &T );
	REP( t, T )
	{
		if( t != 0 )
			cout << endl;
		int a, b;
		scanf( "%d %d", &a, &b );
		if( b < 31623 )
		{
			vector<int>::iterator it = lower_bound( P.begin(), P.end(), a, less<int>() );
			for( ; it != P.end(); ++it )
			{
				if( *it > b )
					break;
				printf( "%d\n", *it );
			}
		}
		else
		{
			if( a == 1 )
				a++;
			
			if( a%2 == 0 )
			{
				if( a == 2 )
					printf( "2\n" );
				a++;
			}
			
			for( int p=a; p<=b; p+=2 )
			{
				bool isPrime = true;
				REP( k, size )
				{
					int X = P[k]*P[k];
					if( X > p )
						break;
					if( p % P[k] == 0 )
					{
						isPrime = false;
						break;
					}
				}
				if( isPrime )
					printf( "%d\n", p );
			}
		}
	}
}
