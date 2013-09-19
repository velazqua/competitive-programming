/* Alex Velazquez
 * Start: Tue May  8 00:39:29 EDT 2012
 * End  : Tue May  8 00:47:02 EDT 2012
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

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		cout << "Scenario #" << i+1 << ": ";
		int hours = (9+(N/60))%24;
		int minutes = N%60;
		cout << ( (hours<10)?"0":"" ) << hours << ":" << ( (minutes<10)?"0":"" ) << minutes << endl;
		if( i != T-1 ) cout << endl;
	}
}
