/* Alex Velazquez
 * Start: Mon Feb 20 14:07:12 EST 2012
 * End  :
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
	//precalculate all fibonacci numbers below 2^31
	vector<int> F( 46, 0 );
	F[0] = 1; F[1] = 1;
	for( int i=2; i<= 45 ; ++i )
		F[i] = F[i-1] + F[i-2];
	F[0] = -1;	
	int T;
	cin >> T;
	REP( i, T )
	{
		int numFibs;
		cin >> numFibs;
		vector<int> fibs( numFibs, 0 );
		int maxFib = 0;
		REP( j, numFibs )
		{
			cin >> fibs[j];
			maxFib = max( maxFib, fibs[j] );
		}
		// find all fibonaccis that don't appear in fibs[]
		vector<int>::iterator lastFib = lower_bound( F.begin(), F.end(), maxFib );
		int pos = lastFib-F.begin();
		vector<int> spaces;
		REP( j, numFibs )
		{
			if( !binary_search( F.begin(), F.end(), fibs[j] )
				spaces.push_back( fibs[j] );
		}
		if( i == 0 ) cin.ignore();
		string line;
		getline( cin, line );
		
	}
}
