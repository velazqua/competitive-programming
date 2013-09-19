/* Alex Velazquez
 * Start: Sun Feb 19 23:34:21 EST 2012
 * End  : Sun Feb 19 23:41:55 EST 2012
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

void toTernary( int N )
{
	if( N == 0 )
	{
		cout << 0 << endl;
		return;
	}
	deque<int> nums;
	while( N )
	{
		nums.push_front( N%3 );
		N /= 3;
	}
	REP( i, nums.size() )
	{
		cout << nums[i];
	}
	cout << endl;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N < 0 )
			break;
		toTernary( N );
	}
}
