/* Alex Velazquez
 * Start: Thu Jul  5 21:43:30 EDT 2012
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

bool isOk( int i, int j, int R, int C ) 
{
	if( i >= 0 && i < R && j >= 0 && j < C )
		return true;
	else
		return false;
}

void dfs( vector< vector<int> > &G, 
		  vector< vector<int> > &dist, 
		  vector< vector<bool> > visited, 
		  int curLen, int r, int c, int &R, int &C )
{
	dist[r][c] = max( dist[r][c], curLen );
	#if DEBUG
		cout << "Entering node " << G[r][c] << " " << dist[r][c] << endl;
	#endif
	if( !visited[r][c] )
	{
		visited[r][c] = true;
		int arrx[] = {-1,0,0,1};
		int arry[] = {0,1,-1,0};
		REP( i, 4 )
		{
			int local_max = 0;
			int x = arrx[i];
			int y = arry[i];
			if( isOk( r+x, c+y, R, C ) && G[r][c] < G[r+x][c+y] )
			{
				dfs( G, dist, visited, curLen+1, r+x, c+y, R, C );
				int d = dist[r+x][c+y];
				local_max = max( local_max, d );
			}
			dist[r][c] = max( dist[r][c], local_max );
		}
	}
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		string S;
		int R, C;
		cin >> S >> R >> C;
		vector< vector<int> > G( R, vector<int>( C, 0 ) );
		REP( r, R )
			REP( c, C )
				cin >> G[r][c];
		vector< vector<int> > dist( R, vector<int>( C, -1 ) );
		vector< vector<bool> > visited( R, vector<bool>( C, false ) );
		int maxx = 0;
		REP( r, R )
		{
			REP( c, C )
			{
				if( dist[r][c] == -1 )
				{
					dfs( G, dist, visited, 1, r, c, R, C );
					visited[r][c] = true;
				}
				maxx = max( maxx, dist[r][c] );
				#if DEBUG
					cout << G[r][c] << " " << dist[r][c] << endl;
				#endif
			}
		}
		cout << S << ": " << maxx << endl;
	}
}
