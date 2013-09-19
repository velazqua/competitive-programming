/* Alex Velazquez
 * Start: Sun Feb 19 17:57:46 EST 2012
 * End  : Sun Jul 15 19:48:56 EDT 2012
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

void sizeGroup( vector< set<int> > &G, int j, vector<bool> &visited, int &c )
{
	visited[j] = true;
	++c;
	for( set<int>::iterator it=G[j].begin(); it!=G[j].end(); ++it )
	{
		if( !visited[*it] )
			sizeGroup( G, *it, visited, c );
	}
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int N, M;
		cin >> N >> M;
		vector<bool> isNode( N+1, false );
		vector< set<int> > G( N+1 );
		REP( j, M )
		{
			int a, b;
			cin >> a >> b;
			G[a].insert( b );
			G[b].insert( a );
			isNode[a] = true;
			isNode[b] = true;
		}
		int maxx = ( N > 0 ) ? 1 : 0;
		FOR( j, 1, N+1 )
		{
			vector<bool> visited( N+1, false );
			int c = 0;
			if( isNode[j] )
				sizeGroup( G, j, visited, c );
			#if DEBUG
				cout << "node " << j << ": " << c << endl;
			#endif
			maxx = max( c, maxx );
		}
		cout << maxx << endl;
	}
}
