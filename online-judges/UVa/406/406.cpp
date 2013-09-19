/* Alex Velazquez
 * Start: Wed Feb  1 19:32:42 EST 2012
 * End  : Wed Feb  1 21:13:58 EST 2012
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

using namespace std;

bool isPrime( int x )
{
	if( x == 2 )
		return true;
	if( x%2 == 0 || x == 0 )
		return false;
	for( int i=3; i*i <= x; i+=2 )
		if( x%i == 0 )
			return false;
	return true;
}

void printPrimes( int s, int C, vector<int> &P )
{
	for( int i=0; i<C; ++i )
		cout << " " << P[s+i];
	cout << endl;
}

int main ()
{
	vector<int> primes;
	REP( i, 1000 )
		if( isPrime( i ) )
			primes.push_back( i );
	int N, C;
	
	while( cin >> N >> C )
	{
		int ind = 0;
		while( primes[ind] <= N && ind<169 ) ++ind;
		int numPrimes = ind+1;
		cout << N << " " << C << ":";
		if( ind%2 == 0 ) //even
		{
			if( 2*C >= numPrimes )
				printPrimes( 0, ind, primes );
			else
				printPrimes( (numPrimes-2*C)/2, 2*C, primes );
		}
		else
		{
			if( 2*C-1 >= numPrimes )
				printPrimes( 0, ind, primes );
			else
				printPrimes( (numPrimes-(2*C-1))/2, 2*C-1, primes );
		}
		cout << endl;
	}
}
