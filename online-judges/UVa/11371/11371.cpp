/* Alex Velazquez
 * Start: Fri Mar 16 23:08:27 EDT 2012
 * End  : Fri Mar 16 23:29:15 EDT 2012
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
	string n;
	while( cin >> n )
	{
		vector<int> digits( 10, 0 );
		REP( i, n.size() )
			digits[n[i]-'0']++;
		vector<int> digits2 = digits;
		// Make biggest permutation of n
		LL x = 1LL;
		LL a = 0LL;
		for( int i=0; i<10; ++i )
		{
			while( digits[i] )
			{
				a += x*i;
				digits[i]--;
				x *= 10LL;
			}
		}
		//cout << "a: " << a << endl;
		// Make lowest permutation of n (no leading zeroes)
		x = 1LL;
		LL b = 0LL;
		// find first digit of b
		LL f = 0LL;
		for( int i=1; i<10; ++i )
		{
			if( digits2[i] > 0 )
			{
				f = (LL)i;
				digits2[i]--;
				break;
			}
		}
		
		for( int i=9; i>0; --i )
		{
			while( digits2[i] )
			{
				b += x*i;
				digits2[i]--;
				x *= 10LL;
			}		
		}
		
		//add the zeroes and then the first digit!
		while( digits2[0] ) 
		{
			x *= 10LL;
			digits2[0]--;
		}
		
		b += x*f; 
		//cout << "b: " << b << endl;
		LL c = a-b;
		cout << a << " - " << b << " = " << c << " = ";
		cout << 9 << " * " << c/9LL << endl; 
	}
}
