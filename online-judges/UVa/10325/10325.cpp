/* Alex Velazquez
 * Start: Fri Jul  6 21:13:56 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int gcd( int a, int b )
{
	while( b != 0 )
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int lcm( int a, int b )
{
	return (a/gcd(a,b))*b;
}

int main ()
{
	LL N, M;
	while( cin >> N >> M )
	{
		vector<LL> nums;
		REP( i, M )
		{
			int t;
			cin >> t;
			bool addIt = true;
			REP( j, SZ( nums ) )
			{
				if( nums[j] % t == 0 || t % nums[j] == 0 )
				{
					addIt = false;
					break;
				}
			}
			if( addIt )
				nums.PB( t );
		}
		int A = N;
		M = SZ( nums );
		for( int i=0; i<(1<<M); ++i )
		{
			vector<LL> mults;
			for( int k=0; k<M; ++k )
			{
				if( (i&(1LL<<k)) > 0 )
					mults.PB( nums[k] );		
			}
			int size = SZ( mults );
			if( size == 1 )
			{
				#if DEBUG
					cout << "Taking: " << mults[0] << " => " << N/mults[0] << endl; 
				#endif
				A -= ( N/mults[0] );
			}
			else if( size > 1 )
			{
				LL X = 1LL;
				bool addIt = true;
				REP( j, size )
				{
					X = lcm( X, mults[j] );
					if( X > N )
					{
						addIt = false;
						break;
					}
				}
				if( addIt )
					A += ( N/X );
			}
		}
		cout << A << endl;
		
	}
}
