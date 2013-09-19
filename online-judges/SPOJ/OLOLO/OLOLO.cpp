/* Alex Velazquez
 * Start: November 22, 2011 @ 08:50PM
 * End  : November 22, 2011 @ 09:02PM
*/

#include <cstdio>

using namespace std;

int main ()
{
	int t;
	int n;
	scanf( "%d\n", &n );
	int answer = 0;
	for( int i=0; i<n; ++i )
	{
		scanf( "%d\n", &t );
		answer ^= t;
	}
	answer ^= 0;
	printf( "%d\n", answer );
}
