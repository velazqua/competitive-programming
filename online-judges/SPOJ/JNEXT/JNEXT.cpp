/* Alex Velazquez
 * Start: Mon Sep 24 13:37:55 EDT 2012
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
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	scanf( "%d", &T );
	REP( t, T )
	{
		int N;
		scanf( "%d", &N );
		vector<int> nums( N, 0 );
		REP( i, N )
			scanf( "%d", &nums[i] );
		bool good = next_permutation( nums.begin(), nums.end() );
		if( !good )
			printf( "-1\n" );
		else
		{
			REP( i, N )
				printf( "%d", nums[i] );
			printf( "\n" );
		}
	}
}
