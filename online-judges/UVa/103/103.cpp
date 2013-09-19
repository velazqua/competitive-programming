/* Alex Velazquez
 * Start: Sun Apr 15 15:27:27 EDT 2012
 * End  : Sun Apr 15 17:19:52 EDT 2012
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

bool fits( vector<vi> &boxes, int i, int j, int size )
{
	REP( k, size )
		if( boxes[i][k] >= boxes[j][k] )
			return false;
	return true;
} 

int findLongestPath( vector<vi> &G, int i, int const& numBoxes, vi &LP )
{
	//cout << "Entering vertex " << i << endl;
	if( LP[i] != -1 )
	{
		//cout << "Already calculated. Vertex " << i << " is " << LP[i] << endl;
		return LP[i];
	}
	int size = G[i].size();
	if( size == 0 )
	{
		//cout << "No neighbours. Vertex " << i << " is " << 1 << endl;
		LP[i] = 1;
		return 1;
	}
	else
	{
		//cout << "Going through neighbours of vertex " << i << endl;
		int maxx = 0;
		REP( k, size )
		{
			LP[G[i][k]] = findLongestPath( G, G[i][k], numBoxes, LP );
			maxx = max( maxx, LP[G[i][k]] );
		}
		LP[i] = 1+maxx;
		//cout << "vertex " << i << " has LP " << LP[i] << endl; 
		return LP[i];
	}
}

void printLongestPaths( vector<vi> &G, int i, vi &LP )
{
	int size = G[i].size();
	if( LP[i] == 1 )
		return;
	int maxx = 0;
	int maxVertex;
	REP( k, size )
	{
		//cout << "LP[" << G[i][k] << "] = " << LP[G[i][k]] << endl;
		if( LP[G[i][k]] > maxx )
		{
			maxx = LP[G[i][k]];
			maxVertex = G[i][k];
		}
	}
	cout << " " << maxVertex+1;
	printLongestPaths( G, maxVertex, LP );
}

void printLP( vi &LP, int numBoxes )
{
	REP( i, numBoxes )
	{
		cout << "Vertex " << i << ". LP: " << LP[i] << endl;
	}
}

int main ()
{
	int numBoxes, numDims;
	while( cin >> numBoxes >> numDims )
	{
		vector<vi> boxes( numBoxes );
		REP( i, numBoxes )
		{
			vi box( numDims );
			REP( j, numDims )
				cin >> box[j];
			sort( box.begin(), box.end() );
			boxes[i] = box;
		}
		
		// create directed graph
		vector<vi> G;
		REP( i, numBoxes )
		{
			vi edges;
			//cout << "The edges of box " << i << " are: " << endl;
			REP( j, numBoxes )
			{
				if( i != j && fits( boxes, i, j, numDims ) )
				{
					//cout << j << " ";
					edges.push_back( j );
				}
			}
			//cout << endl;
			G.push_back( edges );
		}
		
		// find longest path in the graph just created
		int longestPath = 0;
		vi LP( numBoxes, -1 );
		int vertexLP = -1;
		REP( i, numBoxes )
		{
			// print longest paths before entering function
			// printLP( LP, numBoxes );
			LP[i] =	findLongestPath( G, i, numBoxes, LP );
			//cout << "Longest path starting at vertex " << i << " is " << LP[i] << endl;
			if( LP[i] > longestPath )
			{
				longestPath = max( longestPath, LP[i] );
				vertexLP = i;
			}
		}
		cout << longestPath << endl;
		cout << vertexLP+1;
		printLongestPaths( G, vertexLP, LP );
		cout << endl;
	}
}
