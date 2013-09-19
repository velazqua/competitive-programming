/* Alex Velazquez
 * Start: Thu May 10 20:33:28 EDT 2012
 * End  : Thu May 10 20:38:10 EDT 2012
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
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		vector<int> nums( N );
		REP( j, N )
			cin >> nums[j];
		sort( nums.begin(), nums.end() );
		cout << 2*(*(nums.end()-1)-*(nums.begin())) << endl;
	}
}
