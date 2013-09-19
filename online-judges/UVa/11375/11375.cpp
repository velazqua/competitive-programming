/* Alex Velazquez
 * Start: Sun May  6 22:34:46 EDT 2012
 * End  :
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

int main ()
{
	vector<int> ans( 2001, 0 );
	vector<int> matches( 10, 0 );
	int arr[] = {6,2,5,5,4,5,6,3,7,6};
	REP( i, 10 )
		matches[i] = arr[i];
	ans[0] = 0; ans[1] = 0; ans[2] = 1;
	// precalculate all values of ans
	FOR( i, 3, 2000+1 )
	{
		//if( i >= 6 ) ans[i]++;
		REP( j, 10 )
		{
			if( matches[j] <= i )
			{	
				ans[i]++;
				if( j != 0 ) ans[i] += ans[i-matches[j]]; 
			}
		}
	}
	int N;
	while( cin >> N )
	{
		if( N == 0 || N == 1 )
			cout << 0 << endl;
		else
			cout << ans[N] << endl;
	}
}
