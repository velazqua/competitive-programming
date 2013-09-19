/* Alex Velazquez
 * Start: Sat Jun 30 18:11:30 EDT 2012
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
	std::vector<int> v( 6, 0 );
	while( 1 )
	{
		bool done = true;
		int summ = 0;
		REP( i, 6 )
		{
			cin >> v[i];
			summ += v[i]*(i+1)*(i+1);
			if( v[i] != 0 )
				done = false;
		}
		if( done )
			break;
		cout << ceil(summ/36.0) << endl;
	}
}
