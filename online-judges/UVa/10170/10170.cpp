/* Alex Velazquez
 * Start: Tue Jul  3 19:51:50 EDT 2012
 * End  : Tue Jul  3 20:07:43 EDT 2012
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

int main ()
{
	LL S, D;
	while( cin >> S >> D )
	{
		if( D == 1 )
		{
			cout << S << endl;
			continue;
		}
		LL left = 0LL, right = 50000000LL, middle;
		while( 1 )
		{
			middle = (left+right)/2;
			LL val = middle*(middle+1)/2-(S*(S-1)/2);
			LL pVal= (middle-1)*(middle)/2-(S*(S-1)/2);
			#if DEBUG
				cout << val << " " << pVal << " " << middle << endl;
			#endif
			if( val < D )
			{
				left = middle;
			}
			else if( val > D && pVal > D )
			{
				right = middle;
			}
			else if( val == D || ( val > D && pVal < D ) )
			{
				cout << middle << endl;
				break;
			}
		}
	}
}
