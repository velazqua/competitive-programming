/* Alex Velazquez
 * Start: Sun Mar 11 00:34:53 EST 2012
 * End  : Sun Mar 11 00:53:10 EST 2012
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

LL factorial( int N )
{
	LL ans = 1LL;
	for( int i=2; i<=N; ++i )
		ans *= i;
	return ans;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			cout << "Underflow!" << endl;
		else if( N < 0 && (N*-1)%2 == 0 )
			cout << "Underflow!" << endl;
		else if( N < 0 && (N*-1)%2 == 1 )
			cout << "Overflow!" << endl;
		else if( N <= 7 )
			cout << "Underflow!" << endl;
		else if( N > 13 )
			cout << "Overflow!" << endl;
		else
			cout << factorial( N ) << endl;
	}
}
