/* Alex Velazquez
 * Start: Sun Apr 29 00:33:55 EDT 2012
 * End  : Sun Apr 29 00:52:51 EDT 2012
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

void findSuspects( vector<bool> &suspects, vector<vector<int> > &belongsToGroup, vector<vector<int> > &groups, int X )
{
	int size = belongsToGroup[X].size(); // number of groups X belongs to
	suspects[X] = true;
	REP( i, size )
	{
		int sizeGroup = groups[belongsToGroup[X][i]].size();
		REP( j, sizeGroup )
		{
			if( !suspects[groups[belongsToGroup[X][i]][j]] )
			{
				findSuspects( suspects, belongsToGroup, groups, groups[belongsToGroup[X][i]][j] );
			}
		}
	}
}

int main ()
{
	int n, m;
	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 ) break;
		vector<bool> suspects( n, false );
		vector<vector<int> > belongsToGroup( n, vector<int>() );
		vector<vector<int> > groups( n, vector<int>() );
		suspects[0] = true;
		REP( i, m )
		{
			int k;
			cin >> k;
			REP( j, k )
			{
				int t;
				cin >> t;
				belongsToGroup[t].push_back( i );
				groups[i].push_back( t );
			}
		}
		
		findSuspects( suspects, belongsToGroup, groups, 0 );
		
		int c = 0;
		REP( i, n )
			if( suspects[i] )
				++c;
		cout << c << endl;
	}
}
