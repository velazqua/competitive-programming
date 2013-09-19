/* Alex Velazquez
 * Start: Tue Jun 26 23:32:37 EDT 2012
 * End  : Tue Jun 26 23:39:00 EDT 2012
 *  Let Me Count The Ways 

After making a purchase at a large department store, Mel's change was 17 cents. He received 1 dime, 1 nickel, and 2 pennies. Later that day, he was shopping at a convenience store. Again his change was 17 cents. This time he received 2 nickels and 7 pennies. He began to wonder ' "How many stores can I shop in and receive 17 cents change in a different configuration of coins? After a suitable mental struggle, he decided the answer was 6. He then challenged you to consider the general problem.

Write a program which will determine the number of different combinations of US coins (penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50c) which may be used to produce a given amount of money.

Input

The input will consist of a set of numbers between 0 and 30000 inclusive, one per line in the input file.

Output

The output will consist of the appropriate statement from the selection below on a single line in the output file for each input value. The number m is the number your program computes, n is the input value.

There are m ways to produce n cents change.

There is only 1 way to produce n cents change.

Sample input

17 
11
4
Sample output

There are 6 ways to produce 17 cents change. 
There are 4 ways to produce 11 cents change. 
There is only 1 way to produce 4 cents change.
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
	vector< vector<LL> > dp( 30001, vector<LL>( 5, -1LL ) );
	while( cin >> X )
	{
		LL answer = numWays( X, V, 0, dp );
		if( answer == 1LL )
			cout << "There is only 1 way to produce " << X << " cents change." << endl;
		else
			cout << "There are " << answer << " ways to produce " << X << " cents change." << endl;
	}
}
