/* Alex Velazquez
 * Start: Tue Aug 21 21:19:23 EDT 2012
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int numDigitsBinary( int N )
{
	int counter = 0;
	while( N )
	{
		++counter;
		N = ( N >> 1 );
	}
	return counter;
}

int main ()
{
	int T;
	cin >> T;
	REP( t, T )
	{
		int N;
		cin >> N;
		vector<int> nums( N );
		REP( i, N )
			cin >> nums[i];
		sort( nums.begin(), nums.end() );
		int size = SZ(nums);
		int H = numDigitsBinary(nums[size-1]);
		int maxx = 0;
		#if DEBUG
			cout << "H: " << H << endl;
		#endif
		for( int i=size-1; i>=0; --i )
		{
			int d = numDigitsBinary( nums[i] );
			#if DEBUG
				cout << "nums[i]: " << nums[i] << ". d: " << d << endl;
			#endif 
			if( d < H )
				break;
			REP( j, N )
			{
				if( i != j )
				{
					#if DEBUG
						cout << "nums[j]: " << nums[j] << endl;
						cout << "nums[j] | nums[i]: " << (nums[j] | nums[i]) << endl;
					#endif
					maxx = max( maxx, ( nums[j] | nums[i] ) );
				}
			}
		}
		cout << maxx << endl;
	}
}
