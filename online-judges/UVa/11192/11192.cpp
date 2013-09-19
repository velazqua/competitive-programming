/* Alex Velazquez
 * Start: Sat Sep 22 19:06:51 EDT 2012
 * End  : Sat Sep 22 19:10:21 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
	int N;
	while( cin >> N )
	{
		if( !N )
			break;
		string S;
		cin >> S;
		int size = SZ(S);
		int sizeGroup = size/N;
		string::iterator it = S.begin();
		REP( i, N )
		{
			reverse( it, it+sizeGroup );
			it += sizeGroup;
		}
		cout << S << endl;
	}
}
