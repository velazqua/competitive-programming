/* Alex Velazquez
 * Start: Sun Jan 15 20:02:56 EST 2012
 * End  : Sun Jan 15 22:04:07 EST 2012
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

#define DEBUG 0
#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

struct Pocket {
	int x;
	int y;
	Pocket( int a, int b ) : x(a), y(b) {}
};

bool isOk( int &X, int &Y, int &R, int &C )
{
	return ( X>=0 && X<R && Y>=0 && Y<C ) ? true : false ;
}

void groupPockets( Pocket P, vector<string> &G, vector<vector<bool> > &V, int &R, int &C )
{
	V[P.x][P.y] = true;
	int xMove[8] = {-1,-1,-1,0,0,1,1,1};
	int yMove[8] = {-1,0,1,1,-1,-1,0,1};
	REP( i, 8 )
	{
		int newX = P.x+xMove[i];
		int newY = P.y+yMove[i];
		if( isOk( newX, newY, R, C ) && V[newX][newY] == false && G[newX][newY] == '@' )
		{
			#if DEBUG
				cout << "Visiting => (" << newX << "," << newY << ")" << endl;
			#endif
			groupPockets( Pocket( newX, newY ), G, V, R, C );
		}
	}

}

int main ()
{
	int R, C;
	while( cin >> R >> C )
	{
		if( R == 0 && C == 0 )
			break;
		#if DEBUG
			cout << R << " " << C << endl;
		#endif
		vector<string> grid( R );
		vector<Pocket> pockets;
		int numPockets = 0;
		REP( i, R )
		{
			cin >> grid[i];
			REP( j, C )
			{
				if( grid[i][j] == '@' )
				{
					pockets.push_back( Pocket( i, j ) );
					++numPockets;
				}
			}
		}
		#if DEBUG
			cout << "numPockets: " << numPockets << endl;
		#endif
		vector<vector<bool> > visited;
		vector<bool> temp( C, false );
		REP( i, R )
			visited.push_back( temp );
		int oilDeposits = 0;
		REP( i, numPockets )
		{
			#if DEBUG
				cout << "i: " << i << " => (" << pockets[i].x << "," << pockets[i].y << ")" << endl;
			#endif
			Pocket P = pockets[i];
			if( visited[P.x][P.y] == false ) // not visited
			{
				++oilDeposits;
				groupPockets( P, grid, visited, R, C );
			}
		}
		cout << oilDeposits << endl;
	}
}
