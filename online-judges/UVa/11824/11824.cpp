/* Alex Velazquez
 * Start: Fri Feb 24 20:29:17 EST 2012
 * End  : Wed Feb 29 19:52:12 EST 2012
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

LL powerLL( LL a, int n )
{
	LL r = a;
	for( int i=0; i<n-1; ++i )
		r *= a;
	return r;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		vector<LL> nums;
		LL n;
		while( cin >> n )
		{
			if( n == 0 ) break;
			nums.push_back( n );
		}
		int size = nums.size();
		sort( nums.begin(), nums.end(), greater<LL>() );
		LL total = 0LL;
		bool found = false;
		for( int k=1; k<=size; ++k )
		{
			total += 2LL*powerLL(nums[k-1],k);
			if( total > 5000000LL )
			{
				cout << "Too expensive" << endl;
				found = true;
				break;
			}
		}
		if( !found )
			cout << total << endl;
	}
}
