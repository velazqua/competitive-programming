/* Alex Velazquez
 * Start: Fri Feb 24 19:08:57 EST 2012
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

void extendedEuclid( int a, int b, int &x, int &y, int &d )
{
	if( b == 0 )
	{
		x = 1;
		y = 0; 
		d = a;
		return;
	}
	else
	{
		extendedEuclid( b, a%b, x, y, d );
		int x1 = y;
		int y1 = x - (a/b)*y;
		x = x1;
		y = y1;
	}
}

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		double x, k;
		cin >> x >> k;
		int x1, y1, d = x;
		int a = floor(x/k);
		int b = ceil(x/k);
		extendedEuclid( a, b, x1, y1, d );
		cout << "x1: " << x1 << endl;
		cout << "y1: " << y1 << endl;  
		cout << "d: " << d << endl;
		int mult = x/GCD(a,b);
		x1 *= mult;
		y1 *= mult;
		
	}
}
