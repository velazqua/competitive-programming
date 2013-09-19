/* Alex Velazquez
 * Start: Sun Mar 11 17:44:14 EDT 2012
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
	for( int i=3; i<=1100000; ++i )
		if( isPrime( i ) )
			primes.push_back( i );
	int N;
	cin >> N;
	REP( i, N )
	{	
		vector<int> diffs( 1000, 0 );
		int a, b;
		cin >> a >> b;
		if( a == b && !isPrime( a ) )
		{
			cout << "No jumping champion" << endl;
			continue;
		}
		vector<int>::iterator low, upp, next;
		low = lower_bound( primes.begin(), primes.end(), a );
		upp = lower_bound( primes.begin(), primes.end(), b );
		if( *upp > b )
			--upp;
		next = low;
		++next;
		while( low != upp )
		{
			++diffs[*next-*low];
			++low;
			++next;
		}	
		vector<int> D = diffs;
		sort( D.begin(), D.end(), greater<int>() );

		if( D[0] == D[1] )
			cout << "No jumping champion" << endl;
		else
		{
			int ans = 0;
			REP( k, 1000 )
			{
				if( diffs[k] == D[0] )
				{
					ans = k;
					break;
				}
			}
			cout << "The jumping champion is " << ans << endl;
		}
	}
}
