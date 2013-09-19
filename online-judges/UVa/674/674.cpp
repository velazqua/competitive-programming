/* Alex Velazquez
 * Start: Tue Jun 26 23:43:08 EDT 2012
 * End  : Tue Jun 26 23:45:05 EDT 2012
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

LL numWays( int money, int V[], int i, vector< vector<LL> > &dp )
{
	#if DEBUG
		cout << "money: " << money << ". i: " << i << endl;
	#endif
	if( i == 5 ) // there are only 11 coin denominations
		return 0LL;
	if( money == 0 )
		return 1LL;
	else if( money < 0 )
		return 0LL;
	if( dp[money][i] != -1LL )
		return dp[money][i];
	else
	{
		dp[money][i] = numWays( money, V, i+1, dp ) + numWays( money-V[i], V, i, dp );
		return dp[money][i];
	}
}

string spaces( int N )
{
	string S = "";
	REP( i, N )
		S += ' ';
	return S;
}

int main ()
{
	// coin denominations 
	int V[] = {1,5,10,25,50};
	int X;
	vector< vector<LL> > dp( 7500, vector<LL>( 5, -1LL ) );
	while( cin >> X )
	{
		LL answer = numWays( X, V, 0, dp );
		cout << answer << endl;
	}
}
