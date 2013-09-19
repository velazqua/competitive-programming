/* Alex Velazquez
 * Start: Wed Mar 28 00:42:30 EDT 2012
 * End  : Wed Mar 28 00:54:21 EDT 2012
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
	while( cin >> N )
	{
		if( !N ) break;
		map<set<int>,int> M;
		REP( i, N )
		{
			set<int> nums;
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			nums.insert( a ); nums.insert( b );
			nums.insert( c ); nums.insert( d );
			nums.insert( e );
			M[nums]++;
		}
		vector<int> totals;
		for( map<set<int>,int>::iterator it=M.begin(); it!=M.end(); ++it )
		{
			//cout << "it->second: " << it->second << endl;
			totals.push_back( it->second );
		}
		sort( totals.begin(), totals.end(), greater<int>() );
		int highest = totals[0];
		int counter = 0;
		int size = totals.size();
		REP( i, size )
			if( totals[i] == highest )
				++counter;
			else
				break;
		cout << counter*highest << endl;
	}
}
