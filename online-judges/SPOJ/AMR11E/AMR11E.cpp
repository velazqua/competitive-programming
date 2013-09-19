/* Alex Velazquez
 * Start: Sat Aug 25 00:17:39 EDT 2012
 * End  : Sat Aug 25 00:26:13 EDT 2012
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

bool isLucky( int N, vector<int> &P, int size )
{
	int d = 0;
	int i = 0;
	while( N > 1 )
	{
		if( N % P[i] == 0 )
		{
			++d;
			while( N%P[i] == 0 )
				N /= P[i];
		} 	
		++i;	
	}
	return ( d >= 3 ) ? true : false;
}

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
	
	int size = SZ(P);
	vector<int> lucky;
	int s = 0;
	for( int i=30; s <= 1000; ++i )
	{
		if( isLucky( i, P, size ) )
			lucky.push_back( i ), s++;
	}
	int T;
	cin >> T;
	REP( t, T )
	{
		int n;
		cin >> n;
		cout << lucky[n-1] << endl;
	}
}
