/* Alex Velazquez
 * Start: Sun Apr 22 15:25:39 EDT 2012
 * End  : Sun Apr 22 15:38:22 EDT 2012
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

struct Eagle {
	int i;
	int j;
	Eagle( int I, int J ) : i(I), j(J) {}
};

bool isOk( int x, int y, int N )
{
	if( x >= 0 && x < N && y >= 0 && y < N )
		return true;
	else
		return false;
}

void explore( vector<string> &V, int x, int y, int N )
{
	V[x][y] = 'X';
	int arrX[] = {0,0,-1,-1,-1,1,1,1};
	int arrY[] = {1,-1,-1,0,1,-1,0,1};
	for( int i=0; i<8; ++i )
		if( isOk( x+arrX[i], y+arrY[i], N ) && V[x+arrX[i]][y+arrY[i]] == '1' ) 
			explore( V, x+arrX[i], y+arrY[i], N );
}

int main ()
{
	int N;
	int c = 1;
	while( cin >> N )
	{
		vector<string> V( N );
		vector<Eagle> E;
		REP( i, N )
		{
			cin >> V[i];
			REP( j, N )
			{
				if( V[i][j] == '1' )
					E.push_back( Eagle( i, j ) );
			}
		}
		// loop through the eagles
		int size = E.size();
		int numWarEagles = 0;
		REP( i, size )
		{
			if( V[E[i].i][E[i].j] == '1' )
			{
				explore( V, E[i].i, E[i].j, N );
				++numWarEagles;
			}
		}
		cout << "Image number " << c++ << " contains ";
		cout << numWarEagles << " war eagles." << endl;
	}
}
