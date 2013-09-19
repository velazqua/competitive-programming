/* Alex Velazquez
 * Start: Tue Dec 20 19:02:53 EST 2011
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

int main ()
{
	int C, N;
	cin >> C >> N;
	vector<int> W( N );
	vector<int> V( N );
	for( int i=0; i<N; ++i )
	{
		int w, v;
		cin >> w >> v;
		W[i] = w;
		V[i] = v;
	}
	vector<vector<int> > R;
	vector<int> TEMP( C+1, 0 );
	for( int i=0; i<=N; ++i )
		R.push_back( TEMP );
	for( int i=1; i<=N; ++i )
	{
		for( int j=1; j<=C; ++j )
		{
			if( W[i-1] > j || R[i-1][j] > R[i-1][j-W[i-1]]+V[i-1] )
				R[i][j] = R[i-1][j];
			else
				R[i][j] = R[i-1][j-W[i-1]]+V[i-1];
		}
	}
	cout << R[N][C] << endl;
}
