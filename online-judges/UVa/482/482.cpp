/* Alex Velazquez
 * Start: Mon Mar 26 22:08:16 EDT 2012
 * End  : Mon Mar 26 22:20:38 EDT 2012
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

int main ()
{
	int T;
	cin >> T;
	cin.ignore();
	REP( i, T )
	{
		if( i != 0 )
			cout << endl;
		string emptyLine, perm, nums;
		getline( cin, emptyLine );
		getline( cin, perm );
		getline( cin, nums );
		vector<int> order;
		int size = 0;
		stringstream sPerm( perm ), sNums( nums );
		int o;
		while( sPerm >> o )
		{
			//cout << "o: " << o << endl;
			order.push_back( o );
			++size;
		}
		
		vector<string> dnums( size );
		string d;
		int k = 0;
		while( sNums >> d )
		{
			//cout << "d: " << d << endl;
			dnums[order[k]-1] = d;
			++k;
		}
		REP( k, size )
			cout << dnums[k] << endl;
	}
}
