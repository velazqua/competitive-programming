/* Alex Velazquez
 * Start: Sun Jul 22 02:36:44 EDT 2012
 * End  : Sun Jul 22 04:26:05 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0
#define MOD			 1000000

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int calc( vector<vi> &A, int N, int K )
{
	if( N < 0 || K < 0 )
		return 0;
	if( A[N][K] != 0 )
		return A[N][K];
	if( K == 1 )
		return 1;
	else
	{
		for( int i=0; i<=N; ++i )
			A[N][K] += calc( A, N-i, K-1 ) % MOD;
		return A[N][K];
	}
} 

int main ()
{
	vector< vector<int> > A( 101, vector<int>( 101, 0 ) );
	int N, K;
	while( cin >> N >> K )
	{
		if( N == 0 && K == 0 )
			break;
		if( A[N][K] == 0 )
		{
			if( K == 1 )
				A[N][K] = 1;
			else
			{
				for( int i=0; i<=N; ++i )
					A[N][K] += calc( A, N-i, K-1 ) % MOD;
			}
		}
		cout << A[N][K] % MOD << endl;
	}
}
