/* Alex Velazquez
 * Start: Mon Mar  5 00:24:10 EST 2012
 * End  : Mon Mar  5 00:26:26 EST 2012
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
	int totalAmount = 0;
	REP( i, T )
	{
		string action;
		cin >> action;
		if( !action.compare( "donate" ) )
		{
			int amount;
			cin >> amount;
			totalAmount += amount;
		}
		else
			cout << totalAmount << endl;
	}
}
