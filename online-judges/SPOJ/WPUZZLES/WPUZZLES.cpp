/* Alex Velazquez
 * Start: Sat Sep 15 22:26:40 EDT 2012
 * End  :
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
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( t, T )
	{
		if( t != 0 )
			cout << endl;
		int N, M, numWords;
		cin >> N >> M >> numWords;
		vector<string> P( N, "" );
		vector<vii> L( 91, vii() );
		REP( i, N )
		{
			cin >> P[i];
			REP( j, M )
			{
				L[P[i][j]].push_back( make_pair( i, j ) );
			}
		}
		REP( i, numWords )
		{
			string word;
			cin >> word;
			int size = SZ( word );
			char firstLetter = word[0];
			bool done = false;
			for( vii::iterator it = L[firstLetter].begin(); it != L[firstLetter].end(); ++it )
			{
				int x = it->first;
				int y = it->second;
				int arrx[] = { -1, -1, 0, 1, 1,  1,  0, -1};
				int arry[] = {  0,  1, 1, 1, 0, -1, -1, -1};
				REP( k, 8 )
				{
					bool wordFound = true;
					REP( m, size )
					{
						int X = x+m*arrx[k];
						int Y = y+m*arry[k];
						if( !( X >= 0 && X < N ) || !( Y >= 0 && Y < M ) )
						{
							wordFound = false;
							break;
						}
						if( word[m] != P[x+m*arrx[k]][y+m*arry[k]] )
						{
							wordFound = false;
							break;
						}
					}
					if( wordFound )
					{
						done = true;
						cout << x << " " << y << " " << char( 'A' + k ) << endl;
						break;
					}
				}
				if( done ) 
					break;
			}
		}
	}
}
