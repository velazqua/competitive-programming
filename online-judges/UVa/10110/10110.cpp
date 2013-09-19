/* Alex Velazquez
 * Start: Fri Mar 30 21:51:49 EDT 2012
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

int countDivisors( LL N )
{
	if( N == 1LL )
		return 1;
	else if( N == 2LL || N == 3LL )
		return 2;
	int c = 0;
	for( LL i=1LL; i*i<= N; ++i )
	{
		if( N%i == 0 ) // if divisible
		{
			if( i*i == N ) // square
				++c;
			else
				c += 2;
		}
	}
	return c;
}

int main ()
{
	LL N;
	while( cin >> N )
	{
		if( !N ) break;
		int numDivisors = countDivisors( N );
		if( numDivisors%2 == 0 )
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
}
