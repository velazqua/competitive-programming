/* Alex Velazquez
 * Start: Fri Feb 10 22:36:49 EST 2012
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

using namespace std;

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int n, m;
	while( cin >> n >> m )
	{
		vector<vi> AdjList;
		AdjList.assign( n, vi() );
		if( n == 0 && m == 0 )
			break;
		//read edges
		REP( i, m )
		{
			int x, y;
			cin >> x >> y;
			AdjList[x].push_back( y );
		}
		int answer = bfs( AdjList, n, k );
		if( answer < k )
			cout << "LOSER" << endl;
		else
			cout << answer << endl;
	}
}
