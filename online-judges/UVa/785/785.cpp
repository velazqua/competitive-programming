/* Alex Velazquez
 * Start: Sun Apr 22 14:10:54 EDT 2012
 * End  : Sun Apr 22 14:30:20 EDT 2012
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

struct Mark {
	char c;
	int x;
	int y;
	Mark( char C, int X, int Y ) : c(C), x(X), y(Y) {}
};

void populate( vector<string> &G, char const& c, int x, int y )
{
	G[x][y] = c;
	if( G[x+1][y] == ' ' ) populate( G, c, x+1, y );
	if( G[x-1][y] == ' ' ) populate( G, c, x-1, y );
	if( G[x][y+1] == ' ' ) populate( G, c, x, y+1 );
	if( G[x][y-1] == ' ' ) populate( G, c, x, y-1 );
	
}

int main ()
{
	vector<string> G;
	vector<Mark> M;
	string line;
	int j = 0;
	while( getline( cin, line ) )
	{
		if( !line.compare( "_____________________________" ) )
		{
			// fill the empty grid
			for( vector<Mark>::iterator it=M.begin(); it!=M.end(); ++it )
			{
				//cout << "Mark: " << it->c << " " << it->x << " " << it->y << endl;
				populate( G, it->c, it->x, it->y );
			}
			
			// print the new populated grid
			int size = G.size();
			REP( i, size )
				cout << G[i] << endl;
				
			cout << "_____________________________" << endl;
			G.clear();
			M.clear();
			j = 0;
			continue;
		}
		G.push_back( line );
		
		// find mark characters
		int size = line.size();
		REP( c, size )
			if( line[c] != 'X' && line[c] != ' ' )
				M.push_back( Mark( line[c], j, c ) );
		++j;
	}
}
