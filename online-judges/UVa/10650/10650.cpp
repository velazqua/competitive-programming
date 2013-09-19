/* Alex Velazquez
 * Start: Sun Mar 11 19:29:02 EDT 2012
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
	for( int i=3; i<=32000; ++i )
		if( isPrime( i ) )
			primes.push_back( i );
	vector<vector<int> > DPrimes;
	int size = primes.size();
	// find determinate primes
	bool skip = false;
	REP( i, size-2 )
	{
		if( skip ) 
		{
			skip = false;
			continue;
		}
		int d = primes[i+1]-primes[i];
		int c = primes[i+1];
		FOR( j, i+2, size )
		{
			if( primes[j]-c == d ) 
			{
				c = primes[j];
			}
			else
			{
				if( c != primes[i+1] ) // found it
				{
					vector<int> T;
					for( int k=i; k<=j-1; ++k )
						T.push_back( primes[k] );
					DPrimes.push_back( T );
					if( T.size() == 4 ) skip = true;
				}
				break;
			}
		}
	}
	int x, y;
	while( cin >> x >> y )
	{
		int a = min(x,y);
		int b = max(x,y);
		int size = DPrimes.size();
		REP( i, size )
		{
			if( DPrimes[i][0] < a ) continue;
			if( DPrimes[i][0] > b ) break;
			if( DPrimes[i].size() == 3 )
			{
				if( DPrimes[i][2] <= b )
					cout << DPrimes[i][0] << " " << DPrimes[i][1] << " " << DPrimes[i][2] << endl;
			}
			else
			{
				if( DPrimes[i][3] <= b )
				{
					//cout << DPrimes[i][1] << " " << DPrimes[i][2] << " " << DPrimes[i][3] << endl;
					cout << DPrimes[i][0] << " " << DPrimes[i][1] << " " << DPrimes[i][2] << " " << DPrimes[i][3] << endl;
				}
			}
		}
	}
}
