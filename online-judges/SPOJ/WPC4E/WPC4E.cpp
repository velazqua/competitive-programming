/* Name: Alex Velazquez
 * Start Date: October 24, 2011 @ 09:02PM
 * End Date:   October 24, 2011 @ ??:??PM
*/

#include <cstdio>
#include <map>

typedef unsigned long long ULL;

using namespace std;

ULL calcF( int N, map<int,ULL> &F )
{
	if( F[N] )
	{
		return F[N];
	}
	else
	{
		return calcF(N/4,F) + 2*calcF(N/10,F) + 2*calcF(N/14,F) +
			calcF(N/25,F) + 2*calcF(N/35,F) + calcF(N/49,F);
	}
}

int main ()
{
	int T;
	scanf( "%d\n", &T );
	int N;
	map<int,ULL> F;
	F[0] = 1;
	/*
	for( int i=0; i<T; ++i )
	{
		scanf( "%d\n", &N );
		printf("%lld\n", calcF(N,F));
	}
	*/
	for( int i=1;i<500000;++i)
	{
		F[i] = F[i/2] + F[i/5] + F[i/7];
	}
	for( int i=0; i<T; ++i )
	{
		scanf( "%d\n", &N );
		printf("%lld\n", calcF(N,F));
	}
}
