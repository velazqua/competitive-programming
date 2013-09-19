/* Alex Velazquez
 * Start: Sun Feb 19 17:32:15 EST 2012
 * End  : Sun Feb 19 17:42:22 EST 2012
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

int countVal( char c )
{
	int v = c;
	if( v>=97 && v<=122 )
		return v-96;
	else
		return v-64+26;
}

bool isPrime( int N )
{
	if( N == 1 || N == 2 )
		return true;
	else if( N%2 == 0 )
		return false;
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

int main ()
{
	string W;
	while( cin >> W )
	{
		int total = 0;
		int size = W.size();
		REP( i, size )
			total += countVal( W[i] );
		if( isPrime( total ) )
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}
}
