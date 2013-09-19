/* Alex Velazquez
 * Start: Thu Jul 12 22:23:06 EDT 2012
 * End  :
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
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	LL MOD = 1000000003LL;
	REP( i, T )
	{
		LL n;
		cin >> n;
		LL a = (n*(n+1))%MOD;
		LL b = (a*(n+2))%MOD;
		LL c = ((3*n*n)%MOD+(6*n)%MOD+1LL)%MOD;
		cout << ((b*c)%MOD)/60LL << endl;
	}
}
