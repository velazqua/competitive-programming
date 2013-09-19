/* Alex Velazquez
 * Start: Fri Feb 17 22:57:40 EST 2012
 * End  : Fri Feb 17 23:11:43 EST 2012
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

int main ()
{
	// precalculate all square numbers up to 10^9
	vector<int> S;
	for( int i=0; i*i <= 1000000000; ++i )
		S.push_back( i*i );
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		cout << "Case " << i+1 << ":";
		vector<int> A;
		for( int i=1; S[i]<N; ++i )
		{
			int X = N-S[i];
			if( X%i == 0 )
				A.push_back( X );
		}
		sort( A.begin(), A.end() );
		REP( i, A.size() )
			cout << " " << A[i];
		cout << endl;
	}
}
