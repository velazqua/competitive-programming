/* Alex Velazquez
 * Start: Fri Aug 24 23:08:10 EDT 2012
 * End  : Sat Aug 25 00:06:37 EDT 2012
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

int countWays( string &S, int i, int curr, int prev, int size )
{
	#if DEBUG
	cout << "entering: " << "-> curr: " << curr << ". prev: " << prev << endl;
	#endif	
	if( i >= size )
	{
		if( curr >= prev )
		{
			#if DEBUG
			cout << "===> curr: " << curr << ". prev: " << prev << endl;
			#endif
			return 1;
		}
		else
			return 0;
	}
	else
	{
		#if DEBUG
		cout << "branch1 ==> curr: " << S[i]-48 << ". prev: " << curr << endl;
		#endif
		int ways1 = ( curr >= prev ) ? countWays( S, i+1, S[i]-48, curr, size ) : 0;
		
		#if DEBUG
		cout << "branch2 ==> curr: " << curr+S[i]-48 << ". prev: " << prev << endl;
		#endif
		int ways2 = ( 1 ) ? countWays( S, i+1, curr+S[i]-48, prev, size ) : 0;
		return ways1 + ways2;
	}
}

int main ()
{
	string S;
	int c = 1;
	while( cin >> S )
	{
		if( !S.compare( "bye" ) )
			break;
		int size = SZ(S);
		int ways = countWays( S, 1, S[0]-48, 0, size ); 
		cout << c++ << ". " << ways << endl;
	}
}
