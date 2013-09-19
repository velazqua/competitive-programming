/* Alex Velazquez
 * Start: Tue Sep 11 22:41:02 EDT 2012
 * End  : Tue Sep 11 23:56:45 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	set<int> cabNumbers;
	set<int> potentialCab;
	FOR( i, 1, 1001 )
	{
		FOR( j, i+1, 1001 )
		{
			int X = i*i*i + j*j*j;
			pair< set<int>::iterator, bool > result = potentialCab.insert( X );
			if( result.second == false )
			{
				cabNumbers.insert( X );
			}
		}
	}
	int N, D;
	while( cin >> N >> D )
	{
		int Y = N+D;
		set<int>::iterator N1 = lower_bound( ALL(cabNumbers), N );
		bool found = false;
		for( ; N1 != cabNumbers.end(); ++N1 )
		{
			if( *N1 <= Y )
			{
				found = true;
				cout << *N1 << endl;
			}
			else
				break;
		}
		if( !found )
			cout << "None" << endl;
	}
	
}
