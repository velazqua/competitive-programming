/* Alex Velazquez
 * Start: Sat Feb 18 17:39:25 EST 2012
 * End  : Sat Feb 18 17:59:11 EST 2012
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

bool noDigitsRepeat( LL K )
{
	vector<int> digits( 10 , 0 );
	while( K ) 
	{
		int i = K%10;
		digits[i]++;
		if( digits[i] > 1 )
			return false;
		K /= 10;
	}
	return true;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		LL X;
		cin >> X;
		if( i != 0 )
			cout << endl;
		for( LL i=1LL; i<=9999999999LL/X; ++i )
		{
			if( noDigitsRepeat( i ) )
			{
				LL y = X*i;
				if( y/i == X )
					if( noDigitsRepeat( y ) )
						cout << y << " / " << i << " = " << X << endl;
				else
					continue;
			}
		}
	}
}
