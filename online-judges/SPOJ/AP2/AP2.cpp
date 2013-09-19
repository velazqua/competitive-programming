/* Alex Velazquez
 * Start: Tue Mar 20 00:21:52 EDT 2012
 * End  : Tue Mar 20 00:39:36 EDT 2012
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
typedef unsigned long long int ULL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		ULL third, bottomThird, S;
		cin >> third >> bottomThird >> S;
		ULL N = 2ULL*S/( third+bottomThird );
		cout << N << endl;
		ULL a = ( bottomThird-third )/( N-5 );
		ULL x = third - 2ULL*a;
		cout << x;
		for( ULL i=1ULL; i<N; ++i )
			cout << " " << x+i*a;
		cout << endl; 
	}
}
