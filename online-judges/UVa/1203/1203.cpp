/* Alex Velazquez
 * Start: Thu Mar 29 00:36:28 EDT 2012
 * End  : Thu Mar 29 00:54:32 EDT 2012
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

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct R {
	int id;
	int val;
	int occur;
	R( int ID, int VAL, int OCCUR ) : id( ID ), val( VAL ), occur( OCCUR ) {}
};

bool operator < ( R const& A, R const& B )
{
	if( A.val*A.occur < B.val*B.occur )
		return true;
	else if( A.val*A.occur > B.val*B.occur ) 
		return false;
	else
		return A.id < B.id;
}

int main ()
{
	string reg;
	int id, val;
	set<R> registers;
	while( 1 )
	{
		cin >> reg;
		if( !reg.compare( "#" ) )
			break;
		cin >> id >> val;
		registers.insert( R( id, val, 1 ) );
	}
	int K;
	cin >> K;
	set<R>::iterator it;
	REP( i, K )
	{
		it = registers.begin();
		cout << it->id << endl;
		R newGuy( it->id, it->val, it->occur+1 );
		registers.erase( it );
		registers.insert( newGuy );
	}
}
