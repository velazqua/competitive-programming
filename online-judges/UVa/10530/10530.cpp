/* Alex Velazquez
 * Start: Sun Feb 19 23:44:26 EST 2012
 * End  : Sun Feb 19 23:53:30 EST 2012
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
	int N;
	string f, s;
	bool done = false;
	while( !done )
	{
		vector<int> nums( 11, 0 );
		nums[0] = -1;
		while( cin >> N )
		{
			if( N == 0 )
			{
				done = true;
				break;
			}
			cin >> f >> s;
			if( !f.compare( "right" ) )
			{
				if( nums[N] == 0 )
					cout << "Stan may be honest" << endl;
				else
					cout << "Stan is dishonest" << endl;
				break;
			}
			else if( !s.compare( "high" ) )
			{
				for( int i=N; i<=10; ++i )
					nums[i] = -1;
			}
			else
			{
				for( int i=N; i>=0; --i )
					nums[i] = -1;
			}
		}
	}
}
