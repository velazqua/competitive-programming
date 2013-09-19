/* Alex Velazquez
 * Start: Sat Sep 15 02:08:46 EDT 2012
 * End  : Sat Sep 15 02:23:00 EDT 2012
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

struct Lang {
	char c;
	int o;
	Lang( char C, int O ) : c(C), o(O) {}
};

bool operator <( Lang const& A, Lang const& B )
{
	if( A.o > B.o )
		return true;
	else if( A.o < B.o )
		return false;
	else
		return A.c < B.c;
}

int arrx[] = {-1,0,0,1};
int arry[] = {0,1,-1,0};
void explore( vector<string> &G, int i, int j, vector<vb> &visited, int &N, int &M, char &C )
{
	visited[i][j] = true;
	REP( k, 4 )
	{
		int X = i + arrx[k];
		int Y = j + arry[k];
		if( X >= 0 && X < N && Y >= 0 && Y < M && !visited[X][Y] && G[X][Y] == C )
			explore( G, X, Y, visited, N, M, C );
	}
} 
					
int main ()
{
	int T;
	cin >> T;
	REP( t, T )
	{
		cout << "World #" << t+1 << endl;
		int N, M;
		cin >> N >> M;
		vector<string> G( N, "" );
		REP( i, N )
			cin >> G[i];
		set<Lang> L;
		map<char,int> O;
		vector<vb> visited( N, vb( M, false ) );
		REP( i, N )
		{
			REP( j, M )
			{
				if( !visited[i][j] )
				{
					O[G[i][j]]++;
					explore( G, i, j, visited, N, M, G[i][j] ); 
				}
			}
		}
		for( map<char,int>::iterator it = O.begin(); it != O.end(); it++ )
		{
			L.insert( Lang( it->first, it->second ) );
		}
		for( set<Lang>::iterator it = L.begin(); it != L.end(); ++it )
		{
			cout << it->c << ": " << it->o << endl;
		} 
	}
}
