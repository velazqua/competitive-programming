/* Alex Velazquez
 * Start: Tue Jun 26 22:47:21 EDT 2012
 * End  : Tue Jun 26 23:29:15 EDT 2012
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
#define DEBUG 0

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
	if( i == 11 ) // there are only 11 coin denominations
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
	int V[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	string X;
	vector< vector<LL> > dp( 30001, vector<LL>( 12, -1LL ) );
	while( cin >> X )
	{
		stringstream lineStream( X );
		int dollarPart, centPart;
		char dot;
		lineStream >> dollarPart >> dot >> centPart; 
		int A = dollarPart*100+centPart; // round dollars to cents
		if( A == 0 )
			break;
		LL answer = numWays( A, V, 0, dp );
		cout << spaces( 6-(int)X.size() ) << X;
		printf( "%*lld\n", 17, answer );
	}
}
