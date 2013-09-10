#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

bool isPrime( int x, set<int> &primes )
{
	if( x <= 10000 )
	{
		if( primes.count( x ) > 0 )
			return true;
		else
			return false;
	}
	else
	{
		for( set<int>::iterator it=primes.begin(); it!=primes.end(); ++it )
			if( x%(*it) == 0 )
				return false;
		return true;
	}
}

bool isSmallPrime( int N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

string intToStr( int N )
{
	stringstream ss;
	ss << N;
	return ss.str();
}

int eulerTotient( int N, set<int> &primes )
{
	int A = N;
	for( set<int>::iterator it=primes.begin(); N != 1 && *it * *it <= N; ++it )
	{
		if( N % *it == 0 )
		{
			A /= *it;
			A *= (*it-1);
			while( N % *it == 0 ) N /= *it;
		}
	}
	if( N != 1 )
	{ 
		A /= N;
		A *= (N-1);
		return A;
	}
	else
		return A;
}

int main ()
{
	// generate primes up to 10^4
	set<int> primes;
	primes.insert( 2 );
	for( int i=3; i<=10000; i+=2 )
		if( isSmallPrime( i ) )
			primes.insert( i );
	double minn = 20000;
	int val = 0;
	int LIMIT = 10000000;
	for( int i=2; i<LIMIT; ++i )
	{
		string x = intToStr( i );
		int p = eulerTotient( i, primes );
		string phix = intToStr( p );
		sort( x.begin(), x.end() );
		sort( phix.begin(), phix.end() );
		if( !x.compare( phix ) )
		{
			double d = (double)i/p;
			if( d < minn )
				minn = d, val = i;
		}
	}
	cout << val << endl;
}

