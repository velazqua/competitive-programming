/* Alex Velazquez
 * Start: Sat Sep 15 23:17:25 EDT 2012
 * End  : Sat Sep 15 23:33:54 EDT 2012
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
#include <iterator>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        1

typedef long long int LL;

using namespace std;

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
		if( N < 10 )
		{
			cout << N << endl;
			continue;
		}
		string answer = "";
		for( int k=9; k >= 2; --k )
		{
			while( N % k == 0 )
			{
				N /= k;
				answer = char( 48+k ) + answer;
			}
		}
		if( N != 1 )
			cout << -1 << endl;
		else
			cout << answer << endl;

	}
}
