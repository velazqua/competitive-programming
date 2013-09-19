/* Alex Velazquez
 * Start: Thu May 10 20:44:38 EDT 2012
 * End  : Thu May 10 21:47:35 EDT 2012
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
typedef unsigned long long ULL;
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ULL search( ULL n, ULL f, ULL l )
{
	ULL mid = (f+l)/2ULL;
	ULL N = (mid*(mid+1ULL))/2ULL;
	//cout << "mid: " << mid << ". N: " << N << endl;
	if( N == n )
		return mid;
	else if( N < n )
	{
		ULL next = mid+1ULL;
		ULL Nnext = (next*(next+1ULL))/2ULL;
		//cout << "next: " << next << ". Nnext: " << Nnext << endl;
		if( Nnext == n )
			return next;
		else if( Nnext > n )
			return mid;
		return search( n, mid, l );
	}
	else
		return search( n, f, mid );
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		ULL n;
		cin >> n;
		cout << search( n, 0ULL, 2000000000ULL ) << endl;
	}
}
