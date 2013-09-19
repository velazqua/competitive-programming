/* Alex Velazquez
 * Start: Sat Sep 22 02:00:47 EDT 2012
 * End  : Sat Sep 22 02:41:54 EDT 2012
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

int sumDigits( int N )
{
	int s = 0;
	while( N )
	{
		s += N%10;
		N /= 10;
	}
	return s;
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
			
	
	vector<int> L( 1000000+1, 0 );
	vector<bool> harshad( lim+1, true );
	harshad[0] = false;
	for( int i=1; i<1000000+1; ++i )
	{
		int X = i + sumDigits( i );
		if( X <= 1000000 )
			harshad[X] = false;
		L[i] = L[i-1];
		if( !primes[i] && harshad[i] )
			L[i]++;
	}
	
	int T;
	cin >> T;
	REP( i, T )
	{
		int A, B;
		cin >> A >> B;
		cout << L[B]-L[((A-1>0)?A-1:0)] << endl;
	}
}
