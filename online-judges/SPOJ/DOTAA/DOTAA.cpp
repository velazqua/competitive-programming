/* Alex Velazquez
 * Start: Sun Jan 22 18:27:27 EST 2012
 * End  : Sun Jan 22 18:46:29 EST 2012
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

typedef long long int LL;


int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int n, m, D;
		cin >> n >> m >> D;
		vector<int> health( n );
		REP( j, n )
			cin >> health[j];
		sort( health.begin(), health.end(), greater<int>() );
		bool win = true;
		REP( j, n )
		{
			m -= health[j]/D;
			m += ( health[j]%D == 0 ) ? 1 : 0;
		}
		if( m > 0 )
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
}
