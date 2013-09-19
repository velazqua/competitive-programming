/* Alex Velazquez
 * Start: Sat Mar 31 23:01:31 EDT 2012
 * End  : Sat Mar 31 23:13:01 EDT 2012
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

int GCD( int a, int b )
{
	while( b != 0 )
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

string justify( int N )
{
	string spaces = "";
	int numDigits = 0;
	while( N )
	{
		numDigits++;
		N /= 10;
	}
	REP( i, 10-numDigits )
		spaces += " ";
	return spaces;
}

int main ()
{
	int STEP, MOD;
	while( cin >> STEP >> MOD )
	{
		cout << justify( STEP ) << STEP;
		cout << justify( MOD )  << MOD ;
		if( GCD( STEP, MOD ) == 1 )
			cout << "    Good Choice" << endl;
		else
			cout << "    Bad Choice" << endl;
		cout << endl;
	}
	
}
