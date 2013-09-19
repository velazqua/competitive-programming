/* Alex Velazquez
 * Start: Sat Sep 15 01:49:38 EDT 2012
 * End  : Sat Sep 15 02:07:03 EDT 2012
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

int main ()
{
	int N, M;
	int arrx[] = {-1,0,1,1,-1,-1,0,1};
	int arry[] = {-1,-1,-1,0,0,1,1,1};
	while( cin >> N >> M )
	{
		if( !N && !M )
			break;
		vector<string> MAP( N, "" );
		REP( i, N )
			cin >> MAP[i];
		vector< vector<bool> > visited( N, vector<bool>( M, false ) );
		int counter = 0;
		REP( i, N )
		{
			REP( j, M )
			{
				if( MAP[i][j] == '*' && !visited[i][j] )
				{
					bool star = true;
					// check all adjacent squares
					REP( k, 8 )
					{
						int X = i+arrx[k];
						int Y = j+arry[k];
						if( X >= 0 && X < N && Y >= 0 && Y < M )
						{
							if( MAP[X][Y] == '*' )
								star = false;
							visited[X][Y] = true;
						}
					}
					if( star )
						++counter;
				}
			}
		}
		cout << counter << endl;
	}
}
