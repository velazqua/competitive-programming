/* Alex Velazquez
 * Start: Sat Jun 30 00:41:56 EDT 2012
 * End  : Sat Jun 30 01:01:20 EDT 2012
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
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
    unsigned int lim = 10000, i, j;
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
	int numPrimes = SZ( P );
	int N;
	while( cin >> N )
	{
		bool first = true;
		vector<int> exp( numPrimes+1, 0 );
		for( int i=0; i<numPrimes && P[i]<=N; ++i )
		{
			for( int j=1; i<numPrimes && P[i]*j<=N; ++j )
			{
				int X = P[i]*j;
				while( X%P[i] == 0 )
					exp[i]++, X /= P[i];
			}
			if( exp[i] > 0 )
			{
				if( first )
				{
					cout << P[i] << "^" << exp[i];
					first = false;
				}
				else
					cout << " * " << P[i] << "^" << exp[i];
			}
		}
		cout << endl;
	}
}
