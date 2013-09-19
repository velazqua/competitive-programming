/* Alex Velazquez
 * Start: Tue May  8 23:08:19 EDT 2012
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	scanf( "%d\n", &T );
	REP( i, T )
	{
		int A, B;
		scanf( "%d %d\n", &A, &B );
		int X = min( A, B );
		int comdiv = 0;
		for( int i=1; i*i<=X; ++i )
		{
			if( A % i == 0 )
			{
				if( B % i == 0 )
					++comdiv;
				if( i*i != X && B % ( A/i ) == 0 )
					++comdiv;
			}
		}
		printf( "%d\n", comdiv );
	}
}
