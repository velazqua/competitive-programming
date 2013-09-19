/* Alex Velazquez
 * Start: Fri Sep 28 20:40:31 EDT 2012
 * End  : Mon Oct  1 22:16:36 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define MP			 make_pair
#define DEBUG        0

typedef unsigned long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

LL find( map< pair<int,int>, LL>  &dp, int n, int back )
{
	//cout << "Called (" << n << "," << back << ")" << endl;
	pair<int,int> curr = MP(n,back);
	if( dp[curr] )
		return dp[curr];
	dp[curr] += 1LL;
	if( n <= 0 ) return 0LL;
	if( n == 1 ) return 1LL;
	for( int i=1; i<=back; ++i )
	{
		if( dp[MP(n-i,back)] != 0LL )
		{
			dp[curr] += dp[MP(n-i,back)];
		}
		else
		{
			LL p = find( dp, n-i, back );
			dp[MP(n-i,back)] = p;
			dp[curr] += dp[MP(n-i,back)];
		} 
	}
	return 1LL;
}

int main ()
{
	map< pair<int,int>, LL > dp;
	for( int i=-65; i<=1; ++i )
	{
		for( int j=-65; j<65; ++j )
		{
			dp[MP(i,j)] = 1LL;
			if( i <= 0 )
				dp[MP(j,i)] = 1LL;
		}
	}
	for( int i=1; i<65; ++i )
	{
		for( int j=1; j<65; ++j )
			find( dp, i, j );
	}	
	int n, back;
	int c = 1;
	while( cin >> n >> back )
	{
		if( n > 60 )
			break;
		cout << "Case " << c++ << ": " << dp[MP(n,back)] << endl;
	}
}
