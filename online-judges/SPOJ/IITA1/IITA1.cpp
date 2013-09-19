/* Alex Velazquez
 * Start: Sat Aug 25 16:23:55 EDT 2012
 * End  : Sat Aug 25 16:30:30 EDT 2012
*/
#include <cstdio>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)

int cB( int N )
{
	int c = 0;
	while( N )
	{
		N &= N-1;
		++c;
	}
	return c;
}

int main ()
{
	int T;
	scanf( "%d", &T );
	REP( t, T )
	{
		int a, b;
		scanf( "%d %d\n", &a, &b );
		printf( "%d\n", cB( a^b ) );
	}
}
