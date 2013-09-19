/* Alex Velazquez
 * Start: Sat Feb 18 18:21:40 EST 2012
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

struct Stats {
	double wins;
	double losses;
	bool playing;
	Stats( double w, double l, bool p ) : wins(w), losses(l), playing(p) {}
};

void whoWon( int p1, string m1, int p2, string m2, vector<Stats> &S )
{
	if( m1.compare( m2 ) != 0 )
	{
		if( ( !m1.compare( "scissors" ) && !m2.compare( "paper" ) ) ||
			( !m1.compare( "paper" ) && !m2.compare( "rock" ) ) ||
			( !m1.compare( "rock" ) && !m2.compare( "scissors" ) ) 
		)
			S[p1].wins += 1.0, S[p2].losses += 1.0;
		else
			S[p2].wins += 1.0, S[p1].losses += 1.0;
	}
}

int main ()
{
	int n, k;
	int c = 0;
	while( cin >> n )
	{
		if( n == 0 ) break;
		cin >> k;
		if( c != 0 ) printf( "\n" );
		++c; 
		int p1, p2;
		string m1, m2;
		vector<Stats> stats( 101, Stats( 0, 0, false ) );
		REP( i, (k*((n*(n-1))/2)) )
		{
			cin >> p1 >> m1 >> p2 >> m2;
			stats[p1].playing = true;
			stats[p2].playing = true;
			whoWon( p1, m1, p2, m2, stats );
		}
		for( int i=1; i<=n; ++i )
		{
			if( stats[i].playing && stats[i].wins == 0 && stats[i].losses == 0 )
				printf( "-\n" );
			else if( stats[i].playing )
				printf( "%.3lf\n", (stats[i].wins)/(stats[i].wins+stats[i].losses) );
		}
	}
}
