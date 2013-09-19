/* Alex Velazquez
 * Start: Wed Mar 28 22:00:54 EDT 2012
 * End  : Wed Mar 28 22:08:50 EDT 2012
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
	int N, M;
	while( 1 )
	{
		scanf( "%d %d\n", &N, &M );
		if( N == 0 && M == 0 ) break;
		set<int> jill;
		int x;
		REP( i, N )
		{
			scanf( "%d\n", &x );
			jill.insert( x ); 
		}
		int counter = 0;
		REP( i, M )
		{
			scanf( "%d\n", &x );
			pair<set<int>::iterator,bool> result = jill.insert( x );
			if( !result.second )
				++counter;
		}
		cout << counter << endl;
	}
}
