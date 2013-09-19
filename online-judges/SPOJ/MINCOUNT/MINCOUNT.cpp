/* Name: Alex Velazquez
 * Start Date: October 24, 2011 @ 08:08PM
 * End Date:   October 24, 2011 @ ??:??PM
*/

#include <cstdio>

using namespace std;

typedef unsigned long long ULL;

int main ()
{
	int N;
	scanf("%d\n",&N);
	for( int i=0; i<N; ++i )
	{
		ULL t;
		scanf("%lld\n",&t);
		if( t == 1 || t == 0)
			printf("0\n");
		else if( t%2ULL == 0 ) // if even
			printf("%lld\n",(t/2ULL-1ULL)*(t/2ULL)+1ULL);
		else
			printf("%lld\n",((t+1ULL)/4ULL)*(t+1ULL)-t+1ULL);
	}
}
