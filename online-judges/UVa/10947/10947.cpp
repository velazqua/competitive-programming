/* Alex Velazquez
 * Start: Sun Jul 22 03:33:40 EDT 2012
 * End  : Sun Jul 22 03:59:43 EDT 2012
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

struct Island {
	int x;
	int y;
	int r;
	Island( int X, int Y, int R ) : x(X), y(Y), r(R) {}
};

double dist( Island &i1, Island &i2 )
{
	double X = abs( i2.x-i1.x );
	double Y = abs( i2.y-i1.y );
	double R = i2.r+i1.r;
	return sqrt(X*X+Y*Y)-R;
}

void dfs( vector<vi> &G, int i, vb &visited )
{
	#if DEBUG
		cout << "Arrived at " << i << endl;
	#endif
	visited[i] = true;
	int size = SZ(G[i]); 
	REP( j, size )
	{
		if( !visited[G[i][j]] )
			dfs( G, G[i][j], visited );
	}
}

int main ()
{
	int K, M;
	while( cin >> K >> M ) 
	{
		int startX, startY, startR;
		cin >> startX >> startY >> startR;
		int endX, endY, endR;
		cin >> endX >> endY >> endR;
		int N;
		cin >> N;
		vector<Island> I;
		I.PB( Island( startX, startY, startR ) );
		I.PB( Island( endX, endY, endR ) );
		REP( i, N )
		{
			int X, Y, R;
			cin >> X >> Y >> R;
			I.PB( Island( X, Y, R ) );
		}
		
		// create adjancency list!
		vector<vi> G( N+3, vi() );
		REP( i, N+1 )
		{
			FOR( j, i+1, N+2 )
			{
				double distIslands = dist( I[i], I[j] );
				if( distIslands <= K*M )
				{
					#if DEBUG
						cout << "Travel from " << i << " to " << j << endl;
					#endif
					G[i].PB( j );
					G[j].PB( i );
				}
			}
		}
		
		#if DEBUG
			cout << "Contents of of G: " << endl;
			REP( i, N+2 )
			{
				cout << "i: " << i << " has " << SZ(G[i]) << " elements." << endl;
			}
		#endif
		
		// dfs starting from current island
		vb visited( N+3, false );
		dfs( G, 0, visited );
		if( visited[1] )
			cout << "Larry and Ryan will escape!" << endl;
		else
			cout << "Larry and Ryan will be eaten to death." << endl;
	}
}
