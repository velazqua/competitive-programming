/* Alex Velazquez
 * Start: Sun Apr 15 22:31:40 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


bool isPrime( int N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

int countFactors( int N, vector<int> &primes, int const& size )
{
	int f = 0;
	for( int i=0; i<size; ++i )
	{
		if( N == 1 ) break;
		while( N%primes[i] == 0 )
		{
			N /= primes[i];
			++f;
		}
	}
	return f;
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	vector<int> F( 1000001, 0 );
	int size = 1;
	F[0] = 0; F[1] = 0; F[2] = 1;
	for( int N=3; N<=1000000; N+=2 )
	{
		if( isPrime( N ) ) 
		{
			primes.push_back( N );
			++size;
			//F[N] = F[N-1] + 1;
		}
		else
		{
			int factors = countFactors( N, primes, size );

			//F[N] = F[N-1] + factors;
			//cout << F[N] << " " << F[N-1] << " " << factors << endl;
		}
	}
	int N;
	while( cin >> N )
	{
		cout << N << " : " << countFactors( N, primes, size ) << endl;
	}
}
