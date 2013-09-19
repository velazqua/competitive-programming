/* Alex Velazquez
 * Start: Mon Mar  5 00:19:10 EST 2012
 * End  : Mon Mar  5 00:22:31 EST 2012
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
	int T;
	cin >> T;
	REP( i, T )
	{
		int l, w, h;
		cin >> l >> w >> h;
		cout << "Case " << i+1 << ": ";
		if( l <= 20 && w <= 20 && h <= 20 )
			cout << "good" << endl;
		else
			cout << "bad" << endl;
	}
}
