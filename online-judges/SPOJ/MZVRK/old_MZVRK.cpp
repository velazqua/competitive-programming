/* Name: Alex Velazquez
 * Start Date: November 05, 2011 @ 02:23PM
 * End Date:   November 05, 2011 @ ???????
*/

#include <cstdio>
#include <iostream>
#include <vector>

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

void whirligig( ULL &power2, int k, ULL currSum, ULL &summ, ULL &counter, ULL &A, ULL &B, vector<ULL> &powerOfTwos ) 
{
	for( int i=k; i<50; ++i )
	{
		ULL nextSum = currSum + powerOfTwos[i];
		//cout << nextSum << endl;
		if( nextSum > B )
			break;
		else if( nextSum >= A )
		{
			summ += power2;
			++counter;
		}
		if( counter < B+1-A )
			whirligig( power2, i+1, nextSum, summ, counter, A, B, powerOfTwos);
	}
}

int main ()
{
	ULL A, B;
	scanf( "%lld %lld", &A, &B );
	ULL counter = 0ULL, summ = 0ULL;
	vector<ULL> power2;
	power2.push_back( 1ULL ); power2.push_back( 2ULL );
	for( int i=2; i<50; ++i )
		power2.push_back( power2[i-1]*2ULL );
	
	for( int i=0; i<50; ++i )
	{
		if( power2[i] > B )
			break;
		else if( power2[i] >= A )
			summ += power2[i];
		whirligig( power2[i], i+1, power2[i], summ, counter, A, B, power2 );
	}
	printf( "%lld\n", summ );
}
