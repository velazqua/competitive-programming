/* Alex Velazquez
 * Start: Sun Mar 25 13:59:23 EDT 2012
 * End  : Sun Mar 25 14:36:12 EDT 2012
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

vector<int> circle( int N, int multiplyBy )
{
	int originalN = N;
	vector<int> newNums;
	multiplyBy /= 10;
	newNums.push_back( N );
	do
	{
		int t = N%10;
		N /= 10;
		N += t*multiplyBy;
		newNums.push_back( N );
	} while( originalN != N );
	return newNums;
}

int checkDigit( int N )
{
	int t = 1;
	while( N )
	{
		int X = N%10;
		if( X == 5 || X%2 == 0 )
			return -1;
		N /= 10;
		t *= 10;
	}
	return t;
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	for( int i=3; i<1000000; i+=2 )
		if( isPrime( i ) )
			primes.push_back( i );
	set<int> circular;
	int size = primes.size();
	REP( i, size )
	{
		// if prime contains a digit other than 1,3,7,9. skip it
		int multiplyBy = checkDigit( primes[i] );
		if( multiplyBy == -1 )
			continue;
		// if prime is already circular, skip it
		if( circular.count( primes[i] )  )
			continue;
		else
		{
			// do the circular operation on the prime number
			vector<int> C = circle( primes[i], multiplyBy );
			
			// test if all of these numbers are prime
			bool test = true;
			for( vector<int>::iterator it=C.begin();it!=C.end();++it)
			{
				if( !binary_search( primes.begin(), primes.end(), *it ) )
				{
					test = false;
					break;
				}
			}
			if( test )
				for( vector<int>::iterator it=C.begin();it!=C.end();++it)
					if( *it < 1000000 && *it > 100)
					{
						//cout << *it << endl;
						circular.insert( *it );
					}
		}
	}
	int N1, N2;
	while( cin >> N1 )
	{
		int cp = 0;
		if( N1 == -1 ) break;
		cin >> N2;
		for( set<int>::iterator it=circular.begin();it!=circular.end();++it )
			if( *it >= N1 && *it <= N2 )
				++cp;
		if( cp == 0 )
			cout << "No Circular Primes." << endl;
		else if( cp == 1 )
			cout << "1 Circular Prime." << endl;
		else
			cout << cp << " Circular Primes." << endl;
	}
}
