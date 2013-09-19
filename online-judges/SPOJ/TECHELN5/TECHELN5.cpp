/* Alex Velazquez
 * Start: Tue Apr 17 22:13:56 EDT 2012
 * End  : Tue Apr 17 22:27:05 EDT 2012
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
		if( N%2 ) // if odd
			N--;
		if( (N/2)%2 == 0 )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
