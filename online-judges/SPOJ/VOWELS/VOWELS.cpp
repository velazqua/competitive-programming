/* Alex Velazquez
 * Start: Tue Apr 17 22:27:37 EDT 2012
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
	string S;
	cin >> S;
	int size = S.size();
	int counter = 0;
	set<char> V;
	V.insert( 'a' );V.insert( 'A' );V.insert( 'Y' );
	V.insert( 'e' );V.insert( 'E' );V.insert( 'y' );
	V.insert( 'i' );V.insert( 'I' );
	V.insert( 'o' );V.insert( 'O' );
	V.insert( 'u' );V.insert( 'U' );
	REP( c, size )
		if( V.count( S[c] ) > 0 )
			++counter;
	cout << counter << endl;
}
