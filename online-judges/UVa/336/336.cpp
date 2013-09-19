/* Alex Velazquez
 * Start: Sun Feb 19 23:59:34 EST 2012
 * End  : Mon Feb 20 00:38:39 EST 2012
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

void dfs( map<int,vi> &G, int startNode, int TTL, set<int> &visited, map<int,int> &P )
{
	if( visited.count( startNode ) > 0 )
	{
		if( P[startNode] >= TTL )
			return;
	}
	visited.insert( startNode );
	P[startNode] = TTL;
	if( TTL == 0 ) return;
	for( int i=0; i<(int)G[startNode].size(); ++i )
	{
		dfs( G, G[startNode][i], TTL-1, visited, P ); 
	}
}

int main ()
{
	int NC;
	int c = 1;
	while( cin >> NC )
	{
		if( NC == 0 ) break;
		int a, b;
		map<int,vi> G;
		set<int> nodes;
		REP( i, NC )
		{
			cin >> a >> b;
			if( a != b )
			{
				G[a].push_back( b );
				G[b].push_back( a );
			}
			nodes.insert( a );
			nodes.insert( b );
		}
		// queries
		int startNode, TTL;
		while( cin >> startNode >> TTL )
		{
			if( startNode == 0 && TTL == 0 ) break;
			set<int> visited;
			map<int,int> P;
			dfs( G, startNode, TTL, visited, P );
			cout << "Case " << c++ << ": ";
			cout << nodes.size()-visited.size() << " nodes not";
			cout << " reachable from node " << startNode << " ";
			cout << "with TTL = " << TTL  << "." << endl;
		}
	}
}
