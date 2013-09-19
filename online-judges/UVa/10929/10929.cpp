/* Alex Velazquez
 * Start: Sun Mar 25 01:01:28 EDT 2012
 * End  : Sun Mar 25 01:06:14 EDT 2012
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
	string N;
	while( cin >> N )
	{
		if( !N.compare( "0" ) )
			break;
		int size = N.size();
		int odd = 0, even = 0;
		REP( i, size )
		{
			if( i%2 )
				odd += N[i]-'0';
			else
				even +=N[i]-'0';
		}
		if( !( (even-odd)%11 ) )
			cout << N << " is a multiple of 11." << endl;
		else
			cout << N << " is not a multiple of 11." << endl;
	}
}
