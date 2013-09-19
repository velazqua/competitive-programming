/* Alex Velazquez
 * Start: Sat Sep 22 20:06:30 EDT 2012
 * End  : Sat Sep 22 20:15:05 EDT 2012
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

int main ()
{
    unsigned int lim = 20000000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> twinPrimes( 100000 );
	int c = 0;
	for( int i=3; i<20000000-2; ++i )
	{
		if( c > 100000 )
			break;
		if( !primes[i] && !primes[i+2] )
			twinPrimes[c++] = i;
	}
	
	int N;
	while( cin >> N )
	{
		cout << "(" << twinPrimes[N-1] << ", " << twinPrimes[N-1]+2 << ")" << endl;
	}
}
