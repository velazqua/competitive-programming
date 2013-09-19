/* Alex Velazquez
 * Start: Tue Mar 20 19:39:43 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	string S;
	int c = 1;
	while( cin >> S )
	{
		int Q, a, b, i, j;
		cin >> Q;
		cout << "Case " << c++ << ":" << endl;
		while( Q-- )
		{
			cin >> a >> b;
			i = min( a, b );
			j = max( a, b );
			string SB = S.substr( i, j-i+1 );
			sort( SB.begin(), SB.end() );
			if( SB[0] == SB[j-i] )
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
