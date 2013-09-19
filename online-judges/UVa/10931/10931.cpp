/* Alex Velazquez
 * Start: Mon Feb 20 20:17:49 EST 2012
 * End  : Mon Feb 20 20:21:37 EST 2012
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

void solve( int I )
{
	int count = 0;
	string b = "";
	while( I ) 
	{
		if( I%2 ) ++count;
		b = char((I%2)+48)+b;
		I /= 2;
	}
	cout << "The parity of " << b << " is " << count << " (mod 2)." << endl;
}

int main ()
{
	int I;
	while( cin >> I )
	{
		if( I == 0 ) break;
		solve( I );
	}
}
