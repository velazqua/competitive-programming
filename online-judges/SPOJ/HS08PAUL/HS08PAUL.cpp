/* Alex Velazquez
 * Start: Thu Sep 13 16:05:19 EDT 2012
 * End  : Thu Sep 13 17:16:08 EDT 2012
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
	unsigned int lim = 10000000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
	primes[0] = true;
    primes[1] = true;
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	set<int> paulPrimes;
	for( int i=0; i<3163; ++i )
	{
		for( int j=0; j<57; ++j )
		{
			int X = i*i + j*j*j*j;
			if( X > 10000000 )
				break;
			if( !primes[X] )
				paulPrimes.insert( X );
		}
	}
	map<int,int> M;
	int c = 1;
	for( set<int>::iterator it=paulPrimes.begin(); it!=paulPrimes.end(); ++it )
	{
		M[*it] = c++;
	}
	
	int N;
	cin >> N;
	REP( t, N )
	{
		int n;
		cin >> n;
		set<int>::iterator it = paulPrimes.lower_bound( n );
		if( *it == n ) 
			cout << M[*it] << endl;
		else
		{
			it--;
			cout << M[*it] << endl;
		}
	}
}
