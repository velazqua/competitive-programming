#include <iostream>
#include <vector>
#include <set>

using namespace std; 

typedef unsigned long long ULL;

bool isPrime( ULL N )
{
	for( ULL i=3ULL; i*i<=N; i+=2 )
		if( N%i == 0ULL )
			return false;
	return true;
}

int main ()
{
	// calculate primes
	set<ULL> primes;
	primes.insert( 2ULL );
	ULL LIMIT = 1000000;
	for( ULL i=3ULL; i<LIMIT; i+=2 )
		if( isPrime( i ) )
			primes.insert( i );
			
	vector<ULL> cubes;
	vector<ULL> squares;
	vector<ULL> nines;
	int numCubes = 100000;
	for( ULL i=0ULL; i<(ULL)numCubes; ++i )
		cubes.push_back( i*i*i ),
		squares.push_back( i*i ),
		nines.push_back( cubes[i]*cubes[i]*cubes[i] );
	int counter = 0;
	for( ULL i=1ULL; i<10000; ++i )
	{
		ULL n = i*i*i;
		//cout << i << " " << n << " " << n+i*i << endl;
		ULL possiblePrime = 3*i*i+3*i+1ULL;
		if( primes.count( possiblePrime )>0 )
		{
			++counter;
			cout << n << "^3 + " << n << "^2 * " << possiblePrime;
			cout << " = " << n+i*i << "^3" << endl;
		}
	}
	cout << counter << endl;
}
