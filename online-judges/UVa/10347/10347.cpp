/* Alex Velazquez
 * Start: Wed Feb  8 20:32:51 EST 2012
 * End  : Wed Feb  8 20:43:58 EST 2012
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
	double a, b, c;
	while( cin >> a >> b >> c )
	{
		double s = (a+b+c)/2.0;
		double x = s*(s-a)*(s-b)*(s-c);
		vector<int> sides( 3 );
		sides[0] = a; sides[1] = b; sides[2] = c;
		sort( sides.begin(), sides.end() );
		if( x <= 0.0 )
			printf( "-1.000\n" );
		else
			printf( "%.3f\n", sqrt( x )*(4.0/3.0) );
	}
}
