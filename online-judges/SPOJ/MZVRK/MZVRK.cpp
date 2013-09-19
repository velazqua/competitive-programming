/* Name: Alex Velazquez
 * Start Date: November 05, 2011 @ 02:23PM
 * End Date:   November 05, 2011 @ 04:44PM
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ULL;

ULL poww2( int K )
{
	if( K == 0 ) return 1ULL;
	else if( K == 1 ) return 2ULL;
	ULL X = 1ULL;
	for( int i=0; i<K; ++i )
		X *= 2;
	return X;
} 

int main ()
{
	ULL A, B;
	scanf( "%lld %lld", &A, &B );
	A -= 1ULL;
	ULL summA = 0ULL, summB = 0ULL;
	vector<ULL> power2;
	power2.push_back( 1ULL ); power2.push_back( 2ULL );
	for( int i=2; i<51; ++i )
		power2.push_back( power2[i-1]*2ULL );
	
	for( int i=0; power2[i]<=B; ++i )
	{
		if( power2[i]<= A ) summA += ( ( A-power2[i] )/power2[i+1] + 1ULL ) * power2[i];
		summB += ( ( B-power2[i] )/power2[i+1] + 1ULL ) * power2[i] ;
	}
	printf( "%lld\n", summB-summA );
}
