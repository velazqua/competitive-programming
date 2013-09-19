/* Alex Velazquez
 * Start: Sat Sep 22 19:16:04 EDT 2012
 * End  : Sat Sep 22 20:04:07 EDT 2012
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

int bfs( int start, int goal, vector< vector<int> > &G )
{
	vector<int> Q;
	Q.PB( start );
	vector<bool> visited( 19, false );
	visited[start] = true;
	int depth = 1;
	while( 1 )
	{
		vector<int> newQ;
		while( !Q.empty() )
		{
			int node = Q.back();
			Q.pop_back();
			visited[node] = true;
			int size = SZ(G[node]);
			#if DEBUG
				cout << "Expanding node " << node << ". size: " << size << endl;
			#endif
			REP( i, size )
			{
				#if DEBUG
					cout << "Checking node " << G[node][i] << endl;
				#endif
				if( !visited[G[node][i]] )
				{
					#if DEBUG
						cout << "Adding " << G[node][i] << " to the queue" << endl;
					#endif
					if( G[node][i] == goal )
						return depth;
					visited[G[node][i]] = true;
					newQ.PB( G[node][i] );
				}
			}
		}
		depth++;
		Q = newQ;
	}
	return -1;
}

int main ()
{
	int t;
	int ts = 1;
	while( cin >> t )
	{
		vector< vector<int> > G( 21, vector<int>() );
		int n;
		REP( i, t )
		{
			cin >> n;
			G[0].PB( n-1 ); 
			G[n-1].PB( 0 );
		}
		REP( i, 18 )
		{
			int t;
			cin >> t;
			REP( k, t )
			{
				cin >> n;
				G[i+1].PB( n-1 );
				G[n-1].PB( i+1 );
			}
		}
		int Q;
		cin >> Q;
		cout << "Test Set #" << ts++ << endl;
		REP( i, Q )
		{
			int start, goal;
			cin >> start >> goal;
			cout << ( (start < 10)?" ":"") << start << " to " << ( (goal < 10)?" ":"") << goal << ": " << bfs( start-1, goal-1, G ) << endl;
		}
		cout << endl;
	}
}
