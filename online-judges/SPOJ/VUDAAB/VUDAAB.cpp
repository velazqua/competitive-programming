/* Alex Velazquez
 * Start: Tue May  8 02:14:05 EDT 2012
 * End  : Tue May  8 02:18:41 EDT 2012
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
		int a, b, c;
		cin >> a >> b >> c;
		// check for arithmetic exp.
		if( b-a == c-b )
			cout << c+b-a << endl;
		else
			cout << c*(b/a) << endl;
	}
}
