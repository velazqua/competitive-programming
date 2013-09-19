/* Alex Velazquez
 * Start: Mon Feb 20 00:40:40 EST 2012
 * End  : Mon Feb 20 01:03:58 EST 2012
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
	if( N == 1 ) return false;
	else if( N == 2 ) return true;
	else if( N%2 == 0 ) return false;
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

int sumDigits( int N )
{
	int summ = 0;
	while( N )
	{
		summ += N%10;
		N /= 10;
	}
	return summ;
}

int main ()
{
	// precalculate all primes to 1M
	vector<int> primes;
	for( int i=1; i<=1000000; ++i )
		if( isPrime( i ) && isPrime( sumDigits( i ) ) )
			primes.push_back( i );
	int N;
	cin >> N;
	REP( i, N )
	{
		int A, B;
		cin >> A >> B;
		vector<int>::iterator low, upp;
		low=lower_bound( primes.begin(), primes.end(), A );
		upp=upper_bound( primes.begin(), primes.end(), B );
		//cout << "lowerbound: " << *low << endl;
		//cout << "upperbound: " << *upp << endl;
		cout << int( upp-low ) << endl;
	}
	
}
