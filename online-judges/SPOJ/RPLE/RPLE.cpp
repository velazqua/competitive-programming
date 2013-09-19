/* Alex Velazquez
 * Start: Sun Apr 15 20:31:50 EDT 2012
 * End  : Sun Apr 15 20:39:33 EDT 2012
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int N, R;
		cin >> N >> R;
		vector<int> ppl( N );
		bool spying = true;
		set<int> S, C;
		REP( j, R )
		{
			int R1, R2;
			cin >> R1 >> R2;
			C.insert( R1 );
			S.insert( R2 );
		}
		REP( j, N )
		{
			if( C.count( j ) > 0 && S.count( j ) > 0 )
			{
				spying = false;
				break;
			}
		}
		cout << "Scenario #" << i+1 << ": ";
		if( spying )
			cout << "spying" << endl;
		else
			cout << "spied" << endl;
	}
}
