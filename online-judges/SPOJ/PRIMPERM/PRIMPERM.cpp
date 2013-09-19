/* Alex Velazquez
 * Start: Fri Aug 17 01:30:20 EDT 2012
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
#include <cassert>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 		 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int numPrimPerm( unsigned int N, vector<bool> &primes, vector<int> &dp )
{
	if( N == 2 )
		return 1;
	int total = 0;
	vector<char> digits;
	while( N )
	{
		int d = N%10;
		digits.push_back( d );
		N /= 10;
	}
	int numDigits = SZ( digits );
	sort( ALL(digits) );
	vector<unsigned int> nums;
	do
	{
		if( digits[0] == 0 || digits[numDigits-1] == 0 || digits[numDigits-1] == 2 || digits[numDigits-1] == 4 || digits[numDigits-1] == 6 || digits[numDigits-1] == 8)
			continue;
		unsigned int number = 0;
		unsigned int t = 1;
		for( int k=numDigits-1; k>=0; --k )
			number += digits[k]*t, t *= 10;
		if( !primes[number] )
		{
			#if DEBUG
				cout << number << " is prime" << endl;
			#endif
			++total;
		}
		nums.push_back( number );
	} while( next_permutation( digits.begin(), digits.end() ) );
	int sizeNums = SZ(nums);
	REP( i, sizeNums )
		dp[nums[i]] = total;
	return total;
}
 
int main ()
{
    unsigned int lim = 10000001, i, j;
	vector<int> dp( 10000001, -1 );
	vector<bool> primes( 10000001, false );
    lim += 1;
	primes[0] = true;
	primes[1] = true;
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;

	int T;
	scanf( "%d", &T );
	
	REP( t, T )
	{
		int n;
		scanf( "%d", &n );
		if( dp[n] != -1 )
			printf( "%d\n", dp[n] );
		else
			printf( "%d\n", numPrimPerm( n, primes, dp ) );
	}
}
