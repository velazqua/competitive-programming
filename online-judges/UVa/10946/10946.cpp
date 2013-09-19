/* Alex Velazquez
 * Start: Sun Jul 22 03:07:54 EDT 2012
 * End  : Sun Jul 22 03:23:04 EDT 2012
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

struct Hole {
	int size;
	char C;
	Hole( int S, char c ) : size(S), C(c) {}
};

bool operator <( Hole const& A, Hole const& B )
{
	if( A.size > B.size )
		return true;
	else if( A.size < B.size )
		return false;
	else
	{
		return ( ( A.C <= B.C ) ? true : false );
	}
}

bool isOk( int i, int j, int x, int y )
{
	return ( ( i >= 0 && i < x && j >= 0 && j < y ) ? true : false );
}

void explore( vector<string> &G, int x, int y, int i, int j, vector<vb> &visited, int &holeSize, char C )
{
	visited[i][j] = true;
	++holeSize;
	int arrx[] = {1,0,0,-1};
	int arry[] = {0,1,-1,0};
	REP( r, 4 )
	{
		int X = i+arrx[r];
		int Y = j+arry[r];
		if( isOk( X, Y, x, y ) && !visited[X][Y] && C == G[X][Y] )
			explore( G, x, y, X, Y, visited, holeSize, C );
	}
}

int main ()
{
	int x, y;
	int c = 1;
	while( cin >> x >> y ) 
	{
		if( !x && !y )
			break;
		vector<string> G( x );
		REP( i, x )
			cin >> G[i];
		
		vector<vb> visited( x, vb( y, false ) );
		set<Hole> holes;
		REP( i, x )
		{
			REP( j, y )
			{
				if( !visited[i][j] && G[i][j] != '.' )
				{
					int holeSize = 0;
					char C = G[i][j];
					explore( G, x, y, i, j, visited, holeSize, C );
					holes.insert( Hole( holeSize, C ) );
				}
			}
		}
		cout << "Problem " << c++ << ":" << endl;
		for( set<Hole>::iterator it=holes.begin();it!=holes.end();++it )
		{
			cout << it->C << " " << it->size << endl;
		}
	}
}
