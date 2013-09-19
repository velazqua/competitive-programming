/* Alex Velazquez
 * Start: Fri Feb 17 23:13:20 EST 2012
 * End  : Fri Feb 17 23:17:46 EST 2012
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
	int a, b, c, d, L;
	while( cin >> a >> b >> c >> d >> L )
	{
		if( a == 0 && b == 0 && c == 0 && d == 0 && L == 0 ) break;
		int count = 0;
		for( int x=0; x<=L; ++x )
			if( (a*x*x+b*x+c)%d == 0 )
				++count;
		cout << count << endl;
	}
}
