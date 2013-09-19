/* Alex Velazquez
 * Start: Wed Sep 19 21:47:51 EDT 2012
 * End  : Wed Sep 19 22:03:02 EDT 2012
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
typedef vector<bool> vb;


void explore( int n, vector<vb> &G, vb &visited, int V )
{
	FOR( i, 0, V+1 )
	{
		if( G[n][i] && !visited[i] )
		{
			visited[i] = true;
			explore( i, G, visited, V );
		}
	}
}

int main ()
{
	int V;
	while( cin >> V )
	{
		if( !V )
			break;
		int start;
		vector<vb> G( V+1, vb( V+1, false ) );
		while( cin >> start )
		{
			if( !start )
				break;
			int v;
			while( cin >> v )
			{
				if( !v )
					break;
				G[start][v] = true;
			}
		}
		int numQueries;
		cin >> numQueries;
		REP( i, numQueries )
		{
			int n;
			cin >> n;
			vb visited( V+1, false );
			explore( n, G, visited, V );
			int notVisited = 0;
			vi nodes;
			FOR( i, 1, V+1 )
			{
				if( !visited[i] )
				{
					++notVisited;
					nodes.PB( i );
				}
			}
			cout << notVisited;
			REP( i, notVisited )
				cout << " " << nodes[i];
			cout << endl;
		}
	}
}
