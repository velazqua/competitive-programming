/* Alex Velazquez
 * Start: Wed Apr 18 21:28:09 EDT 2012
 * End  : Wed Apr 18 21:43:27 EDT 2012
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
	int R, N;
	int i = 1;
	while( cin >> R >> N )
	{
		if( N == 0 && R == 0 ) break;
		cout << "Case " << i++ << ": ";
		if( N*27 < R ) 
			cout << "impossible" << endl;
		else
		{
			REP( k, 27 )
			{
				if( N*(k+1) >= R )
				{
					cout << k << endl;
					break;
				}
			}
		}
	}
}
