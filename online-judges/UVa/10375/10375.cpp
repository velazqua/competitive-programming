/* Alex Velazquez
 * Start: Mon Apr  2 23:10:03 EDT 2012
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

vector<int> C ( int N, int M, vector<vector<int> > &divisors ) 
{
	if( N-M < M )
		M = N-M;
	vector<int> num, den;
	REP( i, M )
		num.push_back( N-i );
	
	for( int i=M; i>=2; --i )
	{
		for( int k=0; k<(int)divisors[i].size(); ++k )
		{
			REP( j, M )
			{
				if( num[j]%divisors[i][k] == 0 )
				{
					num[j] /= divisors[i][k];
					break;
				}
			}
		}
	}
	return num;
}

bool isPrime( int X )
{
	for( int i=3; i*i<=X; i+=2 )
		if( X%i == 0 )
			return false;
	return true;
}

double factor( vector<int> &N, vector<int> &D )
{
	int sizeN = N.size();
	int sizeD = D.size();
	REP( i, sizeD )
	{
		REP( j, sizeN )
		{
			if( D[i] == 1 )
				break;
			if( N[j]%D[i] == 0 )
			{
				N[j] /= D[i];
				D[i] = 1;
			}
		}
	}
	double num = 1.0, den = 1.0;
	REP( i, sizeN )
	{
		num *= N[i];
	}
	REP( i, sizeD )
	{
		den *= D[i];
	}
	return num/den;
}

void preprocess( int &p, int &q, int &r, int &s )
{
	
}

int main ()
{
	//calculate all primes to LIMIT
	const int LIMIT = 10000;
	vector<int> primes;
	vector<bool> is_prime( LIMIT+1, false );
	is_prime[2] = true;
	primes.push_back( 2 );
	for(int i=3; i<=LIMIT; i+=2 )
		if( isPrime( i ) ) 
		{
			primes.push_back( i );
			is_prime[i] = true;
		}
	int numPrimes = primes.size();
	//find all divisors of numbers up to LIMIT
	vector<vector<int> > divisors( LIMIT+1 );
	divisors.push_back( vector<int>() );
	divisors.push_back( vector<int>() );
	
	for( int i=2; i<=LIMIT; ++i )
	{
		int X = i;
		for( int j=0; j<numPrimes; ++j )
		{
			if( X == 1 )
				break;
			if( is_prime[X] )
			{
				divisors[i].push_back( X );
				break;
			}
			else
			{
				while( X%primes[j] == 0 )
				{
					divisors[i].push_back( primes[j] ); 
					X /= primes[j];
				}
			}
		}
	}
	int p, q, r, s;
	while( cin >> p >> q >> r >> s )
	{
		preprocess( p, q, r, s );
		vector<int> numerator = C( p, q, divisors );
		vector<int> denominator=C( r, s, divisors );
		double result = factor( numerator, denominator );
		printf( "%.5f\n", result);
	}
}
