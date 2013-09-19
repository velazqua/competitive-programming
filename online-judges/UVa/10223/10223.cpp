/* Alex Velazquez
 * Start: Sat Jan 14 22:24:52 EST 2012
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

int main ()
{
	// precalculate all catalan numbers up to 2^32 -1
	vector<LL> catalan( 20 );
	catalan[0] = 1;
	for( int i=1; i<=19; ++i )
	{
		int n = i-1;
		catalan[n+1] = catalan[n]*(((2*n+2)*(2*n+1))/((n+2)*(n+1)));
		cout << i << " " << catalan[i] << endl;
	}
	
	map<LL,int> catMap;
	for( int i=0; i<=19; ++i )
		catMap[catalan[i]] = i;
	int N;
	while( cin >> N )
	{
		cout << catMap[N] << endl;
	}
}
