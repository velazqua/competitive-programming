/* Alex Velazquez
 * Start: Fri May 11 19:49:02 EDT 2012
 * End  : Fri May 11 19:53:09 EDT 2012
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
	string S;
	while( cin >> S )
	{
		if( !S.compare( "#" ) ) break;
		bool worked = next_permutation( S.begin(), S.end() );
		if( worked ) 
			cout << S << endl;
		else
			cout << "No Successor" << endl;
	}
}
