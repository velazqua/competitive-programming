/* Alex Velazquez
 * Start: Sat Jan 14 22:45:16 EST 2012
 * End  :
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <sstream>
#include <numeric>
#include <list>
#include <iterator>
#define DEBUG 1

using namespace std;

struct Point {
	int x;
	int y;
	Point (int x_, int y_ ) : x(x_), y(y_) {}
};

bool operator <( Point const& A, Point const& B )
{
	if( A.x < B.x ) return true;
	else if( A.x > B.x ) return false;
	else return ( A.y<B.y );
}

int dist( Point const& P1, Point const& P2 )
{
	return abs(P1.x-P2.x)+abs(P1.y-P2.y);
}

struct State {
	Point P;
	int distTravelled;
	int approxDistanceToGoal;
	State( Point p, int d, int a ) : P(p), distTravelled(d), approxDistanceToGoal(a) {}
};

bool operator == (Point const& A, Point const& B)
{
	return ( (A.x==B.x) && (A.y==B.y) );
}

bool operator <( State const& A, State const& B )
{
	if( A.approxDistanceToGoal+A.distTravelled < B.approxDistanceToGoal+B.distTravelled )
		return true;
	else if( A.approxDistanceToGoal+A.distTravelled > B.approxDistanceToGoal+B.distTravelled )
		return false;
	else
		return A.P < B.P;
}

int findDistance( Point const& A, Point const& B, vector<vector<int> > &grid, int &R, int &C )
{
	set<State> openList;
	//set<Point> closedList;
	openList.insert( State( A, 0, dist( A, B ) ) );
	
	vector<vector<int> > visited;
	vector<int> temp( C, 0 );
	for( int i=0; i<R; ++i )
		visited.push_back( temp );
	visited[A.x][A.y] = 1;
	while( openList.size() > 0 ) 
	{
		// get smallest element in open list
		set<State>::iterator smallest = openList.begin();
		//cout << "Currently at node: (" << smallest->P.x << "," << smallest->P.y << ")"<<endl;
		// expand that smallest element
		// expand up!
		vector<State> expandedStates;
		if( smallest->P.y+1 < R && grid[smallest->P.x][smallest->P.y+1] != 1 )
		{
			State up( Point( smallest->P.x, smallest->P.y+1 ), 
							smallest->distTravelled+1,
							dist( Point( smallest->P.x, smallest->P.y+1 ), B ) ); 
			expandedStates.push_back( up );
			//visited[smallest->P.x][smallest->P.y+1] = 1;
		}
		
		if( smallest->P.y-1 >= 0 && grid[smallest->P.x][smallest->P.y-1] != 1 )
		{
			State down( Point( smallest->P.x, smallest->P.y-1 ), 
							smallest->distTravelled+1,
							dist( Point( smallest->P.x, smallest->P.y-1 ), B ) ); 
			expandedStates.push_back( down );
			//visited[smallest->P.x][smallest->P.y-1] = 1;
		}

		if( smallest->P.x-1 >= 0 && grid[smallest->P.x-1][smallest->P.y] != 1 )
		{
			State left( Point( smallest->P.x-1, smallest->P.y ), 
							smallest->distTravelled+1,
							dist( Point( smallest->P.x-1, smallest->P.y ), B ) ); 
			expandedStates.push_back( left );		
			
			//visited[smallest->P.x-1][smallest->P.y] = 1;		 
		}
		
		if( smallest->P.x+1 < C && grid[smallest->P.x+1][smallest->P.y] != 1 )
		{
			State right( Point( smallest->P.x+1, smallest->P.y ), 
							smallest->distTravelled+1,
							dist( Point( smallest->P.x+1, smallest->P.y ), B ) ); 
			expandedStates.push_back( right );
			//visited[smallest->P.x+1][smallest->P.y] = 1;
		}
		
		for( int k=0; k<(int)expandedStates.size(); ++k )
		{
			// check if the expanded elements are not in closed list
			//set<Point>::iterator findIt = closedList.find( expandedStates[k].P );
			bool found = (visited[expandedStates[k].P.x][expandedStates[k].P.y] == 1 ) ? true:false;
			if( !found ) // if not found
			{
				// check if we reached our goal
				if( expandedStates[k].P == B ) // if yes, terminate loop
					return expandedStates[k].distTravelled;
				else // if not, add to openlist
					openList.insert( expandedStates[k] );
			}
		}
		// add smallest element to closedList (remove from openList)
		visited[smallest->P.x][smallest->P.y] = 1;
		openList.erase( *smallest );
	}
	return -1;
}

int main ()
{
	int R, C;
	while( cin >> R >> C )
	{
		if( R == 0 && C == 0 )
			break;
		int totalRows;
		cin >> totalRows;
		
		// contruct grid:
		vector<vector<int> > grid;
		vector<int> temp( C, 0 );
		for( int i=0; i<R; ++i )
			grid.push_back( temp );
		
		for( int i=0; i<totalRows; ++i )
		{
			int actualRow, numPoints;
			cin >> actualRow >> numPoints;
			for( int j=0; j<numPoints; ++j )
			{
				int actualColumn;
				cin >> actualColumn;
				grid[actualRow][actualColumn] = 1;
			}
		}
		int sx, sy, ex, ey;
		cin >> sx >> sy;
		cin >> ex >> ey;
		Point start( sx, sy ), finish( ex, ey );
		cout << findDistance( start, finish, grid, R, C ) << endl;
	}
}
