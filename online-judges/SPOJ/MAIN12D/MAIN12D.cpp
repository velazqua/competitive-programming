/* Alex Velazquez
 * Start: Tue Apr 17 23:03:47 EDT 2012
 * End  : Tue Apr 17 23:10:45 EDT 2012
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

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		cout << "Case #" << i+1 << ": ";
		int N, M;
		cin >> N >> M;
		vector<int> nums( M );
		int maxx = 0;
		REP( j, M )
		{
			cin >> nums[j];
			maxx = max( maxx, nums[j] );
		}
		
		if( M == 0 )
		{
			cout << "1/1" << endl;
			continue;
		}
	
		int den = N-maxx;
		int num = N;
		int gcd = GCD( den, num );
		den /= gcd;
		num /= gcd;
		cout << den << "/" << num << endl;
	}
}
