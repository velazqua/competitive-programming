/* Alex Velazquez
 * Start: Sat Jun 30 01:05:55 EDT 2012
 * End  : Sat Jun 30 01:49:01 EDT 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void explore( int x, int y, vector<string> &M, vector<vi> &vals, int iter )
{
	if( iter <= vals[x][y] )
		vals[x][y] = iter;
	++iter;
	int arrx[] = {-1,0,0,1};
	int arry[] = {0,1,-1,0};
	REP( i, 4 )
	{
		int X = x+arrx[i];
		int Y = y+arry[i];
		if( X >= 0 && X < 10 && Y >= 0 && Y < 10 && M[X][Y] == 'T' && iter < vals[X][Y] )
		{
			explore( X, Y, M, vals, iter );
		} 
	}
}

int main ()
{
	vector<string> M( 10 );
	vii F;
	vii T;
	REP( i, 10 )
	{
		cin >> M[i];
		REP( j, 10 )
		{
			if( M[i][j] == 'T' )
				T.push_back( make_pair( i, j ) );
			else if( M[i][j] == 'F' )
				F.push_back( make_pair( i, j ) );
		}
	}
	vector<vi> vals( 10, vi( 10, 1337 ) ); 
	REP( i, SZ( F ) )
	{
		explore( FST(F[i]), SEC(F[i]), M, vals, 0 );
	}
	int maxx = 0;
	REP( i, SZ( T ) )
	{
		//cout << FST(T[i]) << " " << SEC(T[i]) << " " << vals[FST(T[i])][SEC(T[i])] << endl;
		if( vals[FST(T[i])][SEC(T[i])] == 1337 )
		{
			cout << -1 << endl;
			return 0;
		}
		else
			maxx = max( maxx, vals[FST(T[i])][SEC(T[i])] );
	}
	cout << maxx << endl;
}
