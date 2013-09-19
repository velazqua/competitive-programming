/* Alex Velazquez
 * Start: Sun Nov 27 18:34:37 EST 2011
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
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int M, C;
		cin >> M >> C;
		vector<vector<int> > V;
		for( int j=0; j<C; ++j )
		{
			int K, p;
			cin >> K;
			vector<int> t;
			for( int k=0; k<K; ++k )
			{
				cin >> p;
				t.push_back( p );
			}
			sort( t.begin(), t.end() );
		}
		// check if there is a solution
		int summ = 0;
		for( int j=0; j<C; ++j )
			summ += V[j][0];
		if( summ > M )
		{
			cout << "no solution" << endl;
		}
		else if( summ == M )
			cout << summ << endl;
		else
		{
			
		}
	}
}
