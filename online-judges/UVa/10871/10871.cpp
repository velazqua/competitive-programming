/* Alex Velazquez
 * Start: Sun Mar 25 14:55:08 EDT 2012
 * End  : Sun Mar 25 15:35:08 EDT 2012
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPrime( int N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( N%i == 0 )
			return false;
	return true;
}

bool isPrime2( int N, vector<int> &primes )
{
	if( N <= 10000 )
		return binary_search( primes.begin(), primes.end(), N );
	else
	{
		int size = primes.size();
		for( int i=0; i<size; ++i )
			if( N%primes[i] == 0 )
				return false;
		return true;
	}
}

int main ()
{
	vector<int> primes;
	primes.push_back( 2 );
	for( int i=3; i<10000; i+=2 )
		if( isPrime( i ) )
			primes.push_back( i );
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		vector<int> nums( N );
		REP( j, N )
			cin >> nums[j];
		int S = N+1;
		vector<int> sseq;
		vector<int> aseq;
		REP( j, N-1 )
		{
			sseq.clear();
			sseq.push_back( nums[j] );
			int currSum = nums[j];
			FOR( k, j+1, N )
			{
				currSum += nums[k];
				sseq.push_back( nums[k] );
				if( k-j+1 < S )
				{
					if( isPrime2( currSum, primes )  )
					{
						//cout << "currSum: " << currSum << endl;
						S = k-j+1;
						aseq = sseq;
					}
				}
				else
					break;
			}
		}
		if( S == N+1 )
			cout << "This sequence is anti-primed." << endl;
		else
		{
			cout << "Shortest primed subsequence is length " << S << ":";
			for( vector<int>::iterator it=aseq.begin();it!=aseq.end();++it )
				cout << " " << *it;
			cout << endl;
		}
	}
}
