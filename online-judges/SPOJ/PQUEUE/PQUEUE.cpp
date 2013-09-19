/* Alex Velazquez
 * Start: Thu Feb 16 22:28:27 EST 2012
 * End  :
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
		int n, m;
		cin >> n >> m;
		vector<int> nums( n );
		REP( j, n ) cin >> nums[j];
	}
}
