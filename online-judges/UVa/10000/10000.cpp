/* Alex Velazquez
 * Start: Tue Jul  3 18:17:39 EDT 2012
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
#define SZ(A)		 int((A).size())
#define PB			 push_back
#define DEBUG		 0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


void dfs( vector< vi > &G, int i, int currDepth, int &endingNode, int &longestPath, vector<bool> visited )
{
	#if DEBUG
		cout << "Entering node: " << i << endl;
	#endif
	if( visited[i] || SZ(G[i]) == 0 )
	{
		#if DEBUG
			cout << "Node " << i << " was already visited" << endl;
			cout << currDepth << " " << longestPath << endl;
		#endif
		if( currDepth > longestPath )
		{
			longestPath = currDepth;
			endingNode = i;
		}
		
	}
	if( !visited[i] )
	{
		#if DEBUG
			cout << "Node " << i << " was not visited before" << endl;
		#endif
		visited[i] = true;
		for( int k=0; k<SZ(G[i]); ++k )
		{
			dfs( G, G[i][k], currDepth+1, endingNode, longestPath, visited );
		}
	}
}

int main ()
{
	int numNodes;
	int c = 1;
	while( cin >> numNodes )
	{
		if( !numNodes )
			break;
		int startingNode;
		cin >> startingNode;
		int x, y;
		vector< vi > G( numNodes+1 ); 
		while( cin >> x >> y )
		{
			if( x == 0 && y == 0 )
				break;
			G[x].PB( y );
		}
		vector<bool> visited( numNodes+1, false );
		int longestPath = 0;
		int endingNode = 0;
		dfs( G, startingNode, 0, endingNode, longestPath, visited );
		cout << "Case " << c++ << ": The longest path from ";
		cout << startingNode << " has length " << longestPath;
		cout << ", finishing at " << endingNode << "." << endl;
		cout << endl;
	}
}
