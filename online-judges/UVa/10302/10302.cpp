/* Alex Velazquez
 * Start: Mon Mar 19 23:42:24 EDT 2012
 * End  : Mon Mar 19 23:47:15 EDT 2012
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
typedef unsigned long long int ULL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	vector<ULL> nums( 50005, 0ULL );
	for( ULL i=1ULL; i<=50000ULL; ++i )
		nums[i] = i*i*i + nums[i-1];
	int X;
	while( cin >> X )
	{
		cout << nums[X] << endl;
	}
}
