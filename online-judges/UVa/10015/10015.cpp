/* Alex Velazquez
 * Start: Fri Mar 16 22:18:11 EDT 2012
 * End  : Fri Mar 16 22:31:44 EDT 2012
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


void printVector( vector<int>::iterator first, vector<int>::iterator last )
{
	for( ; first!=last; ++first )
		cout << *first << " " ;
	cout << endl;
}

bool isPrime( int N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( !( N%i ) )
			return false;
	return true;
}

int main ()
{
	// calculate first 3505 primes
	vector<int> primes;
	primes.push_back( 2 );
	for( int i=3; primes.size()<=3505; i+=2 )
		if( isPrime( i ) )
			primes.push_back( i );
	int N;
	while( cin >> N )
	{
		if( !N )
			break;
		vector<int> nums( N );
		for( int i=1; i<=N; ++i )
			nums[i-1] = i;
		int toDelete = N;
		for( int k=0; k<N-1; ++k )
		{
			int m = primes[k];
			//cout << "m: " << m << endl;
			//printVector( nums.begin(), nums.end() );
			int indx = (m-1)%toDelete;
			//cout << "There are " << toDelete << " elements. Deleting: " << E << endl;
			vector<int> T( indx );
			copy( nums.begin(), nums.begin()+indx, T.begin() );
			nums.erase( nums.begin(), nums.begin()+indx+1 );
			nums.insert( nums.end(), T.begin(), T.end() );
			toDelete--;
		}
		cout << nums[0] << endl;
	}
}
