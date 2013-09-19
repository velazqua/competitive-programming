/* Alex Velazquez
 * Start: Sat Sep 15 20:09:32 EDT 2012
 * End  : Sat Sep 15 20:15:31 EDT 2012
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
	REP( t, T )
	{
		int N1;
		cin >> N1;
		set<int> nums1;
		REP( i, N1 )
		{
			int n;
			cin >> n;
			nums1.insert( n );
		}
		int N2;
		cin >> N2;
		int minn = 2000000000;
		REP( i, N2 )
		{
			int n;
			cin >> n;
			set<int>::iterator it = nums1.lower_bound( n );
			minn = min( minn, abs( n - *it ) );
			if( it != nums1.begin() )
			{
				it--;
				minn = min( minn, abs( n - *it ) );
			}
		}
		cout << minn << endl;
	}
}
