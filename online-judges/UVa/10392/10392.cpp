/* Alex Velazquez
 * Start: Sun Apr  8 22:08:51 EDT 2012
 * End  : Sun Apr  8 22:18:43 EDT 2012
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPrime( LL N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

void largePrime( LL N, vector<int> &P, int size )
{
	for( int i=0; i<size; ++i )
	{
		if( N == 1 )
			break;
		while( N%P[i] == 0 )
		{
			cout << "    " << P[i] << endl;
			N /= P[i];
		}
	}
	if( N != 1LL )
		cout << "    " << N << endl;
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	for( int i=3; i<1000000; i+=2 )
		if( isPrime( i ) )
			primes.push_back( i );
	LL n;
	int size = primes.size();
	while( cin >> n )
	{
		if( n < 0LL ) break;
		largePrime( n, primes, size );
		cout << endl;
	}
	
}
