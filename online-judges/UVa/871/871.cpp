/* Alex Velazquez
 * Start: Sun Apr 29 00:08:38 EDT 2012
 * End  : Sun Apr 29 00:29:38 EDT 2012
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

bool isOk( int x, int y, int N, int M )
{
	return ( ( x >= 0 && x < N && y >= 0 && y < M ) ? true : false );
}

void countBlob( vector<string> &B, vector<vector<bool> > &visited, int j, int k, const int& N, const int &M, int &C )
{
	if( isOk( j, k, N, M ) && !visited[j][k] && B[j][k] == '1' )
	{
		visited[j][k] = true;
		++C;
		int arrx[] = {-1,-1,-1,0,0,1,1,1};
		int arry[] = {-1,0,1,-1,1,-1,0,1};
		for( int i=0; i<8; ++i )
			countBlob( B, visited, j+arrx[i], k+arry[i], N, M, C );
	}
}

int main ()
{
	int T;
	cin >> T;
	string dummy;
	getline( cin, dummy ); // dummy newline
	REP( i, T )
	{
		if( i != 0 ) cout << endl;
		string line;
		vector<string> B;
		if( i == 0 ) cin.ignore();
		while( getline( cin, line ) )
		{
			if( !line.compare( "" ) ) break;
			B.push_back( line );
		}
		int N = B.size(), M = B[0].size();
		vector<vector<bool> > visited( N, vector<bool>( M, false ) );
		int largestBlob = 0;
		REP( j, N )
		{
			REP( k, M )
			{
				if( !visited[j][k] && B[j][k] == '1' )
				{
					int blob = 0;
					countBlob( B, visited, j, k, N, M, blob );
					largestBlob = max( largestBlob, blob );
				}
			}
		}
		cout << largestBlob << endl;
	}
}
