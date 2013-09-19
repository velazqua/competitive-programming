/* Alex Velazquez
 * Start: Tue Jan 24 21:36:20 EST 2012
 * End  : Tue Jan 24 22:17:28 EST 2012
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

using namespace std;

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct State {
	int node;
	int dist;
	State( int n, int d ) : node(n), dist(d) {}
};

int bfs( vector<vi> &G, int &n , int &k )
{
	State s( 0, 1 );
	deque<State> S;
	S.push_back( s );
	while( !S.empty() )
	{
		State t = S.front();
		S.pop_front();
		for( vi::iterator it=G[t.node].begin(); it!=G[t.node].end(); ++it )
		{
			int D = t.dist+1;
			if( D > 20 )
				return -1;
			if( *it == n-1 && D >= k )
				return D;
			S.push_back( State( *it, D ) );
		}
	}
	return -1;
}

int main ()
{
	int n, m, k;
	while( cin >> n >> m >> k )
	{
		vector<vi> AdjList;
		AdjList.assign( n, vi() );
		if( n == 0 && m == 0 && k == 0 )
			break;
		//read edges
		REP( i, m )
		{
			int x, y;
			cin >> x >> y;
			AdjList[x].push_back( y );
		}
		int answer = bfs( AdjList, n, k );
		if( answer < k )
			cout << "LOSER" << endl;
		else
			cout << answer << endl;
	}
}
