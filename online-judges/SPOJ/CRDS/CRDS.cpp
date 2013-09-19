/* Alex Velazquez
 * Start: Tue Feb 14 20:01:29 EST 2012
 * End  : Tue Feb 14 20:07:35 EST 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;


int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		LL N;
		cin >> N;
		cout << ((N*(N+1LL)/2LL)*3LL-N)%1000007LL << endl;
	}
}
