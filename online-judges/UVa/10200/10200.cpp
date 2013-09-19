/* Alex Velazquez
 * Start: Sun Mar 11 18:45:21 EDT 2012
 * End  : Sun Aug  5 20:36:22 EDT 2012
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
#define EPS 		 1e-9

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isBigPrime( int N, vector<int> &primes, int size )
{
	REP( i, size )
	{
		if( primes[i]*primes[i] > N )
			return true;
		if( N%primes[i] == 0 )
			return false;
	}
	return true;
}

bool isSmallPrime( int N )
{
	if( N%2 == 0 ) return false;
	for( int i=3; i*i<=N; ++i )
		if( N%i == 0 )	
			return false;
	return true;
}

bool isPrime( int N, vector<int> &primes, int size, vector<bool> &primeArray )
{
	if( N <= 10000 )
		return primeArray[N];
	else
		return isBigPrime( N, primes, size );
}

int main ()
{
	vector<int> primes;
	vector<bool> primeArray( 10005, false );
	primeArray[2] = true;
	primes.push_back( 2 );
	for( int i=3; i<=10000; ++i )
		if( isSmallPrime( i ) )
			primes.push_back( i ), primeArray[i] = true;
	int size = primes.size();
	int a, b;
	vector<int> answer( 10005, 0 );
	answer[0] = 1;
	FOR( i, 1, 10001 )
	{
		answer[i] = answer[i-1];
		int X = i*i+i+41;
		bool isItPrime = isPrime( X, primes, size, primeArray );
		if( isItPrime )
			answer[i] += 1;
	}
	while( cin >> a >> b )
	{
		double amountPrimes = answer[b]-((a-1>0)?answer[a-1]:0);
		double totalNums = b-a+1.0;
		double ans = amountPrimes/totalNums*10000.00;
		int r = amountPrimes/totalNums*100000.00;
		r %= 10;
		if( r >= 5 )
			ans = ceil( ans );
		ans /= 100;
		ans += EPS;
		printf( "%.2f\n", ans );
	}
}
