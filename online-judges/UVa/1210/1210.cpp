/* Alex Velazquez
 * Start: Sun Mar 11 18:30:50 EDT 2012
 * End  : Sun Mar 11 18:40:52 EDT 2012
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
	if( N%2 == 0 ) return false;
	for( int i=3; i*i<=N; ++i )
		if( N%i == 0 )	
			return false;
	return true;
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	for( int i=3; i<=10000; ++i )
		if( isPrime( i ) )
			primes.push_back( i );

	int N;
	vector<int> ways( 10005, 0 );
	int size = primes.size();
	REP( i, size )
	{
		ways[primes[i]]++;
		int X = primes[i];
		FOR( j, i+1, size )
		{
			X += primes[j];
			if( X > 10000 )
				break;
			ways[X]++;
		}
	}
	
	while( cin >> N )
	{
		if( N == 0 ) break;
		cout << ways[N] << endl;
	}
}
