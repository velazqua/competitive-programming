/* Alex Velazquez
 * Start: Sat Jun 30 18:37:32 EDT 2012
 * End  : Sat Jun 30 18:53:15 EDT 2012
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

int main ()
{	
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		vector<string> G( N );
		REP( j, N )
			cin >> G[j];
		cout << "Case " << i+1 << ":" << endl;
		REP( k, N )
		{
			REP( j, N )
			{
				if( G[k][j] != '.' )
				{
					cout << G[k][j];
					continue;
				}
				char c = 'A';
				while( 1 )
				{
					bool isOk = true;
					if( j != N-1 && G[k][j+1] == c ) isOk = false;
					if( j != 0   && G[k][j-1] == c ) isOk = false;
					if( k != N-1 && G[k+1][j] == c ) isOk = false;
					if( k != 0   && G[k-1][j] == c ) isOk = false;
					if( isOk )
						break;
					else
						c++;
				}
				G[k][j] = c; 
				cout << c;
			}
			cout << endl;
		}
	}
}
