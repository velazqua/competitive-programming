/* Alex Velazquez
 * Start: Sun Apr 22 15:43:43 EDT 2012
 * End  : Sun Apr 22 16:18:03 EDT 2012
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

bool isOk( int x, int y, int X, int Y )
{
	if( x >= 0 && x < Y && y >= 0 && y < X )
		return true;
	else
		return false;
}

void explore( vector<string> &V, int x, int y, int X, int Y, int &waterArea, vector<vector<bool> >&visited )
{
	//cout << "x: " << x << ". y: " << y << ". X: " << X << ". Y: " << Y << endl;
	if( V[x][y] != 'W' || visited[x][y] ) return;
	++waterArea;
	visited[x][y] = true;
	int arrX[] = {0,0,-1,-1,-1,1,1,1};
	int arrY[] = {1,-1,-1,0,1,-1,0,1};
	for( int i=0; i<8; ++i )
		if( isOk( x+arrX[i], y+arrY[i], X, Y ) && V[x+arrX[i]][y+arrY[i]] == 'W' ) 
			explore( V, x+arrX[i], y+arrY[i], X, Y, waterArea, visited );
}

int main ()
{
	int N;
	cin >> N;
	string dummy;
	getline( cin, dummy );
	REP( l, N )
	{
		if( l == 0 ) cin.ignore();
		if( l != 0 ) cout << endl;
		vector<string> V;
		// read input ( kind of tricky )
		int i, j;
		string line;
		while( getline( cin, line ) )
		{
			//cout << "line: " << line << endl;
			if( line[0] == 'L' || line[0] == 'W' )
				V.push_back( line );
			else if( !line.compare( "" ) )
			{
				break;
			}
			else // query
			{
				istringstream lineStream( line );
				lineStream >> i >> j;
				//cout << i << " " << j << endl;
				i--; j--;
				int waterArea = 0;
				//cout << "V[0]: " << V[0] << endl;
				int X = V[0].size();
				int Y = V.size();
				vector<vector<bool> > visited( X, vector<bool>( Y, false ) );
				if( isOk( i, j, X, Y ) )
					explore( V, i, j, X, Y, waterArea, visited );
				cout << waterArea << endl;
			}
		}
	}
}
