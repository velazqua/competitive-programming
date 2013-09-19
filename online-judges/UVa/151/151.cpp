/* Alex Velazquez
 * Start: Fri Mar 16 21:05:00 EDT 2012
 * End  : Fri Mar 16 21:56:18 EDT 2012
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

int main ()
{
	int N;
	while( cin >> N )
	{
		if( !N )
			break;
		for( int m=1; ; ++m )
		{
			vector<int> nums( N );
			for( int i=1; i<=N; ++i )
				nums[i-1] = i;
			nums.erase( nums.begin() );
			int toDelete = N-1;
			//cout << "m: " << m << endl;
			while( 1 )
			{
				//printVector( nums.begin(), nums.end() );
				if( !toDelete )
					break;
				int indx = (m-1)%toDelete;
				int E = nums[indx];
				//cout << "There are " << toDelete << " elements. Deleting: " << E << endl;
				if( E == 13 )
					break;
				vector<int> T( indx );
				copy( nums.begin(), nums.begin()+indx, T.begin() );
				nums.erase( nums.begin(), nums.begin()+indx+1 );
				nums.insert( nums.end(), T.begin(), T.end() );
				toDelete--;
			}
			if( nums[0] == 13 && nums.size() == 1 )
			{
				cout << m << endl;
				break;
			}
		}
	}
}
