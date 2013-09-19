/* Alex Velazquez
 * Start: Thu May 31 22:09:09 EDT 2012
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
		LL num;
		cin >> num;
		if( num == 1LL )
		{
			cout << 5 << endl;
			continue;
		}
		string answer = "";
		for( int j=1; ; ++j )
		{
			LL X;
			LL P = ( 1LL << j );
			if( j==1 ) 
				X = ( num ) % ( P );
			else
				X = ( num-( P-2LL )+1LL ) % ( P );
		
			cout << P << " " << X << " " << (( P-2LL )) << endl;
			if( X <= 0 ) break;  
			answer += ( ( X < ( 1LL << (j-1) ) ) ? "5":"6" );
		}
		reverse( ALL( answer ) );
		cout << answer << endl;
	}
}
